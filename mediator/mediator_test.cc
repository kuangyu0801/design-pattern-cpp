#include "gtest/gtest.h"
#include "public/people.h"
#include "public/chat_room.h"

TEST(MediatorPattern, ChatRoomExample) {
  ChatRoom room;

  Person john{"John"};
  Person jane{"Jane"};
  room.Join(&john);
  room.Join(&jane);
  john.Say("hi room");
  jane.Say("oh, hey john");

  Person simon{"Simon"};
  room.Join(&simon);
  simon.Say("hi everyone!");

  jane.PrivateMessage("Simon", "glad you found us, simon!");
}
