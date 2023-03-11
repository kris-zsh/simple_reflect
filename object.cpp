#include "object.h"
#include <iostream>
#include "register_object.h"
using namespace reflect;

using namespace std;

A::A(){
    cout << " AAAAAA" << endl;
}

A::~A(){
}

void A::show(){
    cout << "show A" << endl;
}


REGISTER_CLASS(A)