#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> states{"CHA", "MA", "JAPAN"};

  bool applies_to_mass = false;
  for (const auto& s : states) {
    if (s == "MA") {
      applies_to_mass = true;
    }
  }

  std::cout << applies_to_mass << std::endl;
  return 0;
}