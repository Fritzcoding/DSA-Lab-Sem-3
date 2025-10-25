#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    while (true) {
        cin >> s;
        if (s == "end") break;

        int balance = 0;
        bool valid = true;

        for (char ch : s) {
            if (ch == '(') balance++;
            else if (ch == ')') {
                if (balance == 0) { // no '(' to match
                    valid = false;
                    break;
                }
                balance--;
            }
        }

        if (balance != 0) valid = false;

        if (valid) cout << 1 << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}
