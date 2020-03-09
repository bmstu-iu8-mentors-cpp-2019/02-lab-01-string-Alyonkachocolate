// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include "string.hpp"

/// Деструктор
String::~String() { delete[] data; }

/// Конструктор по умолчанию
String::String() { data = new char[0]; }

/// Конструктор копирования
String::String(const String &rhs) : length(rhs.length) {
  data = new char[length];
  for (size_t i = 0; i < length; i++) data[i] = rhs.data[i];
}

/// Пользовательский конструктор
String::String(const char *data) {
  while (data[length] != 0) {
    length++;
  }
  this->data = new char[length];
  for (size_t i = 0; i < length; i++) this->data[i] = data[i];
}
