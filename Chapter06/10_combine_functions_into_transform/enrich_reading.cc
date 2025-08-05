
#include <iostream>

struct Record {
  std::string customer;
  int quantity;
  int month;
  int year;
};

Record AcquireReading() { return Record{"ivan", 10, 5, 2017}; }
double BaseRate(int month, int year) { return 0.5; }

double CaculateBaseCharge(Record reading) {
  return BaseRate(reading.month, reading.year) * reading.quantity;
}

int TaxThreshold(int year) { return 10; }

int main() {
  Record reading = AcquireReading();
  double base = BaseRate(reading.month, reading.year) * reading.quantity;
  int basic_charge_amount = CaculateBaseCharge(reading);
  int taxable_charge = std::max(0.0, base - TaxThreshold(reading.year));

  std::cout << base << std::endl;
  std::cout << basic_charge_amount << std::endl;
  std::cout << taxable_charge << std::endl;
  return 0;
}