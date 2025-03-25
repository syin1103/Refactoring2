#include <iostream>

struct Custom {
  double base_rate = 0.7;
};

struct Provider {
  int connection_charge = 10;
};

double BaseCharge(Custom custom, int usage) { return custom.base_rate * usage; }

double Charge(Custom custom, Provider provider, int usage) {
  return BaseCharge(custom, usage) + provider.connection_charge;
}

int main() {
  double month_charge = Charge(Custom(), Provider(), 10);
  std::cout << month_charge << std::endl;
  return 0;
}