#include <iostream>
#include <string>
#include <unordered_map>

class Owner {
 public:
  Owner(const std::string& first_name, const std::string& last_name)
      : first_name_(first_name), last_name_(last_name) {}
  ~Owner() {}

  std::string first_name() const { return first_name_; }
  std::string last_name() const { return last_name_; }

 private:
  std::string first_name_;
  std::string last_name_;
};

int main() {
  Owner default_owner("Martin", "Fowler");
  std::cout << default_owner.first_name() << std::endl;
  std::cout << default_owner.last_name() << std::endl;
  return 0;
}