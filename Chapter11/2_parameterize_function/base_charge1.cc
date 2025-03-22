#include <algorithm>
#include <iostream>

struct Usd {
  Usd(int val) : value(val) {}
  int value;
};

int WithinBand(int usage, int bottom, int top) {
  return usage > bottom ? std::min(usage, top) - bottom : 0;
}

Usd BaseCharge(int usage) {
  if (usage < 0) {
    return Usd(0);
  }

  int amount = WithinBand(usage, 0, 100) * 0.03 +
               WithinBand(usage, 100, 200) * 0.05 +
               WithinBand(usage, 200, INT32_MAX) * 0.07;
  return Usd(amount);
}

int main() {
  std::cout << BaseCharge(400).value << std::endl;
  return 0;
}