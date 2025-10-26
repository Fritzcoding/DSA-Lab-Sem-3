#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

bool trainproblem(string input, int n){
    bool possible = true;
    int target[n], i = 0, k = n;
    stringstream ss(input);
    while(n--){
        ss >> target[i];
        i++;
    }
    queue<int> que;
    for(int i = 1; i <= k; i++) {
        que.push(i);
    }
    stack<int> stackk;
    if(stackk.empty()){
        stackk.push(que.front());
        que.pop();
    }
    for(i = 0; i<k; i++){
        if(stackk.empty()){
            stackk.push(que.front());
            que.pop();
        }
        while(target[i] != stackk.top() && possible != false){
            if(que.empty()){
                possible = false;
            }
            stackk.push(que.front());
            que.pop();
        }
        stackk.pop();
    }
    
    return possible;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string input;
    while(getline(cin, input)){
        if(input[0] == '-') break;
        cout << (trainproblem(input, n)? "YES" : "NO") << endl;;
    }
}