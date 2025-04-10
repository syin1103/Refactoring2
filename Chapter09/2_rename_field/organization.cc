#include <iostream>
#include <string>

class Organization {
 public:
  Organization(const std::string& name, const std::string& country)
      : name_(name), country_(country) {}
  std::string name() { return name_; }
  void set_name(const std::string& name) { name_ = name; }
  std::string country() { return country_; }
  void set_country(const std::string& country_code) { country_ = country_code; }

 private:
  std::string name_;
  std::string country_;
};

int main() {
  Organization org{"Acme Gooseberries", "GB"};
  std::cout << org.name() << ", " << org.country() << std::endl;
  return 0;
}