#include <iostream>

struct AccountType {
  bool is_premium = true;
  double OverDraftCharge(int days_over_drawn) {
    if (is_premium) {
      int base_charge = 10;
      if (days_over_drawn <= 7) {
        return base_charge;
      } else {
        return base_charge + (days_over_drawn - 7) * 0.85;
      }
    } else {
      return days_over_drawn * 1.75;
    }
  }
};

class Account {
 public:
  double BankCharge() {
    double result = 4.5;
    if (days_over_drawn_ > 0) {
      result += OverDraftCharge();
    }
    return result;
  }

 private:
  double OverDraftCharge() { return type_.OverDraftCharge(days_over_drawn_); }

  int days_over_drawn_ = 1;
  AccountType type_;
};

int main() {
  Account account;
  std::cout << account.BankCharge() << std::endl;
  return 0;
}