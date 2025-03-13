#include <iostream>
#include <string>

constexpr int PRIVILEGED_GRADE = 4;

class Employee {
 public:
  Employee(std::string name) : name_(name) {}
  std::string name() { return name_; }

 protected:
  void AssignCar() { std::cout << "AssignCar..." << std::endl; }

 private:
  virtual bool IsPrivileged() = 0;

  std::string name_;
};

class Manager : public Employee {
 public:
  Manager(std::string name, int grade) : Employee(name), grade_(grade) {
    if (IsPrivileged()) {  // every subclass does it
      AssignCar();
    }
  }

 private:
  bool IsPrivileged() override { return grade_ > PRIVILEGED_GRADE; }
  int grade_;
};

int main() {
  Manager mag("manager", 5);
  std::cout << mag.name() << std::endl;
  return 0;
}