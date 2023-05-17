#include "public/phone_state.h"

using namespace state;

int main(int argc, char* argv[]) {
  map<State, vector<pair<Trigger, State>>> rules;

  rules[State::kOffHook] = {{Trigger::kCallDialed, State::kConnecting},
                            {Trigger::kStopUsingPhone, State::kOnHook}};

  rules[State::kConnecting] = {{Trigger::kHungUp, State::kOffHook},
                               {Trigger::kCallConnected, State::kConnected}};

  rules[State::kConnected] = {{Trigger::kLeftMessage, State::kOffHook},
                              {Trigger::kHungUp, State::kOffHook},
                              {Trigger::kPlacedOnHold, State::kOnHold}};

  rules[State::kOnHold] = {{Trigger::kTakenOffHold, State::kConnected},
                           {Trigger::kHungUp, State::kOffHook}};

  State curr_state = State::kOffHook;
  State exit_state = State::kOnHook;

  while (true) {
    cout << "The phone is currently " << curr_state << endl;
    cout << "Select a trigger:"
         << "\n";

    int i = 0;
    for (auto item : rules[curr_state]) {
      cout << i++ << ". " << item.first << "\n";
    }

    int input;
    cin >> input;
    if (input < 0 || (input + 1) > rules[curr_state].size()) {
      cout << "Incorrect option. Please try again."
           << "\n";
      continue;
    }
    cout << "Setting new state" << endl;
    curr_state = rules[curr_state][input].second;
    if (curr_state == exit_state) {
      break;
    }
  }

  cout << "We are done using the phone"
       << "\n";

  getchar();
  getchar();
  return 0;
}