#pragma once
#include "wrapper/object.hpp"
#include "wrapper/buttonmatrix.hpp"
class Layout{
public:
				static const int screenWidth = 480;
				static const int screenHeight = 240;
				Layout();
private:				
				static ButtonMatrix colorSelector;
				lv_style_t* colorBackground;
				lv_style_t* colorReleased;
				lv_style_t* colorPressed;
				static lv_res_t colorSelectorAction(lv_obj_t*, const char *);
				static ButtonMatrix autonSelector;
				lv_style_t* autonBackground;
				lv_style_t* autonReleased;
				lv_style_t* autonPressed;
				static lv_res_t autonSelectorAction(lv_obj_t*, const char *);
				static const char* colormap[3];
				static const char* autonmap[12];
};
