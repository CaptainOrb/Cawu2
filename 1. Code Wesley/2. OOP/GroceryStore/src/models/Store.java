package models;

import java.util.*;

public class Store {
	private final String id;
	public String name;
	public final int maxItem;
	public HashMap<String, Item> items;
	
	public Store(String id, String name, int maxItem) {
		this.id = id;
		this.name = name;
		this.maxItem = maxItem;
		items = new HashMap<>();
	}

	public String getId() {
		return id;
	}
	
	public void addItem(String id, String name, String brand, int price, int quantity) {
		// stop immediately if ID is not unique!
		if (items.get(id) != null) {
			System.out.println("Add item of ID: "+id+" failed due to non-unique ID!");
		}
		// check for space
		else if (items.size() == maxItem) {
			System.out.println("Add item of ID: "+id+" failed due to too many items!");
		}
		// add the item
		else {
			items.put(id, new Item(id, name, brand, price, quantity));
			System.out.println("Add item of ID: "+id+" succeed!");
		}
	}
	
	public void addItem(Item item) {
		// stop immediately if ID is not unique!
		if (items.get(item.getId()) != null) {
			System.out.println("Add item of ID: "+item.getId()+" failed due to non-unique ID!");
		}
		// check for space
		else if (items.size() == maxItem) {
			System.out.println("Add item of ID: "+item.getId()+" failed due to too many items!");
		}
		// add the item
		else {
			items.put(item.getId(), item);
			System.out.println("Add item of ID: "+item.getId()+" succeed!");
		}
	}
	
	public void deleteItem(String id) {
		if (items.get(id) == null) {
			System.out.println("Delete failed because item with id: "+id+" not found!");
		}
		else {
			items.remove(id);
			System.out.println("Delete succeed for item with id: "+id+"!");
		}
	}
	
	public List<Item> getItems() {
		List<Item> tmp = new ArrayList<>();
		for (String str : items.keySet()) {
			tmp.add(items.get(str));
		}
		return tmp;
	}

	public void showItems(){
		System.out.println("\nSHOW ITEMS!");
		System.out.println("Store Name: "+name+" of ID: "+id);
		for (Item item : this.getItems()) {
			System.out.println(item.getId());
			System.out.println(item.name);
			System.out.println(item.brand);
			System.out.println(item.price);
			System.out.println(item.quantity);
			System.out.println();
		}
	}
}
