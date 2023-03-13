
#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "class_field.h"
#include "object.h"
#include "singleton.h"

namespace reflect {

    using create_object = Object* (*) ();

    class ClassFactory {
    public:
        void register_class(const std::string& name, create_object object);
        Object* create_class(const std::string& name);

        void register_field(const std::string& name, ClassField* field);
        size_t get_class_field_size(const std::string& name);
        size_t get_field_size();
        ClassField* get_class_field(const std::string& name, int pos);
        ClassField* get_class_field(const std::string& name, const std::string& field_name);

    private:
        ClassFactory() = default;
        ~ClassFactory() = default;
        std::unordered_map<std::string, create_object> class_maps_;
        std::unordered_map<std::string, std::vector<ClassField*>> class_fields_;
        friend class Singleton<ClassFactory>;
    };
}// namespace reflect