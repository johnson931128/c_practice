#include <iostream>
#include <vector>
#include <algorithm> // 為了使用 find()
using namespace std;

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    vector<int> intersection;
    int num;

    // 讀取 nums1
    cout << "Enter elements for nums1 (end with 0):" << endl;
    while (cin >> num)
    {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break; // 檢查是否為行尾
    }

    // 讀取 nums2
    cout << "Enter elements for nums2 (end with 0):" << endl;
    while (cin >> num)
    {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break; // 檢查是否為行尾
    }

    // 找出兩個數組的共同元素
    for (int i = 0; i < nums1.size(); i++)
    {
        if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
        // 如果在nums2裡面找到相同的元素 會回傳該元素，若無，則回傳nums2.end()
        {
            // 防止重複插入
            if (find(intersection.begin(), intersection.end(), nums1[i]) == intersection.end())
            {
                intersection.push_back(nums1[i]);
            }
        }
    }

    // 輸出結果 注意:vector不能直接cout
    cout << "Intersection elements:" << endl;
    for (int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << " ";
    }
    cout << endl;

    return 0;
}
