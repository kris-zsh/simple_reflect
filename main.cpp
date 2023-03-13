#include <functional>
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
    obj->call("show");

    std::string name;
    size_t size;
    obj->set("type_", "1111");
    obj->set("size", 100);

    obj->get("size", size);
    obj->get("type_", name);
    cout << name << endl;
    cout << size << endl;
}