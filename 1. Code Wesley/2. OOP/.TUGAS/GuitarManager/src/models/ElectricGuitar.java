package models;

public class ElectricGuitar extends Guitar {
	String sound;
	int tone;
	int volume;
	int switchPosition;
	
	public ElectricGuitar(String type, int switchPosition, int tone, int volume) {
		super(type);
		this.switchPosition = switchPosition;
		this.tone = tone;
		this.volume = volume;
		if (switchPosition == 1) this.sound = "Funk";
		else if (switchPosition == 2) this.sound = "Jazz";
		else if (switchPosition == 3) this.sound = "Blues";
		else if (switchPosition == 4) this.sound = "Rock";
	}
	
	@Override
	public void getStatus() {
		System.out.printf("%s Guitar - %s - %d - %d - %d%n", getType(), sound, tone, volume, switchPosition);
	}

}
