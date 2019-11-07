#pragma once

#include "wrapper/object.hpp"

/**
 * Creates Line Object
 */
class Line : public Object {
public:
  /**
   * Wraps an LVGL button pointer
   */
  using Object::Object;

  /**
   * Moving the Line is supported
   */
  Line(Line&& Line) = default;
  Line& operator=(Line&& iline) = default;

  /**
   * Create Line with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Line create();

  /** 
   * Create Line with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Line create(const Object& iparent);

  /** 
   * Create Line with both parent and copy parameters
   *
   * @param iparent the parent Line for this Line to be a child of
   * @param icopy   the Line for this Line to copy
   */
  static Line create(const Object& iparent, const Line& icopy);
};
