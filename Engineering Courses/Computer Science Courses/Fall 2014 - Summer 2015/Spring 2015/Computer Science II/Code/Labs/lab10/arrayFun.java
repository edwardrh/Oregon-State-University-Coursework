import java.util.Scanner;

public class arrayFun{
   public static int length(){
      int x;
      Scanner input = new Scanner(System.in);
      System.out.println("How big is the array? ");
      x = input.nextInt();
      System.out.println(x);
      return x; 
   }
   public static int[] create(){
      int i = length();
      int[] array = new int[i];
      return array;
   }
   public static int[] initialize(){
      int[] array = create();
      int i = length();
      int count = 0;
      for(int j = 0; j < i; j++){
	 array[j] = count++;
      }
      return array;
   }
   public static void print(){
      int[] array = initialize();
      for(int i = 0; i < array.length; i++){
	 System.out.print(array[i] + " ");
      }
      System.out.println(" ");
   }
   public static void main(String[] args){
      print();
   }
}

/* Loops sypported in Java:
 * For Loops, While Loops, Do-While Loops
 *
 * For Loop Example:
 * for(int i = 0; i < 5; i++){
 *    System.out.println(i);
 * }
 *
 * While Loop Example:
 * int i = 1;
 * while(i <= 5){
 *    System.out.println(i);
 *    i++
 * }
 *
 * Do-While Loop Example:
 * int i = 1;
 * do{
 *    System.out.println(i);
 *    i++;
 * } while(false);
 *
 * Static Array of Ints (Possible):
 * int[] array = new int[3];
 *
 * Dynamic Array of Ints (Possible):
 * int size = 4;
 * int[] data = new int[size];
 * static int count;
 * for(int i = 0, i < size, i++){
 *    data[i] = count++;
 * }
 *
 * Creating a Function in Java:
 *
 * Passing an Int to a Function:
 *
 * Passing an Array to a Funtion:
 *
 * */
