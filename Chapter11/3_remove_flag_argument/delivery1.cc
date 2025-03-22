#include <iostream>

struct Order {
  Order(std::string deli_state) : state(deli_state) {}
  std::string state;
};

int RushDeliveryDate(Order order) {
  int delivery_time = 0;
  if (order.state == "MA" || order.state == "CT") {
    delivery_time = 1;
  } else if (order.state == "NY" || order.state == "NH") {
    delivery_time = 2;
  } else {
    delivery_time = 3;
  }
  return 1 + delivery_time;
}

int RegularDeliveryDate(Order order) {
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

int main() {
  Order order("ME");
  std::cout << RushDeliveryDate(order) << std::endl;
  std::cout << RegularDeliveryDate(order) << std::endl;
  return 0;
}