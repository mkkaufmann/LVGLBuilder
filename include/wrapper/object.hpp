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

  /*---------------------
   * Appearance set
   *--------------------*/

  /**
   * Set a new style for an object
   *
   * @param style the new style
   */
  void setStyle(lv_style_t* style);

  /**
   * Notify an object about its style is modified
   */
  void refreshStyle();

  /*-----------------
   * Attribute set
   *----------------*/

  /**
   * Hide an object. It won't be visible and clickable.
   *
   * @param enabled true: hide the object
   */
  void setHidden(bool enabled);

  /**
   * Enable or disable the clicking of an object
   *
   * @param enabled true: make the object clickable
   */
  void setClick(bool enabled);

  /**
   * Enable to bring this object to the foreground if it or any of its children is clicked
   *
   * @param enabled true: enable the auto top feature
   */
  void setTop(bool enabled);

  /**
   * Enable the dragging of an object
   *
   * @param enabled true: make the object dragable
   */
  void setDrag(bool enabled);

  /**
   * Enable the throwing of an object after is is dragged
   *
   * @param enabled true: enable the drag throw
   */
  void setDragThrow(bool enabled);

  /**
   * Enable to use parent for drag related operations. If trying to drag the object the parent will be moved instead
   *
   * @param enabled true: enable the 'drag parent' for the object
   */
  void setDragParent(bool enabled);

  /**
   * Set the opa scale enable parameter (required to set opa_scale with `lv_obj_set_opa_scale()`)
   *
   * @param enabled true: opa scaling is enabled for this object and all children; false: no opa scaling
   */
  void setOpacityScaleEnable(bool enabled);

  /**
   * Set the opa scale of an object
   *
   * @param opa_scale a factor to scale down opacity [0..255]
   */
  void setOpacityScale(lv_opa_t opa_scale);

  /**
   * Set a bit or bits in the protect filed
   *
   * @param prot 'OR'-ed values from `lv_protect_t`
   */
  void setProtect(uint8_t prot);

  /**
   * Clear a bit or bits in the protect filed
   *
   * @param prot 'OR'-ed values from `lv_protect_t`
   */
  void clearProtect(uint8_t prot);

  /*----------------
   * Other set
   *--------------*/

#ifdef LV_OBJ_FREE_NUM_TYPE
  /**
   * Set an application specific number for an object. It can help to identify objects in the application.
   *
   * @param free_num the new free number
   */
  void setFreeNum(LV_OBJ_FREE_NUM_TYPE free_num);
#endif

#if LV_OBJ_FREE_PTR != 0
  /**
   * Set an application specific  pointer for an object. It can help to identify objects in the application.
   *
   * @param free_p the new free pinter
   */
  void setFreePtr(void* free_p);
#endif

#if USE_LV_ANIMATION
  /**
   * Animate an object
   *
   * @param type  type of animation from 'lv_anim_builtin_t'. 'OR' it with ANIM_IN or ANIM_OUT
   * @param time  time of animation in milliseconds
   * @param delay delay before the animation in milliseconds
   * @param cb    a function to call when the animation is ready
   */
  void animate(lv_anim_builtin_t type, uint16_t time, uint16_t delay, void (*cb)(lv_obj_t*));
#endif

  /*=======================
   * Getter functions
   *======================*/

  /*------------------
   * Screen get
   *-----------------*/

  /**
   * Return with the active screen
   *
   * @return the active screen object (loaded by 'lv_scr_load()')
   */
  static Object ActiveScreen();

  /**
   * Return with the top layer. (Same on every screen and it is above the normal screen layer)
   *
   * @return the top layer object (transparent screen sized lv_obj)
   */
  static Object TopScreen();

  /**
   * Return with the system layer. (Same on every screen and it is above the all other layers) It is used for example by
   * the cursor
   *
   * @return the system layer object (transparent screen sized lv_obj)
   */
  static Object SystemScreen();

  /**
   * Return with the screen of an object
   *
   * @return the screen
   */
  Object getScreen() const;

  /*---------------------
   * Parent/children get
   *--------------------*/

  /**
   * Returns with the parent of an object
   *
   * @return the parent of 'obj'
   */
  Object getParent() const;

  /**
   * Iterate through the children of an object (start from the "youngest, lastly created")
   *
   * @param child NULL at first call to get the next children and the previous return value later
   *
   * @return the child after 'act_child' or NULL if no more child
   */
  Object getChild(const Object& child) const;

  /**
   * Iterate through the children of an object (start from the "oldest", firstly created)
   * @param obj pointer to an object
   * @param child NULL at first call to get the next children
   *                  and the previous return value later
   * @return the child after 'act_child' or NULL if no more child
   */
  Object getChildBack(const Object& child) const;
protected:
  lv_obj_t* object = NULL;
};
