#include <iostream>
#include <string>

class Manager {
 public:
  Manager(const std::string& name = "") : name_(name) {}
  ~Manager() {}

  std::string name() const { return name_; }

 private:
  std::string name_;
};

class Department {
 public:
  Department() {}
  ~Department() {}

  int charge_code() const { return charge_code_; }
  void set_charge_code(int code) { charge_code_ = code; }

  Manager manager() const { return manager_; }
  void set_manager(Manager manager) { manager_ = manager; }

 private:
  int charge_code_ = 0;
  Manager manager_;
};

class Person {
 public:
  Person(const std::string& name) : name_(name) {}
  ~Person() {}

  std::string name() const { return name_; }
  Department department() const { return department_; }
  void set_department(Department department) { department_ = department; }

  Manager manager() const { return department_.manager(); }

 private:
  std::string name_;
  Department department_;
};

int main() {
  Department department;
  department.set_manager({"Jack"});

  Person person("Tom");
  person.set_department(department);

  Manager manager = person.manager();
  std::cout << manager.name() << std::endl;

  return 0;
}