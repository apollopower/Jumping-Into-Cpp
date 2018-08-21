// Implement a small address book program that allows users
// to enter names and email addresses, remove or change 
// entries, and list the entries in their address book:

# include <iostream>
# include <vector>
# include <map>

using namespace std;


// function prototypes
void listContacts(map<string, string> contact_list);
map<string, string> addContact(map<string, string> contact_list, string name, string phone);
map<string, string> updateContact(map<string, string> contact_list, string name);
map<string, string> removeContact(map<string, string> contact_list, string name);
bool quitApplication();

// main function call
int main()
{
    bool run_status = true;

    int option;

    string name;
    string phone;

    cout << "Welcome to your address book! Initializing it now\n";
    // Initializing our address book
    map<string, string> address_book;

    while (run_status) {
        cout << "Enter the number corresponding to what you would like to do:\n"
             << "1. List Contacts\n"
             << "2. Add Contact\n"
             << "3. Update Contact\n"
             << "4. Remove Contact\n"
             << "5. Quit Application\n";

        cin >> option;

        switch (option)
        {
            case 1:
                listContacts(address_book);
                break;
            case 2:
                cout << "Enter contact name: ";
                cin >> name;
                cout << "Enter contact phone: ";
                cin >> phone;
                address_book = addContact(address_book, name, phone);
                break;
            case 3:
                cout << "Enter contact name: ";
                cin >> name;
                address_book = updateContact(address_book, name);
                break;
            case 4:
                cout << "Enter contact name to be deleted: ";
                cin >> name;
                address_book = removeContact(address_book, name);
                break;
            case 5:
                run_status = quitApplication();
                break;
            default:
                cout << "Sorry, not a valid command\n";
        }
    }

    cout << "Goodbye!\n";

    return 0;

}


// Functions Defined:

void listContacts(map<string, string> contact_list) {

    for (map<string, string>::iterator itr = contact_list.begin(),
        end = contact_list.end();
        itr != end; ++itr)
    {
        cout << itr->first << ": " << itr->second << endl;
    }
}

map<string, string> addContact(map<string, string> contact_list, string name, string phone) {
    contact_list[name] = phone;
    cout << name << " added to contacts!\n";
    return contact_list;
}

map<string, string> updateContact(map<string, string> contact_list, string name) {
    if (contact_list.find(name) == contact_list.end()) {
        cout << "Sorry, contact not found.\n";
        return contact_list;
    }
    else {
        cout << "Please update contact's phone number:\n";
        cin >> contact_list[name];
        cout << name << " updated!\n";
        return contact_list;
    }
}

map<string, string> removeContact(map<string, string> contact_list, string name) {
    if (contact_list.find(name) == contact_list.end()) {
        cout << "Sorry, contact not found.\n";
        return contact_list;
    }
    else {
        contact_list.erase(name);
        cout << name << " removed from contacts.\n";
        return contact_list;
    }
}

bool quitApplication() {
    return false;
}