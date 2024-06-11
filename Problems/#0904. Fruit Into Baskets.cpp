// #0904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force
// Space - O(n)  Time - O(n^3)  TLE
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxPicked = 0;
        for (int left = 0; left < fruits.size(); ++left) {
            for (int right = 0; right < fruits.size(); ++right) {
                set<int> basket;
                for (int currentIndex = left; currentIndex <= right;
                     ++currentIndex) {
                    basket.insert(fruits[currentIndex]);
                }
                if (basket.size() <= 2) {
                    maxPicked = max(maxPicked, right - left + 1);
                }
            }
        }
        return maxPicked;
    }
};

// Approach 2 - Optimized Brute Force
// Space - O(1)  Time - O(n^2)  TLE         
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxPicked = 0;
        for (int left = 0; left < fruits.size(); ++left) {
            set<int> basket;
            int right = left;
            while (right < fruits.size()) {
                // Current fruit not present and basket size                             
                if (basket.find(fruits[right]) == basket.end() && basket.size() == 2)
                    break;
                
                // Otherwise, update the number of this fruit.
                basket.insert(fruits[right]);
                right++;
            }
            maxPicked = max(maxPicked, right - left);
        }
        return maxPicked;
    }
};

// Approach 3: Sliding Window
// Time - O(n), Space - O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left, right;
        for (left = 0, right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            // If the current window has more than 2 types of fruit,
            // we remove one fruit from the left index (left) of the window.
            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
        }
        // Once we finish the iteration, the indexes left and right 
        // stands for the longest valid subarray we encountered.
        return right - left;
    }
};

// Approach 4: Sliding Window II
// Time - O(n), Space - O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int maxPicked = 0;
        for (int left = 0,right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            maxPicked = max(maxPicked, right - left + 1);
        }
        return maxPicked;
    }
};