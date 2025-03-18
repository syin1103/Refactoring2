#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Party {
 public:
  Party(std::string name) : name_(name) {}
  ~Party() = default;

  std::string name() { return name_; }

  virtual int TotalMonthlyCost() = 0;
  int TotalAnnualCost() { return TotalMonthlyCost() * 12; }

 private:
  std::string name_;
};

class Employee : public Party {
 public:
  Employee(std::string name, std::string id, int monthly_cost)
      : Party(name), id_(id), monthly_cost_(monthly_cost) {}
  ~Employee() = default;

  int TotalMonthlyCost() override { return monthly_cost_; }
  std::string id() { return id_; }

 private:
  std::string id_;
  int monthly_cost_;
};

class Department : public Party {
 public:
  Department(std::string name, const std::vector<int>& staff)
      : Party(name), staff_(staff) {}
  ~Department() {}

  std::vector<int> staff() { return staff_; }

  int TotalMonthlyCost() {
    return std::accumulate(staff_.begin(), staff_.end(), 0);
  }

  int HeadCount() { return staff_.size(); }

 private:
  std::vector<int> staff_;
};

int main() {
  Employee emp("employee", "emp_id", 10);
  Department depart("department", {1, 2, 3});

  std::cout << emp.TotalAnnualCost() << std::endl;
  std::cout << depart.TotalAnnualCost() << std::endl;
  return 0;
}