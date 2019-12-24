public class Math {
	public native double sqrt(double d);
	
	static {
		System.loadLibrary("math");
	}
	
	public static void main(String[] args) {
		Math m = new Math();
		double result = m.sqrt(9.1);
		System.out.println("Square root of 9.1 is " + result);
	}
}