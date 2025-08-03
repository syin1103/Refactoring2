#include <iostream>
#include <string>

class TrackingInformation {
 public:
  std::string shipping_company() const { return shipping_company_; }
  void set_shipping_company(const std::string& company) {
    shipping_company_ = company;
  }

  std::string tracking_number() const { return tracking_number_; }
  void set_tracking_number(const std::string& number) {
    tracking_number_ = number;
  }

  std::string Display() const {
    return shipping_company() + ": " + tracking_number();
  }

 private:
  std::string shipping_company_{};
  std::string tracking_number_{};
};

class Shipment {
 public:
  std::string TrackingInfo() { return track_info_.Display(); }

  TrackingInformation tracking_information() const { return track_info_; }
  void set_tracking_information(TrackingInformation track_info) {
    track_info_ = track_info;
  }

 private:
  TrackingInformation track_info_{};
};

int main() {
  TrackingInformation info;
  info.set_shipping_company("Google");
  info.set_tracking_number("12345678");

  Shipment shipment;
  shipment.set_tracking_information(info);

  std::cout << shipment.TrackingInfo() << std::endl;
  return 0;
}