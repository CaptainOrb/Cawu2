import java.util.HashMap;

import Models.Book;
import Models.Order;
import Models.User;
import Utils.*;

public class Main {
	public static void main(String[] args) {
		HashMap<Integer, Order> orders = new HashMap<>();
		HashMap<Integer, Book> books = new HashMap<>();
		HashMap<Integer, User> users = new HashMap<>();
		
		UserManagement.addUser(users,  "fikri", "fikri@mail.com", "fikrifikri");
		UserManagement.addUser(users,  "hasan", "hasan@mail.com", "hasanwuy");
		
		BookManagement.addBook(books, "7 kiat kurus", 2019, "Salma");
		BookManagement.addBook(books, "Kamu itu baik", 2021, "Kiki");
		
		OrderManagement.addOrder(orders, users.get(1), books.get(1));
		OrderManagement.addOrder(orders, users.get(1), books.get(2));
		OrderManagement.addOrder(orders, users.get(2), books.get(2));
		OrderManagement.addOrder(orders, users.get(2), books.get(1));
		
		DisplayData.displayUsers(users);
		DisplayData.displayBooks(books);
		DisplayData.displayOrders(orders);
	}
}
