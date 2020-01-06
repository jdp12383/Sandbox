package my.sandbox.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/pascals-triangle/
 * 
 * Example:
 * 
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
public class pascals_triangle {

	public static void main(String[] args) {
		System.out.println(generate(5));
	}
	
	public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle=new ArrayList<>();
        
        //check for the 0 value
        if(numRows==0) return triangle;
        
        //add the 1st row since it now it has at-least 1 row
        List<Integer> row0=new ArrayList<>();
        row0.add(1);
        triangle.add(row0);
        
        for(int row=1;row<numRows;row++) {
        	//get the previous row
        	List<Integer> prevRow=triangle.get(row-1);
        	
        	List<Integer> currentRow=new ArrayList<>();
        	
        	//1st and last elements are always 1
        	currentRow.add(1);
        	
        	//every row has elements same as its row number
        	for(int col=1;col<row;col++) {
        		currentRow.add(prevRow.get(col-1) + prevRow.get(col));
        	}
        	
        	//last element is always 1
        	currentRow.add(1);
        	
        	triangle.add(currentRow);
        }
        
        
        return triangle;
    }

}
