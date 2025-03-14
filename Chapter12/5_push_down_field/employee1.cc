#include <iostream>
#include <string>

class Employee {};

class Engineer : public Employee {};
class Salesman : public Employee {
 private:
  std::string quota;
};

int main() {
  Engineer eng;
  Salesman sal;
  return 0;
}