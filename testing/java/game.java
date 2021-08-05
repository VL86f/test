import java.util.*;
public class game {
	public static void main(String[] args){
		Boolean test = false;
		String clear = "\033[H\033[2J";
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
				
				case "1" :
				default:
					System.out.print(clear);
				break;
			}
		}		
	}
}
