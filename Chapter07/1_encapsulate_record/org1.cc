#include <iostream>
#include <string>

struct Data {
  std::string name;
  std::string country;
};

class Organization {
 public:
  Organization(Data data) : name_(data.name), country_(data.country) {}
  ~Organization() {}

  void set_name(std::string name) { name_ = name; }
  std::string name() { return name_; }

  void set_country(std::string country) { country_ = country; }
  std::string country() { return country_; }

 private:
  std::string name_;
  std::string country_;
};

int main() {
  Organization org({"ACMe Gooseberries", "GB"});

  std::cout << "name: " << org.name() << ", ";
  std::cout << "country: " << org.country() << std::endl;
  return 0;
}