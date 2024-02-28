// Условия задачи: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int d = 0;
    int num = nums[0];
    for (int i = 1; i < size(nums) - d; ++i)
    {
        if (nums[i] != num)
        {
            num = nums[i];
            continue;
        }
        if (nums[i] == num)
        {
            for (int j = i; j < size(nums) - d - 1; ++j)
            {
                nums[j] = nums[j + 1];
            }
            ++d;
            --i;
        }
    }
    return size(nums) - d;
}

void main()
{
    int x[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    vector<int> nums(x, x + sizeof x / sizeof x[0]);
    cout << " nums = { ";
    for (int i = 0; i < size(nums); ++i)
    {
        cout << nums[i] << "  ";
    }
    int k = removeDuplicates(nums);
    cout << "} \n\n Result: \n k = " << k <<"\n nums = { ";
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i] << "  ";
    }
    cout << "}" << endl;
}

