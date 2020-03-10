// Copyright 2019 Alyonkachocolate <Nyanyoka@yandex.ru>

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <iostream>
#include <utility>

class String {
 public:
  /// Деструктор
  ~String();

  /// Конструктор по умолчанию
  String();

  /// Конструктор копирования
  String(const String &rhs);

  /// Пользовательский конструктор
  explicit String(const char *data1);

  /// Оператор присваивания
  String &operator=(const String &rhs);

  /// Оператор +=
  String &operator+=(const String &rhs);

  /// Оператор *=
  String &operator*=(unsigned int m);

  /// Оператор ==
  bool operator==(const String &rhs) const;

  /// Оператор &lt;
  bool operator<(const String &rhs) const;

  /// Функция поиска подстроки
  size_t Find(const String &substr) const;

  /// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
  void Replace(char oldSymbol, char newSymbol);

  /// Функция возвращает длину строки
  size_t Size() const;

  /// Функция для определения пуста ли строка
  bool Empty() const;

  /// Оператор []
  char operator[](size_t index) const;

  /// Оператор []
  char &operator[](size_t index);

  void RTrim(char symbol);

  void LTrim(char symbol);

  void swap(String &oth);

  friend std::ostream &operator<<(std::ostream &, const String &);

  void resize(size_t n);

 private:
  size_t length = 0;
  char *data;

  explicit String (size_t n);

  void crop(bool t);  //удаляет символ 1 - справа, 0 - слева

  /// Оператор +
  friend String operator+(const String &a, const String &b);

  /// Оператор *
  friend String operator*(const String &a, unsigned int b);

  /// Оператор !=
  friend bool operator!=(const String &a, const String &b);

  /// Оператор &gt;
  friend bool operator>(const String &a, const String &b);
};

/// Оператор +
String operator+(const String &a, const String &b);

/// Оператор *
String operator*(const String &a, unsigned int b);

/// Оператор !=
bool operator!=(const String &a, const String &b);

/// Оператор &gt;
bool operator>(const String &a, const String &b);

/// Оператор вывода
std::ostream &operator<<(std::ostream &out, const String &str);

#endif  // INCLUDE_STRING_HPP_
