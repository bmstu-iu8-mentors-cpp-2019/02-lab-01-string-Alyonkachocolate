// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include "string.hpp"

String &String::operator=(const String &rhs) {
  if (&rhs != this) {
    if (length != rhs.length) {
      delete[] data;
      data = new char[rhs.length];
    }
    length = rhs.length;
    std::copy(rhs.data, rhs.data + rhs.length, data);
  }
  return *this;
}

String &String::operator+=(const String &rhs) {
  size_t len = length;
  resize(len + rhs.length);
  std::copy(rhs.data, rhs.data + rhs.length, data + len);
  return *this;
}

String &String::operator*=(unsigned int m) {
  size_t len = length;
  resize(len * m);
  for (size_t i = 1; i < m; i++) std::copy(data, data + len, data + len * i);
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
    if (data[i] < rhs.data[i]) return true;
    if (data[i] > rhs.data[i]) return false;
  }
  return false;
}

char String::operator[](size_t index) const { return data[index]; }

char &String::operator[](size_t index) { return data[index]; }

String operator+(const String &a, const String &b) {
  String str(a.length + b.length);
  std::copy(a.data, a.data + a.length, str.data);
  std::copy(b.data, b.data + b.length, str.data + a.length);
  return str;
}

String operator*(const String &a, unsigned int b) {
  String str(a.length * b);
  for (size_t i = 0; i < b; i++)
    std::copy(a.data, a.data + a.length, str.data + i * a.length);
  return str;
}

bool operator!=(const String &a, const String &b) { return !(a == b); }

bool operator>(const String &a, const String &b) { return b < a; }
