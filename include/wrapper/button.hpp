#pragma once
#include "object.hpp"

class Button : public Object {
public:
  /**
   * Wrap an LVGL button pointer
   */
  using Object::Object;

  /**
   * Create a button. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Button create();

  /**
   * Create a button with the parent parameter. Defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Button create(const Object& iparent);

  /** 
   * Create a button with both the parent and copy parameters
   *
   * @param iparent the parent object for this object to be a child of
   * @param icopy   the object for this object to be a copy of
   */
  static Button create(const Object& iparent, const Button& icopy);

  /**
   * Set the label of the button
   *
   * @param char new text of the button
   */
  void setText(const char* txt, const lv_obj_t* copy = NULL);

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
   * Set a function to call when a button event happens
   *
   * @param type   the type of event
   * @param action the action to perform
   */
  Button& setAction(lv_btn_action_t type, lv_action_t action);

  /** 
   * Set the layout of a button
   *
   * @param layout the new layout of the button
   */
  Button& setLayout(lv_layout_t layout);

  /**
   * Enable the horizontal or vertical fit of a button
   *
   * @param horizontal_enable enable horizontal fit if true
   * @param vertical_enable   enable vertical fit if true
   */
  Button& setFit(bool horizontal_enable, bool vertical_enable);

  /**
   * Set the style of a button
   * 
   * @param type which style should be set
   * @param style style to be set
   */
  Button& setStyle(lv_btn_style_t type, lv_style_t* style);

  /**
   * Get the current state of the button
   *
   * @return the state of the button (from lv_btn_state_t enum)
   */
  lv_btn_state_t getState();

  /**
   * Get the toggle enable attribute of the button
   *
   * @return ture: toggle enabled, false: disabled
   */
  bool getToggle();

  /**
   * Get the release action of a button
   *
   * @param  type the action type
   * @return pointer to the release action function
   */
  lv_action_t getAction(lv_btn_action_t type);

  /**
   * Get the layout of a button
   *
   * @return the layout from 'lv_cont_layout_t'
   */
  lv_layout_t getLayout();

  /**
   * Get horizontal fit enable attribute of a button
   *
   * @return true: horizontal fit is enabled; false: disabled
   */
  bool getHorFit();

  /**
   * Get vertical fit enable attribute of a container
   *
   * @return true: vertical fit is enabled; false: disabled
   */
  bool getVerFit();

  /**
   * Get style of a button.
   *
   * @param  type which style should be get
   * @return style pointer to the style
   */
  lv_style_t* getStyle(lv_btn_style_t type);

  /**
   * Return the name of the object, used for logging
   */
  static constexpr const char* getName() {
    return "Button";
  }

protected:
  lv_obj_t* label = NULL;
};
