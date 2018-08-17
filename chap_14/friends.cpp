// Write a program that lets users keep track of the last time they
// talked to each of their friends. User should be able to add new
// friends (as many as they want!) and store the number of days ago
// they last talked to each friend.

# import <iostream>
# import <string>

using namespace std;

struct friendInfo {
    string name;
    int days;
};

friendInfo addFriend(string friend_name, int num_days) {
    friendInfo person;
    person.name = friend_name;
    person.days = num_days;
    return person;
}

friendInfo *growFriends(friendInfo* friends_list, int *size);

void showFriends(
    friendInfo* friends,
    int size,
    int current_slot
);

int main() {

    int size = 10;
    friendInfo *friends = new friendInfo[size];
    int current_slot = 0;
    int run_value = 1;

    string friend_name;
    int num_days;

    cout << "Welcome to the friends app! \n";

    while (run_value == 1) {
        cout << "NEW RECORD ENTRY: \n";
        cout << "Input friend name: ";
        cin >> friend_name;
        cout << "Input days since you spoke with " << friend_name << ": ";
        cin >> num_days;

        if (size == current_slot + 1) {
            // Grow friends list
            friends = growFriends(friends, & size);
        }
        friends[current_slot] = addFriend(friend_name, num_days);
        current_slot++;
        cout << "Friend added! \n";
        showFriends(friends, size, current_slot);
        cout << "Press 1 to continue. Press anything else to quit: ";
        cin >> run_value;
    }
    delete [] friends;
    cout << "Goodbye!\n";

    return 0;
}

friendInfo *growFriends(friendInfo* friends, int *size) {
    *size *= 2;
    friendInfo* new_friends = new friendInfo [*size];

    for (int i = 0; i < *size; i++) {
        new_friends[i] = friends[i];
    }
    // Deleting old friends list:
    delete [] friends;
    // Return new freinds list:
    return new_friends;
}

void showFriends(friendInfo* friends, int size, int current_slot) {
    cout << "Total number of friends are: " << current_slot << endl;
    cout << "Current Friends: \n";
    for (int i = 0; i < current_slot; i++) {
        cout << friends[i].name << " last spoken to "
             << friends[i].days << " days ago\n";
    }
}