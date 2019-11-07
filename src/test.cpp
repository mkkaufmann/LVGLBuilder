#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include "wrapper/button.hpp"
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"

void ui_init() {

  Object obj1 = Object::create().setSize(100, 100).setPosition(50, 50);

  Object obj2 = Object::create(obj1);
  obj2.setSize(20, 20).setPosition(0, 0);

  Button btn = Button::create().setSize(200, 100).setPosition(0, 0);
  static lv_style_t style_1;
  lv_style_copy(&style_1, &lv_style_plain);
  style_1.body.main_color = LV_COLOR_RED;
  btn.setStyle(LV_BTN_STYLE_PR, &style_1);

  ButtonMatrix btnm = ButtonMatrix::create();
  while (true) {
    usleep(1000000);
  }
}
