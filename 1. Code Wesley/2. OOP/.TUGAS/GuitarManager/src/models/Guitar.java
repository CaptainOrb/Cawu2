package models;

public class Guitar {
	private String type;

	public Guitar(String type) {
		this.setType(type);
	}
	
	public void getStatus() {
		System.out.printf("%s Guitar%n", type);
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}
}