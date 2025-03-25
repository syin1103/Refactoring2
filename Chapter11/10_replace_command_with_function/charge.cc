#include <iostream>

struct Custom {
  double base_rate = 0.7;
};

struct Provider {
  int connection_charge = 10;
};

class ChargeCaculator {
 public:
  ChargeCaculator(Custom custom, Provider provider, int usage)
      : custom_(custom), provider_(provider), usage_(usage) {}

  double Charge() { return BaseCharge() + provider_.connection_charge; }

 private:
  double BaseCharge() { return custom_.base_rate * usage_; }

  Custom custom_;
  Provider provider_;
  int usage_;
};

int main() {
  double month_charge = ChargeCaculator(Custom(), Provider(), 10).Charge();
  std::cout << month_charge << std::endl;
  return 0;
}