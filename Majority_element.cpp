// Условия задачи: https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
    double k = size(nums) / 2;
    int count = 0;
    map<int, int> duplicates;
    for (int i = 0; i < size(nums); ++i)
    {
        duplicates[nums[i]]++;
    }
    int arg_max = 0;
    for (auto it = duplicates.cbegin(); it != duplicates.cend(); ++it)
    {
        if (it->second > k)
        {
            arg_max = it->first;
            break;
        }
    }
    return arg_max;
}

void main()
{
    int x[7] = { 2,2,1,1,1,2,2 };
    vector<int> nums(x, x + sizeof x / sizeof x[0]);
    cout << " nums = { ";
    for (int i = 0; i < size(nums); ++i)
    {
        cout << nums[i] << "  ";
    }
    int k = majorityElement(nums);
    cout << "} \n\n Majority element: " << k << endl;
}

