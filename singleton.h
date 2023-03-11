#pragma once

template <typename T> class Singleton {
public:
  static T &get_instance() {
    static T instance_;
    return instance_;
  }
  Singleton(const Singleton &other) = delete;
  Singleton &operator=(const Singleton &other) = delete;

private:
  Singleton() = default;
  ~Singleton() = default;
};