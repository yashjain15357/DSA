class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp={}
        for i  , number in enumerate(nums):
            if target-number in mp :
                return [ i , mp[target-number]]
            
            mp[number] = i 
        return []

        