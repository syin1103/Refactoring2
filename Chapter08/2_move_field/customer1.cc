#include <iostream>
#include <string>

double DateToday() { return 0.9; }

struct Amount {
 public:
  Amount(int base) : base_(base) {}
  double multiply(double rate) { return rate * base_; }

 private:
  int base_;
};

class CustomerContract {
 public:
  CustomerContract(double start_rate) : start_rate_(start_rate) {}
  double discount_rate() { return discount_rate_; }
  void set_discount_rate(double rate) { discount_rate_ = rate; }

 private:
  double start_rate_;
  double discount_rate_;
};

class Customer {
 public:
  Customer(const std::string& name, double rate)
      : name_(name), contract_(CustomerContract(DateToday())) {
    contract_.set_discount_rate(rate);
  }
  double GetDiscountRate() { return contract_.discount_rate(); }
  void BecomePreferred() {
    contract_.set_discount_rate(GetDiscountRate() + 0.03);
    // discount_rate_ += 0.03;
  }

  double ApplyDiscount(Amount amount) {
    return amount.multiply(GetDiscountRate());
  }

 private:
  std::string name_;
  // double discount_rate_;
  CustomerContract contract_;
};

int main() {
  Amount amount(2);
  Customer customer("customer", 0.3);
  std::cout << customer.GetDiscountRate() << std::endl;
  customer.BecomePreferred();
  std::cout << customer.ApplyDiscount(amount) << std::endl;
  return 0;
}