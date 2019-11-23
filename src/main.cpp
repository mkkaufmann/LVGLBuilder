#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lvgl/lvgl.h"
#include <SDL2/SDL.h>

/*On OSX SDL needs different handling*/
#if defined(__APPLE__) && defined(TARGET_OS_MAC)
  #if __APPLE__ && TARGET_OS_MAC
    #define SDL_APPLE
  #endif
#endif

static void hal_init(void);
static int tick_thread(void* data);
static int lvgl_thread(void* data);
void ui_init();

// run this function before initializing globals
__attribute__((constructor(101))) static void display_init() {
  /*Initialize LittlevGL*/
  lv_init();
  /*Initialize the HAL (display, input devices, tick) for LittlevGL*/
  hal_init();
  // set the global theme
  lv_theme_set_current(lv_theme_alien_init(40, NULL));
}

int main(int argc, char** argv) {
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  ui_init();

  return 0;
}

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void) {
  /* Add a display
   * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.disp_flush = monitor_flush;
  disp_drv.disp_fill = monitor_fill;
  disp_drv.disp_map = monitor_map;
  lv_disp_drv_register(&disp_drv);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read = mouse_read;
  lv_indev_drv_register(&indev_drv);

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about how much time were elapsed
   * Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);
  SDL_CreateThread(lvgl_thread, "lvgl", NULL);
}

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void* data) {
  (void)data;

  while (1) {
    SDL_Delay(5); /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

static int lvgl_thread(void* data) {
  (void)data;

  while (1) {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_task_handler();
    usleep(5 * 1000);

#ifdef SDL_APPLE
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
  #if USE_MOUSE != 0
      mouse_handler(&event);
  #endif

  #if USE_KEYBOARD
      keyboard_handler(&event);
  #endif

  #if USE_MOUSEWHEEL != 0
      mousewheel_handler(&event);
  #endif
    }
#endif
  }

  return 0;
}
