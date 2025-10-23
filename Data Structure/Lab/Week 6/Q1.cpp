#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class circular_queue{
private:
    int *arr;
    int front;
    int rear;
    int maxsize;

public:
    circular_queue(int size){
        maxsize = size;
        arr = new int[maxsize];
        front = 0;
        rear = 0;
    }
    
    ~circular_queue() {
        delete[] arr;
    }
    
    bool isFull(){
        return (rear + 1) % maxsize == front;
    }
    
    bool isEmpty(){
        return front == rear;
    }
    
    void enqueue(int number){
        if(isFull()){
            cout << "FULL" << endl;
            return;
        }
        rear = (rear + 1) % maxsize;
        arr[rear] = number;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout << "EMPTY" << endl;
        }
        else{
            front = (front + 1) % maxsize;
            cout << arr[front] << endl;    
        }
    }
};

int main(){
    int maxsize, operation, value;
    cin >> maxsize;
    circular_queue cq(maxsize);
    cin.ignore();
    string s;
    while(getline(cin, s)){
        if(s == "-1") break;
        stringstream ss(s);
        ss >> operation;
        if(operation == 1){
            ss >> value;
            cq.enqueue(value);
        }
        else{
            cq.dequeue();
        }
    }
    return 0;
}