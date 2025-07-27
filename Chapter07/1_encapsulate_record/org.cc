#include <iostream>
#include <string>
#include <unordered_map>

using OrgMap = std::unordered_map<std::string, std::string>;

OrgMap organization = {{"name", "ACme Gooseberries"}, {"country", "GB"}};

int main() {
  std::cout << "name: " << organization["name"] << ", ";
  std::cout << "country: " << organization["country"] << std::endl;
  return 0;
}