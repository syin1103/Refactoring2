#include <iostream>
#include <map>
#include <memory>
#include <string>

class Employee {
  using TypeCodeMap = std::map<std::string, std::string>;

 public:
  Employee(std::string name, std::string type_code)
      : name_(name), type_code_(type_code) {}

  std::string name() { return name_; }
  std::string type() { return LegalTypeCodes()[type_code_]; }

  static TypeCodeMap LegalTypeCodes() {
    return TypeCodeMap{{"E", "Engineer"}, {"M", "Manager"}, {"S", "Salesman"}};
  }

 private:
  std::string name_;
  std::string type_code_;
};

using EmployeePtr = std::shared_ptr<Employee>;

EmployeePtr CreateEmployee(std::string name, std::string type_code) {
  return std::make_shared<Employee>(name, type_code);
}

EmployeePtr CreateEngineer(std::string name) {
  return std::make_shared<Employee>(name, "E");
}

int main() {
  EmployeePtr engineer1 = CreateEmployee("engineer1", "E");
  EmployeePtr engineer2 = CreateEngineer("engineer2");
  std::cout << engineer1->name() << ", " << engineer1->type() << std::endl;
  std::cout << engineer2->name() << ", " << engineer2->type() << std::endl;
  return 0;
}