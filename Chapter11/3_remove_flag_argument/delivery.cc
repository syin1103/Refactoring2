#include <iostream>

struct Order {
  Order(std::string deli_state) : state(deli_state) {}
  std::string state;
};

int DeliveryDate(Order order, bool is_rush) {
  if (is_rush) {
    int delivery_time = 0;
    if (order.state == "MA" || order.state == "CT") {
      delivery_time = 1;
    } else if (order.state == "NY" || order.state == "NH") {
      delivery_time = 2;
    } else {
      delivery_time = 3;
    }
    return 1 + delivery_time;
  } else {
    int delivery_time = 0;
    if (order.state == "MA" || order.state == "CT" || order.state == "NY") {
      delivery_time = 2;
    } else if (order.state == "ME" || order.state == "NH") {
      delivery_time = 3;
    } else {
      delivery_time = 4;
    }
    return 2 + delivery_time;
  }
}

int main() {
  Order order("ME");
  std::cout << DeliveryDate(order, true) << std::endl;
  std::cout << DeliveryDate(order, false) << std::endl;
  return 0;
}