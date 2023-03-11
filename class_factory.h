
#pragma once

#include <unordered_map>
#include <string>
#include "singleton.h"

class Object;

namespace reflect{

    using create_object = Object* (*)();

    class ClassFactory{
        public:
            void register_class(const std::string& name, create_object object);
            Object* create_class(const std::string& name);

          private:
            ClassFactory() = default;
            ~ClassFactory() = default;
            std::unordered_map<const std::string&, create_object> class_maps_;
            friend class Singleton<ClassFactory>;
    };
}