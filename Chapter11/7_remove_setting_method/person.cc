#include <iostream>
#include <string>

class Person {
 public:
  std::string id() { return id_; }
  void set_id(std::string id) { id_ = id; }

  std::string name() { return name_; }
  void set_name(std::string name) { name_ = name; }

 private:
  std::string name_ = "";
  std::string id_ = "";
};

int main() {
  Person martin;
  martin.set_name("martin");
  martin.set_id("1234");

  std::cout << martin.name() << std::endl;
  std::cout << martin.id() << std::endl;
  return 0;
}