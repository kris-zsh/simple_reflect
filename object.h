#pragma once

#include <string>

class Object {
public:
  Object() = default;
  virtual ~Object() = default;
  virtual void show() = 0;
};

class A : public Object {
public:
  A();
  ~A();
  void show() override;
};

 class B: public Object{
 public:
   B() = default;
   B(const std::string& name);
   ~B() override = default;
   void show() override;
 private:
   std::string name_;
 };

#define REGISTER_CLASS(object)                                                 \
  Object *register_object_##object() { return new object(); }                  \
  RegisterObject REGISTER_CLASS##object(#object, register_object_##object);\
