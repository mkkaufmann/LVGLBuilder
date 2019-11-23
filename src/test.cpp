#include "lvgl/lvgl.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "layout.hpp"
#include "wrapper/button.hpp"
#include "wrapper/buttonmatrix.hpp"
#include "wrapper/label.hpp"
#include "wrapper/line.hpp"
#include "wrapper/object.hpp"
#include "wrapper/page.hpp"
#include "wrapper/tileview.hpp"

void test() {
  Object container = Object::create();
  container.setSize(LV_HOR_RES, LV_VER_RES);

  ButtonMatrix btnm = ButtonMatrix::create(container);
  btnm.setSize(LV_HOR_RES, LV_VER_RES / 4.0);

  Label label = Label::create(container);
  label.setSize(LV_HOR_RES / 4.0, LV_VER_RES * 0.75);
  label.setPosition(0, LV_VER_RES / 4.0);
  label.setStaticText("    l\n    a\n    b\n    e\n    l\n\n  here  ");

  lv_point_t points[] = {{LV_HOR_RES / 8.0, LV_VER_RES / 4.0}, {LV_HOR_RES / 8.0, LV_VER_RES}};
  Line line = Line::create(container);
  line.setPoints(points, 2);

  Button button = Button::create(container);
  button.setSize(LV_HOR_RES / 4.0, LV_VER_RES * 0.75);
  button.setPosition(LV_HOR_RES / 8.0, LV_VER_RES / 4.0);
  button.setText("Button");

  TileView tileView = TileView::create(container);
  tileView.setSize(LV_HOR_RES * 0.625, LV_VER_RES * 0.75);
  tileView.setPosition(LV_HOR_RES * 0.375, LV_VER_RES / 4.0);
}

void ui_init() {
  test();
  //  Layout layout();
  while (true) {
    usleep(1000000);
  }
}
