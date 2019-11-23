#include "wrapper/button.hpp"
#include "wrapper/label.hpp"

Button Button::create() {
  return Button(lv_btn_create(ActiveScreen(), NULL));
}

Button Button::create(const Object& iparent) {
  return Button(lv_btn_create(iparent, NULL));
}

Button Button::create(const Object& iparent, const Button& icopy) {
  return Button(lv_btn_create(iparent, icopy));
}

void Button::setText(const char* txt, const lv_obj_t* copy) {
  label = lv_label_create(object, copy);
  lv_label_set_text(label, txt);
}

Button& Button::setToggle(bool enabled) {
  lv_btn_set_toggle(object, enabled);
  return *this;
}

Button& Button::setState(lv_btn_state_t state) {
  lv_btn_set_state(object, state);
  return *this;
}

Button& Button::toggle() {
  lv_btn_toggle(object);
  return *this;
}

Button& Button::setAction(lv_btn_action_t type, lv_action_t action) {
  lv_btn_set_action(object, type, action);
  return *this;
}

Button& Button::setLayout(lv_layout_t layout) {
  lv_btn_set_layout(object, layout);
  return *this;
}

Button& Button::setFit(bool horizontal_enable, bool vertical_enable) {
  lv_btn_set_fit(object, horizontal_enable, vertical_enable);
  return *this;
}

Button& Button::setStyle(lv_btn_style_t type, lv_style_t* style) {
  lv_btn_set_style(object, type, style);
  return *this;
}

lv_btn_state_t Button::getState() {
  return lv_btn_get_state(object);
}

bool Button::getToggle() {
  return lv_btn_get_toggle(object);
}

lv_action_t Button::getAction(lv_btn_action_t type) {
  return lv_btn_get_action(object, type);
}

lv_layout_t Button::getLayout() {
  return lv_btn_get_layout(object);
}

bool Button::getHorFit() {
  return lv_btn_get_hor_fit(object);
}

bool Button::getVerFit() {
  return lv_btn_get_ver_fit(object);
}

lv_style_t* Button::getStyle(lv_btn_style_t type) {
  return lv_btn_get_style(object, type);
}
