#include <iostream>
using namespace std;
class MinStack {
private:
    static const int MAX_SIZE = 10000;
    int stack[MAX_SIZE];
    int minStack[MAX_SIZE];
    int topIndex;
    int minTopIndex;

public:
    MinStack() : topIndex(-1), minTopIndex(-1) {
	
	}

    void push(int val) {
        if (topIndex == MAX_SIZE - 1) {
            cout<< "Stack overflow!" <<endl;
            return;
        }

        stack[++topIndex] = val;
        if (minTopIndex == -1 || val <= minStack[minTopIndex]) {
            minStack[++minTopIndex] = val;
        }
    }

    void pop() {
        if (topIndex == -1) {
            cout<< "Stack underflow!" <<endl;
            return;
        }

        if (stack[topIndex] == minStack[minTopIndex]) {
            minTopIndex--;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout<< "Stack is empty!" <<endl;
            return -1;
        }
        return stack[topIndex];
    }

    int getMin() {
        if (minTopIndex == -1) {
            cout << "Stack is empty!" <<endl;
            return -1;
        }
        return minStack[minTopIndex];
    }
};

int main() {
    MinStack obj;
    obj.push(5);
    obj.push(2);
    obj.push(7);
    cout << obj.getMin() << endl;  // Output: 2
    obj.pop();
    cout << obj.top() <<endl;     // Output: 2
    cout << obj.getMin() <<endl;  // Output: 2

    return 0;
}