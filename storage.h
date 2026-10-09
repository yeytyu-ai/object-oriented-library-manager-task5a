#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "library_manager.h"

class Storage {
public:
    static std::vector<Book> loadBooks(const std::string& filename);

    static bool saveBooks(
        const std::string& filename,
        const std::vector<Book>& books
    );
};

#endif
