// Amazon Question - Blogspot List 1 + Java sol

// ###################################################
// 12. Copy List With Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/


// ###################################################
// 13. Longest Substring With Out Repeating Characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int a_pointer = 0;
        int b_pointer = 0;
        int max = 0;

        HashSet<Character> hash_set = new HashSet();

        while(b_pointer < s.length()) {
            if(hash_set.contains(s.charAt(b_pointer))){
                hash_set.add(s.charAt(b_pointer));
                b_pointer++;
                max = Math.max(hash_set.size(), max);
            } else {
                hash_set.remove(s.charAt(a_pointer));
                a_pointer++;
            }
        }
        return max;
    }
}


// ###################################################
// 14. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/


// ###################################################
// 15. Min Stack


class MinStack{
    int stack[10000];
    int min[10000];
    int topPtr;
    int minPtr;

public:
    /* Initialize your data Structure */
    MinStack(){
        topPtr = -1;
        minPtr = -1;
    }

    void push(int x){
        if(topPtr >= 10000)
            return;

        stack[++topPtr] = x;

        if(minPtr >= 0){
            if(min[minPtr] > x)
                min[++minPtr] = x;
            else {
                min[minPtr + 1] = min[minPtr];
                minPtr += 1;
            }
        } else 
            min[++minPtr] = x;
    }

    void pop() {
        if(topPtr < 0)
            return;

        topPtr -= 1;
        minPtr -= 1;
    }

    int top() {
        return stack[topPtr];
    }

    int getMin() {
        return min[minPtr];
    }

};



// ###################################################
// 16. Lowest Common Ancestor Of a Binary Search Tree


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
}

class Solution{
    TreeNode* LowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val < p->val && root->val < q->val){
            return LowestCommonAncestorBST(root->right, p, q);
        } else if(root->val > p->val && root->val > q->val){
            return LowestCommonAncestorBST(root->left, p, q);
        } else {
            return root;
        }
    }
};


// ###################################################
// 17. Rotate Image

class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;

        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N/2;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][N-1-j];
                matrix[i][N-1-j] = temp;
            }
        }
    }
}



// ###################################################
// 18. #0121 Best Time To Buy And Sell Stock

class Solution {
    public int maxProfit(int[] prices){
        int max = 0;
        int min = Integer.MAX_VALUE;
        for(int i=0;i<prices.length; i++){
            if(prices[i] < min) {
                min = prices[i];
            } else {
                max = Math.max(max, prices[i] - min);
            }
        }

        return max;
    }
}


// ###################################################
// 19. #0098 Validate Binary Search Tree

class Solution{
    public boolean isValidBST(TreeNode root){
        return validate(root, null, null);
    }

    publc boolean validate(treeNode root, Integer max, Integer min) {
        if(root == null){
            return true;
        } else if(max != null && root.val >= max ||
                  min != null && root.val <= min){
            return false;
        } else {
            return validate(root.left, root.val, min) && validate(root.right, max, root.val);
        }
    }
}

// ###################################################
// 20. Word Break


// ###################################################
// 21. Linked List Cycle

struct ListNode{
    int val;
    ListNode* next;
}

class Solution{
public:
    bool* hasCycle(ListNode* root){
        TreeNode* fast = root->next;
        TreeNode* slow = root;

        while(fast != slow){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast == NULL){
            return NULL;
        }else {
            return fast;
        }
    }
};


// ###################################################
// 22. #0049 Group Anagrams

class Solution{
public:
    vector<vector<string>> groupedAnagrams(vector<string>& strs){

        unordered_map<string, vector<string>> mymap;
        int n = strs.size();
        string temp;

        for(int i=0;i<n;i++){
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mymap[strs[i]].push_back(temp);
        }

        vector<vector<string> result;
        for(auto itr = mymap.begin(); itr != mymap.end() ;itr++){
            result.push_back(itr->second);
        }

        return result;
    }

};


// ###################################################
// 23. #0015 3Sum


class Solution {
    public List<List<Interger>> threeSum(int[] nums){
        Arrays.sort(nums);
        List<List<Integer>> output_arr = new linkedList();

        for(int i=0;i<nums.length-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low  = i+1;
                int high = nums.length - 1;
                int sum = 0 - nums[i];

                while(low<high){
                    if(nums[low] + nums[high] == sum){
                        output_arr.add(Arrays.asList(nums[i], nums[low], nums[high]));
                        
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;

                        low++;
                        high--;
                    }else if(nums[low] + nums[high] > sum){
                        high--;
                    }else {
                        low++;
                    }
                }

            }
        }

        return output_arr;
    }
}

// ###################################################
// 24. Product Of Array Except Self

class Solution {
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        if(n<1){
            return {};
        }

        vector<int> output(n);
        int product = 1;
        for(int i=0;i<n;i++){
            product *= nums[i]; 
            output[i] = product;
        }

        // Traverse from right and update output array
        product  = 1;
        for(int i=n-1;i>0;i--){
            output[i] = output[i-1] * product;
            product *= nums[i];
        }
        output[0] = product;

        return output;
    }
}


// ###################################################
// 25. Valid Anagram

class Solution {
    public boolean isAnagram (String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }

        int[] counts = new int[26];
        for(int i=0;i<s.length();i++){
            counts[s.charAt(i) - 'a']++;
            counts[t.charAt(i) - 'a']--;
        }

        for(int i: counts){
            if(i != 0){
                return false;
            }
        }

        return true;
    }
}


// ###################################################
// 26. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/



// ###################################################
// 27. Search A 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix-ii/


class Solution {
    public boolean searchMatrix(int[][] matrix, int target){
        if(matrix.length == 0) result false;

        int rows = matrix.length;
        int columns = matrix[0].length;

        int left = 0;
        int right = rows*columns-1;

        while(left <= right){
            int midpoint = left + (right-left) / 2;
            int midpoint_element = matrix[midpoint / columns][midpoint % columns];
            if(midpoint_element == target) {
                return true;
            } else if(target < midpoint_element){
                right = midpoint - 1;
            } else if(target > midpoint_element){
                left = midpoint+1;
            }

            return false;
        }
    }
}

// ###################################################
// 28. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
}

class Solution{
    ListNode* mergeTwoLists(ListNode* p, ListNode* q){
        ListNode dummy(-1);
        ListNode* head = &dummy;

        while(p != NULL && q != NULL){
            if(p->val < q->val){
                head->next = p;
                p = p->next;
            } else if(p->val >= q->val){
                head->next = q;
                q = q->next;
            }

            head = head->next;
        }

        if(p != NULL){
            head->next = p;
        }else if(q != NULL){
            head->next = q;
        }
    }
};

// ###################################################
// 29. Merge K Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

// (MIN AND MAX HEAP)
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode dummy(0);
        auto *curr = &dummy;

        struct Compare{
            bool operator()(cont ListNode *a, const ListNode *b){
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        for(const auto& n : lists) {
            if(n){
                min_heap.emplace(n);
            }
        }

        while(!min_heap.empty()) {
            // Get min of K lists.
            auto *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }
};

// ###################################################
// 30. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/



// ###################################################
// 31. Kth Largest Element In An Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// (MIN AND MAX HEAP)

class KthLargest{
    int K;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for(int ele:nums){
            add(ele);
        }
    }

    int add(int val){
        min_heap.push(val);
        if(min_heap.size() > k){
            min_heap.pop();
        }
        return min_heap.top();
    }
};


// ###################################################
// 32. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
    public boolean isPalindrome(ListNode head){
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }

        slow = reversed(slow);
        fast = head;

        while(slow != null){
            if(slow.val != fast.val){
                return false;
            }
            slow = slow.next;
            fast = fast.next;
        }

        return true;
    }

    public ListNode reversed(ListNode head){

        ListNode prev = null;
        while(head != null){
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
}


// ###################################################
// 33. Intersection Of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public: 
    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB){
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while(p1!=p2){
            if(p1 == NULL){
                p1 = headB;
            }else{
                p1 = p1->next;
            }

            if(p2 == NULL){
                p2 = headA;
            }else{
                p2 = p2->next;
            }
        }

        return p1;
    }
};


class Solution{
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        set<ListNode*> visited;

        while(headA != NULL){
            visited.insert(headA);
            headA = headA->next;
        }

        while(headB != NULL) {
            if(visited.count(headB) > 0){
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
}

// ###################################################
// 34. Subsets
// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> subsets;
        generateSubsets(nums, 0, vector<int>(), subsets);
        return subsets;
    }

    void generateSubsets(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& subsets){
        subsets.push_back(vector<int>(curr));
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            generateSubsets(nums, i+1, curr, subsets);
            curr.pop_back();
        }
    }
}


// ###################################################
// 35. String To Integer
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
    int atoi(string str){
        int result = 0;
        int i = 0;
        int sign = 1;

        if(str[i] == '-'){
            sign = -1;
            i++;
        }

        while(str[i]){
            if(!(str[i]-'0'>=0 && str[i]-'0'<=9))
                return -1;
            result = result*10 + str[i] - '0';
            i++;
        }
    }
    return result*sign;

};


// ###################################################
// 36. First Unique Character In a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution{
public:
    int firstUniqChar(string)
    vector<int> freq(26,0);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }

    for(int i=0;i<s.size();i++){
        if(freq[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
};

// ###################################################
// 37. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
}

class Solution{
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> lvl;
        if(root == NULL){
            return lvl;
        }

        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            vector<int> currLevel;
            int n = qu.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = qu.front();
                qu.pop();
                currLevel.push_back(curr->val);
                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL){
                    qu.push(curr->right);
                }
            }
            lvl.push_back(currLevel);
        }

        return lvl;
    }
};

// ###################################################
// 38. Count Primes
// https://leetcode.com/problems/count-primes/

class Solution{
public:
    int countPrimes(int n){
        bool prime[n+1];
        memset(prime, true, sizeof(prime));

        for(int p=2; p*p<=n; p++){
            if(prime[p] == true){
                for(int i=p*p; i<=n; i+=p)
                    prime[i] = false;
            }
        }

        int totalPrimes = 0;
        for(int i=0;i<prime.size();i++){
            if(prime[i] == 1)
                totalPrimes++;
        }

        return totalPrimes;
    }
};

// ###################################################
// 39. Gray Code
// https://leetcode.com/problems/gray-code/

// ###################################################
// 40. Two Sum Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int left=0, right=number.size()-1;

        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum<target){
                left++;
            } else if(sum>target){
                right--;
            } else {
                return {left+1, right+1};
            }
        }

        return {0,0};
    }

}

// ###################################################
// 41. Insert Delete Get In Random O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet{
    vector<int> v;
    unordered_map<int,int> mymap;

public:
    RandomizedSet(){}

    bool insert(int val){
        if(mymap.find(val) != mymap.end())
            return false;

        v.push_back(val);
        mymap[val] = v.size() - 1;
        return true;
    }

    bool remove(int val){
        if(mymap.find(val) == mymap.end())
            return false;

        auto it = mymap.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mymap[v[it->second]] = it->second;
        mymap.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }

};


// ###################################################
// 42. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution{
    vector<int> rightSideView(TreeNode* root){
        vector<int> rightSide;
        if(root == NULL) return rightSide;

        Queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = qu.front();
                qu.pop();
                if(i == n-1){
                    rightSide.push_back(curr->val);
                }

                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL) {
                    qu.push(curr->right);
                }
            }
        } 
        
        return rightSide;
    }

};


// ###################################################
// 43. Design Twitter
// https://leetcode.com/problems/design-twitter/

// ###################################################
// 44. Reverse Words In A String II (Premium)
// https://leetcode.com/problems/reverse-words-in-a-string-ii/

// ###################################################
// 45. Rotate Function
// https://leetcode.com/problems/rotate-function/
