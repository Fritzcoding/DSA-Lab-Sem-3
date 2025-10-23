#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int precedence(const string &op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

bool isOperator(const string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

string infixToPostfix(const string &expr) {
    stringstream ss(expr);
    string token;
    stack<string> opStack;
    vector<string> output;

    while (ss >> token) {
        if (isdigit(token[0])) {
            output.push_back(token);
        }
        else if (token == "(") {
            opStack.push(token);
        }
        //klo rparen pop until lparen
        else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); //pop '('
        }
        else if (isOperator(token)) {
            while (!opStack.empty() && isOperator(opStack.top()) &&
                   precedence(opStack.top()) >= precedence(token)) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    //pop remaining operators
    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }

    string result;
    for (size_t i = 0; i < output.size(); ++i) {
        result += output[i];
        if (i != output.size() - 1) result += " ";
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string expr;
        getline(cin, expr);
        cout << infixToPostfix(expr) << "\n";
    }

    return 0;
}
