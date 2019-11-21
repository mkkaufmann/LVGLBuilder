#include "wrapper/textarea.hpp"

TextArea TextArea::create() {
  return TextArea(lv_ta_create(lv_scr_act(), NULL));
}

TextArea TextArea::create(const Object& iparent) {
  return TextArea(lv_ta_create(iparent.get(), NULL));
}

TextArea TextArea::create(const Object& iparent, const TextArea& icopy) {
  return TextArea(lv_ta_create(iparent.get(), icopy.get()));
}
