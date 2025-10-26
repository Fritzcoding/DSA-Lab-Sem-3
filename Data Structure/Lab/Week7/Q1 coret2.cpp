#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int precendence(string& chara){
    if(chara == "*" || chara == "/") return 2;
    if(chara == "+" || chara == "-") return 1;
    return 0;
}

bool isOperator(string op){
    if(op == "*" || op == "/" || op == "+" || op == "-") return true;
    return false;
}

string infixtopostfix(string input){
    stringstream ss(input);
    string token;
    stack<string> opstack;
    vector<string> output;
    while(ss >> token){
        if(isdigit(token[0])){
            output.push_back(token);
        }
        else if(token == "("){
            opstack.push("(");
        }
        else if(token == ")"){
            while(!opstack.empty() && opstack.top() != "("){
                output.push_back(opstack.top());
                opstack.pop();
            }
            if(!opstack.empty()) opstack.pop();
        }
        else if(isOperator(token)){
            while(!opstack.empty() && isOperator(opstack.top()) && precendence(opstack.top()) >= precendence(token)){
                output.push_back(opstack.top());
                opstack.pop();
            }
            opstack.push(token);
        }
    }
    
    while(!opstack.empty()){
        output.push_back(opstack.top());
        opstack.pop();
    }
    
    string result;
    
    for(auto i = output.begin(); i != output.end(); i++){
        result += *i;
        if(std::next(i) != output.end()){
            result += " ";
        }
    }
    
    return result;
}

int main()
{
    int n;
    
    cin >> n;
    cin.ignore();
    while(n--){
        string input;
        getline(cin, input);
        cout << infixtopostfix(input) << endl;
    }
}