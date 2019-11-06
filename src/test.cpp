#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include "wrapper/object.hpp"

void ui_init() {

  Object object1 = Object::create().setSize(100, 100).setPosition(50, 50);

  Object obj2 = Object::create(object1);
  obj2.setSize(20, 20).setPosition(0, 0);

  while (true) {
    usleep(1000000);
  }
}