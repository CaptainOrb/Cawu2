package Utils.Display;

import java.util.HashMap;

import Models.Order;

public class DisplayOrder {
	public static void displayOrder(HashMap<Integer, Order> orders) {
		System.out.println(orders);
	}
	public static void displayOrderDetail(HashMap<Integer, Order> orders, Integer orderId) {
		System.out.println(orders.get(orderId).user);
		System.out.println(orders.get(orderId).books);
		System.out.println(orders.get(orderId).id);
	}
}
