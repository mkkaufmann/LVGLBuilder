#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include <string>

#include "wrapper/button.hpp"
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"
#include "wrapper/tileview.hpp"
#include "wrapper/label.hpp"
#include "wrapper/line.hpp"

const int screenWidth = 480;
const int screenHeight = 240;
void ui_init() {
  Object container = Object::create();
  while (true) {
    usleep(1000000);
  }
}
