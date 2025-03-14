#include <iostream>

class Employee {};

class Engineer : public Employee {};
class Salesman : public Employee {
 public:
  void quota() {}
};

int main() {
  Engineer eng;
  Salesman sal;
  return 0;
}