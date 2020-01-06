package my.sandbox.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/contains-duplicate/
 * Example 1:
 * 
 * Input: [1,2,3,1]
 * Output: true
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: false
 * Example 3:
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 */
public class contains_duplicate {

	public static void main(String[] args) {
		int[] input1=new int[] {1,2,3,1};
		System.out.println(containsDuplicate1(input1));
		
		int[] input2=new int[] {1,2,3,4};
		System.out.println(containsDuplicate1(input2));
		
		int[] input3=new int[] {1,1,1,3,3,4,3,2,4,2};
		System.out.println(containsDuplicate1(input3));

	}
	
	public static boolean containsDuplicate(int[] nums) {
        HashSet<Integer> numbers=new HashSet<Integer>();
        
        for(int i=0;i<nums.length;i++) {
        	if(numbers.contains(nums[i])) {
        		return true;
        	}
        	numbers.add(nums[i]);
        }
        return false;
    }
	
	public static boolean containsDuplicate1(int[] nums) {
        Arrays.sort(nums);
        
        for(int i=0;i<nums.length-1;i++) {
        	if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }

}
