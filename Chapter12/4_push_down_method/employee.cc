#include <iostream>

class Employee {
 public:
  void quota() {}
};

class Engineer : public Employee {};
class Salesman : public Employee {};

int main() {
  Engineer eng;
  Salesman sal;
  return 0;
}