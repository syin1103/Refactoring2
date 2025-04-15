#include <iostream>
#include <memory>

class TelephoneNumber {
 public:
  TelephoneNumber(int code = 0, int number = 0)
      : area_code_(code), office_number_(number) {}

  int area_code() { return area_code_; }
  int office_number() { return office_number_; }

 private:
  int area_code_;
  int office_number_;
};

class Person {
 public:
  Person() { telephone_ = std::make_unique<TelephoneNumber>(); }

  int GetOfficeAreaCode() { return telephone_->area_code(); }
  void SetOfficeAreaCode(int code) {
    telephone_ = std::make_unique<TelephoneNumber>(code, GetOfficeNumber());
  }

  int GetOfficeNumber() { return telephone_->office_number(); }
  void SetOfficeNumber(int number) {
    telephone_ = std::make_unique<TelephoneNumber>(GetOfficeAreaCode(), number);
  }

 private:
  std::unique_ptr<TelephoneNumber> telephone_;
};

int main() {
  Person person;
  person.SetOfficeAreaCode(10);
  person.SetOfficeNumber(20);
  std::cout << person.GetOfficeAreaCode() << ", " << person.GetOfficeNumber()
            << std::endl;
  return 0;
}