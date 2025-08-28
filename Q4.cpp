#include <iostream>
#include <string>
using namespace std;

void concatenate() {
    string s1, s2;
    cout << "Enter first string: ";
    cin.ignore();
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);
    cout << "Concatenated string: " << s1 + s2 << endl;
}

void reversestring() {
    string s;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);
    cout << "Reversed string: ";
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
}

void deletevowels() {
    string s, result = "";
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
}

void sortstrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i+1 << ": ";
        getline(cin, arr[i]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

void UpperToLower() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }
    cout << "Lowercase character: " << c << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Concatenate strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: concatenate(); break;
            case 2: reversestring(); break;
            case 3: deletevowels(); break;
            case 4: sortstrings(); break;
            case 5: UpperToLower(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
