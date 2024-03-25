package models;

public class Person {
	private String name;
	private String address;

	public Person(String name, String address) {
		this.name = name;
		this.setAddress(address);
	}

	public String getName() {
		return name;
	}
	
	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}
	
	public String toString() {
		return this.name + "(" + this.address + ")";
	}

}
