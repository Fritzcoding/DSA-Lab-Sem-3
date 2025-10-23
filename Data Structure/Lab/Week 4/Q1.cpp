#include <bits/stdc++.h>
using namespace std;

#define MAX_TERMS 100

typedef struct {
    float coef;
    int expon;
} polynomial;

void printPoly(vector<polynomial> &poly) {
    bool first = true;
    for (auto &term : poly) {
        if (fabs(term.coef) < 0) continue; // neglect 0 koefisien
        if (!first) {
            if (term.coef >= 0) cout << "+";
        }
        cout << fixed << setprecision(2) << term.coef;
        if (term.expon > 0) {
            cout << "x";
            if (term.expon > 1) cout << "^" << term.expon;
        }
        first = false;
    }
    cout << "\n";
}

void pmult(vector<polynomial> &a, vector<polynomial> &b, vector<polynomial> &c) {
    map<int, float, greater<int>> mp; // dictionary sort dr biggest koefisien ke kecil
    for (auto &pa : a) {
        for (auto &pb : b) {
            mp[pa.expon + pb.expon] += pa.coef * pb.coef;
        }
    }
    for (auto &p : mp) {
        if (fabs(p.second) > 0) {
            c.push_back({p.second, p.first});
        }
    }
}

int main() {
    int na, nb;
    cin >> na;
    vector<polynomial> A(na);
    for (int i = 0; i < na; i++) cin >> A[i].coef >> A[i].expon;
    cin >> nb;
    vector<polynomial> B(nb);
    for (int i = 0; i < nb; i++) cin >> B[i].coef >> B[i].expon;

    sort(A.begin(), A.end(), [](polynomial a, polynomial b){ return a.expon > b.expon; });
    sort(B.begin(), B.end(), [](polynomial a, polynomial b){ return a.expon > b.expon; });

    printPoly(A);
    printPoly(B);

    vector<polynomial> C;
    pmult(A, B, C);

    printPoly(C);

    return 0;
}
