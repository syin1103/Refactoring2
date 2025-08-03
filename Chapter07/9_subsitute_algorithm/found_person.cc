#include <iostream>
#include <string>
#include <vector>

std::string FoundPerson(const std::vector<std::string>& people) {
  for (int i = 0; i < people.size(); i++) {
    if (people[i] == "Don") {
      return "Don";
    }

    if (people[i] == "John") {
      return "John";
    }

    if (people[i] == "Kent") {
      return "Kent";
    }
  }
  return "";
}

int main() {
  std::vector<std::string> people{"Jack", "Tom", "Kent"};
  std::cout << FoundPerson(people) << std::endl;
  return 0;
}