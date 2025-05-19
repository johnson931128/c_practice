#include <iostream>
using namespace std;

// 定義節點結構
struct Node
{
    int data;   // 節點資料
    Node *next; // 指向下一個節點
};

// 全域變數，表示堆疊的頂部
Node *topNode = nullptr;

// push 操作
void push(int value)
{
    Node *newNode = new Node(); // 創建新節點
    newNode->data = value;      // 設定數據
    newNode->next = topNode;    // 新節點指向原頂部
    topNode = newNode;          // 更新頂部為新節點
}

// pop 操作
void pop()
{
    if (topNode == nullptr)
    { // 檢查堆疊是否為空
        cout << "Stack is empty!" << endl;
        return;
    }
    Node *temp = topNode;    // 暫存當前頂部
    topNode = topNode->next; // 更新頂部為下一個節點
    delete temp;             // 刪除原頂部節點
}

// 取得頂部元素
int top()
{
    if (topNode == nullptr)
    { // 檢查堆疊是否為空
        cout << "Stack is empty!" << endl;
        return -1; // 表示堆疊為空
    }
    return topNode->data; // 返回頂部數據
}

// 檢查堆疊是否為空
bool isEmpty()
{
    return topNode == nullptr; // 返回堆疊是否為空
}

int main()
{
    push(10); // 添加元素 10
    push(20); // 添加元素 20
    push(30); // 添加元素 30

    cout << "Top element: " << top() << endl; // 顯示頂部元素

    pop();                                               // 移除頂部元素
    cout << "After pop, top element: " << top() << endl; // 顯示新的頂部元素

    return 0;
}
