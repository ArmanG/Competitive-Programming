import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Problem003{
	
	static long largest_prime(long num){
		ArrayList factors = new ArrayList();
		for(long i = 2; i <= num; i++){
			while(num % i == 0){
				factors.add(i);
				num /= i;
			}
		}
		return Collections.max(factors);
	}
	
	public static void main(String args []){
		System.out.println(largest_prime(600851475143L));
	}
}