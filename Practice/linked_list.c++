#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = nullptr;

void push(int val)
{
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = head; // 新節點指向舊 head
    head = newnode;       // 更新 head 為新節點
}

void pop()
{
    if (head == nullptr)
    {
        cout << "堆疊為空，無法執行 pop 操作。" << endl;
        return;
    }

    Node *temp = head; // 暫存目前的 head
    head = head->next; // 將 head 指向下一個節點
    cout << "彈出的值為: " << temp->value << endl;
    delete temp; // 釋放原 head 節點
}

void printStack()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 測試
int main()
{
    push(10);
    push(20);
    push(30);

    cout << "目前的堆疊內容: ";
    printStack(); // 預期輸出: 30 -> 20 -> 10 -> NULL

    pop(); // 預期彈出: 30
    cout << "執行 pop 後的堆疊內容: ";
    printStack(); // 預期輸出: 20 -> 10 -> NULL

    pop(); // 預期彈出: 20
    pop(); // 預期彈出: 10
    pop(); // 堆疊為空，無法彈出

    return 0;
}
