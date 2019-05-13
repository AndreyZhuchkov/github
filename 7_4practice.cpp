#include <iostream>
using namespace std;
class Screen {
public:
  virtual void ScreenSize() = 0;
};

class Keyboard {
public:
  virtual void KeyboardLayout() = 0;
};

class Laptop : public Screen, Keyboard {
public:
    void KeyboardLayout() {
      cout <<"Информация про ноутбук: \n"<<"Клавиатура: "<< "Английская раскладка" << endl;
    }

    void ScreenSize() {
      cout << "Экран: 15 дюймов" << endl;
    }
};

class Phone: public Screen, Keyboard {
public:
  void KeyboardLayout() {
    cout <<"Информация про телефон: \n"<<"Клавиатура: "<<"Русская раскладка" << endl;
  }

  void ScreenSize() {
    cout << "Экран: 5 дюймов" << endl;
  }
};

class Desktop: public Screen, Keyboard {
public:
  void KeyboardLayout() {
    cout <<"Информация про компьютер: \n"<<"Клавиатура: "<<"Французская раскладка" << endl;
  }

  void ScreenSize() {
    cout << "Экран: 17 дюймов" << endl;
  }
};


int main(int argc, char const *argv[]) {
  Laptop laptop;
  laptop.KeyboardLayout();
  laptop.ScreenSize();

  Desktop desktop;
  desktop.KeyboardLayout();
  desktop.ScreenSize();

  Phone phone;
  phone.KeyboardLayout();
  phone.ScreenSize();
  return 0;
}
