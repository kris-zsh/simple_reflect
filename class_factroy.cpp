#include "class_factory.h"
using namespace reflect;
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

void ClassFactory::register_class(const std::string& name,
                                  create_object object) {
    class_maps_[name] = object;
}

Object* ClassFactory::create_class(const std::string& name) {
    auto it = class_maps_.find(name);
    if (it == class_maps_.end()) {
        cout << "create_class failed" << endl;
        return nullptr;
    }
    return it->second();
}

void ClassFactory::register_field(const std::string& name, ClassField* field) {
    class_fields_[name].push_back(field);
}

size_t ClassFactory::get_class_field_size(const std::string& name) {
    return class_fields_[name].size();
}

ClassField* ClassFactory::get_class_field(const std::string& name, int pos) {
    size_t size = class_fields_[name].size();
    if (pos >= size || pos < 0) {
        return nullptr;
    }
    return class_fields_[name][pos];
}

ClassField* ClassFactory::get_class_field(const std::string& name, const std::string& field_name) {
    auto it = class_fields_.find(name);

    if (it != class_fields_.end()) {
        for (auto field: it->second) {
            if (field->name() == field_name) return field;
        }
    }
    return nullptr;
}