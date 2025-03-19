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

class Booking {
 public:
  Booking(Show show, Date date) : show_(show), date_(date) {}
  ~Booking() = default;

  bool HasTalkBack() { return show_.HasOwnProperty("talkback") && IsPeekDay(); }
  int BasePrice() {
    int result = show_.price;
    if (IsPeekDay()) {
      result += std::round(result * 0.15);
    }
    return result;
  }

 protected:
  bool IsPeekDay() { return date_.IsPeekDay(); }
  Show show_;

 private:
  Date date_;
};

using BookingPtr = std::shared_ptr<Booking>;

class PremiumBooking : public Booking {
 public:
  PremiumBooking(Show show, Date date, Extras extras)
      : Booking(show, date), extras_(extras) {}

  bool HasTalkBack() { return show_.HasOwnProperty("talkback"); }
  int BasePrice() {
    return std::round(Booking::BasePrice() + extras_.premium_fee);
  }

  bool HasDinner() { return extras_.HasOwnProperty("dinner") && !IsPeekDay(); }

 private:
  Extras extras_;
};

using PremiumBookingPtr = std::shared_ptr<PremiumBooking>;

int main() {
  Show show;
  Date date;
  Extras extras;

  BookingPtr booking = std::make_shared<Booking>(show, date);
  PremiumBookingPtr prem_booking =
      std::make_shared<PremiumBooking>(show, date, extras);

  std::cout << booking->BasePrice() << std::endl;
  std::cout << booking->HasTalkBack() << std::endl;

  std::cout << prem_booking->BasePrice() << std::endl;
  std::cout << prem_booking->HasDinner() << std::endl;
  std::cout << prem_booking->HasTalkBack() << std::endl;

  return 0;
}