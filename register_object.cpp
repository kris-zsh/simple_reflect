#include "register_object.h"
#include "class_field.h"

using namespace reflect;

RegisterObject::RegisterObject(const std::string& name, create_object object) {
  Singleton<ClassFactory>::get_instance().register_class(name, object);
}

RegisterField::RegisterField(const std::string& name, const std::string& field_name, const std::string& field_type, size_t offset){
  Singleton<ClassFactory>::get_instance().register_field(name, new ClassField(field_name, field_type, offset));
}
