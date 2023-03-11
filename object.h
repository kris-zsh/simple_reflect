#pragma once

#include <string>

class Object{
public:
    Object() = default;
    virtual ~Object() = default;
    virtual void show() = 0;
};

class A: public Object{
public:
    A();
    ~A();
    void show() override;
};

#define REGISTER_CLASS(object)     \
      Object* register_object_##object(){                                       \
        return new object();                                                    \
      }                                                                         \
      RegisterObject REGISTER_CLASS##object(#object, register_object_##object); \
