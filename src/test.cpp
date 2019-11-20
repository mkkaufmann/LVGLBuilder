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
#include "util/point.hpp"
#include "util/polarpoint.hpp"
#include "util/pointutil.hpp"

void ui_init() {
  const int screenWidth = 480;
	const int screenHeight = 240;
//  static lv_style_t container_style;
//
//  Object container = Object::create()
//		  .setPosition(0, 0)
//		  .setSize(screenWidth,screenHeight);
//  
//  static lv_style_t field_style;
//
////  Object field = Object::create(container)
////		  .setPosition(0, 0)
////		  .setSize(screenHeight, screenHeight);
//
//  static lv_style_t tile_style;
//
//  Object mainScreen = Object::create(container).setPosition(screenHeight, 0)
//		  .setSize(screenWidth-screenHeight, screenHeight);
//  
//  std::string xStr( "X: " + std::to_string(1234087) );
//  std::string yStr( "Y: " + std::to_string(1234087) );
//  std::string tStr( "T: " + std::to_string(1234087) );
//
//  Label x = Label::create(container).setY(0);
//    x.setText(xStr.c_str());
//  Label y = Label::create(container).setY(40);
//		y.setText(yStr.c_str());
//  Label t = Label::create(container).setY(80);
//		t.setText(tStr.c_str());
//
//  double xPos = 3 * 20;
//  double yPos = 3 * 20;
//  double tRot = M_PI;
//  double botWidth = 1.5 * 20;
//  double botLength = 1.5 * 20;
//  PolarPoint topRightPolar = PointUtil::toPolar(Point(botWidth/2, -botLength/2));
//  topRightPolar.rotateAngle(tRot);
//  Point topRight = PointUtil::toCartesian(topRightPolar);
//  PolarPoint bottomRightPolar = PointUtil::toPolar(Point(botWidth/2, botLength/2));
//  bottomRightPolar.rotateAngle(tRot);
//  Point bottomRight = PointUtil::toCartesian(bottomRightPolar);
//  PolarPoint bottomLeftPolar = PointUtil::toPolar(Point(-botWidth/2, botLength/2));
//  bottomLeftPolar.rotateAngle(tRot);
//  Point bottomLeft = PointUtil::toCartesian(bottomLeftPolar);
//  PolarPoint topLeftPolar = PointUtil::toPolar(Point(-botWidth/2, -botLength/2));
//  topLeftPolar.rotateAngle(tRot);
//  Point topLeft = PointUtil::toCartesian(topLeftPolar);
//  PolarPoint arrowLeftPolar = PointUtil::toPolar(Point(-botWidth/4, -botLength/2));
//  arrowLeftPolar.rotateAngle(tRot);
//  Point arrowLeft = PointUtil::toCartesian(arrowLeftPolar);
//  PolarPoint arrowPointPolar = PointUtil::toPolar(Point(0, -botLength/2 - 10));
//  arrowPointPolar.rotateAngle(tRot);
//  Point arrowPoint = PointUtil::toCartesian(arrowPointPolar);
//  PolarPoint arrowRightPolar = PointUtil::toPolar(Point(botWidth/4, -botLength/2));
//  arrowRightPolar.rotateAngle(tRot);
//  Point arrowRight = PointUtil::toCartesian(arrowRightPolar);
//
//  lv_point_t points[] = {
//		{(short)(topRight.getX() + xPos), (short)(topRight.getY() + yPos)},
//		{(short)(bottomRight.getX() + xPos), (short)(bottomRight.getY() + yPos)},
//		{(short)(bottomLeft.getX() + xPos), (short)(bottomLeft.getY() + yPos)},
//		{(short)(topLeft.getX()+ xPos), (short)(topLeft.getY() + yPos)},
//		{(short)(arrowLeft.getX()+ xPos), (short)(arrowLeft.getY() + yPos)},
//		{(short)(arrowPoint.getX()+ xPos), (short)(arrowPoint.getY() + yPos)},
//		{(short)(arrowRight.getX()+ xPos), (short)(arrowRight.getY() + yPos)},
//		{(short)(topRight.getX() + xPos), (short)(topRight.getY() + yPos)}
//  };
//
//  Line bot = Line::create().setPoints(&points[0], 8);
//
//  Label mainContent = Label::create(mainScreen).setText(" This UI was made using\n LVGLBuilder, a\n collaboration between\n teams 4911A, 7842F, 914M.\n The library aims to ease\n the creation of UIs for\n programming beginners\n and veterans alike. The\n library is currently in\n early development.\0"); 
//  lv_style_copy(&container_style, &lv_style_plain);
//  container_style.body.main_color = LV_COLOR_GRAY;
//  container_style.body.grad_color = LV_COLOR_RED;
//  lv_style_copy(&field_style, &lv_style_plain);
//  field_style.body.main_color = LV_COLOR_WHITE;
//  field_style.body.grad_color = LV_COLOR_WHITE;
//  lv_style_copy(&tile_style, &lv_style_plain);
//  tile_style.body.main_color = LV_COLOR_GRAY;
//  tile_style.body.grad_color = LV_COLOR_GRAY;
//  tile_style.body.border.color = LV_COLOR_WHITE;
//  tile_style.body.border.width = 2;
//	
//	container.setStyle(&container_style);
//	//field.setStyle(&field_style);
//	x.setPosition(0, 0);
//	y.setPosition(0, 40);
//	t.setPosition(0, 80);

//  Button btnred = Button::create().setPosition(0,0).setSize(screenWidth/2, screenHeight);
//  Label redlabel = Label::create(btnred).setText("RED");
//  Button btnblue = Button::create().setPosition(screenWidth/2,0).setSize(screenWidth/2, screenHeight);
//  Label bluelabel = Label::create(btnblue).setText("BLUE");
	static const char * autonMap[] = {"one", "five", "\n",
                                  "ONE", "TWO", "THREE", ""};
	Object container = Object::create().setSize(screenWidth, screenHeight);
	ButtonMatrix autonSelector = ButtonMatrix::create().setSize(screenWidth, (screenHeight * 2)/3);
	autonSelector.setToggle(true, 1);
	autonSelector.setMap(autonMap);

	static const char * sideMap[] = {"Red", "Blue", ""};

	ButtonMatrix sideSelector = ButtonMatrix::create().setSize(screenWidth, screenHeight/3).setPosition(0, (screenHeight * 2)/3);
	sideSelector.setToggle(true, 1);
	sideSelector.setMap(sideMap);
  while (true) {
    for(double i = 0; i < 9000000000; i++){
      printf("I = %f\n", i);
    }
    printf("done\n");
  }
}
