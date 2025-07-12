#include <iostream>

struct PircingPlan {
  int base = 10;
  int unit = 1;
  int discount_threshold = 3;
  int discount_factor = 0.5;
};

struct Order {
  int units = 10;
  bool is_repeat = true;
};

PircingPlan RetrievePricingPlan() { return PircingPlan(); }
Order RetreiveOrder() { return Order(); }
void ChargeOrder(int charge) {}

int main() {
  PircingPlan pricing_plan = RetrievePricingPlan();
  Order order = RetreiveOrder();
  int base_charge = pricing_plan.base;
  int charge;
  int charge_per_unit = pricing_plan.unit;
  int units = order.units;
  int discount;
  charge = base_charge + units * charge_per_unit;
  int discountable_units = std::max(units - pricing_plan.discount_threshold, 0);
  discount = discountable_units * pricing_plan.discount_factor;
  if (order.is_repeat) {
    discount += 20;
  }
  charge = charge - discount;
  ChargeOrder(charge);
  std::cout << charge << std::endl;
  return 0;
}