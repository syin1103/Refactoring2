
#include <iostream>

struct Record {
  std::string customer;
  int quantity;
  int month;
  int year;
  int base = 0;
  double base_charge = 0.0;
  int taxable_charge = 0;
};

Record AcquireReading() { return Record{"ivan", 10, 5, 2017}; }
double BaseRate(int month, int year) { return 0.5; }

double CaculateBaseCharge(Record reading) {
  return BaseRate(reading.month, reading.year) * reading.quantity;
}

int TaxThreshold(int year) { return 10; }

Record EnrichReading(const Record& reading) {
  Record result = reading;
  result.base = BaseRate(result.month, result.year) * reading.quantity;
  result.base_charge = CaculateBaseCharge(result);
  result.taxable_charge = std::max(0, result.base - TaxThreshold(result.year));
  return result;
}

int main() {
  Record reading = AcquireReading();
  Record enrich_reading = EnrichReading(reading);

  std::cout << enrich_reading.base << std::endl;
  std::cout << enrich_reading.base_charge << std::endl;
  std::cout << enrich_reading.taxable_charge << std::endl;
  return 0;
}