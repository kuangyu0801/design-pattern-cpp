#include <iostream>
#include <memory>

#include "gtest/gtest.h"
#include "public/bank_account.h"
#include "public/bitmap.h"
#include "public/person.h"
#include "public/pingpong.h"
#include "public/property.h"

namespace {

using std::wcout;

TEST(Proxy, CurrentAccount) {
  BankAccount* a = new CurrentAccount(123);
  a->Deposit(321);
  delete a;

  // << will not work if you make this a shared_ptr<BankAccount>
  auto b = std::make_shared<CurrentAccount>(123);
  // pointer's own operations on a . underlying object's operations are on ->
  // note this expression is identical to what's above
  BankAccount* actual = b.get();
  b->Deposit(321);

  std::cout << *b << std::endl;
  // no delete
  // see shared_ptr in file structure window
}

TEST(Proxy, CreatureProperty) {
  CreatureWithProperty c;
  c.strength = 11;
  int x = c.strength;
  EXPECT_EQ(x, 11);
}

TEST(Proxy, LazyBitmap) {
  LazyBitmap lazy_bitmap("Lazy bitmap");
  lazy_bitmap.Draw();
}

TEST(Proxy, PingPong) {
  Pong pong;
  for (int i = 0; i < 3; ++i) {
    wcout << pong.Ping(L"ping") << "\n";
  }
}

TEST(Proxy, PersonExercise) {
  Person p{10};
  ResponsiblePerson rp{p};
  ASSERT_EQ("too young", rp.drive());
  ASSERT_EQ("too young", rp.drink());
  ASSERT_EQ("dead", rp.drink_and_drive());

  rp.set_age(20);

  ASSERT_EQ("driving", rp.drive());
  ASSERT_EQ("drinking", rp.drink());
  ASSERT_EQ("dead", rp.drink_and_drive());
}

}  // namespace