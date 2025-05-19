#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    TreeNode *root;
    void printLevelOrder(TreeNode *node)
    {
        if (!node)
            return;

        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr)
                {
                    cout << curr->value << " ";
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else
                {
                    cout << "null";
                }
            }
            cout << endl;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (!root)
        {
            root = newNode;
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (!curr->left)
            {
                curr->left = newNode;
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (!curr->right)
            {
                curr->right = newNode;
                return;
            }
            else
            {
                q.psuh(curr->right);
            }
        }
    }

    void printTree()
    {
        cout << "Binary Tree : " << endl;
        printLevelOrder(root);
    }
};

int main()
{
    BinaryTree bt;

    // 插入節點
    bt.insert(50); // 根節點
    bt.insert(20); // 左子節點
    bt.insert(80); // 右子節點
    bt.insert(10); // 左子樹的左節點
    bt.insert(30); // 左子樹的右節點
    bt.insert(71); // 右子樹的左節點
    bt.insert(90); // 右子樹的右節點

    // 打印樹結構
    bt.printTree();

    return 0;
}
