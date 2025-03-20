#include <cmath>
#include <iostream>
#include <memory>

struct Show {
  bool HasOwnProperty(std::string property) { return true; }
  int price = 10;
};

struct Date {
  bool IsPeekDay() { return true; }
};

struct Extras {
  bool HasOwnProperty(std::string property) { return true; }
  int premium_fee = 5;
};

class PremiumBookingDelegate;
class Booking : public std::enable_shared_from_this<Booking> {
 public:
  Booking(Show show, Date date) : show_(show), date_(date) {}
  ~Booking() = default;

  bool HasTalkBack();
  int BasePrice();
  bool HasDinner();

  int ComputeBasePrice() {
    int result = show_.price;
    if (IsPeekDay()) {
      result += std::round(result * 0.15);
    }
    return result;
  }

  void BePremium(Extras extras) {
    prem_delegate_ =
        std::make_unique<PremiumBookingDelegate>(shared_from_this(), extras);
  }

 private:
  bool IsPeekDay() { return date_.IsPeekDay(); }

  std::unique_ptr<PremiumBookingDelegate> prem_delegate_ = nullptr;
  Date date_;
  Show show_;

  friend class PremiumBookingDelegate;
};

using BookingPtr = std::shared_ptr<Booking>;

class PremiumBookingDelegate {
 public:
  PremiumBookingDelegate(std::shared_ptr<Booking> host_booking, Extras extras)
      : host_booking_(host_booking), extras_(extras) {}
  ~PremiumBookingDelegate() = default;

  bool HasTalkBack() { return host_booking_->show_.HasOwnProperty("talkback"); }
  int BasePrice() {
    return std::round(host_booking_->ComputeBasePrice() + extras_.premium_fee);
  }

  bool HasDinner() {
    return extras_.HasOwnProperty("dinner") && !host_booking_->IsPeekDay();
  }

 private:
  Extras extras_;
  std::shared_ptr<Booking> host_booking_;
};

bool Booking::HasTalkBack() {
  return prem_delegate_ ? prem_delegate_->HasTalkBack()
                        : show_.HasOwnProperty("talkback") && IsPeekDay();
}

int Booking::BasePrice() {
  return prem_delegate_ ? prem_delegate_->BasePrice() : ComputeBasePrice();
}

bool Booking::HasDinner() {
  if (!prem_delegate_) {
    throw std::runtime_error("Just premiumbooking has dinner.");
  }
  return prem_delegate_->HasDinner();
}

BookingPtr CreateBooking(Show show, Date date) {
  return std::make_shared<Booking>(show, date);
}

BookingPtr CreatePremiumBooking(Show show, Date date, Extras extras) {
  BookingPtr prem_ptr = std::make_shared<Booking>(show, date);
  prem_ptr->BePremium(extras);
  return prem_ptr;
}

int main() {
  Show show;
  Date date;
  Extras extras;

  BookingPtr booking = CreateBooking(show, date);
  BookingPtr prem_booking = CreatePremiumBooking(show, date, extras);

  std::cout << booking->BasePrice() << std::endl;
  std::cout << booking->HasTalkBack() << std::endl;

  std::cout << prem_booking->BasePrice() << std::endl;
  std::cout << prem_booking->HasDinner() << std::endl;
  std::cout << prem_booking->HasTalkBack() << std::endl;

  return 0;
}