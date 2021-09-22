// LEETCODE AMAZON QUESTIONS

// 15 (206. Reverse Linked List)
class Solution {
	public ListNode reverseList(ListNode head) {
		Stack<ListNode> stack = new Stack<ListNode>();
		while(head != null) {
			stack.push(head);
			head = head.next;
		}

		ListNode dummy = new ListNode(-1);
		head = dummy;
		while(!stack.isEmpty()){
			ListNode current = stack.pop();
			head.next = new ListNode(current.val);
			head = head.next;
		}

		return dummy.next;
	}
}

// =====================================================================
// 16 (819. Most Common Word)
class Solution {
	public String mostCommonWord(String paragraph, String[] banned) {
		HashSet<String> bannedWords = new HashSet<>();
		for(String word: banned) {
			bannedWords.add(word);
		}

		HashMap<String, Integer> counts = new HashMap<>();
		for(String word:paragraph.replaceAll("[^a-zA-Z]"," ").toLowerCase().split(" ")) {
			if(!bannedWords.contains(word)) {
				counts.put(word, counts.getOrDefault(word, 0) + 1);
			}
		}

		String result = "";
		for(String key: counts.keySet()){
			if(result.equals("") || counts.get(key) > counts.get(result)) {
				result = key;
			}
		}

		return result;
	}
}


// 17 (929. Unique Email Addresses)
class Solution {
	public int numUniqueEmails(String[] emails){
		HashSet<String> set = new HashSet<>();
		for(String email: emails){
			StringBuilder address = new StringBuilder();
			for(int i=0; i<email.length(); i++){
				char c = email.charAt(i);
				if(c == '.'){
					continue;
				} else if(c == '+') {
					while(email.charAt(i) != '@'){
						i++;
					}
					address.append(email.substring(i+1));
				} else {
					address.append(c);
				}
			}

			set.add(address.toString());
		}

		return set.size();
	}
}


// 18 (253. Meeting Rooms II)
class Solution {
	public int minMeetingRooms(Interval[] intervals) {
		if(intervals == null || intervals.length == 0){
			return 0;
		}

		Arrays.sort(intervals, (a,b) -> a.start - b.start);
		PriorityQueue<Interval> minHeap = new PriorityQueue<>((a,b) -> a.end - b.end());
		minHeap.add(intervals[0]);
		for(int i = 1; i<intervals.length ; i++){
			Interval current = intervals[i];
			Interval earliest = minHeap.remove();
			if(current.start >= earliest.end) {
				earliest.end = current.end;
			} else {
				minHeap.add(earliest);
			}
		}

		return minHeap.size();
	}
}

// 19 (973. K Closest Points to Origin)
class Solution {
	public int[][] kClosest(int[][] points, int K) {
		PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
			(a,b) -> ( b[0]*b[0] + b[1]*b[1] - (a[0]*a[0] + a[1]*a[1]) )
		);

		for (int[] point: points){
			maxHeap.add(point);
			if(maxHeap.size() > k){
				maxHeap.remove();
			}
		}

		int[][] result = new int[k][2];
		while(K-- > 0) {
			result[k] = maxHeap.remove();
		}

		return result;
	}
}

// 20 (695. Max Area of Island)
class Solution {
	public int maxAreaOfIsland(int[][] grid) {
		int max = 0;
		for (int i=0;i<grid.length;i++){
			for(int j=0;j<grid[i].length;j++) {
				max = Math.max(max, dfs(grid, i, j));
			}
		}

		return max;
	}

	public int dfs(int[][] grid, int i, int j){
		if(i<0 || i>=grid.length || j<0 || j<grid[i].length || grid[i][j] == 0){
			return 0;
		}

		grid[i][j] = 0;
		int count = 1;
		count += dfs(grid, i+1, j);
		count += dfs(grid, i-1, j);
		count += dfs(grid, i, j+1);
		count += dfs(grid, i, j-1);

		return count;
	}
}

// =====================================================================
// 21 (403. Frog Jump)
class Solution {
	public boolean canCross(int[] stones){
		for(int i=3;i<stones.length;i++) {
			if(stones[i] > stones[i-1]*2){
				return false;
			}
		}

		HashSet<Integer> stonePositions = new HashSet<>();
		for(int stone:stones) {
			stonePositions.add(stone);
		}

		int lastStone = stones[stones.length - 1];
		Stack<Integer> positions = new Stack<>();
		Stack<Integer> jumps = new Stack<>();
		positions.add(0);
		jumps.add(0);

		while(!positions.isEmpty()) {
			int position = positions.pop();
			int jumpDistance = jumps.pop();
			for(int i = jumpDistance-1 ; i<=jumpDistance+1 ; i++) {
				if(i <= 0){
					continue;
				}

				int nextPosition = position+i;
				if(nextPosition = lastStone) {
					return true;
				} else if(stonePositions.contains(nextPosition)) {
					positions.add(nextPosition);
					jumps.add(i);
				}
			}
		}

		return false;
	}
}


// 22 Merge K Sorted Lists
class Solution {
	public ListNode mergeKLists(ListNode[] lists){
		PriorityQueue<Integer> minHeap = new PriorityQueue<>();
		for(ListNode head : lists) {
			while(head != null) {
				minHeap.add(head.val);
				head = head.next;
			}										
		}							
										
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		while(!miHeap.isEmpty()) {														
			head.next = new ListNode(minHeap.remove());									
			head = head.next;						
		}					
		
		return dummy.next;
	}
}

// 23 Grouped Anagrams

class Solution {
	public List<List<String>> groupedAnagrams(String[] strs) {
		List<List<String>> groupedAnagrams = new ArrayList<>();
		HashMap<String, List<String>> map = new HashMap<>();
		for(String current: strs) {
			char[] characters = current.toCharArray();
			Arrays.sort(characters);
			String.sorted = new String(characters);
			if(!map.containskey(sorted)) {
				map.put(sorted, new ArrayList<>());
			}
			map.get(sorted).add(current);
		}

		groupedAnagrams.addAll(map.values());
		return groupedAnagrams;
	}
}

// 24 Unique Paths

class Solution {
	public int uniquePaths(int m,int n) {
		int[][] dp = new int[m][n];
		for(int i = 0; i < dp.length; i++) {
			dp[i][0] = 1;
		}
		for(int i = 0; i < dp[0].length; i++) {
			dp[0][i] = 1;
		}

		for(int i = 1; i < dp.length; i++) {
			for(int j=1; j<dp[i].length; j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}

		return dp[m-1][n-1];
	}
}

// 25 House Robber

class Solution {
	public int rob(int[] nums) {
		if(nums == null || nums.length == 0) { return 0; }
		if(nums.length == 1) { return nums[0]; }
		if(nums.length == 2) { return Math.max(nums[0], nums[1]); }

		int []dp = new int[nums.length];
		dp[0] = nums[0];
		dp[1] = Math.max(nums[0], nums[1]);
		for(int i = 2 ; i < dp.length ; i++) {
			dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
		}

		return dp[nums.length - 1];		
	}
}

// 26 Path Sum 2

class Solution {
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List <Integer>> paths = new ArrayList<>();
		findPaths(root, sum, new ArrayList<Integer>(), paths);
		retunrn paths;
	}

	public void findPaths(TreeNode root, int sum, List<Integer> current, List<List<Integer>> paths){
		if(root == null){ return; }

		current.add(root.val);
		if(root.val == sum && root.left == null && root.right == null){
			paths.add(current);
			return;
		}

		findPaths(root.left, sum-root.val, new ArrayList<Integer>(current), paths);
		findPaths(root.right, sum-root.val, new ArrayList<Integer>(current), paths);
	}
}

// 27 Same Tree

class Solution{
	public boolean isSameTree(TreeNode p, TreeNode q){
		if(p==null && q==null) {
			return true;
		} else if(p==null || q==null){
			return false;
		} else if(p.val != q.val){
			return false;
		} else{
			return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
		}
	}
}

// 28 Maximum Depth of Binary Tree

class Solution{
	public int maxDepth(TreeNode root){
		if(root == null){ return 0; }

		int left = maxDepth(root.left);
		int right = maxDepth(root.right);

		return Math.max(left, right) + 1;
	}
}

// 29 (101. Symmetric Tree)
class Solution{
	public boolean isSymmetric(TreeNode root){
		if(root == null) { return true; }
		return isSymmetric(root.left, root.right);
	}

	public boolean isSymmetric(TreeNode left, TreeNode right){
		if(left == null || right == null){
			return left == right;
		}

		if(left.val != right.val){
			return false;
		}

		return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
	}
}

// 30 (286. Walls & Gates)

class Solution{
	public void wallsAndGates(int[][] rooms){
		for(int i=0;i<rooms.length;i++){
			for(int j=0;j<rooms[i].length;j++){
				if(rooms[i][j] == 0){
					dfs(i, j, 0, rooms);
				}
			}
		}
	}

	public void dfs(int i, int j, int count, int[][] rooms){
		if(i<0 || i>=rooms.length || j<0 || j>=rooms.length || rooms[i][j] < count){
			return ;
		}

		rooms[i][j] = count;
		dfs(i+1, j, count+1, rooms);
		dfs(i-1, j, count+1, rooms);
		dfs(i, j+1, count+1, rooms);
		dfs(i, j+1, count+1, rooms);
	}
}

 
// 31 (905. Sort Array By Parity)

class Solution{
	public int[] sortArrayByParity(int[] A){
		int index = 0;
		for(int i=0;i<A.length;i++){
			if(A[i] % 2 == 0){
				int temp = A[index];
				A[index] = A[i];
				A[i] = temp;

				index++;
			}
		}

		return A;
	} 
}

// 32 (40. Combination Sum II)

class Solution{
	public List<List<Integer>> combinationSum2(int candidates, int target){
		List<List<Integer>> result = new ArrayList<>();
		Arrays.sort(candidates);
		
		findCombinations(candidates, 0, target, new ArrayList<Integer>(), result);
		return result;
	}

	public void findCombinations(int[] candidates, int index, int target, List<Integer> current, List<List<Integer>> result) {
		if(target == 0) {
			result.add(new ArrayList<>(current));
			return;
		}

		if(target < 0){
			return;
		}

		for(int i=index; i<candidates.length; i++){
			if(i == index || candidates[i] != candidates[i-1]) {
				current.add(candidates[i]);
				findCombinations(candidates, i+1, target-candidates[i], current, result);
				current.remove(current.size() - 1);
			}
		}
	}
}

// 33 (79. Word Search)

class Solution{
	public boolean exist(char[][] board, String word){
		for(int i=0;i<board.length;i++){
			for(int j=0;j<board[i].length;j++){
				if(board[i][j] == word.charAt(0) && dfs(board, i, j, 0, word)){
					return true;
				}
			}
		}
		return false;
	}

	public boolean dfs(char[][] board, int i, int j, int count, String word){
		if(count == word.length()){
			return true;
		}

		if(i<0 || i>=board.length || j<0 || j>=board[i].length 
			|| board[i][j] != word.charAt(count)){
			return false;
		}

		char temp = board[i][j];
		board[i][j] = ' ';
		boolean found = dfs(board, i+1, j, count+1, word)
			|| dfs(board, i-1, j, count+1, word)
			|| dfs(board, i, j+1, count+1, word)
			|| dfs(board, i, j-1, count+1, word);

		board[i][j] = temp;
		return found;
	}
}


// 34 (763. Partition Labels)

class Solution{
	public List<Integer> partitionLabels(String S) {
		List<Integer> partitionLengths = new ArrayList<>();
		int[] lastIndexes = new int[26];
		for(int i=0;i<S.length(); i++){
			lastIndexes[S.charAt(i) - 'a'] = i;
		}

		int i=0;
		while(i<S.length()){
			int end = lastIndexes[S.charAt(i) - 'a'];
			int j = i;
			while(j != end){
				end = Math.max(end, lastIndexes[S.charAt(j++) - 'a']);
			}

			partitionLengths.add(j - i + 1);
			i = j + 1;
		}

		return partitionLengths;
	}
}


// 35 (14. Longest Common Prefix)

class Solution{
	public String longestCommonPrefix(String[] strs){
		String longestCommonPrefix = "";
		if(strs == null || strs.length == 0){
			return longestCommonPrefix;
		}

		int index = 0;
		for(char c:strs[0]/toCharArray()){
			for(int i=1;i<strs.length;i++){
				if(index >= strs[i].length() || c != strs[i].charAt(index)){
					return longestCommonPrefix;
				}
			}

			longestCommonPrefix += c;
			index++;
		}

		return longestCommonPrefix;
	}
}

// =====================================================================
// 36 (78. Subsets)

class Solution{
	public List<List<Integer>> subsets(int[] nums){
		List<List<Integer>> subsets = new ArrayList<>();
		generateSubsets(0, nums, new ArrayList<Integer>(), subsets);

		return subsets;
	}

	public void generateSubsets(int index, int[] nums, List<Integer> current, List<List<Integer>> subsets){
		subsets.add(new ArrayList<>(current));
		for(int i=index; i<nums.length;i++){
			current.add(nums[i]);
			generateSubsets(i+1, nums, current, subsets);
			current.remove(current.size() - 1);
		}
	}
}

// 37 (21. Merger two Sorted Lists)

class Solution{
	public ListNode mergeTwoLists(ListNode l1, Listnode l2){
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		while(l1 != null && l1 != null){
			if(l1.val < l2.val){
				dummy.next = l1;
				l1 = l1.next;
			} else{
				dummy.next = l2;
				l2 = l2.next;
			}
			dummy = dummy.next;
		}

		if(l1 != null){
			dummy.next = l1;
		}else{
			dummy.next = l2;
		}

		return head.next;
	}
}

// =====================================================================
// 38 (322. Coin Change)

class Solution{
	public int coinChange(int[] coins, int amount){
		int[] dp = new int[amount+1];
		Arrays.fill(dp, amount+1);
		dp[0] = 0;
		for(int i=0;i<=amount;i++){
			for(int j=0;j<coins.length;j++){
				if(coins[j] <= i){
					dp[i] = Math.min(dp[i], 1+dp[i-coins[j]]);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
}


class Solution{
	public int coinChange(int[] coins, int amount){
		// Sorted Initially
		Array.sort(coins);
		int[] dp = new int[amount+1];
		Arrays.fill(dp, amount+1);
		dp[0] = 0;
		for(int i=0;i<=amount;i++){
			for(int j=0;j<coins.length;j++){
				if(coins[j] <= i){
					dp[i] = Math.min(dp[i], 1+dp[i-coins[j]]);
				}
				// Added this else statement
				else{
					break;
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
}

// 39 (199. Binary Tree Right Side View)

class Solution{
	public List<Integer> rightSideView(TreeNode root){
		List<Integer> visibleValues = new ArrayList<>();
		if(root == null){
			return visibleValues;
		}

		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			int size = queue.size();
			for(int i=0;i<size;i++){
				TreeNode current = queue.remove();
				if(i == size-1){
					visibleValues.add(current.val);
				}
				if(current.left != null){
					queue.add(current.left);
				}
				if(current.right != null){
					queue.add(current.right);
				}
			}
		}

		return visibleValues;
	}
}

// 40 (1119. Remove Vowels from a String)

class Solution{
	public String removeVowels(String S){
		Set<Character> vowels = new hashSet<>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		StringBuilder result = new StringBuilder();
		for(char c : S.toCharArray()){
			if(!vowels.contains(c)){
				result.append(c);
			}
		}

		return result.toString();
	}
}

// 41 (64. Minimum Path Sum)

class Solution {
	public int minPathSum(int[][] grid){
		if(grid == null || grid.length == 0){
			return 0;
		}

		int[][] dp = new int[grid.length][grid[0].length];
		for(int i=0; i<dp.length; i++){
			for(int j = 0; j<dp[i].length; j++){
				dp[i][j] += grid[i][j];
				if(i>0 && j>0){
					dp[i][j] += Math.min(dp[i-1][j], dp[i][j-1]);
				} else if(i>0){
					dp[i][j] += dp[i-1][j];
				} else if(j>0){
					dp[i][j] += dp[i][j-1];
				}
			}
		}

		return dp[dp.length - 1][dp[0].length - 1];
	}
}

// 42 (257. Binary Tree Paths)

class Solution {
	public List<String> binaryTreePaths(TreeNode root){
		List<String> paths = new ArrayList<>();
		if(root == null){
			return paths;
		}

		dfs(root, "", paths);
		return paths;
	}

	public void dfs(TreeNode root, String path, List<String> paths){
		path += root.val;
		if(root.left == null && root.right == null){
			paths.add(path);
			return;
		}
		if(root.left != null){
			dfs(root.left, path + "->",paths);
		}
		if(root.right != null){
			dfs(root.right, path + "->", paths);
		}
	}
}

// 43 (345. Reverse Vowels of a String)

class Solution {
	public String reverseVowels(String s){
		Set<Character> vowels = new HashSet<>();
		vowels.add('A');
		vowels.add('E');
		vowels.add('I');
		vowels.add('O');
		vowels.add('U');
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		char[] characters = s.toCharArray();
		int i = 0;
		int j = s.length() - 1;
		while(i<j){
			while(i < j && !vowels.contains(characters[i])){
				i++;
			}
			while(i < j && !vowels.contains(characters[j])){
				j--;
			}

			char temp = characters[i];
			characters[i++] = characters[j];
			characters[j--] = temp;
		}

		return new String(characters);
	}
}

// 44 (160. Intersection of Two Linked Lists)

class Solution{
	public ListNode getIntersectionNode(ListNode headA, ListNode headB){
		Set<ListNode> visited = new hashSet<>();
		while(headA != null){
			visited.add(headA);
			headA = headA.next;
		}

		while(headB != null){
			if(visited.contains(headB)){
				return headB;
			}
			headB = headB.next;
		}

		return null;
	}

}

// 45 (938. Range Sum of BST)

class Solution{
	public int rangeSumBST(TreeNode root, int L, int R){
		int sum = 0;
		if(root == null){
			return sum;
		}

		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			TreeNode current = queue.remove();
			if(current.val >= L && current.val <= R){
				sum += current.val;
			}
			if(current.left != null && currrent.val > L){
				queue.add(current.left);
			}
			if(current.right != null && current.val < R){
				queue.add(current.right);
			}
		}

		return sum;
	}
}

// =====================================================================
// 46 (1046. Last Stone Weight)

class Solution {
	public int lastStoneWeight(int[] stones) {
		PriorityQueue<Integer> maxHeap = new PriorityQueue<>();
		for(int stone: stones){
			maxHeap.add(-stone);
		}

		while(maxHeap.size() > 1) {
			int stoneOne = -maxHeap.remove();
			int stoneTwo = -maxHeap.remove();
			if(stoneOne != stoneTwo) {
				maxHeap.add(-(stoneOne - stoneTwo));
			}
		}

		return maxHeap.isEmpty() ? 0 : -maxHeap.remove();
	}
}


// 47 (1167. Minimum Cost to Connect Sticks)

class Solution {
	public int connectSticks(int[] sticks) {
		int cost = 0;
		PriorityQueue<Integer> minHeap = new PriorityQueue<>();
		for(int stick: sticks){
			minHeap.add(stick);
		}

		while(minHeap.size() > 1){
			int sum = minHeap.remove() + minHeap.remove();
			cost += sum;
			minHeap.add(sum);
		}

		return cost;
	}
}

// 48 (415. Add Strings)

class Solution {
	public String addStrings(String num1, String num2) {
		StringBuilder result = new StringBuilder();
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int carry = 0;

		while(i >= 0 || j >= 0){
			int sum = carry;
			if(i>=0){
				sum += num1.charAt(i) - '0';
				i--;
			}
			if(j>=0){
				sum += num2.charAt(j) - '0';
				j--;
			}

			reult.append(sum % 10);
			carry = sum / 10;
		}

		if(carry != 0){
			result.append(carry);
		}

		return result.reverse().tostring();
	}
} 

// =====================================================================
// 49 (98. Validate Binary Search Tree)

class Solution {
	public boolean isValidBST(TreeNode root){
		return validate(root, null, null);
	}

	public boolean validate(TreeNode root, Integer max, Integer min) {
		if(root == null) {
			return true;
		} else if (max != null && root.val >= max || min != null && root.val <= min){
			return false;
		} else {
			return validate(root.left, root.val, min) && validate(root.right, max, root.val);
		}
	}
}


// 50 (1007. Minimum Domino Rotations for Equal Row)

class Solution {
	public int minDominoRotations(int[] A, int [] B) {
		int minSwaps = Math.min(
			numSwaps(A[0], A, B),
			numSwaps(B[0], A, B)
		);

		minSwaps = Math.min(minSwaps, numSwaps(A[0], B, A));
		minSwaps = Math.min(minSwaps, numSwaps(B[0], B, A));
		return minSwaps == Integer.MAX_VALUE ? -1 : minSwaps;
	}

	public int numSwaps(int target, int[] A, int[] B) {
		int numSwaps = 0;
		for(int i = 0; i < A.length; i++){
			if(A[i] != target && B[i] != target) {
				return Integer.MAX_VALUE;
			} else if(A[i] != target) {
				numSwaps++;
			}
		}

		return numSwaps;
	}
}


// =====================================================================
// 51 (767. Reorganize String)

class Solution {
	public String reorganizeString(String S) {
		Map<Character, Integer> counts = new HashMap<>();
		for(char c:S.toCharArray()) {
			counts.put(c, counts.getOrDefault(c, 0) + 1);
		}

		PriorityQueue<Character> maxHeap = new PriorityQueue<>
			((a,b) -> counts.get(b) - counts.get(a));
		maxHeap.add(counts.keySet());

		StringBuilder result = new StringBuilder();
		while(maxHeap.size() > 1){
			char current = maxHeap.remove();
			char next = maxHeap.remove();
			result.append(current);
			result.append(next);
			counts.put(current, counts.get(current) - 1);
			counts.put(next, count.get(next) - 1);
			if(counts.get(current) > 0){
				maxHeap.add(current);
			}
		}

		if(!maxHeap.isEmpty()) {
			char last = maxHeap.remove();
			if(counts.get(last) > 1) {
				return "";
			}
			result.append(last);
		}

		return result.toString();
	}
}


// =====================================================================
// 52 (735. Asteroid Collision) 

class Solution{
	public int[] asteroidCollision(int[] asteroids) {
		Stack<Integer> stack = new Stack<>();
		int i = 0;
		while(i<asteroids.length){
			if(asteroids[i] > 0) {
				stack.push(asteroids[i]);
			} else {
				while (!stack.isEmpty() && stack.peek()>0 && stack.peek()<Math.abs(asteroids[i])) {
					stack.pop();
				}
				if(stack.isEmpty() || stack.peek()<0) {
					stack.push(asteroids[i]);
				} else if(stack.peek() == Math.abs(asteroids[i])) {
					stack.pop();
				}
			}
			i++;
		}

		int[] remaining = new int[stack.size()];
		for(i = stack.size() - 1; i >= 0 ; i--){
			remaining[i] = stack.pop();
		}

		return remaining;
	}
}


// 53 (572. Subtree of Another Tree)

class Solution {
	public boolean isSubtree(TreeNode s, TreeNode t){
		if(s==null) {
			return false;
		} else if(isSameTree(s,t)){
			return true;
		} else {
			return isSubtree(s.left, t) || isSubtree(s.right, t);
		}
	}

	public boolean isSameTree(TreeNode s, TreeNode t){
		if(s==null || t==null) {
			return s==null && t==null;
		} else if(s.val == t.val){
			return isSameTree(s.left, t.left) && isSameTree(s.right, t.right);
		} else {
			return false;
		}
	}
}

// 54 (443. String Compression) 

class Solution {
	public int compress(char[] chars) {
		int index = 0;
		int i = 0;
		while(i<chars.length) {
			int j = i;
			while(j<chars.length && chars[j] == chars[i]){
				j++;
			}

			chars[index] = chars[i];
			index++;
			if(j-i > 1){
				String count = j-i+"";
				for(char c: count.toCharArray()) {
					chars[index++] = c;
				}
			}

			i=j;
		}

		return index;
	}
}