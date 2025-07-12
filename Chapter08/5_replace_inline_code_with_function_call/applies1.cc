#include <iostream>
#include <string>
#include <vector>

bool Includes(std::vector<std::string> states, std::string target) {
  for (const auto& s : states) {
    if (s == target) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::string> states{"CHA", "MA", "JAPAN"};
  std::cout << Includes(states, "MA") << std::endl;
  return 0;
}