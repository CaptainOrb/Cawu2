import java.util.HashMap;

import Models.Book;
import Models.Order;
import Models.User;
import Utils.DataManagement.*;
import Utils.Display.*;

public class Main {
	public static void main(String[] args) {
		HashMap<Integer, Order> orders = new HashMap<>();
		HashMap<Integer, Book> books = new HashMap<>();
		HashMap<Integer, User> users = new HashMap<>();
		
		UserManagement.addUser(users,  "fikri", "fikri@mail.com", "fikrifikri");
		UserManagement.addUser(users,  "hasan", "hasan@mail.com", "hasanwuy");
		
		BookManagement.addBook(books, "7 kiat kurus", 2019, "Salma");
		BookManagement.addBook(books, "Kamu itu baik", 2021, "Kiki");
		
		for (Integer i: users.keySet()) {
//			System.out.println("User email: "+users.get(i).email+", User name: "+users.get(i).name);
//			System.out.println("Username: "+users.get(i).username+", ID: "+users.get(i).id);
			DisplayUser.displayUserDetail(users, i);
			System.out.println();
		}
		for (Integer i: books.keySet()) {
//			System.out.println("Title: "+books.get(i).title+", Year Published: "+books.get(i).yearPublished);
//			System.out.println("Author: "+books.get(i).author+", ID: "+books.get(i).id);
			DisplayBook.displayBookDetail(books, i);
			System.out.println();
		}
		for (Integer i: orders.keySet()) {
//			System.out.println("Title: "+books.get(i).title+", Year Published: "+books.get(i).yearPublished);
//			System.out.println("Author: "+books.get(i).author+", ID: "+books.get(i).id);
			DisplayOrder.displayOrderDetail(orders, i);
			System.out.println();
		}
	}
}
