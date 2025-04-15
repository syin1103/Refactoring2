#include <iostream>
#include <memory>

struct Data {
  Data(int n = 0, int i = 0) : number(n), id(i) {}
  int number;
  int id;
};

class Customer {
 public:
  Customer(int id) : id_(id) {}
  int id() { return id_; }

 private:
  int number_;
  int id_;
};

class Order {
 public:
  Order(Data data) : number_(data.number) {
    customer_ = std::make_shared<Customer>(data.id);
  }

  std::shared_ptr<Customer> customer() { return customer_; }
  int number() { return number_; }

 private:
  int number_;
  std::shared_ptr<Customer> customer_;
};

int main() {
  Data data(20, 30);
  Order order(data);

  auto customer = order.customer();
  std::cout << order.number() << "," << customer->id() << std::endl;
  return 0;
}