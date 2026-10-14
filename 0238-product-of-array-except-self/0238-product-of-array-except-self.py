class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        list1 = []
        list2 = []
        p1 = 0
        p2 = len(nums)-1
        product1 = 1
        product2 = 1
        while(p1< len(nums)):
            list1.append(product1)
            list2.append(product2)
            product1 *= nums[p1]
            product2 *= nums[p2]
            p1 += 1
            p2 -= 1 
        
        list2 = list2[::-1]
        for i in range(0 , len(list1)):
            nums[i] = list1[i]*list2[i]
        
        return nums