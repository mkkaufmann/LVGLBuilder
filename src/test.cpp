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

  Object mainScreen = Object::create(container).setPosition(screenHeight, 0)
		  .setSize(screenWidth-screenHeight-80, screenHeight);

  Object sidebar = Object::create(container).setPosition(screenWidth - 80, 0).setSize(80, screenHeight);

  for(int i = 0; i < 4; i++){
		  Button::create(sidebar).setPosition(0, i * 60).setSize(80, 60);
  }

  while (true) {
    usleep(1000000);
  }
}
