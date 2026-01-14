#include <iostream>
#include <string>
using namespace std;

struct Book {
    string name;
    string author;
    int id;
    bool isIssued;
};

Book library[100];  
int totalBooks = 0;

void addBook() {
    cout << "\nEnter Book Name: ";
    cin.ignore();
    getline(cin, library[totalBooks].name);

    cout << "Enter Author Name: ";
    getline(cin, library[totalBooks].author);

    cout << "Enter Book ID: ";
    cin >> library[totalBooks].id;

    library[totalBooks].isIssued = false;
    totalBooks++;

    cout << "\nBook Added Successfully!\n";
}

void searchBook() {
    cin.ignore();
    string key;
    cout << "\nEnter Book Name to Search: ";
    getline(cin, key);

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].name == key) {
            cout << "\nBook Found!\n";
            cout << "Name: " << library[i].name << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "ID: " << library[i].id << endl;
            cout << "Status: " << (library[i].isIssued ? "Issued" : "Available") << endl;
            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void issueBook() {
    int bid;
    cout << "\nEnter Book ID to Issue: ";
    cin >> bid;

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == bid) {
            if (library[i].isIssued) {
                cout << "\nBook is already issued.\n";
            } else {
                library[i].isIssued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void returnBook() {
    int bid;
    cout << "\nEnter Book ID to Return: ";
    cin >> bid;

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == bid) {
            if (!library[i].isIssued) {
                cout << "\nBook was not issued.\n";
            } else {
                library[i].isIssued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void displayBooks() {
    if (totalBooks == 0) {
        cout << "\nNo Books in Library.\n";
        return;
    }

    cout << "\n=== Library Book List ===\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << "\nBook " << i + 1 << endl;
        cout << "Name   : " << library[i].name << endl;
        cout << "Author : " << library[i].author << endl;
        cout << "ID     : " << library[i].id << endl;
        cout << "Status : " << (library[i].isIssued ? "Issued" : "Available") << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== MINI LIBRARY MANAGEMENT SYSTEM ====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: searchBook(); break;
        case 3: issueBook(); break;
        case 4: returnBook(); break;
        case 5: displayBooks(); break;
        case 6: return 0;
        default: cout << "\nInvalid Choice.\n";
        }
    }
}
