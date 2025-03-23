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

int main() {
  EmployeePtr engineer = std::make_shared<Employee>("engineer", "E");
  std::cout << engineer->name() << ", " << engineer->type() << std::endl;
  return 0;
}