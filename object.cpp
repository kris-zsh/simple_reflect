#include "object.h"
#include "register_object.h"
using namespace reflect;
#include <iostream>
using namespace std;

A::A(){
    cout << " AAAAAA" << endl;
}

A::~A(){
}

void A::show(){
    cout << "show A" << endl;
}

#define REGISTER_CLASS(object)                                                  \
      RegisterObject REGISTER_CLASS##object(#object, register_object_##object); \
      Object* register_object_##object(){                                       \
            return new object();                                                \
      }                                                                         \

REGISTER_CLASS(A)