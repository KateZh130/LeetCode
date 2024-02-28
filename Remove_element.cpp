//Условия задачи: https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
    int j = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i >= nums.size() - j)
            break;
        if (nums[i] == val)
        {
            nums[i] = nums[nums.size() - j - 1];
            ++j;
            --i;
        }
    }
    return nums.size() - j;
}

void main()
{
    int x[8] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;
    vector<int> nums(x, x + sizeof x / sizeof x[0]);
    cout << " nums = { ";
    for (int i = 0; i < size(nums); ++i)
    {
        cout << nums[i] << "\t";
    }
    int k = removeElement(nums, val);
    cout << "} \n\n Result: \n k = " << k <<"\n nums = { ";
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i] << "\t";
    }
    cout << "}" << endl;
}

