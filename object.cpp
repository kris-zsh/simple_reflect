#include "object.h"
#include "register_object.h"
#include <iostream>
using namespace reflect;

using namespace std;

REGISTER_CLASS(A)
REGISTER_CLASS(B)

REFISTER_CLASS_FIELD(B, name_, string)
REFISTER_CLASS_FIELD(B, type_, string)

A::A() {}

A::~A() {}

void A::show() { cout << "show A" << endl; }

 B::B(const string &name, const string& type) :name_(name), type_(type){}

 void B::show() {
   cout << "show B" <<endl;
 }
