#include <iostream>
using namespace std;
class Animals { // создание абстрактного класса Животные
  public:
    virtual void Pronounce()=0; // виртуальная функция
};

class Cat : public Animals{
  public:
    void Pronounce() {
          cout << "Я кот, меня зовут Томас" << endl;
    }
};

class Dog : public Animals{
  public:
    void Pronounce() {
        cout << "Я собака , меня зовут Фаня" << endl;
    }
};

class Parrot : public Animals{
  public:
    void Pronounce() {
          cout << "Я попугай, меня зовут Говорун :)" << endl;
    }
};

int main() {
  Cat cat;
  cat.Pronounce();
    Dog dog;
    dog.Pronounce();
      Parrot parrot;
      parrot.Pronounce();
  return 0;
}
