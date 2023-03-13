#include <iostream>

#include "class_field.h"
#include "object.h"
#include "register_object.h"
#include "singleton.h"

using namespace std;
using namespace reflect;

int main() {
    auto &factory = Singleton<ClassFactory>::get_instance();
    Object *obj = factory.create_class("B");
    obj->show();
    cout << obj->get_name() << endl;

    std::string name;
    obj->set("type_", "1111");

    obj->get("type_", name);
    cout << name << endl;

    Object *obj1 = factory.create_class("B");
//    obj1->set("type_", "2222222222");
    obj1->get("type_", name);
    cout << name << endl;

    obj->get("type_", name);
    cout << name << endl;

}