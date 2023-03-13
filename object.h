#pragma once

#include "class_field.h"

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    virtual void show();

    void set_name(const std::string& class_name);
    std::string get_name() const;

    size_t get_field_size() const;
    ClassField* get_field(const std::string& name) const;

    template<typename T>
    void get(const std::string& field_name, T& value);

    template<typename T>
    void set(const std::string& field_name, const T& value);

    void set(const std::string& field_name, const char* value);

private:
    std::string class_name_;
};

template<typename T>
void Object::get(const std::string& field_name, T& value) {
    ClassField* field = get_field(field_name);
    size_t offset = field->offset();
    value = *(T*) ((size_t) this + offset);
}

template<typename T>
void Object::set(const std::string& field_name, const T& value) {
    ClassField* field = get_field(field_name);
    size_t offset = field->offset();
    *(T*) ((size_t) this + offset) = value;
}

class A : public Object {
public:
    A();
    ~A();
    void show() override;
};

class B : public Object {
public:
    B() = default;
    B(const std::string& name, const std::string& type);
    ~B() override = default;
    void show() override;
    std::string name_;
    std::string type_;
};

//
//template<typename T>
//void Object::get(const std::string& field_name, T& value){
//     ClassField* field = get_field(field_name);
//     size_t offset = field->offset();
//     value = *(T *)((size_t)this + offset);
//}
//
//template<typename T>
//void Object::set(const std::string& field_name, T& value){
//    ClassField* field = get_field(field_name);
//    size_t offset = field->offset();
//    *(T *)((size_t)this + offset) = value;
//}
