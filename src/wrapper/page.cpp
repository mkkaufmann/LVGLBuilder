#include "wrapper/page.hpp"

Page Page::create() {
  return Page(lv_page_create(lv_scr_act(), NULL));
}

Page Page::create(const Object& iparent) {
  return Page(lv_page_create(iparent.get(), NULL));
}

Page Page::create(const Object& iparent, const Page& icopy) {
  return Page(lv_page_create(iparent.get(), icopy.get()));
}

Page& Page::setRelAction(lv_action_t rel_action) {
  lv_page_set_rel_action(object, rel_action);
  return *this;
}

Page& Page::setPrAction(lv_action_t pr_action) {
  lv_page_set_pr_action(object, pr_action);
  return *this;
}

Page& Page::setSbMode(lv_sb_mode_t sb_mode) {
  lv_page_set_sb_mode(object, sb_mode);
  return *this;
}

Page& Page::setScrollPropagation(bool en) {
  lv_page_set_scroll_propagation(object, en);
  return *this;
}

Page& Page::setEdgeFlash(bool en) {
  lv_page_set_edge_flash(object, en);
  return *this;
}

Page& Page::setScrlWidth(lv_coord_t w) {
  lv_page_set_scrl_width(object, w);
  return *this;
}

Page& Page::setScrlHeight(lv_coord_t h) {
  lv_page_set_scrl_height(object, h);
  return *this;
}

Page& Page::setScrlLayout(lv_layout_t layout) {
  lv_page_set_scrl_layout(object, layout);
  return *this;
}

Page& Page::setStyle(lv_page_style_t type, lv_style_t* style) {
  lv_page_set_style(object, type, style);
  return *this;
}
