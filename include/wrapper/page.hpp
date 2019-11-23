#pragma once
#include "object.hpp"

class Page : public Object {
public:
  /**
   * Wraps an LVGL page pointer
   */
  using Object::Object;

  /**
   * Returns the name of the object, used for logging
   */
  static constexpr const char* getName() {
    return "Page";
  }

  /**
   * Create Page with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Page create();

  /** 
   * Create Page with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Page create(const Object& iparent);

  /** 
   * Create Page with both parent and copy parameters
   *
   * @param iparent the parent Page for this Page to be a child of
   * @param icopy   the Page for this Page to copy
   */
  static Page create(const Object& iparent, const Page& icopy);

  /* SETTERS */

  /**
   * Set a release action for the page
   * @param rel_action a function to call when the page is released
   */
  Page& setRelAction(lv_action_t rel_action) &;
  Page&& setRelAction(lv_action_t rel_action) &&;

  /**
   * Set a press action for the page
   * @param pr_action a function to call when the page is pressed
   */
  Page& setPrAction(lv_action_t pr_action) &;
  Page&& setPrAction(lv_action_t pr_action) &&;

  /**
   * Set the scroll bar mode on a page
   * @param sb_mode the new mode from 'lv_page_sb.mode_t' enum
   */
  Page& setSbMode(lv_sb_mode_t sb_mode) &;
  Page&& setSbMode(lv_sb_mode_t sb_mode) &&;

  /**
   * Enable the scroll propagation feature. If enabled then the page will move its parent if there is no more space to scroll.
   * @param en true or false to enable/disable scroll propagation
   */
  Page& setScrollPropagation(bool en) &;
  Page&& setScrollPropagation(bool en) &&;

  /**
   * Enable the edge flash effect. (Show an arc when the an edge is reached)
   * @param en true or false to enable/disable end flash
   */
  Page& setEdgeFlash(bool en) &;
  Page&& setEdgeFlash(bool en) &&;

  /**
   * Set width of the scrollable part of a page
   * @param w the new width of the scrollable (it ha no effect is horizontal fit is enabled)
   */
  Page& setScrlWidth(lv_coord_t w) &;
  Page&& setScrlWidth(lv_coord_t w) &&;

  /**
   * Set height of the scrollable part of a page
   * @param h the new height of the scrollable (it ha no effect is vertical fit is enabled)
   */
  Page& setScrlHeight(lv_coord_t h) &;
  Page&& setScrlHeight(lv_coord_t h) &&;

  /**
  * Set the layout of the scrollable part of the page
  * @param layout a layout from 'lv_cont_layout_t'
  */
  Page& setScrlLayout(lv_layout_t layout) &;
  Page&& setScrlLayout(lv_layout_t layout) &&;

  /**
   * Set a style of a page
   * @param style pointer to a style
   */
  Page& setStyle(lv_page_style_t type, lv_style_t* style) &;
  Page&& setStyle(lv_page_style_t type, lv_style_t* style) &&;
};
