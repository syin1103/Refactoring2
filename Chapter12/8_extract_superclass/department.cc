#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Employee {
 public:
  Employee(std::string name, std::string id, int monthly_cost)
      : name_(name), id_(id), monthly_cost_(monthly_cost) {}
  ~Employee() = default;

  int monthly_cost() { return monthly_cost_; }
  std::string name() { return name_; }
  std::string id() { return id_; }

  int GetAnnualCost() { return monthly_cost() * 12; }

 private:
  std::string name_;
  std::string id_;
  int monthly_cost_;
};

class Department {
 public:
  Department(std::string name, const std::vector<int>& staff)
      : name_(name), staff_(staff) {}
  ~Department() {}

  std::vector<int> staff() { return staff_; }
  std::string name() { return name_; }

  int TotalMonthlyCost() {
    return std::accumulate(staff_.begin(), staff_.end(), 0);
  }

  int HeadCount() { return staff_.size(); }
  int TotalAnnualCost() { return TotalMonthlyCost() * 12; }

 private:
  std::string name_;
  std::vector<int> staff_;
};

int main() {
  Employee emp("employee", "emp_id", 10);
  Department depart("department", {1, 2, 3});

  std::cout << emp.GetAnnualCost() << std::endl;
  std::cout << depart.TotalAnnualCost() << std::endl;
  return 0;
}