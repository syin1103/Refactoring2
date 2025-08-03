#include <iostream>
#include <string>
#include <vector>

struct Order {
  Order(int val) : amount(val) {}
  int amount;
};

class Invoice {
 public:
  Invoice(const std::string& name, const std::string& date)
      : customer_(name), date_(date) {}
  ~Invoice() {}

  const std::vector<Order>& orders() const { return orders_; }
  void set_orders(const std::vector<Order>& orders) { orders_ = orders; }

  std::string customer() const { return customer_; }
  std::string date() const { return date_; }

 private:
  std::string customer_;
  std::vector<Order> orders_{};
  std::string date_;
};

void PrintOwing(const Invoice& invoice) {
  int outstanding = 0;

  std::cout << "************************" << std::endl;
  std::cout << "**** Customer Owes *****" << std::endl;
  std::cout << "************************" << std::endl;

  // caculate outstanding
  for (const auto& o : invoice.orders()) {
    outstanding += o.amount;
  }

  // print details
  std::cout << "name: " << invoice.customer() << std::endl;
  std::cout << "amount: " << outstanding << std::endl;
  std::cout << "due: " << invoice.date() << std::endl;
}

int main() {
  Invoice invoice("invoice", "19370707");

  std::vector<Order> orders{Order(10), Order(20), Order(30)};
  invoice.set_orders(orders);
  PrintOwing(invoice);

  return 0;
}