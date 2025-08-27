#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements (in sorted order for binary search):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int pos1 = linearsearch(arr, n, key);
    if (pos1 != -1)
        cout << "Linear Search: Element found at index " << pos1 << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    int pos2 = binarysearch(arr, n, key);
    if (pos2 != -1)
        cout << "Binary Search: Element found at index " << pos2 << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
