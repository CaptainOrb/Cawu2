package Utils;

import java.util.HashMap;

import Models.Book;
import Models.Order;
import Models.User;

public class OrderManagement {
	public static void addOrder(HashMap<Integer, Order> orders, User user, Book book) {
		int orderId;
		// check if the user is unique
		for (int i : orders.keySet()) {
			// if user is not unique
			if (orders.get(i).user.equals(user)) {
				orderId = i;
				orders.get(orderId).books.put(orders.get(orderId).books.size()+1, book);
				return;
			}
		}
		
		// if the user is unique
		orderId = orders.size()+1;
		orders.put(orderId, new Order(orderId, user));
		orders.get(orderId).books.put(orders.get(orderId).books.size()+1, book);
	}
	public static void removeOrder(HashMap<Integer, Order> orders, Integer orderId) {
		orders.remove(orderId);
	}
}