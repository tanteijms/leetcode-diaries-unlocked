def lower_bound(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1
    while left <= right:  # 开区间写法
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def lower_bound2(nums: List[int], target: int) -> int:  # 左闭右开写法
    left = 0
    right = len(nums)
    while left < right:  # 当left == right时，退出循环
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1  # [mid+1, right)
        else:
            right = mid  #[left, mid)
    return left  # right也可

def lower_bound3(nums: List[int], target: int) -> int:  # 开区间写法
    left = -1
    right = len(nums)
    while left + 1 < right:  # 当left + 1 == right时，停止循环，答案为right
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid
        else:
            right = mid
    return right

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = lower_bound(nums, target)
        if start == len(nums) or nums[start] != target:
            return [-1, -1]
        end = lower_bound(nums, target + 1) - 1
        return [start, end]