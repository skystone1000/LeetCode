class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        if(matrix.length == 0)
        	return 0;

        int rows = matrix.length;
        int cols = matrix[0].length;
        int count = 0;

        for(int i=0; i<rows; i++){
        	for(int j=1; j<cols; j++){
        		matrix[i][j] += matrix[i][j-1];
        	}
        }

        Map<Integer,Integer> m = new HashMap<>();
        for(int startCol=0; startCol<cols; startCol++){
        	for(int currCol=startCol; currCol<cols; currCol++){
        		m.clear();
        		int sum = 0;
        		m.put(0,1);
        		for(int row=0;row<rows;row++){
        			sum += matrix[row][currCol] - (startCol>0?matrix[row][startCol-1]:0);
        			count += m.getOrDefault(sum-target,0);
        			m.put(sum,m.getOrDefault(sum,0)+1);
        		}
        	}
        }
        return count;
    }
}