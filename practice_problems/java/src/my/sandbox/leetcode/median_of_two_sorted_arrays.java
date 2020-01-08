package my.sandbox.leetcode;

/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */

public class median_of_two_sorted_arrays {

	public static void main(String[] args) {
		int[] num1=new int[] {1,3};
		int[] num2=new int[] {2};
		System.out.println(findMedianSortedArrays(num1, num2));
		
		int[] num3=new int[] {1,2};
		int[] num4=new int[] {3, 4};
		System.out.println(findMedianSortedArrays(num3, num4));
	}
	
	public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
    }

}
