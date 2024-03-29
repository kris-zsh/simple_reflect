#include "object.h"

#include <iostream>

#include "class_factory.h"
#include "register_object.h"

using namespace reflect;

using namespace std;

REGISTER_CLASS(A)

REGISTER_CLASS(B)

REGISTER_CLASS_FIELD(B, name_, string)
REGISTER_CLASS_FIELD(B, type_, string)
REGISTER_CLASS_FIELD(B, size, size_t)
REGISTER_CLASS_METHOD(B, show)

A::A() {}

A::~A() {}

void A::show() { cout << "show A" << endl; }

B::B(const string &name, const string &type) : name_(name),
                                               type_(type) {}

void B::show() {
    cout << "show B" << endl;
}

void Object::show() {
}

void Object::set_name(const std::string &class_name) {
    class_name_ = class_name;
}

std::string Object::get_name() const {
    return class_name_;
}
ClassField *Object::get_field(const string &name) const {
    return Singleton<ClassFactory>::get_instance().get_class_field(class_name_, name);
}

size_t Object::get_field_size() const {
    return Singleton<ClassFactory>::get_instance().get_class_field_size(class_name_);
}

void Object::set(const std::string &field_name, const char *value) {
    ClassField *field = get_field(field_name);
    size_t offset = field->offset();
    *(string *) ((size_t) this + offset) = value;
}

void Object::call(const string &method_name) {
    ClassMethod *method = Singleton<ClassFactory>::get_instance().get_class_method(class_name_, method_name);
    uintptr_t add = method->method();
    using function = std::function<void(decltype(this))>;
    (*(function *) add)(this);
}
