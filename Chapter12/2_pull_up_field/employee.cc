#include <iostream>
#include <string>

class Employee {};

class Salesman : public Employee {
 public:
  Salesman(std::string name) : name_(name) {}
  std::string name() { return name_; }

 private:
  std::string name_;
};

class Engineer : public Employee {
 public:
  Engineer(std::string name) : name_(name) {}
  std::string name() { return name_; }

 private:
  std::string name_;
};

int main() {
  Salesman salesman("salesman");
  Engineer engineer("engineer");

  std::cout << salesman.name() << std::endl;
  std::cout << engineer.name() << std::endl;
  return 0;
}