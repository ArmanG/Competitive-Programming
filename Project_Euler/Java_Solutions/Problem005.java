public class Problem005 
{

  public static long smallestMultiple (){
    int num = 2;
    while (true) {
      for (int i = 1; i <=20; i++) {
        if (num % i == 0) {
          if (i == 20) {
            return num;
          }
          else {
            continue;
        }
        else {
          break;
        }
      }
      num += 2;
    }
  }
  
  publis static void main (String args[]) {
    System.out.println(Problem005.smallestMultiple());
  }
  
}
