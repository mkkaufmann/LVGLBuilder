
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
#include "layout.hpp"

const int screenWidth = 480;
const int screenHeight = 240;

void ui_init() {
  Object container = Object::create();
  container.setSize( screenWidth, screenHeight );

  ButtonMatrix btnm = ButtonMatrix::create(container);
  btnm.setSize(screenWidth, screenHeight/4);

  Label label = Label::create(container);
  label.setSize(screenWidth/4, screenHeight * .75);
  label.setPosition(0,screenHeight/4);
  label.setStaticText("    l\n    a\n    b\n    e\n    l\n\n  here  ");

  lv_point_t points[] = { { screenWidth/8, screenHeight/4 }, { screenWidth/8, screenHeight } };
  Line line = Line::create(container);
  line.setPoints( points, 2 );

  Button button = Button::create(container);
  button.setSize(screenWidth/4, screenHeight * .75);
  button.setPosition( screenWidth/8, screenHeight/4 );
  button.setText("Button");

  TileView tileView = TileView::create(container);
  tileView.setSize(screenWidth * (5/8), screenHeight * .75);
  tileView.setPosition(screenWidth * (3/8), screenHeight/4);

  while (true) {
    usleep(1000000);
  }
}
