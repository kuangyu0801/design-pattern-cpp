#include "public/chat_room.h"

void ChatRoom::Broadcast(const string &origin, const string &message)
{
  for (auto p : people_)
    if (p->name_ != origin)
      p->Receive(origin, message);
}

void ChatRoom::Join(Person *p)
{
  string join_msg = p->name_ + " joins the chat";
  Broadcast("room", join_msg);
  p->room_ = this;
  people_.push_back(p);
}
