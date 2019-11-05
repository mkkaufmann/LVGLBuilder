#include "wrapper/object.hpp"

Object::Object() {
  object = lv_obj_create(lv_scr_act(), NULL);
}

Object::Object(Object* parent) {
  object = lv_obj_create(parent->getPointer(), NULL);
}

Object::Object(Object* parent, Object* copy) {
  object = lv_obj_create(parent->getPointer(), copy->getPointer());
}

void Object::remove() {
  lv_obj_del(object);
}

void Object::removeAsync() {
  lv_obj_del_async(object);
}

Object& Object::clean() {
  lv_obj_clean(object);
  return *this;
}

Object& Object::invalidate() {
  lv_obj_invalidate(object);
  return *this;
}

Object& Object::setParent(Object* parent) {
  lv_obj_set_parent(object, parent->getPointer());
  return *this;
}

Object& Object::moveToForeground() {
  lv_obj_move_foreground(object);
  return *this;
}

Object& Object::moveToBackground() {
  lv_obj_move_background(object);
  return *this;
}

Object& Object::setPosition(int x, int y) {
  lv_obj_set_pos(object, x, y);
  return *this;
}

Object& Object::setX(int x) {
  lv_obj_set_x(object, x);
  return *this;
}

Object& Object::setY(int y) {
  lv_obj_set_x(object, y);
  return *this;
}

Object& Object::setSize(int width, int height) {
  lv_obj_set_size(object, width, height);
  return *this;
}

Object& Object::setWidth(int width) {
  lv_obj_set_width(object, width);
  return *this;
}

Object& Object::setHeight(int height) {
  lv_obj_set_height(object, height);
  return *this;
}

Object& Object::align(Object* base, lv_align_t alignment, int xShift, int yShift) {
  lv_obj_align(object, base->getPointer(), alignment, xShift, yShift);
  return *this;
}

Object& Object::alignToParent(lv_align_t alignment, int xShift, int yShift) {
  lv_obj_align(object, lv_obj_get_parent(object), alignment, xShift, yShift);
  return *this;
}

Object& Object::alignOrigo(Object* base, lv_align_t alignment, int xShift, int yShift) {
  lv_obj_align_origo(object, base->getPointer(), alignment, xShift, yShift);
  return *this;
}

Object& Object::realign() {
  lv_obj_realign(object);
  return *this;
}

Object& Object::setAutoRealign(bool enabled) {
  lv_obj_set_auto_realign(object, enabled);
  return *this;
};

Object& Object::setExtendedClickArea(int left, int right, int top, int bottom) {
  lv_obj_set_ext_click_area(object, left, right, top, bottom);
  return *this;
}

lv_obj_t* Object::getPointer() {
  return object;
}
