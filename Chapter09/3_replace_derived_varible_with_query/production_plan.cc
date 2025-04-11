#include <iostream>
#include <vector>

struct Adjustment {
  int amount = 1;
};

class ProductinPlan {
 public:
  ProductinPlan(int production) : production_(production) {}

  int production() { return production_; }
  void ApplyAdjustment(Adjustment adjustment) {
    adjustments_.push_back(adjustment);
    production_ += adjustment.amount;
  }

 private:
  std::vector<Adjustment> adjustments_{};
  int production_;
};

int main() {
  ProductinPlan plan(10);
  plan.ApplyAdjustment(Adjustment());
  plan.ApplyAdjustment(Adjustment());

  std::cout << plan.production() << std::endl;

  return 0;
}