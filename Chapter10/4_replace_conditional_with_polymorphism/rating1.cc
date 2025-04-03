#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

struct Voyage {
  Voyage(const std::string& z, int len) : zone(z), length(len) {}
  int length;
  std::string zone;
};

class Rating {
 public:
  Rating(Voyage voyage, const std::unordered_map<std::string, int>& history)
      : voyage_(voyage), history_(history) {}

  bool HasChina(const std::unordered_map<std::string, int>& history) {
    return history.find("china") != history.end();
  }

  int VoyageProfitFactor(Voyage voyage,
                         const std::unordered_map<std::string, int>& history) {
    int result = 2;
    if (voyage.zone == "china") {
      result += 1;
    }
    if (voyage.zone == "east-indies") {
      result += 1;
    }
    result += HistoryLengthFactor();
    result += VoyageLengthFactor();
    return result;
  }

  int VoyageRisk(Voyage voyage) {
    int result = 1;
    if (voyage.length > 4) {
      result += 2;
    }
    if (voyage.length > 8) {
      result += voyage.length - 8;
    }

    if (voyage.zone == "china") {
      result += 4;
    }
    return std::max(result, 0);
  }

  virtual int CaptainHistoryRisk(
      Voyage voyage, const std::unordered_map<std::string, int>& history) {
    int result = 1;
    if (history.size() < 5) {
      result += 4;
    }
    for_each(history.begin(), history.end(),
             [&result](std::pair<std::string, int> item) {
               if (item.second < 0) {
                 result++;
               }
             });
    return std::max(result, 0);
  }

  virtual std::string Value(
      Voyage voyage, const std::unordered_map<std::string, int>& history) {
    int vpf = VoyageProfitFactor(voyage, history);
    int vr = VoyageRisk(voyage);
    int chr = CaptainHistoryRisk(voyage, history);

    if (vpf * 3 > (vr + chr * 2)) {
      return "A";
    }
    return "B";
  }

  virtual int VoyageLengthFactor() {
    int result = 0;
    if (voyage_.length > 14) {
      result += -1;
    }
    return result;
  }

  virtual int HistoryLengthFactor() { return history_.size() > 8 ? 1 : 0; }

 protected:
  Voyage voyage_;
  std::unordered_map<std::string, int> history_;
};

class ExperiencedChinaRating : public Rating {
 public:
  ExperiencedChinaRating(Voyage voyage,
                         const std::unordered_map<std::string, int>& history)
      : Rating(voyage, history) {}

  int CaptainHistoryRisk(
      Voyage voyage,
      const std::unordered_map<std::string, int>& history) override {
    int result = Rating::CaptainHistoryRisk(voyage, history) - 2;
    return std::max(result, 0);
  }

  int VoyageLengthFactor() override {
    int result = 3;
    if (voyage_.length > 12) {
      result += 1;
    }
    if (voyage_.length > 18) {
      result -= 1;
    }
    return result;
  }

  int HistoryLengthFactor() override { return history_.size() > 10 ? 1 : 0; }
};

std::shared_ptr<Rating> CreateRating(
    Voyage voyage, const std::unordered_map<std::string, int>& history) {
  if (voyage.zone == "china" && history.find("china") != history.end()) {
    return std::make_shared<ExperiencedChinaRating>(voyage, history);
  }
  return std::make_shared<Rating>(voyage, history);
}

int main() {
  Voyage voyage = {"west-indies", 10};
  std::unordered_map<std::string, int> history{
      {"east-indies", 5},
      {"west-indies", 15},
      {"china", -2},
      {"west-africa", 7},
  };

  std::cout << CreateRating(voyage, history)->Value(voyage, history)
            << std::endl;

  return 0;
}