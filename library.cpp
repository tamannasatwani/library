#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d) : title(t), author(a), dueDate(d) {}

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }
};

class Book : public LibraryItem {
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "The book '" << title << "' is checked out.\n";
    }

    void returnItem() override {
        cout << "The book '" << title << "' has been returned.\n";
    }

    void displayDetails() const override {
        cout << "Book Title: " << title << "\nAuthor: " << author << "\nDue Date: " << dueDate << "\n";
    }
};

class DVD : public LibraryItem {
public:
    DVD(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "The DVD '" << title << "' is checked out.\n";
    }

    void returnItem() override {
        cout << "The DVD '" << title << "' has been returned.\n";
    }

    void displayDetails() const override {
        cout << "DVD Title: " << title << "\nDirector: " << author << "\nDue Date: " << dueDate << "\n";
    }
};


class Magazine : public LibraryItem {
public:
    Magazine(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "The magazine '" << title << "' is checked out.\n";
    }

    void returnItem() override {
        cout << "The magazine '" << title << "' has been returned.\n";
    }

    void displayDetails() const override {
        cout << "Magazine Title: " << title << "\nEditor: " << author << "\nDue Date: " << dueDate << "\n";
    }
};

class LibrarySystem {
private:
    vector<LibraryItem*> items;  

public:
    void addItem(LibraryItem* item) {
        items.push_back(item);  
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "No items in the library.\n";
            return;
        }
        cout << "\nLibrary Items:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            items[i]->displayDetails();  
        }
    }

    void checkOutItem(int index) {
        if (index < 0 || index >= items.size()) {
            cout << "Invalid index.\n";
            return;
        }
        items[index]->checkOut();  
    }

    void returnItem(int index) {
        if (index < 0 || index >= items.size()) {
            cout << "Invalid index.\n";
            return;
        }
        items[index]->returnItem();  
    }

    ~LibrarySystem() {
        for (size_t i = 0; i < items.size(); ++i) {
            delete items[i];
        }
    }
};

int main() {
    LibrarySystem library;

    
    library.addItem(new Book("The Great Gatsby", "F. Scott Fitzgerald", "2024-01-15"));
    library.addItem(new DVD("Inception", "Christopher Nolan", "2024-01-22"));
    library.addItem(new Magazine("National Geographic", "Various Authors", "2024-02-01"));

    int choice;
    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Display all items\n";
        cout << "2. Check out item\n";
        cout << "3. Return item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.displayItems();
            break;
        case 2:
            {
                int index;
                cout << "Enter index of item to check out: ";
                cin >> index;
                library.checkOutItem(index);
            }
            break;
        case 3:
            {
                int index;
                cout << "Enter index of item to return: ";
                cin >> index;
                library.returnItem(index);
            }
            break;
        case 4:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
