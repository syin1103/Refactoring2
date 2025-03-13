#include <iostream>
#include <string>

constexpr int EMPLOYEE_MONTHLY_COST = 10;

class Party {};

class Employee : public Party {
 public:
  Employee(std::string name, std::string id, int monthly_cost)
      : name_(name), id_(id), monthly_cost_(monthly_cost) {}

  std::string name() { return name_; }

 private:
  std::string name_;
  std::string id_;
  int monthly_cost_;
};

int main() {
  Employee emp("employee", "emp_id", EMPLOYEE_MONTHLY_COST);
  std::cout << emp.name() << std::endl;
  return 0;
}