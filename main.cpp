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

  B b("aaa");
  size_t offset = (size_t)&((B*)0)->name_;
  cout << offset << endl;
  string name = *(string*)((size_t)&b + offset);

  size_t offset1 = (size_t)&b.name_ - (size_t)&b;
  string name1 = *(string*)((size_t)&b + offset1);
  cout << name << endl;
  cout << name1 << endl;
}