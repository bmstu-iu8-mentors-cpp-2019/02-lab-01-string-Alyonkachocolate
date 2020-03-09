// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>
#include "string.hpp"

/// Функция поиска подстроки
size_t String::Find(const String &substr) const {
  size_t i = 0, j = 0;
  for (i = 0; i < length; i++) {
    if (substr.length == 1) {
      if (data[i] == substr[0]) return i;
    } else {
      if (j == substr.length - 1) {
        return i - substr.length + 1;
      }
      if (data[i] == substr[j])
        j++;
      else
        j = 0;
    }
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
  size_t i = length - 1;
  while (data[i] == symbol) {
    crop(true);
    i--;
  }
}

void String::LTrim(char symbol) {
  size_t i = 0;
  while (data[i] == symbol) {
    crop(false);
    i++;
  }
}

/// Функция для "обмена" строк
void String::swap(String &oth) {
  char *data1 = new char[oth.length];
  for (size_t i = 0; i < length; i++) data1[i] = oth[i];
  delete[] data;
  data = data1;
  length = oth.length;
  char *oth1 = new char[length];
  for (size_t i = 0; i < length; i++) oth1[i] = data[i];
  delete[] oth.data;
  oth = oth1;
  oth.length = length;
}

/// Функция вывода
std::ostream &operator<<(std::ostream &out, const String &str) {
  for (size_t i = 0; i < str.Size(); i++) out << str[i];
  out << '\n';
  return out;
}

/// Функция удаления последнего/первого символа
void String::crop(bool t) {
  if (t) {
    char *data1 = new char[length - 1];
    for (size_t i = 0; i < length - 1; i++) data1[i] = data[i];
    delete[] data;
    data = data1;
    length = length - 1;
  } else {
    char *data1 = new char[length - 1];
    for (size_t i = length - 1; i < 1; i--) data1[i] = data[i];
    delete[] data;
    data = data1;
    length = length - 1;
  }
}

/// Функция увеличения размера
void String::resize(size_t n) {
  char *data1 = new char[n];
  if (n > 0)
    for (size_t i = 0; i < length; i++) data1[i] = data[i];
  delete[] data;
  data = data1;
  length = n;
}
