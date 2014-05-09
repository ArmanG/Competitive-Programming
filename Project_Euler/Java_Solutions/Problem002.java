

public class Problem002{
	
	public static void main(String args []){
		System.out.println(even_fib());
	}
	
	private static int fib(int num){
		if (num < 2) return 1;
		else return fib(num - 1) + fib(num - 2);
	}
	
	private static int even_fib(){
		int sum = 0;
		for (int i = 1; fib(i) < 4000000; i++){
			int fib_i = fib(i);
			if (fib_i % 2 == 0) sum += fib_i;
		}
		return sum;
	}
}