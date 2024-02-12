package Utils.DataManagement;

import java.util.HashMap;

import Models.Book;
import Models.Order;
import Models.User;

public class OrderManagement {
	
	public static void addOrder(HashMap<Integer, Order> orders, User user, Book book) {
		int orderId;
		if (orders.isEmpty()) {
			orderId = 1;
		} else {
//			Integer[] keys = orders.keySet().toArray(new Integer[orders.size()]);
//			Integer lastId = keys[keys.length - 1];
//			orderId = lastId + 1;
			orderId = orders.size()+1;
		}

		// Create a new order or get the existing order
		Order order = orders.getOrDefault(orderId, new Order(orderId, user));

		order.addBook(book);
		orders.put(orderId, order);
	}
	public static void removeOrder(HashMap<Integer, Order> orders, Integer orderId) {
		orders.remove(orderId);
	}
}