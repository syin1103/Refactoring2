#include <iostream>
#include <string>

class Employee {
 private:
  std::string quota;
};

class Engineer : public Employee {};
class Salesman : public Employee {};

int main() {
  Engineer eng;
  Salesman sal;
  return 0;
}