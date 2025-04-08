#include <iostream>
#include <memory>

struct BillingPlan {};
struct PaymentHistory {
  PaymentHistory(int number = 10) : weeks_delinquent(number) {};
  int weeks_delinquent;
};

class Customer {
 public:
  Customer(std::string name) : name_(name) {}

  virtual std::string name() const { return name_; }
  virtual PaymentHistory payment_history() const { return payment_history_; }

  virtual BillingPlan billing_plan() const { return billing_plan_; }
  virtual void set_billing_plan(BillingPlan plan) { billing_plan_ = plan; }

 protected:
  std::string name_;
  PaymentHistory payment_history_{};
  BillingPlan billing_plan_{};

  //  private:
};

class UnknownCustomer : public Customer {
 public:
  UnknownCustomer() : Customer("Unknown") {}

  std::string name() const override { return "occupant"; }
  PaymentHistory payment_history() const { return {0}; }

  BillingPlan billing_plan() const { return billing_plan_; }
  void set_billing_plan(BillingPlan plan) override {}
};

class Site {
 public:
  Site(std::string name) { customer_ = std::make_shared<Customer>(name); }

  std::shared_ptr<Customer> customer() const {
    return (customer_ != nullptr) ? customer_
                                  : std::make_shared<UnknownCustomer>();
  }

 private:
  std::shared_ptr<Customer> customer_ = nullptr;
};

int main() {
  Site site1("site1");
  auto customer = site1.customer();

  {
    /*
     * lots of interventing code
     */
    std::string customer_name = customer->name();
    std::cout << customer_name << std::endl;
  }

  {
    customer->set_billing_plan(BillingPlan());
    std::cout << "set billing plan..." << std::endl;
  }

  {
    int weeks_delinquent = customer->payment_history().weeks_delinquent;
    std::cout << weeks_delinquent << std::endl;
  }

  return 0;
}