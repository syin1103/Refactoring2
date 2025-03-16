#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

enum class Type { engineer = 0, manager, salesman };

class EmployeeType {
 public:
  virtual std::string ToString() = 0;
};

class Engineer : public EmployeeType {
 public:
  std::string ToString() override { return "engineer"; }
};

class Manager : public EmployeeType {
 public:
  std::string ToString() override { return "manager"; }
};

class Salesman : public EmployeeType {
 public:
  std::string ToString() override { return "salesman"; }
};

class Employee {
 public:
  Employee(std::string name, std::unique_ptr<EmployeeType> type)
      : name_(name), type_(std::move(type)) {}
  ~Employee() = default;

  void set_type(Type type_code) { type_ = CreateEmployeeType(type_code); }

  std::string ToString() { return name_ + "_" + CapitalizedType(); }

  std::string TypeString() { return type_->ToString(); }

  static std::unique_ptr<EmployeeType> CreateEmployeeType(Type type_code) {
    switch (type_code) {
      case Type::engineer:
        return std::make_unique<Engineer>();
      case Type::manager:
        return std::make_unique<Manager>();
      case Type::salesman:
        return std::make_unique<Salesman>();
      default:
        throw std::runtime_error("Undefined type");
    }
  }

 private:
  std::string CapitalizedType() {
    std::string tmp = TypeString();
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    tmp[0] = std::toupper(tmp[0]);
    return tmp;
  }

  std::string name_;
  std::unique_ptr<EmployeeType> type_;
};

int main() {
  Employee eng("eng", std::make_unique<Engineer>());
  Employee mag("mag", std::make_unique<Manager>());
  Employee sal("sal", std::make_unique<Salesman>());

  std::cout << eng.ToString() << std::endl;
  std::cout << mag.ToString() << std::endl;
  std::cout << sal.ToString() << std::endl;

  eng.set_type(Type::manager);
  std::cout << eng.ToString() << std::endl;

  return 0;
}