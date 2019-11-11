#include "lvgl/lvgl.h"
#include <stdlib.h>
#include <unistd.h>

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
  
  Label x = Label::create(container).setY(0);
  x.setText("X: 01590238049\0");
  Label y = Label::create(container).setY(40);
		  y.setText("X: 01590238049\0");
  Label t = Label::create(container).setY(80);
		  t.setText("X: 01590238049\0");
  Label mainContent = Label::create(mainScreen).setText(" This UI was made using\n LVGLBuilder, a\n collaboration between\n teams 4911A, 7842F and 914M.\n The library aims to ease\n the creation of UIs for\n programming beginners\n and veterans alike. The\n library is currently in\n early development.\0"); 
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
    usleep(1000000);
  }
}
