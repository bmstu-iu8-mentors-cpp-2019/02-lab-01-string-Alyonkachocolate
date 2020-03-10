// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include <cstring>
#include "string.hpp"
/// Деструктор
String::~String() { delete[] data; }

/// Конструктор по умолчанию
String::String() : String(static_cast<size_t>(0)) {}

/// Конструктор копирования
String::String(const String &rhs) : String(rhs.length) {
  std::copy(rhs.data, rhs.data + length, data);
}

/// Пользовательский конструктор
String::String(const char *data1) : String(strlen(data1)) {
  std::copy(data1, data1 + length, data);
}

String::String(size_t n) : length(n), data(new char[n]){}