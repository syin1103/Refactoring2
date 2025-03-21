#include <iostream>
#include <map>
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
using CatalogItemPtr = std::shared_ptr<CatalogItem>;

class Scroll {
 public:
  Scroll(std::string scroll_id, int last_cleaned_date_, std::string catalog_id,
         const std::map<std::string, CatalogItemPtr>& catalogs)
      : id_(scroll_id), last_cleaned_(last_cleaned_date_) {
    // assert(catalogs.find(catalog_id) != catalogs.end());
    catalog_ = (catalogs.find(catalog_id))->second;
  }
  ~Scroll() = default;

  std::string id() { return id_; }
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
  std::string id_;
  int last_cleaned_;
};

int main() {
  std::set<std::string> tags{"revered", "other"};
  auto catalog_item =
      std::make_shared<CatalogItem>("catalog_id", "catalog_title", tags);
  std::map<std::string, CatalogItemPtr> catalogs{{"catalog_id", catalog_item}};

  Scroll scroll("scroll_id", 2000, "catalog_id", catalogs);
  std::cout << scroll.id() << ", " << scroll.title() << std::endl;
  std::cout << scroll.HasTag("revered") << ", " << scroll.NeedsClean(5000)
            << std::endl;
  return 0;
}