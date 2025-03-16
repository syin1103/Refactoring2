#include <iostream>
#include <memory>
#include <string>

class Employee {
 public:
  Employee(std::string name, std::string type) : name_(name), type_(type) {}
  ~Employee() = default;

  std::string ToString() { return name_ + "_" + type_; }

 private:
  bool ValidateType(std::string type) {
    if (type == "engineer" || type == "manager" || type == "salesman") {
      return true;
    }
    return false;
  }

  std::string name_;
  std::string type_;
};

std::unique_ptr<Employee> CreateEmployee(std::string name, std::string type) {
  return std::make_unique<Employee>(name, type);
}

int main() {
  std::unique_ptr<Employee> eng = CreateEmployee("eng", "engineer");
  std::unique_ptr<Employee> mag = CreateEmployee("mag", "manager");
  std::unique_ptr<Employee> sal = CreateEmployee("sal", "salesman");

  std::cout << eng->ToString() << std::endl;
  std::cout << mag->ToString() << std::endl;
  std::cout << sal->ToString() << std::endl;
  return 0;
}