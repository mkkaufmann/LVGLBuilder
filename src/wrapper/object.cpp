#include "wrapper/object.hpp"

Object::Object(lv_obj_t* iobject) : object(iobject) {}

Object Object::create() {
  return Object(lv_obj_create(lv_scr_act(), NULL));
}

Object Object::create(const Object& iparent) {
  return Object(lv_obj_create(iparent.get(), NULL));
}

Object Object::create(const Object& iparent, const Object& icopy) {
  return Object(lv_obj_create(iparent.get(), icopy.get()));
}

void Object::remove() {
  lv_obj_del(object);
}

Object& Object::clean() & {
  lv_obj_clean(object);
  return *this;
}

Object&& Object::clean() && {
  lv_obj_clean(object);
  return std::move(*this);
}

Object& Object::invalidate() & {
  lv_obj_invalidate(object);
  return *this;
}

Object&& Object::invalidate() && {
  lv_obj_invalidate(object);
  return std::move(*this);
}

Object& Object::setParent(const Object& iparent) & {
  lv_obj_set_parent(object, iparent.get());
  return *this;
}

Object&& Object::setParent(const Object& iparent) && {
  lv_obj_set_parent(object, iparent.get());
  return std::move(*this);
}

Object& Object::setPosition(int x, int y) & {
  lv_obj_set_pos(object, x, y);
  return *this;
}

Object&& Object::setPosition(int x, int y) && {
  lv_obj_set_pos(object, x, y);
  return std::move(*this);
}

Object& Object::setX(int x) & {
  lv_obj_set_x(object, x);
  return *this;
}

Object&& Object::setX(int x) && {
  lv_obj_set_x(object, x);
  return std::move(*this);
}

Object& Object::setY(int y) & {
  lv_obj_set_x(object, y);
  return *this;
}

Object&& Object::setY(int y) && {
  lv_obj_set_x(object, y);
  return std::move(*this);
}

Object& Object::setSize(int width, int height) & {
  lv_obj_set_size(object, width, height);
  return *this;
}

Object&& Object::setSize(int width, int height) && {
  lv_obj_set_size(object, width, height);
  return std::move(*this);
}

Object& Object::setWidth(int width) & {
  lv_obj_set_width(object, width);
  return *this;
}

Object&& Object::setWidth(int width) && {
  lv_obj_set_width(object, width);
  return std::move(*this);
}

Object& Object::setHeight(int height) & {
  lv_obj_set_height(object, height);
  return *this;
}

Object&& Object::setHeight(int height) && {
  lv_obj_set_height(object, height);
  return std::move(*this);
}

Object& Object::align(const Object& base, lv_align_t alignment, int xShift, int yShift) & {
  lv_obj_align(object, base.get(), alignment, xShift, yShift);
  return *this;
}

Object&& Object::align(const Object& base, lv_align_t alignment, int xShift, int yShift) && {
  lv_obj_align(object, base.get(), alignment, xShift, yShift);
  return std::move(*this);
}

Object& Object::alignToParent(lv_align_t alignment, int xShift, int yShift) & {
  lv_obj_align(object, lv_obj_get_parent(object), alignment, xShift, yShift);
  return *this;
}

Object&& Object::alignToParent(lv_align_t alignment, int xShift, int yShift) && {
  lv_obj_align(object, lv_obj_get_parent(object), alignment, xShift, yShift);
  return std::move(*this);
}

Object& Object::alignOrigo(const Object& base, lv_align_t alignment, int xShift, int yShift) & {
  lv_obj_align_origo(object, base.get(), alignment, xShift, yShift);
  return *this;
}

Object&& Object::alignOrigo(const Object& base, lv_align_t alignment, int xShift, int yShift) && {
  lv_obj_align_origo(object, base.get(), alignment, xShift, yShift);
  return std::move(*this);
}

Object& Object::realign() & {
  lv_obj_realign(object);
  return *this;
}

Object&& Object::realign() && {
  lv_obj_realign(object);
  return std::move(*this);
}

Object& Object::setAutoRealign(bool enabled) & {
  lv_obj_set_auto_realign(object, enabled);
  return *this;
};

Object&& Object::setAutoRealign(bool enabled) && {
  lv_obj_set_auto_realign(object, enabled);
  return std::move(*this);
};

lv_obj_t* Object::get() const {
  return object;
}
