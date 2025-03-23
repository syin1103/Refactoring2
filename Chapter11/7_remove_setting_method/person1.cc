#include <iostream>
#include <string>

class Person {
 public:
  Person(std::string name, std::string id) : name_(name), id_(id) {}
  std::string id() { return id_; }
  std::string name() { return name_; }

 private:
  std::string name_;
  std::string id_;
};

int main() {
  Person martin("martin", "1234");

  std::cout << martin.name() << std::endl;
  std::cout << martin.id() << std::endl;
  return 0;
}