#include <iostream>

struct Product {
  int base_price;
  int discount_threshold;
  double discount_rate;
};

struct Method {
  int discount_threshold;
  int discounted_fee;
  int fee_per_case;
};

int PriceOrder(Product product, int quantity, Method shipping_method) {
  int base_price = product.base_price * quantity;
  int discount = std::max(quantity - product.discount_threshold, 0) *
                 product.base_price * product.discount_rate;
  int shipping_per_case = (base_price > shipping_method.discount_threshold)
                              ? shipping_method.discounted_fee
                              : shipping_method.fee_per_case;
  int shipping_cost = quantity * shipping_per_case;
  int price = base_price - discount + shipping_cost;
  return price;
}

int main() {
  Product product{10, 20, 0.5};
  Method shipping_method{10, 20, 30};
  std::cout << PriceOrder(product, 20, shipping_method) << std::endl;
  return 0;
}