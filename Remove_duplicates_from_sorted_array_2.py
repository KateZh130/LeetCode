# Условия задачи: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
def removeDuplicates(nums):
    duplicates = 0
    deleted = 0
    num = nums[0]
    for i in range(1, len(nums)):
        i -= deleted
        if i >= len(nums) - deleted:
            break
        if nums[i] != num:
            num = nums[i]
            duplicates = 0
            continue
        if nums[i] == num and duplicates == 0:
            duplicates += 1
            continue
        if nums[i] == num and duplicates == 1:
            for j in range(i, len(nums) - deleted - 1):
                nums[j] = nums[j + 1]
            deleted += 1
    return len(nums) - deleted


if __name__ == '__main__':
    nums = [0,0,1,1,1,1,2,3,3]
    print(f"Array = {nums}")
    print(f"Result array = {nums[:removeDuplicates(nums)]}")
