#include <iostream>
#include <vector>
#include <cmath> // pow
using namespace std;

class BinaryTree
{
private:
    vector<int> tree; // 用陣列存放樹的節點

public:
    BinaryTree(int size)
    {
        tree.resize(size, -1); // 初始化樹為空 (-1 表示空節點)
    }

    // 插入節點（給定索引和值）
    void insert(int index, int value)
    {
        if (index >= tree.size())
        {
            cout << "索引超出範圍！" << endl;
            return;
        }
        tree[index] = value;
    }

    // 打印樹的結構（類似水平排版）
    void printTree()
    {
        int height = log2(tree.size()) + 1; // 計算樹的高度
        int index = 0;

        for (int level = 0; level < height; ++level)
        {
            int nodesInLevel = pow(2, level); // 該層的節點數
            for (int i = 0; i < nodesInLevel && index < tree.size(); ++i)
            {
                if (tree[index] == -1) // 空節點
                    cout << "   ";
                else
                    cout << tree[index] << "   ";
                ++index;
            }
            cout << endl;
        }
    }
};

int main()
{
    BinaryTree bt(15); // 建立一棵容量為 15 的二元樹

    // 插入節點
    bt.insert(0, 50); // 根節點
    bt.insert(1, 20); // 左子節點
    bt.insert(2, 80); // 右子節點
    bt.insert(3, 10); // 左子樹的左節點
    bt.insert(4, 30); // 左子樹的右節點
    bt.insert(5, 71); // 右子樹的左節點
    bt.insert(6, 90); // 右子樹的右節點

    // 打印樹結構
    cout << "二元樹結構：" << endl;
    bt.printTree();

    return 0;
}
