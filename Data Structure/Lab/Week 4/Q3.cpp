#include <iostream>
#include <string>
using namespace std;

int main() {
    string P, Q, R;

    getline(cin, P);
    getline(cin, Q);
    getline(cin, R);

    int pos = 0;
    while ((pos = P.find(Q, pos)) != string::npos) { //string::npos means not found
        P.replace(pos, Q.length(), R);
        pos += R.length(); // maju buat cri kesamaan selanjutnya
    }

    cout << P << endl;
}