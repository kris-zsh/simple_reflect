#pragma once

#include <functional>

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
    class RegisterMethod {
    public:
        RegisterMethod(const std::string& name, const std::string& method_name, uintptr_t method);
    };


#define REGISTER_CLASS(object)           \
    Object* register_object_##object() { \
        Object* obj = new object();      \
        obj->set_name(#object);          \
        return obj;                      \
    }                                    \
    RegisterObject REGISTER_CLASS##object(#object, register_object_##object);

#define REGISTER_CLASS_FIELD(class_name, field_name, field_type)                               \
    class_name class_name_##field_name;                                                        \
    RegisterField RegisterField##class_name##field_name(#class_name, #field_name, #field_type, \
                                                        (size_t) &class_name_##field_name.field_name - (size_t) &class_name_##field_name);

#define REGISTER_CLASS_METHOD(class_name, method_name)                                   \
    std::function<void(class_name*)> class_name##method_name = &class_name::method_name; \
    RegisterMethod RegisterMethod##class_name_method_name(#class_name, #method_name, (uintptr_t) &class_name##method_name);

}// namespace reflect