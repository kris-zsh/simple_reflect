//
// Created by zhaoshuhao on 2023/3/13.
//

#ifndef SIMPLE_REFLECT_CLASS_METHOD_H
#define SIMPLE_REFLECT_CLASS_METHOD_H
#include <string>

class ClassMethod {
public:
    ClassMethod(const std::string& name, uintptr_t method) : name_(name),
                                                             method_(method) {}
    std::string name() const { return name_; }
    uintptr_t method() const { return method_; }

private:
    std::string name_;
    uintptr_t method_;
};
#endif//SIMPLE_REFLECT_CLASS_METHOD_H
