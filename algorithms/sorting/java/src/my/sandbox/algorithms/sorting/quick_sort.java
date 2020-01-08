package my.sandbox.algorithms.sorting;

public class quick_sort {

	public static void main(String[] args) {
		int[] numbers= {9, 7, 8, 3, 2, 1};
		
		printArray(numbers);
		quickSort(numbers);
		
		printArray(numbers);
	}
	
	public static void quickSort(int[] numbers) {
		if (numbers==null || numbers.length==0) {
			return;
		}
		quickSort(numbers, 0, numbers.length-1);
	}
	
	public static int partition(int[] numbers, int left, int right) {
		int i = left, j = right;
		
		//select the pivot element value
		int pivot=numbers[(left+right)/2];
		System.out.println("pivot=" + pivot);
		
		//now divide the array into two lists
		while(i<=j) {
			System.out.println("before i=" + i + ", j=" + j);
			
			//if the current value from the left list is smaller than the pivot
			// element then get the next element from the left list
			while(numbers[i]<pivot) {
				i++;
				System.out.println(numbers[i] + " < " + pivot + "   i=" + i + ", j=" + j);
			}
			
			//if the current value from the right list is larger than the pivot
			// element then get the next element from the right list
			while(numbers[j]>pivot) {
				j--;
				System.out.println(numbers[j] + " > " + pivot + "   i=" + i + ", j=" + j);
			}
			
			//if we find a value in the left list which is larger than
			// the pivot element and if we have found a value in the right list
			// which is smaller than the pivot element then we exchange the values
			// and increase counters
			if(i<=j) {
				System.out.println("swap i=" + i + ", j=" + j);
				// swap the numbers
				int temp = numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=temp;
				
				i++;
				j--;
				printArray(numbers);
			}
		}
		
		System.out.println("after partition...");
		printArray(numbers);
		
		return i;
	}
	public static void quickSort(int[] numbers, int left, int right) {
		System.out.println("quickSort - left:" + left +", right:" + right);
		
		if(numbers.length > 1) {
			int index = partition(numbers, left, right);
			if(index-1 > left) {
				quickSort(numbers, left, index-1);
			}
			
			if(index < right) {
				quickSort(numbers, index, right);
			}
		}
	}
	
	public static void printArray(int[] numbers) {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<numbers.length;i++) {
			sb.append(numbers[i] + ", ");
		}
		System.out.println(sb.toString());
	}

}
