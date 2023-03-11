#include "class_factory.h"
using namespace reflect;
#include <iostream>
#include <cassert>

using namespace std;

void ClassFactory::register_class(std::string name, create_object object){
    cout << "register_class << " << name << endl;
//    class_maps_[name] = object;
    class_maps_.insert({name, object});
}

Object* ClassFactory::create_class(std::string name){
    auto it = class_maps_.find(name);
    if(it == class_maps_.end()) {
        cout << "create_class failed" << endl;
        return nullptr;
    }
    cout << "create_class"<<endl;
    return it->second();
}