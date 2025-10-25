#include <iostream>
using namespace std;

typedef struct{
    int row; 
    int col;
    int value;
} term;

void fast_transpose(term a[], term b[]){
    int rows[100], startingpos[100] = {0};

    b[0].row = a[0].row;
    b[0].col = a[0].col;
    b[0].value = a[0].value;

    for(int i = 1; i <= a[0].value; i++){
        rows[a[i].col]++;
    }

    startingpos[0] = 1;

    for(int i = 1; i< a[0].col; i++){
        startingpos[i] = startingpos[i-1] + rows[i-1];
    }

    for(int i = 1; i <= a[0].value; i++){
        int x = startingpos[a[i].col]++;
        b[x].row = a[i].col;
        b[x].col = a[i].row;
        b[x].value = a[i].value;

    }
}

int main(){
    term a[MAX_TERMS], b[MAX_TERMS];
    int numRows, numCols, numTerms;
    cout << "Enter number of rows and columes: ";
    cin >> numRows >> numCols;
    cout << "enter non-zero elements: ";
    cin >> numTerms;
    a[0].row = numRows;
    a[0].col = numCols;
    a[0].value = numTerms;
    
    cout << "enter the input: ";
    for (int i = 1; i <= numTerms; i++){
        cin >> a[i].row >> a[i].col >> a[i].value;
    }
    fast_transpose(a, b);
    cout <<"Transposed Matrix: \n";
    for (int i = 1; i <= b[0].value; i++){  
        cout <<  b[i].row <<  b[i].col << b[i].value << endl;
    }
}