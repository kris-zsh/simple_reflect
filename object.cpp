#include "object.h"
#include "register_object.h"
#include <iostream>
using namespace reflect;

using namespace std;

REGISTER_CLASS(A)
 REGISTER_CLASS(B)

A::A() { cout << " AAAAAA" << endl; }

A::~A() {}

void A::show() { cout << "show A" << endl; }

 B::B(const string &name) :name_(name){}

 void B::show() {
   cout << "B" <<endl;
 }
