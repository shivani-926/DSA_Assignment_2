#include <iostream>
using namespace std;

void totriplet(int rows, int cols, int mat[10][10], int triplet[100][3], int &nonzero) {
    nonzero = 0;
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                nonzero++;
                triplet[nonzero][0] = i;
                triplet[nonzero][1] = j;
                triplet[nonzero][2] = mat[i][j];
            }
        }
    }
    triplet[0][2] = nonzero;
}

void printtriplet(int triplet[100][3]) {
    int nonzero = triplet[0][2];
    for (int i = 0; i <= nonzero; i++) {
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }
}

void transposetriplet(int triplet[100][3], int result[100][3]) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonzero = triplet[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = nonzero;
    int k = 1;
    for (int i = 1; i <= nonzero; i++) {
        result[k][0] = triplet[i][1];
        result[k][1] = triplet[i][0];
        result[k][2] = triplet[i][2];
        k++;
    }
    for (int i = 1; i <= nonzero - 1; i++) {
        for (int j = i + 1; j <= nonzero; j++) {
            if (result[i][0] > result[j][0] || (result[i][0] == result[j][0] && result[i][1] > result[j][1])) {
                int t0 = result[i][0];
                int t1 = result[i][1];
                int t2 = result[i][2];
                result[i][0] = result[j][0];
                result[i][1] = result[j][1];
                result[i][2] = result[j][2];
                result[j][0] = t0;
                result[j][1] = t1;
                result[j][2] = t2;
            }
        }
    }
}

void addtriplet(int a[100][3], int b[100][3], int result[100][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n";
        return;
    }
    int i = 1, j = 1, k = 1;
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
        } else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++;
        }
        k++;
    }
    while (i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }
    result[0][2] = k - 1;
}

void multiplytriplet(int a[100][3], int b[100][3], int result[100][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }
    int m = a[0][0], n = a[0][1], p = b[0][1];
    int temp[10][10] = {0};
    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }
    int nonzero = 0;
    result[0][0] = m;
    result[0][1] = p;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            if (temp[i][j] != 0) {
                nonzero++;
                result[nonzero][0] = i;
                result[nonzero][1] = j;
                result[nonzero][2] = temp[i][j];
            }
        }
    }
    result[0][2] = nonzero;
}

int main() {
    int rows, cols;
    cout << "Enter size of first matrix: ";
    cin >> rows >> cols;
    int mat1[10][10];
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat1[i][j];
        }
    }
    int triplet1[100][3], nz1;
    totriplet(rows, cols, mat1, triplet1, nz1);
    cout << "\nTriplet form of first matrix:\n";
    printtriplet(triplet1);
    int transpose1[100][3];
    transposetriplet(triplet1, transpose1);
    cout << "\nTranspose (Triplet form):\n";
    printtriplet(transpose1);
    int rows2, cols2;
    cout << "\nEnter size of second matrix: ";
    cin >> rows2 >> cols2;
    int mat2[10][10];
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cin >> mat2[i][j];
        }
    }
    int triplet2[100][3], nz2;
    totriplet(rows2, cols2, mat2, triplet2, nz2);
    cout << "\nTriplet form of second matrix:\n";
    printtriplet(triplet2);
    int sum[100][3];
    addtriplet(triplet1, triplet2, sum);
    cout << "\nAddition (Triplet form):\n";
    printtriplet(sum);
    int product[100][3];
    multiplytriplet(triplet1, triplet2, product);
    cout << "\nMultiplication (Triplet form):\n";
    printtriplet(product);
    return 0;
}
