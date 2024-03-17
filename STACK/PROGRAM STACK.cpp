#include <iostream>
using namespace std;

class Stack {
public:
    int size = 0;
    int top = -1;
    char *items;

    Stack(int stackSize) { //constructor
        size = stackSize;
        items = new char[size];
    }

    ~Stack() { // Destructor to free memory
        delete[] items;
    }

    void push(char item) {
        if (top == size - 1) { //jika stack penuh
            cerr << "ERROR: Stack overflow, stack is full" << endl;
            exit(1); // Terminate the program on stack overflow
        } else {
            top++; //top = top + 1
            items[top] = item;
        }
    }

    char pop() {
        if (top == -1) { //jika stack kosong
            cerr << "ERROR: Stack underflow, stack is empty" << endl;
            exit(1); // Terminate the program on stack underflow
        } else {
            char item = items[top];
            top--;
            return item;
        }
    }
};

int main(int argc, char** argv) {
    Stack kantong1(5);

    kantong1.push('A');
    kantong1.push('B');
    kantong1.push('C');
    kantong1.push('D');
    kantong1.push('Z');
    kantong1.push('R');

    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl; // This will cause stack underflow
    return 0;
}
