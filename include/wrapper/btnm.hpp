#pragma once

#include "wrapper/object.hpp"

/**
 * Creates ButtonMatrix Object
 */
class ButtonMatrix : public Object {
public:
  /**
   * Moving the ButtonMatrix is supported
   */
  ButtonMatrix(ButtonMatrix&& ButtonMatrix) = default;
  ButtonMatrix& operator=(ButtonMatrix&& ibuttonmatrix) = default;

  /**
   * Create ButtonMatrix with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static ButtonMatrix create();

  /** 
   * Create ButtonMatrix with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent object for this object to be a child of
   */
  static ButtonMatrix create(const Object& iparent);

  /** 
   * Create ButtonMatrix with both parent and copy parameters
   *
   * @param iparent the parent ButtonMatrix for this ButtonMatrix to be a child of
   * @param icopy   the ButtonMatrix for this ButtonMatrix to copy
   */
  static ButtonMatrix create(const Object& iparent, const ButtonMatrix& icopy);
};
