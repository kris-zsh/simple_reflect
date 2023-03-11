#include "object.h"
#include "register_object.h"
#include "singleton.h"
#include <iostream>

using namespace std;
using namespace reflect;

int main() {
  auto &factory = Singleton<ClassFactory>::get_instance();
  Object *obj = factory.create_class("A");
  obj->show();
  Object *obj1 = factory.create_class("B");
  obj1->show();

}