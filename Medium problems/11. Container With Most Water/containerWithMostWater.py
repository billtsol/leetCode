class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_water = 0
        n = len(height)

        left = 0
        right = n -1

        while (left < right):
            max_water = max(max_water, min(height[left],height[right]) * (right - left))
            
            if height[left] < height[right]: 
                left+=1
            else:
                right-=1

        return max_water    
