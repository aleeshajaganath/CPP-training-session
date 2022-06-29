#include <iostream>
using namespace std;

class Shape {
 public:
  virtual void WhatAmI();
};

void Shape::WhatAmI() { cout << "Am shape " << endl; }

class Rectangle : public Shape {
 public:
  void WhatAmI();
};

void Rectangle::WhatAmI() { cout << "Am Rectangle " << endl; }

class Square : public Shape {
 public:
  void WhatAmI();
};
void Square::WhatAmI() { cout << "Am Square " << endl; }

int main() {
  Shape *s1, *s2, *s3;

  s1 = new Rectangle;
  s2 = new Square;

  s3 = new Shape;
  s1->WhatAmI();
  s2->WhatAmI();
  s3->WhatAmI();
  return 0;
}