

public class Problem001{
	
	public static void main(String args[]){
		System.out.println(mults_3_5(10));
	}
	
	private static int mults_3_5(int val){
		int sum = 0;
		for (int i = 1; i < val; i++){			
			if (i % 3 == 0 || i % 5 == 0) sum += i;
		}
		return sum;
	}
}
