#include <iostream>
#include "object.h"
#include "singleton.h"
#include  "register_object.h"

using namespace std;
using namespace reflect;

int main(){
//    RegisterObject object("A", register_object_A);
    auto& factory = Singleton<ClassFactory>::get_instance();

    Object* obj = factory.create_class("A");
    obj->show();
}