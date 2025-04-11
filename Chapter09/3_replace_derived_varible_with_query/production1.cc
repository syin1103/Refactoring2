#include <iostream>
#include <numeric>
#include <vector>

struct Adjustment {
  int amount = 1;
};

class ProductinPlan {
 public:
  int production() { return CaculateProduction(); }
  void ApplyAdjustment(Adjustment adjustment) {
    adjustments_.push_back(adjustment);
  }

 private:
  int CaculateProduction() {
    auto calc = [](int sum, const Adjustment& adj) { return sum + adj.amount; };
    return std::accumulate(adjustments_.begin(), adjustments_.end(), 0, calc);
  }

  std::vector<Adjustment> adjustments_;
};

int main() {
  ProductinPlan plan{};
  plan.ApplyAdjustment(Adjustment());
  plan.ApplyAdjustment(Adjustment());

  std::cout << plan.production() << std::endl;

  return 0;
}