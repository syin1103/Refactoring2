#include <iostream>

class Order {
 public:
  Order(int quantity, int item_price)
      : quantity_(quantity), item_price_(item_price) {}

  double FinalPrice() {
    int base_price = quantity_ * item_price_;
    int discount_level = 1;
    if (quantity_ > 100) {
      discount_level = 2;
    }
    return DiscountedPrice(base_price, discount_level);
  }

 private:
  double DiscountedPrice(int base_price, int discount_level) {
    switch (discount_level) {
      case 1:
        return base_price * 0.95;
      case 2:
        return base_price * 0.9;
      default:
        return 0.0;
    }
  }

  int quantity_;
  int item_price_;
};

int main() {
  Order order(10, 25);
  std::cout << order.FinalPrice() << std::endl;
  return 0;
}