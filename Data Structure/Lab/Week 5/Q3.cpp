#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    float value;
    float weight;
};

int main() {
    stack<Item> backpack;
    stack<Item> ground;
    float totalWeight = 0.0f;
    float totalValue = 0.0f;

    string line;
    while (true) {
        getline(cin, line);
        if (line == "end" || line.empty()) break;

        Item newItem;
        char nameBuffer[50];
        sscanf(line.c_str(), "%49s %f %f", nameBuffer, &newItem.value, &newItem.weight);
        newItem.name = nameBuffer;

        if (totalWeight + newItem.weight <= 20.0f) {
            backpack.push(newItem);
            totalWeight += newItem.weight;
            totalValue += newItem.value;
        } else {
            bool replaced = false;

            while (!backpack.empty()) {
                Item topItem = backpack.top();

                if (topItem.value < newItem.value &&
                    totalWeight - topItem.weight + newItem.weight <= 20.0f) {
                    backpack.pop();
                    totalWeight = totalWeight - topItem.weight + newItem.weight;
                    totalValue = totalValue - topItem.value + newItem.value;
                    backpack.push(newItem);
                    replaced = true;
                    break;
                } else {
                    ground.push(topItem);
                    backpack.pop();
                    totalWeight -= topItem.weight;
                    totalValue -= topItem.value;
                }
            }
            stack<Item> temp;
            while (!ground.empty()) {
                temp.push(ground.top());
                ground.pop();
            }
            while (!temp.empty()) {
                backpack.push(temp.top());
                totalWeight += temp.top().weight;
                totalValue += temp.top().value;
                temp.pop();
            }

            if (!replaced && totalWeight + newItem.weight <= 20.0f) {
                backpack.push(newItem);
                totalWeight += newItem.weight;
                totalValue += newItem.value;
            }
        }
    }

    stack<Item> printStack;
    while (!backpack.empty()) {
        printStack.push(backpack.top());
        backpack.pop();
    }

    cout << fixed << setprecision(1);
    while (!printStack.empty()) {
        cout << printStack.top().name << " " << printStack.top().value << " " << printStack.top().weight << endl;
        printStack.pop();
    }

    cout << "weight:" << totalWeight << endl;
    cout << "value:" << totalValue << endl;

    return 0;
}
