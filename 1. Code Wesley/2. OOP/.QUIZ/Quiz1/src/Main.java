import java.util.*;

/*
 *	WESLEY ALDRICH
 *	2702363613
 *	PPTI 17
 *
 *	QUIZ OOP 1
 */

public class Main {
	static Integer availStorage = 1024;
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		// this will map documents by a number (Integer)
		HashMap<Integer, Document> documents = new HashMap<>();
		
		do {
			int opt = menu(availStorage);
			System.out.print("\n\n");
			
			// REGISTER NEW DOCUMENT
			if (opt == 1) {
				Management.register(documents, in);
			}
			
			// VIEW ALL DOCUMENTS
			else if (opt == 2) {
				Management.view(documents, in);
			}
			
			// APPROVE DOCUMENT
			else if (opt == 3) {
				Management.approve(documents, in);
			}
			
			// EXIT
			else if (opt == 4) {
				System.out.println("Thank you for using this application!");
				break;
			}
			
			// IF ANYTHING HAPPEN OUT OF CONTROL:
			else {
				System.out.println("Unexpected error!");
			}
			
			System.out.print("\n\n\n");
		} while (true);
		
		in.close();
	}
	
	public static int menu(int availStorage) {
		int opt;
		do {
			System.out.println("Hov Document Manager");
			System.out.println("========================");
			System.out.println("Available Storage: "+availStorage+" MB / 1024 MB\n");
			System.out.println("1. Register New Document");
			System.out.println("2. View All Documents");
			System.out.println("3. Approve Document");
			System.out.println("4. Exit");
			System.out.print(">> ");
			opt = in.nextInt();
			in.nextLine();
		}  while (opt < 1 || opt > 4);
		return opt;
	}
}
