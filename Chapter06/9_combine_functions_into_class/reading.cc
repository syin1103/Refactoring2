#include <iostream>
#include <string>
#include <unordered_map>

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

int main() {
  Record reading = AcquireReading();
  double basic_charge_amount = CaculateBaseCharge(reading);
  std::cout << basic_charge_amount << std::endl;
  return 0;
}