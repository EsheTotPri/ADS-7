// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <cstddef>

class Train {
 private:
  struct Car {
    bool light;  // состояние лампочки
    Car* next;
    Car* prev;
    explicit Car(bool l) : light(l), next(this), prev(this) {}
  };

  Car* first;           // указатель на точку входа
  std::size_t countOp;  // счётчик переходов из вагона в вагон

 public:
  Train();
  ~Train();

  // добавить вагон с заданным состоянием лампочки
  void addCar(bool light);

  // вычислить длину поезда (наивным линейным обходом)
  std::size_t getLength();

  // вернуть число переходов (из вагона в вагон)
  std::size_t getOpCount() const;
};

#endif  // INCLUDE_TRAIN_H_
