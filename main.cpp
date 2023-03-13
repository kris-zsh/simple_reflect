#include "object.h"
#include "register_object.h"
#include "singleton.h"
#include <iostream>
#include "class_field.h"

using namespace std;
using namespace reflect;



int main() {
  auto &factory = Singleton<ClassFactory>::get_instance();
  Object *obj = factory.create_class("A");
  obj->show();
  Object *obj1 = factory.create_class("B");
  obj1->show();

  cout << factory.get_class_field_size("B") << endl;
  ClassField* classField = factory.get_class_field("B", "name_");
  cout << classField->name() << endl;
  cout << classField->type() << endl;
  cout << classField->offset() << endl;
  ClassField* classField1 = factory.get_class_field("B", "type_");
  cout << classField1->name() << endl;
  cout << classField1->type() << endl;
  cout << classField1->offset() << endl;

  // cout << name1 << endl;
}