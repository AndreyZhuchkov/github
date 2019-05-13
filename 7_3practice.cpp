#include <iostream>
using namespace std;
class Venicle { // создание абстрактного класса Животные
  public:
    virtual void Mark()=0; // виртуальная функция
};

class Bus : public Venicle{
  public:
    void Mark() {
          cout << "Лиаз" << endl;
    }
};

class Bicycle : public Venicle {
  public:
    void Mark() {
        cout << "Cube" << endl;
    }
};

class Car : public Venicle{
  public:
    void Mark() {
          cout << "Nissan" << endl;
    }
};

int main() {
  Bus bus;
  bus.Mark();
    Bicycle bicycle;
    bicycle.Mark();
      Car car;
      car.Mark();
  return 0;
}
