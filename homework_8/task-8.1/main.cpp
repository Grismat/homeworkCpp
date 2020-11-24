#include <iostream>
#include "Dictionary.h"

void printMenu() {
    std::cout << "\nEnter 1 to add value by the key to the dictionary\n"
         << "Enter 2 to get value by the key from the dictionary\n"
         << "Enter 3 to check if the key is in the dictionary\n"
         << "Enter 4 to delete value by the key from the dictionary\n"
         << "-> ";
}

void handleInput(char const digit, Dictionary<int, std::string> & dictionary) {
    using namespace std;

    int key;
    std::string value;

    switch (digit) {
    case '1':
        cout << "Enter key and value to add in format \"key value\"\n-> ";
        cin >> key >> value;
        dictionary.addElementByKey(key, value);
        break;

    case '2':
        cout << "Enter a key to get a value with this key in format \"key\"\n-> ";
        cin >> key;
        if (dictionary.isElementStored(key)) {
            cout << dictionary.getElementByKey(key) << '\n';
        }
        else {
            cout << "There's no element with this key\n";
        }
        break;

    case '3':
        cout << "Enter a key to check if it is in array in format \"key\"\n-> ";
        cin >> key;
        if (dictionary.isElementStored(key)) {
            cout << "Element with this key is in the dictionary\n";
        }
        else {
            cout << "There's no element with this key\n";
        }
        break;

    case '4':
        cout << "Enter a key delete value in format \"key\"\n-> ";
        cin >> key;
        if (dictionary.isElementStored(key)) {
            dictionary.deleteElementByKey(key);
            cout << "Element with this key successfully deleted\n";
        }
        else {
            cout << "There's no element with this key\n";
        }
        break;
    }
}

int main() {
    Dictionary<int, std::string> dictionary;
    char command;

    while (true) {
        printMenu();
        std::cin >> command;
        handleInput(command, dictionary);
    }

    return 0;
}
