#include <iostream>
#include <set>
#include <string>

class CatalogItem {
 public:
  CatalogItem(std::string id, std::string title,
              const std::set<std::string>& tags)
      : id_(id), title_(title), tags_(tags) {}
  ~CatalogItem() = default;

  std::string id() { return id_; }
  std::string title() { return title_; }
  bool HasTag(std::string tag) { return tags_.find(tag) != tags_.end(); }

 private:
  std::string id_;
  std::string title_;
  std::set<std::string> tags_;
};

class Scroll : public CatalogItem {
 public:
  Scroll(std::string id, std::string title, const std::set<std::string>& tags,
         int last_cleaned_date_)
      : CatalogItem(id, title, tags), last_cleaned_(last_cleaned_date_) {}
  ~Scroll() = default;

  bool NeedsClean(int target_date) {
    int threshold = HasTag("revered") ? 700 : 1500;
    return DaysSinceLastDay(target_date) > threshold;
  }

 private:
  int DaysSinceLastDay(int target_date) {
    return target_date >= last_cleaned_ ? target_date - last_cleaned_ : 0;
  }
  int last_cleaned_;
};

int main() {
  Scroll scroll("scroll_id", "scroll_title", {"revered", "other"}, 2000);
  std::cout << scroll.id() << ", " << scroll.title() << std::endl;
  std::cout << scroll.HasTag("revered") << ", " << scroll.NeedsClean(5000)
            << std::endl;
  return 0;
}