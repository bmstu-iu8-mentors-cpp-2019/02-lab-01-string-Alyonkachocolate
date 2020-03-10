// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include "string.hpp"

/// Функция поиска подстроки
size_t String::Find(const String &substr) const {
  if (substr.Empty()) return 0;
  if (substr.length > length) return -1;
  for (size_t i = 0; i < length - substr.length + 1; i++) {
    bool ok = true;
    for (size_t j = 0; j < substr.length; j++) {
      if (data[i + j] != substr.data[j]) {
        ok = false;
        break;
      }
    }
    if (ok) return i;
  }
  return -1;
}

/// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < length; i++)
    if (data[i] == oldSymbol) data[i] = newSymbol;
}

/// Функция возвращает длину строки
size_t String::Size() const { return length; }

/// Функция для определения пуста ли строка
bool String::Empty() const { return (length == 0); }

void String::RTrim(char symbol) {
  for (size_t i = length - 1; ; i--) {
    if (data[i] != symbol) {
      resize(i + 1);
      return;
    }
    if (i == 0) break;
  }
  resize(0);
}

void String::LTrim(char symbol) {
  for (size_t i = 0; i < length; i++) {
    if (data[i] != symbol) {
      char *data1 = new char[length - i];
      std::copy(data + i, data + length, data1);
      delete[] data;
      data = data1;
      length -= i;
      return;
    }
  }
  resize(0);
}

/// Функция для "обмена" строк
void String::swap(String &oth) {
  std::swap(data, oth.data);
  std::swap(length, oth.length);
}

/// Функция вывода
std::ostream &operator<<(std::ostream &out, const String &str) {
  for (size_t i = 0; i < str.Size(); i++) out << str.data[i];
  return out;
}

/// Функция изменения размера
void String::resize(size_t n) {
  if (length != n) {
    char *data1 = new char[n];
    std::copy(data, data + std::min(length, n), data1);
    delete[] data;
    data = data1;
    length = n;
  }
}
