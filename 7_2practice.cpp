#include <iostream>
using namespace std;
class Figure {
  public:
    virtual void TypeFigure() = 0;
    virtual void FindArea() = 0;
};

class Rectangle : public Figure {
  public:
    virtual void FindPerimeter() = 0;
};

class Rhombus : public Rectangle {
  public:
    void FindPerimeter() {
      cout << "Периметр P=" << "4*a" << endl;
    }
    void FindArea() {
      cout << "Площадь S=" << "a*h" << endl;
    }
    void TypeFigure() {
      cout << "Ромб" << endl;
    }
};

int main() {
  Rhombus r;
  r.FindArea();
  r.FindPerimeter();
  r.TypeFigure();
  return 0;
}
