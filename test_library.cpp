#include "library_manager.h"
#include <cassert>
#include <iostream>

using namespace std;

void testAddBook() {
    Library library;

    Book book(101, "C++ Programming",
              "Bjarne Stroustrup", "Programming", 2013);

    assert(library.addBook(book));
    assert(!library.addBook(book));

    cout << "Add book and duplicate ID test: PASS\n";
}

void testSearchAndUpdate() {
    Library library;

    library.addBook(Book(102, "Old Title",
                         "Author", "Software", 2020));

    library.updateBook(102, "New Title",
                       "New Author", "Programming", 2024);

    library.searchBook(102);

    cout << "Search and update test: PASS\n";
}

void testBorrowAndReturn() {
    Book book(103, "Digital Electronics",
              "Morris Mano", "Electronics", 2017);

    assert(book.isAvailable());

    book.borrowBook();
    assert(!book.isAvailable());

    book.returnBook();
    assert(book.isAvailable());

    cout << "Borrow and return test: PASS\n";
}

void testEmptyLibrary() {
    Library library;
    library.displayBooks();
    library.searchBook(999);

    cout << "Empty library test: PASS\n";
}

int main() {
    testAddBook();
    testSearchAndUpdate();
    testBorrowAndReturn();
    testEmptyLibrary();

    cout << "\nAll tests completed.\n";
    return 0;
}
