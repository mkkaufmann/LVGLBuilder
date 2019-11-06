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
   * Copying the wrapper makes no sense, to copy the object use copy()
   */
  Object(const Object& iobject) = delete;
  Object& operator=(const Object& iobject) = delete;

  /**
   * Moving the wrapper is supported
   */
  Object(Object&& iobject) = default;
  Object& operator=(Object&& iobject) = default;

  virtual ~Object() = default;

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

  /** 
   * Set the parent of this Object
   *
   * @param iparent the parent for this object to become a child of
   */
  Object& setParent(const Object& iparent) &;
  Object&& setParent(const Object& iparent) &&;

  /** 
   * Set the position of the object
   *
   * @param x the new x position of the object
   * @param y the new y position of the object
   */
  Object& setPosition(int x, int y) &;
  Object&& setPosition(int x, int y) &&;

  /** 
   * Set the x position of the object
   *
   * @param x the new x coordinate (measured from left side of the parent)
   */
  Object& setX(int x) &;
  Object&& setX(int x) &&;

  /** 
   * Set the y position of the object
   *
   * @param y the new y coordinate (measured from top of the parent)
   */
  Object& setY(int y) &;
  Object&& setY(int y) &&;

  /** 
   * Set the size of the object
   *
   * @param width  the new width of the object
   * @param height the new height of the object
   */
  Object& setSize(int width, int height) &;
  Object&& setSize(int width, int height) &&;

  /** 
   * Set the width of the object
   *
   * @param width the new width of the object
   */
  Object& setWidth(int width) &;
  Object&& setWidth(int width) &&;

  /** 
   * Set the height of the object
   *
   * @param height the new height of the object
   */
  Object& setHeight(int height) &;
  Object&& setHeight(int height) &&;

  /**
   * Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& align(const Object& base, lv_align_t alignment, int xShift, int yShift) &;
  Object&& align(const Object& base, lv_align_t alignment, int xShift, int yShift) &&;

  /** 
   * Align the object to its parent
   *
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignToParent(lv_align_t alignment, int xShift, int yShift) &;
  Object&& alignToParent(lv_align_t alignment, int xShift, int yShift) &&;

  /** 
   * Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignOrigo(const Object& base, lv_align_t alignment, int xShift, int yShift) &;
  Object&& alignOrigo(const Object& base, lv_align_t alignment, int xShift, int yShift) &&;

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
