#include <iostream>
#include <string>

class Order {
 public:
  Order(const std::string& priority) : priority_(priority) {}
  ~Order() {}

  std::string priority() const { return priority_; }

 private:
  std::string priority_;
};

int main() {
  Order order("high");
  std::cout << order.priority() << std::endl;
  return 0;
}