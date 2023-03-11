#pragma once

#include "class_factory.h"

namespace reflect {
class RegisterObject {
public:
  RegisterObject(const std::string& name, create_object object);
};
} // namespace reflect