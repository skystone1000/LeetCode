// April Challenge 2021 - Day 20
// #0589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

public List<Integer> preorder(Node root){
	LinkedList<node> stack = new LinkedList<>();
	LinkedList<Integer> output_arr = new LinkedList<>();

	if(root==null){
		return output_arr;
	}

	stack.add(root);
	while(!stack.isEmpty()){
		Node node = stack.pollLast();
		output_arr.add(node.val);
		Collections.reverse(node.children);
		for(Node child: node.children){
			stack.add(child);
		}
	}

	return output_arr;
}