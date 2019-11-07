#include "wrapper/button.hpp"

Button Button::create() {
  return Button(lv_btn_create(lv_scr_act(), NULL));
}

Button Button::create(const Object& iparent) {
  return Button(lv_btn_create(iparent.get(), NULL));
}

Button Button::create(const Object& iparent, const Button& icopy) {
  return Button(lv_btn_create(iparent.get(), icopy.get()));
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

Button& Button::setLayout(lv_layout_t layout) {
  lv_btn_set_layout(object, layout);
  return *this;
}
