#include "register_object.h"

using namespace reflect;

RegisterObject::RegisterObject(std::string name, create_object object){
    Singleton<ClassFactory>::get_instance().register_class(name, object);
}