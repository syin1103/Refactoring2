#include <iostream>

constexpr int EMPLOYEE_MONTHLY_COST = 10;
constexpr int DEPARTMENT_MONTHLY_COST = 20;


class Party {
 public:
  virtual int MonthlyCost() = 0; 
};

class Employee : public Party {
 public:
  int AnnualCost() {
    return MonthlyCost() * 12;
  }

  int MonthlyCost() override {
    return EMPLOYEE_MONTHLY_COST; 
  }
};

class Department : public Party {
 public:
  int TotalAnnualCost() {
    return MonthlyCost() * 12;
  }

  int MonthlyCost() override {
    return DEPARTMENT_MONTHLY_COST;
  }
};

int main() {
  Employee emp;
  Department dep;

  std::cout << emp.AnnualCost() << std::endl;
  std::cout << dep.TotalAnnualCost() << std::endl;

  return 0;
}