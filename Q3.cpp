#include <iostream>
using namespace std;

int Linear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int Binary(int arr[], int n) {
    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted numbers: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    cout << "Missing Number (Linear): " << Linear(arr, n) << endl;
    cout << "Missing Number (Binary Search): " << Binary(arr, n) << endl;
    return 0;
}
