#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

#include <string>

#include "wrapper/button.hpp"
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"
#include "wrapper/tileview.hpp"
#include "wrapper/label.hpp"

void ui_init() {
  const int screenWidth = 480;
	const int screenHeight = 240;
  static lv_style_t container_style;

  Object container = Object::create()
		  .setPosition(0, 0)
		  .setSize(screenWidth,screenHeight);
  
  static lv_style_t field_style;

//  Object field = Object::create(container)
//		  .setPosition(0, 0)
//		  .setSize(screenHeight, screenHeight);

  static lv_style_t tile_style;

  Object mainScreen = Object::create(container).setPosition(screenHeight, 0)
		  .setSize(screenWidth-screenHeight, screenHeight);
  
  std::string xStr( "X: " + std::to_string(1234087) );
  std::string yStr( "Y: " + std::to_string(1234087) );
  std::string tStr( "T: " + std::to_string(1234087) );

  Label x = Label::create(container).setY(0);
    x.setText(xStr.c_str());
  Label y = Label::create(container).setY(40);
		y.setText(yStr.c_str());
  Label t = Label::create(container).setY(80);
		t.setText(tStr.c_str());

  Label mainContent = Label::create(mainScreen).setText(" This UI was made using\n LVGLBuilder, a\n collaboration between\n teams 4911A, 7842F, 914M.\n The library aims to ease\n the creation of UIs for\n programming beginners\n and veterans alike. The\n library is currently in\n early development.\0"); 
  lv_style_copy(&container_style, &lv_style_plain);
  container_style.body.main_color = LV_COLOR_GRAY;
  container_style.body.grad_color = LV_COLOR_RED;
  lv_style_copy(&field_style, &lv_style_plain);
  field_style.body.main_color = LV_COLOR_WHITE;
  field_style.body.grad_color = LV_COLOR_WHITE;
  lv_style_copy(&tile_style, &lv_style_plain);
  tile_style.body.main_color = LV_COLOR_GRAY;
  tile_style.body.grad_color = LV_COLOR_GRAY;
  tile_style.body.border.color = LV_COLOR_WHITE;
  tile_style.body.border.width = 2;
	
	container.setStyle(&container_style);
	//field.setStyle(&field_style);
	x.setPosition(0, 0);
	y.setPosition(0, 40);
	t.setPosition(0, 80);

  while (true) {
    for(double i = 0; i < 9000000000; i++){
      printf("I = %f\n", i);
    }
    printf("done\n");
  }
}
