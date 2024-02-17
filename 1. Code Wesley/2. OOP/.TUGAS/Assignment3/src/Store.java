import java.util.ArrayList;
import java.util.List;

public class Store {
	String id;
	String name;
	final int maxItems;
	List<Item> items;
	
	public Store(String id, String name, int maxItems) {
		this.id = id;
		this.name = name;
		this.maxItems = maxItems;
		items = new ArrayList<>();
	}
	
	public void addItem(Item newItem) {
		if (items.size() == maxItems) {
			System.out.println("Failed to add item of id ["+newItem.id+"] to Store of id ["+this.id+"] due to max capacity!");
			return;
		}
		items.add(newItem);
		System.out.println("Item of id ["+newItem.id+"] successfully added to Store of id ["+this.id+"]!");
	}
	
	public void removeItem(Item targetItem) {
		items.remove(targetItem);
		System.out.println("Item of id ["+targetItem.id+"] successfully removed from Store of id ["+this.id+"]!");
	}
}
