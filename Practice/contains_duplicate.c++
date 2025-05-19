#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool duplicate(vector<int> nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {

            if (nums[i] == nums[j] && abs(i - j) <= k)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums;
    int k;
    cin >> k;
    while (true)
    {
        int ele;
        cin >> ele;
        if (ele == 0)
            break;
        nums.push_back(ele);
    }
    bool result = duplicate(nums, k);
    cout << (result ? "true" : "false") << endl; // 明確輸出 true 或 false
    return 0;
}