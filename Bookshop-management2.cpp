#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books

struct Book
{
    string title;
    string author;
    int year;
};

Book books[MAX_BOOKS];
int bookCount = 0; // Number of books in the inventory

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "Maximum number of books reached. Cannot add more books." << endl;
        return;
    }

    Book book;
    cout << "Enter the title of the book: ";
    getline(cin, book.title);
    cout << "Enter the author of the book: ";
    getline(cin, book.author);
    cout << "Enter the year of publication: ";
    cin >> book.year;
    cin.ignore(); // Clear the input buffer

    books[bookCount] = book;
    bookCount++;

    cout << "Book added successfully!" << endl;
}

void displayBooks()
{
    if (bookCount == 0)
    {
        cout << "No books in the inventory." << endl;
        return;
    }

    cout << "----- Book Inventory -----" << endl;
    for (int i = 0; i < bookCount; i++)
    {
        const Book &book = books[i];
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Year: " << book.year << endl;
        cout << "--------------------------" << endl;
    }
}

void searchBook()
{
    string searchTerm;
    cout << "Enter the title or author to search: ";
    getline(cin, searchTerm);

    bool found = false;

    cout << "----- Search Results -----" << endl;
    for (int i = 0; i < bookCount; i++)
    {
        const Book &book = books[i];
        if (book.title.find(searchTerm) != string::npos || book.author.find(searchTerm) != string::npos)
        {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Year: " << book.year << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No books found matching the search term." << endl;
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "------ Bookshop Management ------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice)
        {
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
