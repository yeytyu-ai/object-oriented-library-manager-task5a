#include "library_manager.h"
#include <iostream>

using namespace std;

Book::Book(int id, const string& t, const string& a,
           const string& c, int y)
    : bookId(id), title(t), author(a),
      category(c), year(y), available(true) {}

int Book::getId() const {
    return bookId;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getCategory() const {
    return category;
}

int Book::getYear() const {
    return year;
}

bool Book::isAvailable() const {
    return available;
}

void Book::borrowBook() {
    if (available) {
        available = false;
        cout << "Book borrowed successfully.\n";
    } else {
        cout << "Book is already borrowed.\n";
    }
}

void Book::returnBook() {
    if (!available) {
        available = true;
        cout << "Book returned successfully.\n";
    } else {
        cout << "Book is already available.\n";
    }
}

void Book::display() const {
    cout << "\nBook ID: " << bookId
         << "\nTitle: " << title
         << "\nAuthor: " << author
         << "\nCategory: " << category
         << "\nYear: " << year
         << "\nStatus: "
         << (available ? "Available" : "Borrowed")
         << "\n-------------------------\n";
}

bool Library::addBook(const Book& book) {
    for (const Book& existing : books) {
        if (existing.getId() == book.getId()) {
            cout << "Error: Duplicate book ID.\n";
            return false;
        }
    }

    books.push_back(book);
    cout << "Book added successfully.\n";
    return true;
}

void Library::displayBooks() const {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    for (const Book& book : books) {
        book.display();
    }
}

void Library::searchBook(int id) const {
    for (const Book& book : books) {
        if (book.getId() == id) {
            book.display();
            return;
        }
    }

    cout << "Book not found.\n";
}

bool Library::updateBook(int id, const string& t,
                         const string& a,
                         const string& c, int y) {
    for (Book& book : books) {
        if (book.getId() == id) {
            book = Book(id, t, a, c, y);
            cout << "Book updated successfully.\n";
            return true;
        }
    }

    cout << "Book not found.\n";
    return false;
}

void Library::borrowBook(int id) {
    for (Book& book : books) {
        if (book.getId() == id) {
            book.borrowBook();
            return;
        }
    }

    cout << "Book not found.\n";
}

void Library::returnBook(int id) {
    for (Book& book : books) {
        if (book.getId() == id) {
            book.returnBook();
            return;
        }
    }

    cout << "Book not found.\n";
}

vector<Book> Library::getBooks() const {
    return books;
}
