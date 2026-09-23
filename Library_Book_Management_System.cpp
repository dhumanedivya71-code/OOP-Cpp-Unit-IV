#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    string category;
    bool available;

public:
    Book()
        : available(true) {}

    Book(string i, string t, string a, string c, bool status = true)
        : isbn(i),
          title(t),
          author(a),
          category(c),
          available(status) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getCategory() const {
        return category;
    }

    bool isAvailable() const {
        return available;
    }

    void issueBook() {
        if (available) {
            available = false;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book is already available." << endl;
        }
    }

    void updateBook(string t, string a, string c) {
        title = t;
        author = a;
        category = c;

        cout << "Book details updated successfully." << endl;
    }

    void display() const {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Category: " << category << endl;
        cout << "Availability: "
             << (available ? "Available" : "Issued")
             << endl;
        cout << "-----------------------------------" << endl;
    }

    void saveToFile(ofstream& out) const {
        out << isbn << "|"
            << title << "|"
            << author << "|"
            << category << "|"
            << available << endl;
    }

    bool loadFromFile(const string& line) {
        string status;
        stringstream ss(line);

        if (!getline(ss, isbn, '|'))
            return false;

        if (!getline(ss, title, '|'))
            return false;

        if (!getline(ss, author, '|'))
            return false;

        if (!getline(ss, category, '|'))
            return false;

        if (!getline(ss, status))
            return false;

        available = (status == "1");

        return true;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string isbn;
        string title;
        string author;
        string category;

        cout << "Enter ISBN: ";
        cin >> isbn;
        cin.ignore();

        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter category: ";
        getline(cin, category);

        books.emplace_back(
            isbn,
            title,
            author,
            category
        );

        cout << "Book added successfully." << endl;
    }

    void searchBook() const {
        string isbn;

        cout << "Enter ISBN to search: ";
        cin >> isbn;

        for (const auto& book : books) {
            if (book.getISBN() == isbn) {
                cout << "\nBook Found" << endl;
                cout << "-----------------------------------" << endl;
                book.display();
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void issueBook() {
        string isbn;

        cout << "Enter ISBN to issue: ";
        cin >> isbn;

        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.issueBook();
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void returnBook() {
        string isbn;

        cout << "Enter ISBN to return: ";
        cin >> isbn;

        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                book.returnBook();
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void updateBook() {
        string isbn;

        cout << "Enter ISBN to update: ";
        cin >> isbn;
        cin.ignore();

        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                string title;
                string author;
                string category;

                cout << "Enter new title: ";
                getline(cin, title);

                cout << "Enter new author: ";
                getline(cin, author);

                cout << "Enter new category: ";
                getline(cin, category);

                book.updateBook(
                    title,
                    author,
                    category
                );

                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available." << endl;
            return;
        }

        cout << "\n=== All Books ===" << endl;

        for (const auto& book : books) {
            book.display();
        }
    }

    void availabilityReport() const {
        int availableCount = 0;
        int issuedCount = 0;

        cout << "\n=== Availability Report ===" << endl;

        for (const auto& book : books) {
            if (book.isAvailable()) {
                availableCount++;
            } else {
                issuedCount++;
            }
        }

        cout << "Total Books: "
             << books.size() << endl;

        cout << "Available Books: "
             << availableCount << endl;

        cout << "Issued Books: "
             << issuedCount << endl;
    }

    void saveBooks() const {
        ofstream file("library_books.txt");

        if (!file) {
            cout << "Unable to open file for writing." << endl;
            return;
        }

        for (const auto& book : books) {
            book.saveToFile(file);
        }

        file.close();

        cout << "Library data saved successfully." << endl;
    }

    void loadBooks() {
        ifstream file("library_books.txt");

        if (!file) {
            return;
        }

        books.clear();

        string line;

        while (getline(file, line)) {
            Book book;

            if (book.loadFromFile(line)) {
                books.push_back(book);
            }
        }

        file.close();
    }
};

int main() {
    Library library;

    library.loadBooks();

    int choice;

    do {
        cout << "\n====================================" << endl;
        cout << "     LIBRARY BOOK MANAGEMENT SYSTEM" << endl;
        cout << "====================================" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Update Book" << endl;
        cout << "6. Display All Books" << endl;
        cout << "7. Availability Report" << endl;
        cout << "8. Save Data" << endl;
        cout << "9. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;

        case 2:
            library.searchBook();
            break;

        case 3:
            library.issueBook();
            break;

        case 4:
            library.returnBook();
            break;

        case 5:
            library.updateBook();
            break;

        case 6:
            library.displayAllBooks();
            break;

        case 7:
            library.availabilityReport();
            break;

        case 8:
            library.saveBooks();
            break;

        case 9:
            library.saveBooks();
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
