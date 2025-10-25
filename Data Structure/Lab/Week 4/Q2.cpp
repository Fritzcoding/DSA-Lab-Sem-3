#include <iostream>
using namespace std;

struct term {
    int row;
    int col;
    int value;
};

void transpose(term a[], term b[]) {
    int n = a[0].value;   // number of nonzero terms
    b[0].row = a[0].col;  // swap rows and cols
    b[0].col = a[0].row;
    b[0].value = n;

    int currentb = 1;
    if (n > 0) {
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j].col == i) {         // belongs to this column
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

int main() {
    int rows, cols, num;
    cin >> rows >> cols >> num;

    term a[1000];
    term b[1000];

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = num;

    for (int i = 1; i <= num; i++) {
        cin >> a[i].row >> a[i].col >> a[i].value;
    }

    transpose(a, b);

    for (int i = 0; i <= num; i++) {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << "\n";
    }
}
