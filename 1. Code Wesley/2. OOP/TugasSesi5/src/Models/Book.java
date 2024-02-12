package Models;

public class Book {
	public final int id;
	public String title;
	public int yearPublished;
	public String author;

	public Book(int id, String title, int yearPublished, String author) {
		this.id = id;
		this.title = title;
		this.yearPublished = yearPublished;
		this.author = author;
	}

}
