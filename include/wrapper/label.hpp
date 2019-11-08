#pragma once
#include "object.hpp"

class Label : public Object {
public:
  /**
   * Wraps an LVGL label pointer
   */
  using Object::Object;

  /**
   * Returns the name of the object, used for logging
   */
  static constexpr const char* getName() {
    return "Label";
  }

  /**
   * Create Label with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Label create();

  /** 
   * Create Label with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Label create(const Object& iparent);

  /** 
   * Create Label with both parent and copy parameters
   *
   * @param iparent the parent Label for this Label to be a child of
   * @param icopy   the Label for this Label to copy
   */
  static Label create(const Object& iparent, const Label& icopy);
};
