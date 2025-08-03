#include <iostream>
#include <string>

class Person {
 public:
  std::string name() const { return name_; }
  void set_name(const std::string& name) { name_ = name; }

  std::string TelephoneNumber() {
    return office_area_code() + " " + office_number();
  }

  std::string office_area_code() const { return office_area_code_; }
  void set_office_area_code(const std::string& area_code) {
    office_area_code_ = area_code;
  }

  std::string office_number() const { return office_number_; }
  void set_office_number(const std::string& number) { office_number_ = number; }

 private:
  std::string name_{};
  std::string office_area_code_{};
  std::string office_number_{};
};

int main() {
  Person person;
  person.set_office_area_code("0331");
  person.set_office_number("12345678");

  std::cout << person.TelephoneNumber() << std::endl;
  return 0;
}