// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include <cstring>
#include "string.hpp"
/// Деструктор
String::~String() { delete[] data; }

/// Конструктор по умолчанию
String::String() : length(0), data(new char[0]) {}

/// Конструктор копирования
String::String(const String &rhs) : length(rhs.length), data(new char[length]) {
  std::copy(rhs.data, rhs.data + length, data);
}

/// Пользовательский конструктор
String::String(const char *data1)
    : length(strlen(data1)), data(new char[length]) {
  std::copy(data1, data1 + length, data);
}
