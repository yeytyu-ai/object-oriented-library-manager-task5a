#include "library_manager.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            int id, year;
            string title, author, category;

            cout << "Enter Book ID: ";
            if (!(cin >> id)) {
                cout << "Invalid Book ID.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Category: ";
            getline(cin, category);

            cout << "Enter Year: ";
            if (!(cin >> year)) {
                cout << "Invalid year.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (title.empty() || author.empty() ||
                category.empty() || year <= 0) {
                cout << "Invalid book details.\n";
                continue;
            }

            library.addBook(Book(id, title, author, category, year));
        }
        else if (choice == 2) {
            library.displayBooks();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to search: ";

            if (cin >> id)
                library.searchBook(id);
            else {
                cout << "Invalid ID.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 4) {
            int id, year;
            string title, author, category;

            cout << "Enter Book ID to update: ";
            if (!(cin >> id)) {
                cout << "Invalid ID.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new Title: ";
            getline(cin, title);

            cout << "Enter new Author: ";
            getline(cin, author);

            cout << "Enter new Category: ";
            getline(cin, category);

            cout << "Enter new Year: ";
            if (!(cin >> year)) {
                cout << "Invalid year.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (title.empty() || author.empty() ||
                category.empty() || year <= 0) {
                cout << "Invalid book details.\n";
                continue;
            }

            library.updateBook(id, title, author, category, year);
        }
        else if (choice == 5) {
            int id;
            cout << "Enter Book ID to borrow: ";

            if (cin >> id)
                library.borrowBook(id);
            else {
                cout << "Invalid ID.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 6) {
            int id;
            cout << "Enter Book ID to return: ";

            if (cin >> id)
                library.returnBook(id);
            else {
                cout << "Invalid ID.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 7) {
            cout << "Thank you for using the Library Manager!\n";
            break;
        }
        else {
            cout << "Invalid choice. Select 1 to 7.\n";
        }
    }

    return 0;
}
