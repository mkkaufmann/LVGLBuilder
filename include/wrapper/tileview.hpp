#pragma once

#include "wrapper/object.hpp"

/**
 * Creates TileView Object
 */
class TileView : public Object {
public:
  /**
   * Moving the TileView is supported
   */
  TileView(TileView&& TileView) = default;
  TileView& operator=(TileView&& itileview) = default;

  /**
   * Create TileView with no parameters. Defaults parent to lv_scr_act() and copy to NULL
   */
  static TileView create();

  /** 
   * Create TileView with parent parameter and defaults copy to NULL
   *
   * @param iparent the parent TileView for this TileView to be a child of
   */
  static TileView create(const Object& iparent);

  /** 
   * Create TileView with both parent and copy parameters
   *
   * @param iparent the parent TileView for this TileView to be a child of
   * @param icopy   the TileView for this TileView to copy
   */
  static TileView create(const Object& iparent, const TileView& icopy);
};
