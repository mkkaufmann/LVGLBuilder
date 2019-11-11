#include "wrapper/tabview.hpp"

TabView TabView::create(){
		return TabView(lv_tabview_create(lv_scr_act(), NULL));
}

TabView TabView::create(const Object& iparent){
		return TabView(lv_tabview_create(iparent.get(), NULL));
}

TabView TabView::create(const Object& iparent, const TabView& icopy){
		return TabView(lv_tabview_create(iparent.get(), icopy.get()));
}
