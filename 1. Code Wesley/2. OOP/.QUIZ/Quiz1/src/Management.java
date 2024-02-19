import java.util.*;

public class Management {
	
	public static void register(HashMap<Integer, Document> documents, Scanner in) {
		System.out.println("Register New Document");
		System.out.println("========================");
		
		// get the available storage space in Main
		Integer availStorage = Main.availStorage;
		
		// if there is no space available
		if (availStorage == 0) {
			System.out.println("There is not enough storage space.");
			System.out.print("Press enter to continue...");
			in.nextLine();
			return;
		}
		
		// if there are empty storage space
		String name;
		int size;
		do {
			System.out.print("Input document name [1-50 characters]: ");
			name = in.nextLine();
		} while (name.length() < 1 || name.length() > 50);
		do {
			System.out.print("Input document size in MB [1 - "+availStorage+"]: ");
			size = in.nextInt();
			in.nextLine();
		} while (size < 1 || size > availStorage);
		
		documents.put(documents.size()+1, new Document(name, size, "Draft"));
		// change the available storage space in Main
		Main.availStorage -= size;
		System.out.println("Success input document data!");
		System.out.print("Press enter to continue...");
		in.nextLine();
	}
	
	public static void view(HashMap<Integer, Document> documents, Scanner in) {
		System.out.println("View All Documents");
		System.out.println("========================");
		showDocuments(documents);
		System.out.print("\nPress enter to continue...");
		in.nextLine();
	}
	
	public static void approve(HashMap<Integer, Document> documents, Scanner in) {
		System.out.println("Approve Document");
		System.out.println("========================");
		
		showDocuments(documents);
		
		// if there is no document yet
		if (documents.size() == 0) {
			System.out.print("\nPress enter to continue...");
			in.nextLine();
			return;
		}
	
		// ask for the target document number to approve
		int target;
		do {
			System.out.print("\nInput document number to approve [1 - "+documents.size()+"]: ");
			target = in.nextInt();
			in.nextLine();
		} while (target < 1 || target > documents.size());
		
		if (documents.get(target).getStatus().equals("Draft")) {
			documents.get(target).setStatus("Approved");
			System.out.println("Success approve: "+ documents.get(target).name+".");
		}
		else {
			System.out.println("The document is already approved!");
		}
		System.out.print("Press enter to continue...");
		in.nextLine();
	}
	
	public static void showDocuments(HashMap<Integer, Document> documents) {
		if (documents.size() == 0) {
			System.out.println("There is no document.");
		}
		for (Integer i : documents.keySet()) {
			System.out.printf("%02d. %-50s (%4d MB) - %s\n",
					i, documents.get(i).name, documents.get(i).size, documents.get(i).getStatus());
		}
	}
}
