#include <iostream>
#include <string>

class Shipment {
 public:
  std::string TrackingInfo() {
    return shipping_company() + ": " + tracking_number();
  }

  std::string tracking_number() const { return tracking_number_; }
  void set_tracking_number(const std::string& number) {
    tracking_number_ = number;
  }

  std::string shipping_company() const { return shipping_company_; }
  void set_shipping_company(const std::string& company) {
    shipping_company_ = company;
  }

 private:
  std::string shipping_company_{};
  std::string tracking_number_{};
};

int main() {
  Shipment shipment;
  shipment.set_shipping_company("Google");
  shipment.set_tracking_number("12345678");

  std::cout << shipment.TrackingInfo() << std::endl;
  return 0;
}