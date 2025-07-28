#include <iostream>

struct Item {
  Item(int value) : price(value) {}
  int price;
};

class Order {
 public:
  Order(int quantity, Item item) : quantity_(quantity), item_(item) {}
  ~Order() {}

  double price() {
    double base_price = quantity_ * item_.price;
    double discount_factor = 0.98;
    if (base_price > 1000) {
      discount_factor -= 0.03;
    }
    return base_price * discount_factor;
  }

 private:
  int quantity_;
  Item item_;
};

int main() {
  Item item{20};
  Order order(10, item);
  std::cout << order.price() << std::endl;

  return 0;
}