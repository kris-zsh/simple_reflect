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

    std::string name;
    obj->set("type_", string("1111"));

    obj->get("type_", name);
    cout << name << endl;
}