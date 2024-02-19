
public class Document {
	String name;
	int size;
	private String status;
	public Document(String name, int size, String status) {
		this.name = name;
		this.size = size;
		this.setStatus(status);
	}
	
	public String getStatus() {
		return status;
	}
	
	public void setStatus(String status) {
		this.status = status;
	}
}
