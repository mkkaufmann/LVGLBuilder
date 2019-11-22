#pragma once
#include "object.hpp"

class TextArea : public Object {
public:
  /**
   * Wraps an LVGL tileveiw pointer
   */
  using Object::Object;

  /**
   * Returns the name of the object, used for logging
   */
  static constexpr const char* getName() {
    return "TextArea";
  }

  /**
   * Create TextArea with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static TextArea create();

  /** 
   * Create TextArea with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent TextArea for this TextArea to be a child of
   */
  static TextArea create(const Object& iparent);

  /** 
   * Create TextArea with both parent and copy parameters
   *
   * @param iparent the parent TextArea for this TextArea to be a child of
   * @param icopy   the TextArea for this TextArea to copy
   */
  static TextArea create(const Object& iparent, const TextArea& icopy);
};
