#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

struct Voyage {
  Voyage(const std::string& z, int len) : zone(z), length(len) {}
  int length;
  std::string zone;
};

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
  if (voyage.zone == "china" && HasChina(history)) {
    result += 3;
    if (history.size() > 10) {
      result += 1;
    }
    if (voyage.length > 12) {
      result += 1;
    }
    if (voyage.length > 18) {
      result -= 1;
    }
  } else {
    if (history.size() > 8) {
      result += 1;
    }
    if (voyage.length > 14) {
      result -= 1;
    }
  }
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

int CaptainHistoryRisk(Voyage voyage,
                       const std::unordered_map<std::string, int>& history) {
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

  if (voyage.zone == "china" && HasChina(history)) {
    result -= 2;
  }
  return std::max(result, 0);
}

std::string Rating(Voyage voyage,
                   const std::unordered_map<std::string, int>& history) {
  int vpf = VoyageProfitFactor(voyage, history);
  int vr = VoyageRisk(voyage);
  int chr = CaptainHistoryRisk(voyage, history);

  if (vpf * 3 > (vr + chr * 2)) {
    return "A";
  }
  return "B";
}

int main() {
  Voyage voyage = {"west-indies", 10};
  std::unordered_map<std::string, int> history{
      {"east-indies", 5},
      {"west-indies", 15},
      {"china", -2},
      {"west-africa", 7},
  };

  std::cout << Rating(voyage, history) << std::endl;

  return 0;
}