#include <iostream>
#include <string>
#include <unordered_map>

class Record {
 public:
  Record(const std::string& customer, int quantity, int month, int year)
      : customer_(customer), quantity_(quantity), month_(month), year_(year) {}
  ~Record() {}

  double BaseRate(int month, int year) const { return 0.5; }

  double CaculateBaseCharge() const {
    return BaseRate(month(), year()) * quantity();
  }

  std::string customer() const { return customer_; }
  int quantity() const { return quantity_; }
  int month() const { return month_; }
  int year() const { return year_; }

 private:
  std::string customer_;
  int quantity_;
  int month_;
  int year_;
};

Record AcquireReading() { return Record("ivan", 10, 5, 2017); }

int main() {
  Record reading = AcquireReading();
  double basic_charge_amount = reading.CaculateBaseCharge();
  std::cout << basic_charge_amount << std::endl;
  return 0;
}