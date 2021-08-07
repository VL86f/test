import java.util.*;
public class game {
static String clear = "\033[H\033[2J";
	static void random_mode() {
		Boolean t=false, two=false;
		int a,b,c,d;
		Scanner z = new Scanner(System.in);
		System.out.println(clear);
	/*	while(t==false) {
			System.out.println("Who do you want to play with?");
			System.out.println("1. With a computer");
			System.out.println("2. With the second player");
			switch(z,next()) {
				case "1":
				two = true;
				case "2":
				t = true;
				break;
				default:
				System.out.println(clear);
				break;
			}
		} */
		System.out.println("Enter:");
		System.out.println("");
		System.out.println("1. The number of stones in the heap that must be reached or exceeded.");
		a = z.nextInt();
		System.out.println("2. How many stones can be thrown into a pile?");
		b = z.nextInt();
		System.out.println("3. How many times can you increase the pile?");
		c = z.nextInt();
		System.out.println("4. The initial amount of stones in the heap?");
		d = z.nextInt();
		System.out.println(clear);
	//	System.out.println	
		
	}
	public static void main(String[] args){
		Boolean test = false;
		Scanner z = new Scanner(System.in);
		while(test == false) {
			System.out.println("Welcome to Java (OpenJDK)");
			System.out.println("To find out the rule of the game, enter 1");
			System.out.println("To start the game enter 2");
			System.out.println("To exit the game enter 3");
			switch (z.next()) {
				case "3" :
					test = true;
				break;
				case "2" :
				random_mode();
				break;
				case "1" :
				default:
					System.out.print(clear);
				break;
			}
		}		
	}
}
