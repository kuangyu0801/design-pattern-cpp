#include "gtest/gtest.h"
#include "public/journal.h"

namespace srp {
namespace {

TEST(SingleResponsibilityPrinciple, Basic) {
  Journal journal{"Dear Diary"};
  journal.Add("I ate a bug");
  journal.Add("I cried today");

  journal.Save("diary_by_journal.txt");

  PersistenceManager pm;
  pm.Save(journal, "diary_by_pm.txt");
}

} // namespace
} // namespace srp