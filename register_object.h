#pragma once

#include "class_factory.h"

namespace reflect{
    class RegisterObject{
    public:
        RegisterObject(std::string name, create_object object);
    };
}