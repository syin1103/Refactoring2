#include <iostream>
#include <memory>
#include <string>

enum class Type { engineer = 0, manager, salesman };

class Employee {
 public:
  Employee(std::string name) : name_(name) {}
  ~Employee() = default;

  virtual Type type() = 0;

  std::string name() { return name_; }
  std::string ToString() {
    return name() + "_" + std::to_string(static_cast<int>(type()));
  }

 private:
  std::string name_;
};

class Engineer : public Employee {
 public:
  Engineer(std::string name) : Employee(name) {}
  ~Engineer() = default;

  Type type() override { return Type::engineer; }
};

class Manager : public Employee {
 public:
  Manager(std::string name) : Employee(name) {};
  ~Manager() = default;
  Type type() override { return Type::manager; }
};

class Salesman : public Employee {
 public:
  Salesman(std::string name) : Employee(name) {};
  ~Salesman() = default;
  Type type() override { return Type::salesman; }
};

std::unique_ptr<Employee> CreateEmployee(std::string name, Type type) {
  switch (type) {
    case Type::engineer:
      return std::make_unique<Engineer>(name);
    case Type::manager:
      return std::make_unique<Manager>(name);
    case Type::salesman:
      return std::make_unique<Salesman>(name);
    default:
      throw std::runtime_error("Undefined type");
  }
}

int main() {
  std::unique_ptr<Employee> eng = CreateEmployee("eng", Type::engineer);
  std::unique_ptr<Employee> mag = CreateEmployee("mag", Type::manager);
  std::unique_ptr<Employee> sal = CreateEmployee("sal", Type::salesman);

  std::cout << eng->ToString() << std::endl;
  std::cout << mag->ToString() << std::endl;
  std::cout << sal->ToString() << std::endl;
  return 0;
}