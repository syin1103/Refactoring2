#include <algorithm>
#include <iostream>

struct Usd {
  Usd(int val) : value(val) {}
  int value;
};

int BottomBand(int usage) { return std::min(usage, 100); }

int MiddleBand(int usage) {
  return usage > 100 ? std::min(usage, 200) - 100 : 0;
}

int TopBand(int usage) { return usage > 200 ? usage - 200 : 0; }

Usd BaseCharge(int usage) {
  if (usage < 0) {
    return Usd(0);
  }

  int amount = BottomBand(usage) * 0.03 + MiddleBand(usage) * 0.05 +
               TopBand(usage) * 0.07;
  return Usd(amount);
}

int main() {
  std::cout << BaseCharge(400).value << std::endl;
  return 0;
}