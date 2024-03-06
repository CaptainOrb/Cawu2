package models;

public class AcousticGuitar extends Guitar {
	String sound;
	
	public AcousticGuitar(String type) {
		super(type);
		sound = (Math.random() < 0.5)? "warm": "bright";
	}

	@Override
	public void getStatus() {
		System.out.printf("%s Guitar - %s%n", getType(), sound);
	}
}
