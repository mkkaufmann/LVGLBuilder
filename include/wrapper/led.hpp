#pragma once

#include "wrapper/object.hpp"

/**
 * Creates LED Object
 */
class LED : public Object {
public:
  /**
   * Moving the LED is supported
   */
  LED(LED&& LED) = default;
  LED& operator=(LED&& iled) = default;

  /**
   * Create LED with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static LED create();

  /** 
   * Create LED with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static LED create(const Object& iparent);

  /** 
   * Create LED with both parent and copy parameters
   *
   * @param iparent the parent LED for this LED to be a child of
   * @param icopy   the LED for this LED to copy
   */
  static LED create(const Object& iparent, const LED& icopy);
};
