public class Hello {

	private native void sayHello();
	private native void greetMe(String name);
	
	static {
		System.loadLibrary("hello");
	}
	
	public static void main(String[] args) {
		Hello h = new Hello();
		h.sayHello();
		
		h.greetMe("Jignesh");

	}

}
