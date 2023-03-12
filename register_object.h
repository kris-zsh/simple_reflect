#pragma once

#include "class_factory.h"

namespace reflect {
class RegisterObject {
public:
  RegisterObject(const std::string& name, create_object object);
};


#define REGISTER_CLASS(object)                                                 \
  Object *register_object_##object() { return new object(); }                  \
  RegisterObject REGISTER_CLASS##object(#object, register_object_##object);\

} // namespace reflect