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
   std::string name_;
 };

