#include "storage.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Book> Storage::loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "No existing file found. Starting with empty library.\n";
        return books;
    }

    string line;
    getline(file, line); // Skip CSV header

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string idText, title, author, category, yearText;
        string status;

        if (!getline(ss, idText, ',') ||
            !getline(ss, title, ',') ||
            !getline(ss, author, ',') ||
            !getline(ss, category, ',') ||
            !getline(ss, yearText, ',') ||
            !getline(ss, status, ',')) {
            cout << "Warning: Malformed CSV row skipped.\n";
            continue;
        }

        try {
            size_t idPos, yearPos;
            int id = stoi(idText, &idPos);
            int year = stoi(yearText, &yearPos);

            if (idPos != idText.size() ||
                yearPos != yearText.size() ||
                id <= 0 || year <= 0) {
                cout << "Warning: Invalid CSV values skipped.\n";
                continue;
            }

            bool duplicate = false;
            for (const Book& existing : books) {
                if (existing.getId() == id) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                cout << "Warning: Duplicate book ID skipped.\n";
                continue;
            }

            Book book(id, title, author, category, year);

            if (status == "borrowed") {
                book.borrowBook();
            } else if (status != "available") {
                cout << "Warning: Invalid status; row skipped.\n";
                continue;
            }

            books.push_back(book);
        } catch (...) {
            cout << "Warning: Malformed CSV row skipped.\n";
        }
    }

    return books;
}

bool Storage::saveBooks(const string& filename,
                        const vector<Book>& books) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not save CSV file.\n";
        return false;
    }

    file << "book_id,title,author,category,year,status\n";

    for (const Book& book : books) {
        file << book.getId() << ","
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getCategory() << ","
             << book.getYear() << ","
             << (book.isAvailable() ? "available" : "borrowed")
             << '\n';
    }

    return file.good();
}
