#include <cassert>
#include <iostream>

class Customer {
 public:
  Customer(double rate) : discount_rate_(rate) {}

  int ApplyDiscount(int number) {
    if (!discount_rate_) {
      return number;
    }
    assert(discount_rate_ >= 0);
    return number - discount_rate_ * number;
  }

 private:
  double discount_rate_ = 0.0;
};

int main() {
  Customer customer(0.7);
  std::cout << customer.ApplyDiscount(100) << std::endl;
  return 0;
}