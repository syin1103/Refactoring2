#include <iostream>
#include <string>

class TelephoneNumber {
 public:
  std::string area_code() const { return area_code_; }
  void set_area_code(const std::string& area_code) { area_code_ = area_code; }

  std::string number() const { return number_; }
  void set_number(const std::string& number) { number_ = number; }

 private:
  std::string area_code_{};
  std::string number_{};
};

class Person {
 public:
  std::string name() const { return name_; }
  void set_name(const std::string& name) { name_ = name; }

  std::string ToString() { return office_area_code() + " " + office_number(); }

  std::string office_area_code() const { return telephone_number_.area_code(); }
  void set_office_area_code(const std::string& area_code) {
    telephone_number_.set_area_code(area_code);
  }

  std::string office_number() const { return telephone_number_.number(); }
  void set_office_number(const std::string& number) {
    telephone_number_.set_number(number);
  }

 private:
  std::string name_{};
  TelephoneNumber telephone_number_{};
};

int main() {
  Person person;
  person.set_office_area_code("0331");
  person.set_office_number("12345678");

  std::cout << person.ToString() << std::endl;
  return 0;
}