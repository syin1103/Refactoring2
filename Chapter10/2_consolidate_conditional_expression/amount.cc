#include <iostream>

struct Employee {
  int seniority = 10;
  int months_disabled = 11;
  bool is_part_time = true;
};

int DisabilityAmount(Employee employee) {
  if (employee.seniority < 2) {
    return 0;
  }

  if (employee.months_disabled > 12) {
    return 0;
  }

  if (employee.is_part_time) {
    return 0;
  }
  /* compute the disability amount */
  return 10;
}

int main() {
  Employee employee;
  std::cout << DisabilityAmount(employee) << std::endl;
  return 0;
}