// #0169. Majority Element
// https://leetcode.com/problems/majority-element/description/


// Approach 2 - Boyer-Moore Voting Algorithm
// Time - O(n) Space - O(1)
class Solution {
    fun majorityElement(nums: IntArray): Int {
        var count = 1
        var candidate = nums[0]
        for (i in 1..nums.lastIndex) {
            if (nums[i] == candidate) {
                count++
            } else {
                count--
            }
            if (count == 0) {
                candidate = nums[i]
                count = 1
            }
        }
        return candidate
    }
}


// Approach 1
// Time - O(n) Space - O(n)
/* 
class Solution {
    fun majorityElement(nums: IntArray): Int {
        val mp: MutableMap<Int, Int> = mutableMapOf()
        var count = 0
        var ans = 0
        for (ele in nums) {
            mp[ele] = (mp[ele] ?: 0) + 1  // Safely increment the count
            if (mp[ele]!! > count) {
                count = mp[ele]!!
                ans = ele
            }
        }
        return ans
    }
}
*/