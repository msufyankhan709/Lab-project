#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

vector<Book> books;

void addBook() {
    Book book;
    cout << "Enter the title of the book: ";
    getline(cin, book.title);
    cout << "Enter the author of the book: ";
    getline(cin, book.author);
    cout << "Enter the year of publication: ";
    cin >> book.year;
    cin.ignore();  // Clear the input buffer
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books in the inventory." << endl;
        return;
    }

    cout << "----- Book Inventory -----" << endl;
    for (const auto& book : books) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Year: " << book.year << endl;
        cout << "--------------------------" << endl;
    }
}

void searchBook() {
    string searchTerm;
    cout << "Enter the title or author to search: ";
    getline(cin, searchTerm);

    vector<Book> searchResults;
    for (const auto& book : books) {
        if (book.title.find(searchTerm) != string::npos || book.author.find(searchTerm) != string::npos) {
            searchResults.push_back(book);
        }
    }

    if (searchResults.empty()) {
        cout << "No books found matching the search term." << endl;
    } else {
        cout << "----- Search Results -----" << endl;
        for (const auto& book : searchResults) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Year: " << book.year << endl;
            cout << "--------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "------ Bookshop Management ------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the input buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}