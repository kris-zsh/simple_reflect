#include <iostream>
#include "object.h"
#include "singleton.h"
#include  "register_object.h"

using namespace std;
using namespace reflect;

int main(){
    auto& factory = Singleton<ClassFactory>::get_instance();
    Object* obj = factory.create_class("A");
    obj->show();

}