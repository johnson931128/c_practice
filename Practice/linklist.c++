#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

struct Stack
{
    Node *top;
    Stack() : top(nullptr) {}

    // when programing is shut down, ~Stack() will automatically operate
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        // newNode 的 next 的位置等於 top 的位置
        top = newNode;
        // 將 top 更新為 newNode 的位置
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return -1;
        }

        Node *temp = top;
        // temp的位置設為top的位置
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void printStack() const
    {
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStack(); // 顯示 30 20 10

    cout << "Top element is: " << stack.peek() << endl; // 顯示 30

    stack.pop();
    stack.printStack(); // 顯示 20 10

    cout << "Top element is: " << stack.peek() << endl; // 顯示 20

    stack.pop();
    stack.pop();
    stack.pop(); // 堆疊為空，顯示 "Stack is empty!"

    return 0;
}
