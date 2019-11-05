#pragma once
#include "lvgl/lvgl.h"

/**
 * Wrapper for LVGL Objects
 */
class Object {
public:
  /*
   * Construct object with no parameters. Defaults parent to lv_scr_act() Defaults copy to NULL
   */
  Object();

  /* Construct object with parent parameter Defaults copy to NULL
   *
   * @param parent the parent object for this object to be a child of
   */
  Object(Object* parent);

  /* Construct object with both parent and copy parameters
   *
   * @param parent the parent object for this object to be a child of
   * @param copy   the object for this object to copy
   */
  Object(Object* parent, Object* copy);

  /* Delete this Object and all of its children */
  void remove();

  /* Delete this Object and all of its children */
  void removeAsync();

  /* Delete all of this Object's children */
  Object& clean();

  /* Mark the object as invalid (see LVGL docs) */
  Object& invalidate();

  /* Set the parent of this Object
   *
   * @param parent the parent for this object to become a child of
   */
  Object& setParent(Object* parent);

  /* Move object to the foreground */
  Object& moveToForeground();

  /* Move object to the background */
  Object& moveToBackground();

  /* Set the position of the object
   *
   * @param x the new x position of the object
   * @param y the new y position of the object
   */
  Object& setPosition(int x, int y);

  /* Set the x position of the object
   *
   * @param x the new x coordinate (measured from left side of the parent)
   */
  Object& setX(int x);

  /* Set the y position of the object
   *
   * @param y the new y coordinate (measured from top of the parent)
   */
  Object& setY(int y);

  /* Set the size of the object
   *
   * @param width  the new width of the object
   * @param height the new height of the object
   */
  Object& setSize(int width, int height);

  /* Set the width of the object
   *
   * @param width the new width of the object
   */
  Object& setWidth(int width);

  /* Set the height of the object
   *
   * @param height the new height of the object
   */
  Object& setHeight(int height);

  /* Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& align(Object* base, lv_align_t alignment, int xShift, int yShift);

  /* Align the object to its parent
   *
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignToParent(lv_align_t alignment, int xShift, int yShift);

  /* Align the object to another object
   *
   * @param base      the object to align to
   * @param alignment the type of alignment
   * @param xShift    the x-coordinate shift after alignment
   * @param yShift    the y-coordinate shift after alignment
   */
  Object& alignOrigo(Object* base, lv_align_t alignment, int xShift, int yShift);

  /* Realign the object based on the last alignment */
  Object& realign();

  /* Enable automatic realignment on resize
   *
   * @param enabled whether or not realignment is enabled
   */
  Object& setAutoRealign(bool enabled);

  /* Set the size of an extended clickable area
   *
   * @param left   the size of the extended clickable area on the left
   * @param right  the size of the extended clickable area on the right
   * @param top    the size of the extended clickable area on the top
   * @param bottom the size of the extended clickable area on the bottom
   */
  Object& setExtendedClickArea(int left, int right, int top, int bottom);

protected:
  lv_obj_t* getPointer();

private:
  lv_obj_t* object;
};
