#include <iostream>

class Date {
 public:
  Date(int date) : date_(date) {};
  bool IsBefore(int date) { return date_ < date; }
  bool IsAfter(int date) { return date_ >= date; }

 private:
  int date_;
};

struct Plan {
  int summer_start = 50;
  int summer_end = 100;
  double summer_rate = 0.7;
  double regular_rate = 0.9;
  int regular_service_charge = 10;
};

bool IsSummer(Date date, Plan plan) {
  return !date.IsBefore(plan.summer_start) && !date.IsAfter(plan.summer_end);
}

double SummerCharge(double quantity, Plan plan) {
  return quantity * plan.summer_rate;
}

double RegularCharge(double quantity, Plan plan) {
  return quantity * plan.regular_rate + plan.regular_service_charge;
}

int main() {
  Plan plan;
  Date date(60);

  double quantity = 200;
  double charge = 0.0;
  if (IsSummer(date, plan)) {
    charge = SummerCharge(quantity, plan);
  } else {
    charge = RegularCharge(quantity, plan);
  }

  std::cout << charge << std::endl;
  return 0;
}