#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include "wrapper/button.hpp"
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"
#include "wrapper/tileview.hpp"

void ui_init() {
  
  //max height: 240
  //max width: 480
  const int screenHeight = 240;
  const int screenWidth = 480;
  
  Object container = Object::create().setPosition(0, 0).setSize(screenWidth,screenHeight);
  
  Object field = Object::create(container).setPosition(0, 0).setSize(screenWidth, screenWidth);

  for(int i = 0; i < 6; i++){
		  for(int j = 0; j < 6; j++){
				  Object tile = Object::create(field).setPosition(i * 40, j * 40).setSize(40, 40);
		  }
  }

  Object mainScreen = Object::create(container).setPosition(screenHeight, 0)
		  .setSize(screenWidth-screenHeight-80, screenHeight);

  Object sidebar = Object::create(container).setPosition(screenWidth - 80, 0).setSize(80, screenHeight);

  for(int i = 0; i < 4; i++){
		  Object button = Button::create(sidebar).setPosition(0, i * 60).setSize(80, 60);
  }

  while (true) {
    usleep(1000000);
  }
}
