#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    stack<int> st;
    stringstream ss(line);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            //pop top 2 operands
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;
            else if (token == "%") result = a % b;

            st.push(result);
        } 
        else {
            //operand (integer)
            st.push(stoi(token));
        }
    }

    cout << st.top() << endl;
    return 0;
}
