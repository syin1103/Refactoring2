#include <iostream>
#include <string>

class Priority {
 public:
  Priority(const std::string& value) : value_(value) {}
  ~Priority() {}

  std::string ToString() const { return value_; }

 private:
  std::string value_;
};

class Order {
 public:
  Order(const std::string& value) : priority_({value}) {}
  ~Order() {}

  void set_priority(const std::string& str) { priority_ = Priority(str); }
  Priority priority() const { return priority_; }
  std::string priority_string() const { return priority_.ToString(); }

 private:
  Priority priority_;
};

int main() {
  Order order("rush");
  order.set_priority("high");
  std::cout << order.priority_string() << std::endl;

  return 0;
}