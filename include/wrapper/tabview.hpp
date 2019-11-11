#pragma once
#include "object.hpp"

class TabView : public Object {
public:
  /**
   * Wraps an LVGL pointer
   */
  using Object::Object;

  /**
   * Returns the name of the object, used for logging
   */
  static constexpr const char* getName() {
    return "TabView";
  }

  /**
   * Create TabView with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static TabView create();

  /** 
   * Create TabView with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static TabView create(const Object& iparent);

  /** 
   * Create TabView with both parent and copy parameters
   *
   * @param iparent the parent TabView for this TabView to be a child of
   * @param icopy   the TabView for this TabView to copy
   */
  static TabView create(const Object& iparent, const TabView& icopy);
};
