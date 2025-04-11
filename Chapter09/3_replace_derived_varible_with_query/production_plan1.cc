#include <iostream>
#include <numeric>
#include <vector>

struct Adjustment {
  int amount = 1;
};

class ProductinPlan {
 public:
  ProductinPlan(int production) : init_pro_(production) {}
  int production() { return init_pro_ + CaculateProduction(); }
  void ApplyAdjustment(Adjustment adjustment) {
    adjustments_.push_back(adjustment);
  }

 private:
  int CaculateProduction() {
    auto calc = [](int sum, const Adjustment& adj) { return sum + adj.amount; };
    return std::accumulate(adjustments_.begin(), adjustments_.end(), 0, calc);
  }

  std::vector<Adjustment> adjustments_;
  int init_pro_;
};

int main() {
  ProductinPlan plan(10);
  plan.ApplyAdjustment(Adjustment());
  plan.ApplyAdjustment(Adjustment());

  std::cout << plan.production() << std::endl;

  return 0;
}