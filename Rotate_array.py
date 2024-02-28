# Условия задачи: https://leetcode.com/problems/rotate-array/
def rotate(nums, k):
    if k < len(nums):
        left = nums[:len(nums) - k]
        right = nums[len(nums) - k:]
        nums[:] = right + left
    else:
        while k > 0:
            nums.reverse()
            nums.append(nums.pop(0))
            nums.reverse()
            k -= 1


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    print(f"Array = {nums} rotate {k} steps to the right")
    rotate(nums, k)
    print(f"Result: {nums}")
