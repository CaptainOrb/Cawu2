package Models;

public class User {
	private int id;
	public String name;
	private String email;
	public String username;

	public User(int i, String n, String e, String u) {
		setId(i);
		name = n;
		setEmail(e);
		username = u;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
}
