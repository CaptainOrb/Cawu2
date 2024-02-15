package utils;
import java.util.HashMap;

import models.Store;

public class Management {
	public static void addStore(HashMap<String, Store> stores, String id, String name, int maxItem) {
		if (stores.get(id) == null) {
			stores.put(id, new Store(id, name, maxItem));
			System.out.println("Add store of ID: "+id+" succeed!");
		}
		else {
			System.out.println("Add store of ID: "+id+" failed due to non-unique ID!");
		}
	}
	
	public static void deleteStore(HashMap<String, Store> stores, String id) {
		stores.remove(id);
	}
	
	public static void showStore(HashMap<String, Store> stores) {
		System.out.println("\nSHOW STORES!");
		for (String str : stores.keySet()) {
			System.out.println(stores.get(str).name);
		}
	}
}
