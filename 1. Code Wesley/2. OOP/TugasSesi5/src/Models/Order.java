package Models;

import java.util.HashMap;

public class Order {
	public int id;
	public User user;
	public HashMap<Integer, Book> books;

	public Order(int id, User u) {
		this.id = id;
		user = u;
		books = new HashMap<>();
	}
	
	public void addBook(Book book) {
        books.put(book.id, book);
    }
}
