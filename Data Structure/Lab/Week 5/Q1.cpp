#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Entry {
    int col;
    int val;
};

struct Result {
    int row, col, val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // ignore biar newlinenya ngga msk waktu getline nanti

    unordered_map<int, vector<Entry>> rows;

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        int r, c, v;
        // bikin c-string trus dimskin ke sscanf biar bs pake format
        sscanf(s.c_str(), "(%d:%d)=%d", &r, &c, &v);
        rows[r].push_back({c, v});
    }

    vector<Result> results;
    vector<int> row_keys;
    for (auto &p : rows) row_keys.push_back(p.first);
    sort(row_keys.begin(), row_keys.end());

    // kaliin A * A^T
    for (int i = 0; i < (int)row_keys.size(); ++i) {
        int r1 = row_keys[i];
        for (int j = 0; j < (int)row_keys.size(); ++j) {
            int r2 = row_keys[j];
            int sum = 0;

            // compute perkalian row1 sm row2
            // ide pokoknya itu kalo a kali transposenya,
            // per baris kalo ada kolom yg sama itu bs dikaliin, kalo kolomnya ngga sama berarti itu zero value gbs dikaliin.
            // dan kalo gada ya gabakal di msk in ke results krn itu zero value.

            for (auto &e1 : rows[r1]) { // baris pertama ada value apa aja
                for (auto &e2 : rows[r2]) { // baris kedua ada value apa aja
                    if (e1.col == e2.col) // kalo value nya ada di baris yg sama berarti hasil perkaliannya ngga 0
                        sum += e1.val * e2.val;
                }
            }

            if (sum != 0) {
                results.push_back({r1, r2, sum});
                // if (r1 != r2)
                //     results.push_back({r2, r1, sum});
            }
        }
    }

    sort(results.begin(), results.end(), [](const Result &a, const Result &b) {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    for (auto &r : results)
        cout << r.row << " " << r.col << " " << r.val << "\n";

    return 0;
}
