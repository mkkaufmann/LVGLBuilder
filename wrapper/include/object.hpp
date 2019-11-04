#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "../../lvgl/lvgl.h"
//Wrapper for LVGL Objects
class Object{
public:
		/*
		 * Construct object with no parameters
		 * Defaults parent to lv_scr_act()
		 * Defaults copy to NULL
		*/
		Object();

		/* Construct object with parent parameter
		 * Defaults copy to NULL
		 * @param parent the parent object for this object to be a child of
		*/
		Object(Object *parent);
		
		/* Construct object with both parent and copy parameters
		 * @param parent the parent object for this object to be a child of
		 * @param copy the object for this object to copy
		 */
		Object(Object *parent, Object *copy);
		
		/* Set the parent of this Object
		 * @param parent the parent for this object to become a child of
		 */
		Object& setParent(Object *parent);

		/* Delete this Object and all of its children */ 
		void remove();

		/* Delete all of this Object's children */
		Object& clean();

		/* Set the size of the object
		 * @param width the new width of the object
		 * @param height the new height of the object*/
		Object& setSize(int width, int height);

		/* Set the position of the object
		 * @param x the new x position of the object
		 * @param y the new y position of the object
		 */
		Object& setPosition(int x, int y);
protected:
		lv_obj_t *getPointer();
private:
		lv_obj_t *object;
};
#endif
