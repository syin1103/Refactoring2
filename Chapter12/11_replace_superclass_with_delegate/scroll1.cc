#include <iostream>
#include <memory>
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

class Scroll {
 public:
  Scroll(std::string id, std::string title, const std::set<std::string>& tags,
         int last_cleaned_date_)
      : last_cleaned_(last_cleaned_date_) {
    catalog_ = std::make_shared<CatalogItem>(id, title, tags);
  }
  ~Scroll() = default;

  std::string id() { return catalog_->id(); }
  std::string title() { return catalog_->title(); }
  bool HasTag(const std::string& tag) { return catalog_->HasTag(tag); }

  bool NeedsClean(int target_date) {
    int threshold = HasTag("revered") ? 700 : 1500;
    return DaysSinceLastDay(target_date) > threshold;
  }

 private:
  int DaysSinceLastDay(int target_date) {
    return target_date >= last_cleaned_ ? target_date - last_cleaned_ : 0;
  }

  std::shared_ptr<CatalogItem> catalog_;
  int last_cleaned_;
};

int main() {
  Scroll scroll("scroll_id", "scroll_title", {"revered", "other"}, 2000);
  std::cout << scroll.id() << ", " << scroll.title() << std::endl;
  std::cout << scroll.HasTag("revered") << ", " << scroll.NeedsClean(5000)
            << std::endl;
  return 0;
}