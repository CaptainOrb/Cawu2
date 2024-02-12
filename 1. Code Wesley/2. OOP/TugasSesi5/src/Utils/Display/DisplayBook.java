package Utils.Display;

import java.util.HashMap;

import Models.Book;

public class DisplayBook {
	public static void displayBooks(HashMap<Integer, Book> books) {
		System.out.println(books);
	}
	public static void displayBookDetail(HashMap<Integer, Book> books, Integer bookId) {
		System.out.println(books.get(bookId).title);
		System.out.println(books.get(bookId).yearPublished);
		System.out.println(books.get(bookId).author);
		System.out.println(books.get(bookId).id);
	}
}
