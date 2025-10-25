#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        while (true) {
            vector<int> target(n);
            cin >> target[0];
            if (target[0] == -1) break;
            for (int i = 1; i < n; i++)
                cin >> target[i];

            stack<int> station;  //train c
            int current = 1;     //incoming train
            bool possible = true;

            for (int i = 0; i < n; i++) {
                int desired = target[i];

                while (current <= n && (station.empty() || station.top() != desired)) {
                    station.push(current);
                    current++;
                }

                if (!station.empty() && station.top() == desired) {
                    station.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            cout << (possible ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
