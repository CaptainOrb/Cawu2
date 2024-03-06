package models;

public class AcousticElectricGuitar extends Guitar {
	String sound;
	int tone;
	int volume;
	public AcousticElectricGuitar(String type) {
		super(type);
		sound = "crunch";
		tone = 0;
		volume = 0;
	}
	
	@Override
	public void getStatus() {
		System.out.printf("%s Guitar - %s - %d - %d%n", getType(), sound, tone, volume);
	}

}
