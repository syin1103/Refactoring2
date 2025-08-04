#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> default_owner = {
    {"first_name", "Martin"}, {"last_name", "Fowler"}};

int main() {
  std::cout << default_owner["first_name"] << std::endl;
  std::cout << default_owner["last_name"] << std::endl;
  return 0;
}