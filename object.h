#pragma once

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
Object* register_object_A();