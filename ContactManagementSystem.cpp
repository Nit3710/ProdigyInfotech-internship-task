#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

void loadContacts() {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        Contact contact;
        while (getline(file, contact.name)) {
            getline(file, contact.phone);
            getline(file, contact.email);
            contacts.push_back(contact);
        }
        file.close();
    }
}

void saveContacts() {
    ofstream file("contacts.txt");
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << endl;
            file << contact.phone << endl;
            file << contact.email << endl;
        }
        file.close();
    }
}

void addContact() {
    Contact contact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "Enter phone number: ";
    getline(cin, contact.phone);
    cout << "Enter email address: ";
    getline(cin, contact.email);
    contacts.push_back(contact);
    saveContacts();
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    } else {
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << "Contact " << i + 1 << ":" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phone << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "---------------------" << endl;
        }
    }
}

void editContact() {
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        Contact& contact = contacts[index - 1];
        cout << "Editing contact " << index << ":" << endl;
        cout << "Enter new name (or press enter to keep current): ";
        cin.ignore();
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            contact.name = newName;
        }
        cout << "Enter new phone number (or press enter to keep current): ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) {
            contact.phone = newPhone;
        }
        cout << "Enter new email address (or press enter to keep current): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) {
            contact.email = newEmail;
        }
        saveContacts();
    } else {
        cout << "Invalid contact number." << endl;
    }
}

void deleteContact() {
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + index - 1);
        saveContacts();
    } else {
        cout << "Invalid contact number." << endl;
    }
}

int main() {
    loadContacts();
    int choice;
    do {
        cout << "Contact Manager" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. View contacts" << endl;
        cout << "3. Edit contact" << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
