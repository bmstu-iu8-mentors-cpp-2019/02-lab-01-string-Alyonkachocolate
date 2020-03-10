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
  while (data[length - 1] == symbol) crop(true);
}

void String::LTrim(char symbol) {
  while (data[0] == symbol) crop(false);
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

/// Функция удаления последнего/первого символа
void String::crop(bool t) {
  char *data1 = new char[length - 1];
  if (t) {
    for (size_t i = 0; i < length - 1; i++) data1[i] = data[i];

  } else {
    for (size_t i = 1; i < length; i++) data1[i - 1] = data[i];
  }
  delete[] data;
  data = data1;
  length = length - 1;
}

/// Функция изменения размера
void String::resize(size_t n) {
  if (length != n) {
    char *data1 = new char[n];
    std::copy(data, data+std::min(length, n), data1);
    delete[] data;
    data = data1;
    length = n;
  }
}
