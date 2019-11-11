#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include "wrapper/button.hpp"
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"
#include "wrapper/tileview.hpp"
#include "wrapper/label.hpp"

static lv_res_t click_action()
{
  printf("Clicked!\n");
  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}


void ui_init() {
  
  //max height: 240
  //max width: 480
  const int screenHeight = 240;
  const int screenWidth = 480;
  
  static lv_style_t container_style;
  lv_style_copy(&container_style, &lv_style_plain);
  container_style.body.main_color = LV_COLOR_RED;
  container_style.body.grad_color = LV_COLOR_RED;

  Object container = Object::create()
		  .setPosition(0, 0)
		  .setSize(screenWidth,screenHeight)
		  .setStyle(&container_style);
  
  static lv_style_t field_style;
  lv_style_copy(&field_style, &lv_style_plain);
  field_style.body.main_color = LV_COLOR_WHITE;
  field_style.body.grad_color = LV_COLOR_WHITE;

  Object field = Object::create(container)
		  .setPosition(0, 0)
		  .setSize(screenHeight, screenHeight)
		  .setStyle(&field_style);

  static lv_style_t tile_style;
  lv_style_copy(&tile_style, &lv_style_plain);
  tile_style.body.main_color = LV_COLOR_GRAY;
  tile_style.body.grad_color = LV_COLOR_GRAY;
  tile_style.body.border.color = LV_COLOR_WHITE;
  tile_style.body.border.width = 2;

  for(int i = 0; i < 6; i++){
		  for(int j = 0; j < 6; j++){
				  Object::create(field)
						  .setPosition(i * 40, j * 40)
						  .setSize(40, 40)
						  .setStyle(&tile_style);
		  }
  }

  static lv_style_t main_style;
  lv_style_copy(&main_style, &lv_style_plain);
  main_style.body.main_color = LV_COLOR_WHITE;
  main_style.body.grad_color = LV_COLOR_WHITE;
  main_style.body.border.color = LV_COLOR_BLACK;
  main_style.body.border.width = 2;
  main_style.body.padding.inner = 3;

  Object mainScreen = Object::create(container).setPosition(screenHeight, 0)
		  .setSize(screenWidth-screenHeight, screenHeight).setStyle(&main_style);

  Label mainContent = Label::create(mainScreen).setText(" This UI was made using\n LVGLBuilder, a\n collaboration between\n teams 4911A, 7842F and 914M.\n The library aims to ease\n the creation of UIs for\n programming beginners\n and veterans alike. The\n library is currently in\n early development.\0"); 
//*
  Object sidebar = Object::create(container).setPosition(screenWidth - 80, 0).setSize(80, screenHeight);

  for(int i = 0; i < 4; i++){
		  Button::create(sidebar).setPosition(0, i * 60).setSize(80, 60);
  }

  lv_style_t * main_btn_style = &main_style;

  Button button = Button::create()
    .setAction(LV_BTN_ACTION_CLICK, click_action)
    .setLayout( LV_LAYOUT_OFF )
    .setFit( 100, 100 )
    .toggle()
    .setInkInTime(500)
    .setInkOutTime(500)
    .setInkWaitTime(500)
    .setStyle(LV_BTN_STYLE_REL, main_btn_style);

//*/
  while (true) {
    usleep(1000000);
  }
}
