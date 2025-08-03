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

  double Price() const {
    return Quantity() * ItemPrice() -
           std::max(0, Quantity() - 500) * ItemPrice() * 0.05 +
           std::min(Quantity() * ItemPrice() * 0.1, 100.0);
  }

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