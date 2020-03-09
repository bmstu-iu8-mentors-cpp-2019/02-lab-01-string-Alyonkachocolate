// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include "string.hpp"

String &String::operator=(const String &rhs) {
  if (&rhs != this) {
    if (length < rhs.length) {
      delete[] data;
      data = new char[rhs.length];
      length = rhs.length;
    }
    length = rhs.length;
    for (size_t i = 0; i < length; i++) {
      data[i] = rhs[i];
    }
  }
  return *this;
}

String &String::operator+=(const String &rhs) {
  resize(length + rhs.length);
  for (size_t i = 0; i < rhs.length; i++) data[length + i] = rhs[i];
  return *this;
}

String &String::operator*=(unsigned int m) {
  resize(length * m);
  char *copy = new char[length];
  copy = data;
  for (unsigned int i = 0; i < m - 1; i++)
    for (size_t j = 0; j < length; j++) data[length * i + j] = copy[j];
  return *this;
}

bool String::operator==(const String &rhs) const {
  if (length != rhs.length) return false;
  for (size_t i = 0; i < length; i++)
    if (data[i] != rhs.data[i]) return false;
  return true;
}

bool String::operator<(const String &rhs) const {
  if (length < rhs.length) return true;
  if (length > rhs.length) return false;
  for (size_t i = 0; i < length; i++) {
    if (data[i] < rhs[i]) return true;
    if (data[i] > rhs[i]) return false;
  }
  return false;
}

char String::operator[](size_t index) const { return data[index]; }

char &String::operator[](size_t index) {
  char &t = data[index];
  return t;
}

String operator+(const String &a, const String &b) {
  String str(a);
  str.resize(a.Size() + b.Size());
  for (size_t i = 0; i < str.Size(); i++) str[a.Size() + i] = b[i];
  return str;
}

String operator*(const String &a, unsigned int b) {
  String str(a);
  str.resize(a.Size() * b);
  for (unsigned int i = 0; i < b - 1; i++)
    for (size_t j = 0; j < a.Size(); j++) str[a.Size() * i + j] = str[j];
  return str;
}

bool operator!=(const String &a, const String &b) {
  if (a.Size() == b.Size()) return false;
  for (size_t i = 0; i < a.Size(); i++)
    if (a[i] == b[i]) return false;
  return true;
}

bool operator>(const String &a, const String &b) {
  if (a.Size() < b.Size()) return true;
  if (a.Size() < b.Size()) return false;
  for (size_t i = 0; i < a.Size(); i++) {
    if (a[i] < b[i]) return true;
    if (a[i] > b[i]) return false;
  }
  return false;
}
