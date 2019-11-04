#include "../include/object.hpp"

Object::Object(){
		object = lv_obj_create(lv_scr_act(), NULL);
}

Object::Object(Object *parent){
		object = lv_obj_create(parent->getPointer(), NULL);
}

Object::Object(Object *parent, Object *copy){
		object = lv_obj_create(parent->getPointer(), copy->getPointer());
}

Object& Object::setParent(Object *parent){
		lv_obj_set_parent(object, parent->getPointer());
		return *this;
}

void Object::remove(){
		lv_obj_del(object);
}

Object& Object::clean(){
		lv_obj_clean(object);
		return *this;
}

Object& Object::setSize(int width, int height){
		lv_obj_set_size(object, width, height);
		return *this;
}

Object& Object::setPosition(int x, int y){
		lv_obj_set_pos(object, x, y);
		return *this;
}

lv_obj_t *Object::getPointer(){
		return object;
}
