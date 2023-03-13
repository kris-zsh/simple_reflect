#pragma once

#include "class_factory.h"

namespace reflect {
    class RegisterObject {
    public:
        RegisterObject(const std::string& name, create_object object);
    };

    class RegisterField {
    public:
        RegisterField(const std::string& name, const std::string& field_name, const std::string& field_type, size_t offset);
    };


#define REGISTER_CLASS(object)           \
    Object* register_object_##object() { \
        Object* obj = new object();      \
        obj->set_name(#object);          \
        return obj;                      \
    }                                    \
    RegisterObject REGISTER_CLASS##object(#object, register_object_##object);

#define REFISTER_CLASS_FIELD(class_name, field_name, field_type)                               \
    class_name class_name_##field_name;                                                        \
    RegisterField RegisterField##class_name##field_name(#class_name, #field_name, #field_type, \
                                                        (size_t) &class_name_##field_name.field_name - (size_t) &class_name_##field_name);

}// namespace reflect