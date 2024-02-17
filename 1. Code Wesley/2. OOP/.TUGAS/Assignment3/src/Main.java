import java.util.HashMap;

public class Main {
	public static void main(String[] args) {
		HashMap<String, Store> stores = new HashMap<>();
		
		// CHECK!
		showStatus(stores);

		// 1. Insert new Grocery
		Store store1 = new Store("A", "Art Shop", 2);
		Store store2 = new Store("B", "Wes Shop", 1);
		stores.put(store1.id, store1);
		System.out.println("Store of id ["+store1.id+"] successfully added!");
		stores.put(store2.id, store2);
		System.out.println("Store of id ["+store2.id+"] successfully added!");
		// CHECK!
		showStatus(stores);

		// 2. Insert new Item to Grocery
		Item item1 = new Item("a", "Laptop", "Acer", 1000, 3);
		Item item2 = new Item("b", "Handphone", "Asus", 500, 6);
		stores.get("A").addItem(item1); // or store1.addItem(item1)
		stores.get("A").addItem(item2); // or store1.addItem(item2)
		stores.get("B").addItem(item1); // or store2.addItem(item1)
		stores.get("B").addItem(item2); // or store2.addItem(item2)
		// CHECK!
		showStatus(stores);

		// 3. Update Grocery name
		stores.get("A").name = "ART SHOP"; // or store1.name = "ART SHOP"
		System.out.println("Store of id ["+store1.id+"] successfully updated!");
		// CHECK!
		showStatus(stores);

		// 4. Update Item information
		stores.get("A").items.getFirst().name = "LAPTOP"; // or item1.name = "LAPTOP"
		System.out.println("Item of id ["+item1.id+"] successfully updated!");
		// CHECK!
		showStatus(stores);

		// 5. Remove Item and Store
		// Remove Item
		stores.get("A").removeItem(item1); // or store1.removeItem(item1)
		// CHECK!
		showStatus(stores);
		// Remove store1
		stores.remove("A");
		System.out.println("Store of id ["+store1.id+"] successfully removed!");
		// CHECK!
		showStatus(stores);
		
		// Remove store2
		stores.remove("B");
		System.out.println("Store of id ["+store2.id+"] successfully removed!");
		// CHECK!
		showStatus(stores);
	}

	private static void showStatus(HashMap<String, Store> stores) {
		System.out.println("CURRENT STATUS:");
		
		// if stores is empty
		if (stores.isEmpty()) {
			System.out.println("{there are no store}\n");
			return;
		}
		
		// iterate all store
		for (String str : stores.keySet()) {
			System.out.println("STORE: "+stores.get(str).name);
			
			// if items of current store is empty
			if (stores.get(str).items.isEmpty()) {
				System.out.println("{this store is empty}\n");
				continue;
			}
			
			// iterate all items of current store
			for (Item item : stores.get(str).items) {
				System.out.println("-> "+item.name);
			}
			System.out.println();
		}
	}
}
