import java.util.HashMap;
import utils.*;
import models.*;

public class Main {
	public static void main(String[] args) {
		// maps an ID to a Store
		HashMap<String, Store> stores = new HashMap<>();
		
		
		// 1. Insert new Store
		Management.addStore(stores, "19", "Tika 2 Shop", 4);
		Management.addStore(stores, "19", "Tika 1 Shop", 2);
		Management.addStore(stores, "18", "Tika 3 Shop", 2);
		
		// SHOW STORES!
		Management.showStore(stores);
		
		
		// 2. Insert item to grocery
		stores.get("19").addItem("17", "Pepsodent", "Indofood", 17000, 3);
		stores.get("19").addItem("18", "SENSODYNE", "Sedaap", 27000, 33);
		// other way to do it: (overloading)
		Item item1 = new Item("17", "Barley", "ABC", 37000, 333);
		stores.get("19").addItem(item1);
		
		// SHOW ITEMS!
		stores.get("19").showItems();
		
		
		// 3. Update Store name
		stores.get("19").name = "Tika Shop";
//		store1.maxItem = 1; // doesn't work because maxItem is final
		
		// SHOW STORES!
		Management.showStore(stores);
		
		// 4. Update item info
		item1.name = "Pepsiman";
		item1.brand = "AMBITIS";
		item1.price = 15000;
		item1.quantity = 33;
		// This only update item1, not the item in store!
		// To update the item in store:
		stores.get("19").items.get("17").name = "PEPSODENT";
		
		// SHOW BOTH!
		stores.get("19").showItems();
		Management.showStore(stores);
		

		// 5. Remove item and store
		Management.deleteStore(stores, "18");
		stores.get("19").deleteItem("18");
		
		// SHOW BOTH!
		stores.get("19").showItems();
		Management.showStore(stores);
	}
}
