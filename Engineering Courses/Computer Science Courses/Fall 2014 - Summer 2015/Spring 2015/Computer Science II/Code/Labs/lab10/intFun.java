import java.util.Scanner; /*needed for input*/

/*The class name has to be the same as the filename.java*/
public class intFun{
   public static void main(String[] args){
      int x;
      Scanner input = new Scanner(System.in);

      System.out.println("Enter Int: ");
      x = input.nextInt();
      System.out.println(x);
   }
}
