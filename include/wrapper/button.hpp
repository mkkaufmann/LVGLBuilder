#pragma once
#include "object.hpp"
class Button : public Object {
public:
  /**
   * Wraps an LVGL button pointer
   */
  using Object::Object;

  /**
   * Moving the wrapper is supported
   */
  Button(Button&& ibutton) = default;
  Button& operator=(Button&& ibutton) = default;

  /**
   * Create object with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Button create();

  /** 
   * Create object with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Button create(const Object& iparent);

  /** 
   * Create object with both parent and copy parameters
   *
   * @param iparent the parent object for this object to be a child of
   * @param icopy   the object for this object to copy
   */
  static Button create(const Object& iparent, const Button& icopy);

  /**
   * Enable the toggled states
   *
   * @param enabled if true, enable toggled states. If false, disable
   */
  Button& setToggle(bool enabled);

  /**
   * Set the state of the button
   *
   * @param state new state of the button
   */
  Button& setState(lv_btn_state_t state);

  /** 
   * Toggle the state of the button
   */
  Button& toggle();

  /** 
   * Set the layout of a button
   *
   * @param layout the new layout of the button
   */
  Button& setLayout(lv_layout_t layout);

  /**
   * Set the style of a button
   * 
	 * @param type which style should be set
	 * @param style style to be set
	 */
  //Button& setStyle(lv_btn_style_t type, lv_style_t style);
};
