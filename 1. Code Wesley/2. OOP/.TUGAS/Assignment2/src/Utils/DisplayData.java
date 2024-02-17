package Utils;

import java.util.HashMap;

import Models.Book;
import Models.Order;
import Models.User;

public class DisplayData {
	
	public static void displayBooks(HashMap<Integer, Book> books) {
		for (int i : books.keySet()) {
			displayBookDetail(books, i);
		}
		System.out.println();
	}
	
	public static void displayBookDetail(HashMap<Integer, Book> books, Integer bookId) {
		System.out.println("Book Detail:");
		System.out.println(books.get(bookId).id);
		System.out.println(books.get(bookId).title);
		System.out.println(books.get(bookId).yearPublished);
		System.out.println(books.get(bookId).author);
	}
	
	public static void displayUsers(HashMap<Integer, User> users) {
		for (int i : users.keySet()) {
			displayUserDetail(users, i);
		}
		System.out.println();
	}
	
	public static void displayUserDetail(HashMap<Integer, User> users, Integer userId) {
		System.out.println("User Detail:");
		System.out.println(users.get(userId).getId());
		System.out.println(users.get(userId).name);
		System.out.println(users.get(userId).getEmail());
		System.out.println(users.get(userId).username);
	}
	
	public static void displayOrders(HashMap<Integer, Order> orders) {
		for (int i : orders.keySet()) {
			displayOrderDetail(orders, i);
		}
		System.out.println();
	}
	
	public static void displayOrderDetail(HashMap<Integer, Order> orders, Integer orderId) {
		System.out.println("Order Detail:");
		System.out.println(orders.get(orderId).id);
		System.out.println("User Detail:");
		System.out.println(orders.get(orderId).user.getId());
		System.out.println(orders.get(orderId).user.name);
		System.out.println(orders.get(orderId).user.username);
		System.out.println(orders.get(orderId).user.getEmail());
		displayBooks(orders.get(orderId).books);
		System.out.println();
	}
}
