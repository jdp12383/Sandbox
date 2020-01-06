package my.sandbox.leetcode;

/**
 * https://leetcode.com/problems/number-of-islands/
 * Example 1:
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * Example 2:
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 */
public class number_of_islands {

	public static void main(String[] args) {
		char[][] input1 = { {'1','1','1','1','0'},
							{'1','1','0','1','0'},
							{'1','1','0','0','0'},
							{'0','0','0','0','0'}};
		
		System.out.println("input1 - number of islands: " + numIslands(input1));
		
		char[][] input2 = { {'1','1','0','0','0'},
							{'1','1','0','0','0'},
							{'0','0','1','0','0'},
							{'0','0','0','1','1'}};
		
		System.out.println("input2 - number of islands: " + numIslands(input2));
	}
	
	public static int numIslands(char[][] grid) {
		int count=0;
		
		for(int row=0;row<grid.length;row++) {
			for(int col=0;col<grid[row].length;col++) {
				if(grid[row][col]=='1') {
					count++;
					searchIsland(grid, row, col);
				}
			}
		}
		return count;
	}
	
	public static void searchIsland(char[][] grid, int row, int col) {
		//Boundary check conditions
		if(row<0 || row>=grid.length) return;
		else if(col<0 || col>=grid[row].length) return;
		else if(grid[row][col]=='0') return;
		
		//change the '1' to '0' to avoid is searching again
		grid[row][col]='0';
		
		//search in all 4 directions to look for island
		searchIsland(grid, row-1, col);//top
		searchIsland(grid, row+1, col);//bottom
		searchIsland(grid, row, col-1);//left
		searchIsland(grid, row, col+1);//right
	}

}
