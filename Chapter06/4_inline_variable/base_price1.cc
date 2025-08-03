#include <iostream>

struct Order {
  int base_price = 10;
};

bool BasePrice(const Order& order) { return order.base_price > 1000; }

int main() {
  Order order;
  std::cout << BasePrice(order) << std::endl;
  return 0;
}