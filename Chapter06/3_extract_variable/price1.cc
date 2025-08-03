#include <iostream>

struct Data {
  int quantity;
  int item_price;
};

class Order {
 public:
  Order(const Data& record) : data_(record) {}
  ~Order() {}

  int Quantity() const { return data_.quantity; }
  int ItemPrice() const { return data_.item_price; }

  int BasePrice() const { return Quantity() * ItemPrice(); }

  double QuantityDiscount() const {
    return std::max(0, Quantity() - 500) * ItemPrice() * 0.05;
  }

  double Shipping() const {
    return std::min(Quantity() * ItemPrice() * 0.1, 100.0);
  }

  double Price() const { return BasePrice() - QuantityDiscount() + Shipping(); }

 private:
  Data data_;
};

int main() {
  Data data;
  data.item_price = 10;
  data.quantity = 20;

  Order order(data);
  std::cout << order.Price() << std::endl;

  return 0;
}