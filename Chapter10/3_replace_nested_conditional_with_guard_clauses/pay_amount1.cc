#include <iostream>
#include <string>

struct Employee {
  Employee(bool separated, bool retired)
      : is_separated(separated), is_retired(retired) {}
  bool is_separated;
  bool is_retired;
};

struct Amount {
  Amount() {}
  Amount(int val, std::string code) : amount(val), reason_code(code) {};
  int amount;
  std::string reason_code;
};

Amount SomeFinalComputation() { return {1, "Final"}; }

Amount PayAmount(Employee employee) {
  if (employee.is_separated) {
    return {0, "SEP"};
  }

  if (employee.is_retired) {
    return {0, "RET"};
  }

  /*
   * logic to compute amount
   */
  return SomeFinalComputation();
}

int main() {
  Employee employee(false, true);
  Amount amount = PayAmount(employee);
  std::cout << amount.amount << ", " << amount.reason_code << std::endl;
  return 0;
}