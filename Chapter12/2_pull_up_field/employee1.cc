#include <iostream>
#include <string>

class Employee {
 public:
  Employee(std::string name) : name_(name) {}
  std::string name() { return name_; }

 protected:
  std::string name_;
};

class Salesman : public Employee {
 public:
  Salesman(std::string name) : Employee(name) {}
};

class Engineer : public Employee {
 public:
  Engineer(std::string name) : Employee(name) {}
};

int main() {
  Salesman salesman("salesman");
  Engineer engineer("engineer");

  std::cout << salesman.name() << std::endl;
  std::cout << engineer.name() << std::endl;
  return 0;
}