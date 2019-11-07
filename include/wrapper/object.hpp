#pragma once
#include "lvgl/lvgl.h"
#include <utility>

/**
 * Wrapper for LVGL Objects
 */
class Object {
public:
  /**
   * Wraps an LVGL object pointer
   *
   * @param iobject The object
   */
  explicit Object(lv_obj_t* iobject);

  /**
   * Destroys the Object wrapper but the lvgl object is left untouched.
   * Use remove() to delete the lvgl object
   */
  virtual ~Object() = default;

  /**
   * Copying the wrapper makes no sense, to copy the object use copy()
   */
  Object(const Object& iobject) = delete;
  Object& operator=(const Object& iobject) = delete;

  /**
   * Moving the wrapper is supported
   */
  Object(Object&& iobject) = default;
  Object& operator=(Object&& iobject) = default;

  /**
   * Gets the internal lvgl object pointer.
   *
   * @return The internal lvgl object pointer.
   */
  lv_obj_t* get() const;

  /*--------------------
   * Create and delete
   *-------------------*/

  /**
   * Create object with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static Object create();

  /** 
   * Create object with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static Object create(const Object& iparent);

  /** 
   * Create object with both parent and copy parameters
   *
   * @param iparent the parent object for this object to be a child of
   * @param icopy   the object for this object to copy
   */
  static Object create(const Object& iparent, const Object& icopy);

  /** 
   * Delete this Object and all of its children
   */
  void remove();

  /** 
   * Delete all of this Object's children
   */
  Object& clean() &;
  Object&& clean() &&;

  /** 
   * Mark the object as invalid (see LVGL docs)
   */
  Object& invalidate() &;
  Object&& invalidate() &&;

  /*=====================
   * Setter functions
   *====================*/

  /*--------------------
   * Parent/children set
   *--------------------*/

  /** 
   * Set the parent of this Object
   *
   * @param iparent the parent for this object to become a child of
   */
  Object& setParent(const Object& iparent) &;
  Object&& setParent(const Object& iparent) &&;

  /*--------------------
   * Coordinate set
   * ------------------*/

  /** 
   * Set the position of the object
   *
   * @param x the new x position of the object
   * @param y the new y position of the object
   */
  Object& setPosition(lv_coord_t x, lv_coord_t y) &;
  Object&& setPosition(lv_coord_t x, lv_coord_t y) &&;

  /** 
   * Set the x position of the object
   *
   * @param x the new x coordinate (measured from left side of the parent)
   */
  Object& setX(lv_coord_t x) &;
  Object&& setX(lv_coord_t x) &&;

  /** 
   * Set the y position of the object
   *
   * @param y the new y coordinate (measured from top of the parent)
   */
  Object& setY(lv_coord_t y) &;
  Object&& setY(lv_coord_t y) &&;

  /** 
   * Set the size of the object
   *
   * @param width  the new width of the object
   * @param height the new height of the object
   */
  Object& setSize(lv_coord_t width, lv_coord_t height) &;
  Object&& setSize(lv_coord_t width, lv_coord_t height) &&;

  /** 
   * Set the width of the object
   *
   * @param width the new width of the object
   */
  Object& setWidth(lv_coord_t width) &;
  Object&& setWidth(lv_coord_t width) &&;

  /** 
   * Set the height of the object
   *
   * @param height the new height of the object
   */
  Object& setHeight(lv_coord_t height) &;
  Object&& setHeight(lv_coord_t height) &&;

  /**
   * Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& align(const Object& base, lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &;
  Object&& align(const Object& base, lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &&;

  /** 
   * Align the object to its parent
   *
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignToParent(lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &;
  Object&& alignToParent(lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &&;

  /** 
   * Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignOrigo(const Object& base, lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &;
  Object&& alignOrigo(const Object& base, lv_align_t alignment, lv_coord_t xShift, lv_coord_t yShift) &&;

  /** 
   * Realign the object based on the last alignment
   */
  Object& realign() &;
  Object&& realign() &&;

  /** 
   * Enable automatic realignment on resize
   *
   * @param enabled whether or not realignment is enabled
   */
  Object& setAutoRealign(bool enabled) &;
  Object&& setAutoRealign(bool enabled) &&;

  /**
   * Gets the internal lvgl object pointer.
   *
   * @return The internal lvgl object pointer.
   */
  lv_obj_t* get() const;

protected:
  lv_obj_t* object = NULL;
};
