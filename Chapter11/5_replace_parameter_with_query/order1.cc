#include <iostream>

class Order {
 public:
  Order(int quantity, int item_price)
      : quantity_(quantity), item_price_(item_price) {}

  double FinalPrice() {
    int base_price = quantity_ * item_price_;
    return DiscountedPrice(base_price);
  }

 private:
  int DiscountLevel() { return quantity_ > 100 ? 2 : 1; }

  double DiscountedPrice(int base_price) {
    switch (DiscountLevel()) {
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