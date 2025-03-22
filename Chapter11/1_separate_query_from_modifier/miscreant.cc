#include <iostream>
#include <string>
#include <vector>

void SetOffAlarms() { std::cout << "set off alarms ..." << std::endl; }

std::string AlertForMiscreant(const std::vector<std::string>& people) {
  for (const auto& p : people) {
    if (p == "Don") {
      SetOffAlarms();
      return "Don";
    }

    if (p == "John") {
      SetOffAlarms();
      return "John";
    }
  }

  return "";
}

int main() {
  std::vector<std::string> people{"Lucy", "John", "LiHua"};
  AlertForMiscreant(people);
  return 0;
}