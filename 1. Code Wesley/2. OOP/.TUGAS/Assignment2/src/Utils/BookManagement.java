package Utils;

import java.util.HashMap;
import Models.Book;

public class BookManagement {
	public static void addBook(HashMap<Integer, Book> books, String t, Integer yp, String a) {
		if (books.size() == 0) {
			books.put(1, new Book(1, t, yp, a));
		}
		else {
			Integer[] keys = books.keySet().toArray(new Integer[books.size()]);
			Integer lastId = keys[keys.length-1];
			books.put(lastId+1, new Book(lastId+1, t, yp, a));
		}
	}
	
	public static Book getBook(HashMap<Integer, Book> books, int bookId) {
		return books.get(bookId);
	}

	public static void deleteBook(HashMap<Integer, Book> books, int bookId) {
		books.remove(bookId);
	}

}
