#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> result;
    if (nums.empty())
        return result;

    int start = nums[0];

    for (int i = 1; i <= nums.size(); i++)
    {
        if (i == nums.size() || nums[i] != nums[i - 1] + 1)
        {
            if (start == nums[i - 1])
            {
                // use to_string() to change the type to string
                result.push_back(to_string(start));
            }
            else
            {
                result.push_back(to_string(start) + " -> " + to_string(nums[i - 1]));
            }
            if (i < nums.size())
                start = nums[i];
        }
    }
    return result;
}

int main()
{
    vector<int> nums;
    while (true)
    {
        int ele;
        cin >> ele;
        if (ele == -1)
            break;
        nums.push_back(ele);
    }
    vector<string> ranges = summaryRanges(nums);
    for (const string &range : ranges)
    {
        cout << range << " ";
    }
    return 0;
}