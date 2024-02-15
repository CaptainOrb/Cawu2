package models;

public class Item {
	private final String id;
	public String name;
	public String brand;
	public int price;
	public int quantity;

	public Item(String id, String name, String brand, int price, int quantity) {
		this.id = id;
		this.name = name;
		this.brand = brand;
		this.price = price;
		this.quantity = quantity;
	}

	public String getId() {
		return id;
	}
}
