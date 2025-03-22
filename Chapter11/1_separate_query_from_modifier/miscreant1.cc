#include <iostream>
#include <string>
#include <vector>

void SetOffAlarms() { std::cout << "set off alarms ..." << std::endl; }

std::string FindMiscreant(const std::vector<std::string>& people) {
  for (const auto& p : people) {
    if (p == "Don") {
      return "Don";
    }

    if (p == "John") {
      return "John";
    }
  }
  return "";
}

void AlertForMiscreant(const std::vector<std::string>& people) {
  if (FindMiscreant(people) != "") {
    SetOffAlarms();
  }
}

int main() {
  std::vector<std::string> people{"Lucy", "John", "LiHua"};
  AlertForMiscreant(people);
  return 0;
}