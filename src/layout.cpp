#include "layout.hpp"

const char * Layout::colormap[3] = {"Red", "Blue", ""};
const char* Layout::autonmap[12] = { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "\n",
	"one", "five", "six", "seven", ""};

ButtonMatrix Layout::colorSelector = ButtonMatrix::create().setPosition(0,0).setSize(screenWidth, (screenHeight - 40)/3);

ButtonMatrix Layout::autonSelector = ButtonMatrix::create().setPosition(0,(screenHeight - 40)/3).setSize(screenWidth, (screenHeight - 40)*2/3);

Layout::Layout(){
				lv_style_copy(autonReleased, &lv_style_pretty);			
				lv_style_copy(autonPressed, autonReleased);		
				autonReleased->body.main_color = LV_COLOR_RED;
				autonReleased->body.grad_color = LV_COLOR_RED;
				autonPressed->body.main_color = LV_COLOR_YELLOW;
				autonPressed->body.grad_color = LV_COLOR_YELLOW;

				lv_style_copy(colorReleased, &lv_style_pretty);			
				lv_style_copy(colorPressed, colorReleased);		
				colorPressed->body.main_color = LV_COLOR_RED;
				colorPressed->body.grad_color = LV_COLOR_RED;
				colorSelector.setMap(colormap)
								.setAction(colorSelectorAction)
								.setToggle(true, 1)
								.setStyle(LV_BTNM_STYLE_BG, colorPressed)
								.setStyle(LV_BTNM_STYLE_BTN_PR, colorPressed)
								.setStyle(LV_BTNM_STYLE_BTN_TGL_PR, colorPressed)
								.setStyle(LV_BTNM_STYLE_BTN_TGL_REL, colorPressed)
								.setStyle(LV_BTNM_STYLE_BTN_REL, colorReleased)
								.setStyle(LV_BTNM_STYLE_BTN_INA, colorReleased);
				autonSelector.setMap(autonmap)
								.setAction(autonSelectorAction)
								.setToggle(true, 7)
								.setStyle(LV_BTNM_STYLE_BG, autonPressed)
								.setStyle(LV_BTNM_STYLE_BTN_PR, autonPressed)
								.setStyle(LV_BTNM_STYLE_BTN_TGL_PR, autonPressed)
								.setStyle(LV_BTNM_STYLE_BTN_TGL_REL, autonPressed)
								.setStyle(LV_BTNM_STYLE_BTN_REL, autonReleased)
								.setStyle(LV_BTNM_STYLE_BTN_INA, autonReleased);
}

lv_res_t Layout::colorSelectorAction(lv_obj_t* btnm, const char * txt){
								lv_style_t* style = lv_btnm_get_style(btnm, LV_BTNM_STYLE_BTN_PR);
				if(strcmp(txt, "Red") == 0){
								style->body.main_color = LV_COLOR_RED;
								style->body.grad_color = LV_COLOR_RED;
				}else if(strcmp(txt, "Blue") == 0){
								style->body.main_color = LV_COLOR_BLUE;
								style->body.grad_color = LV_COLOR_BLUE;
				}
				colorSelector					
				.setStyle(LV_BTNM_STYLE_BG, style)
				.setStyle(LV_BTNM_STYLE_BTN_PR, style)
				.setStyle(LV_BTNM_STYLE_BTN_TGL_PR, style)
				.setStyle(LV_BTNM_STYLE_BTN_TGL_REL, style);
				return LV_RES_OK;
}

lv_res_t Layout::autonSelectorAction(lv_obj_t* btnm, const char * txt){
				return LV_RES_OK;
}
