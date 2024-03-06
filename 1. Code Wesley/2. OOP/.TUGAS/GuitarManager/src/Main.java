import java.util.*;

import models.*;

public class Main {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
	List<Guitar> guitars = new ArrayList<>();
		
		while (true) {
			switch (menu()) {
				case 1: {
					System.out.println("\n1. Acoustic");
					System.out.println("2. Electric");
					System.out.println("3. Acoustic Electric");
					
					int select;
					do {
						System.out.print("Input guitar type [1..3]: ");
						select = in.nextInt();
						in.nextLine();
					} while (select < 1 || select > 3);
					
					
					if (select == 1) {
						guitars.add(new AcousticGuitar("Acoustic"));
					}
					else if (select == 2) {
						int switchPosition;
						do {
							System.out.print("Input switch position: ");
							switchPosition = in.nextInt();
							in.nextLine();
						} while (switchPosition < 1 || switchPosition > 4);
						int tone;
						System.out.print("Input tone: ");
						tone = in.nextInt();
						in.nextLine();
						int volume;
						System.out.print("Input volume: ");
						volume = in.nextInt();
						in.nextLine();
						guitars.add(new ElectricGuitar("Electric", switchPosition, tone, volume));
					}
					else if (select == 3) {
						guitars.add(new AcousticElectricGuitar("Acoustic Electric"));
					}
					
					System.out.println();
					break;
				}
				case 2: {
					for (Guitar g : guitars) {
						g.getStatus();
					}
					in.nextLine();
					System.out.println();
					break;
				}
				case 3: {
					return;
				}
			}
		}
	}
	
	public static int menu() {
		System.out.println("1. Buat Gitar");
		System.out.println("2. Tampilkan Daftar Gitar");
		System.out.println("3. Keluar");
		int select;
		do {
			System.out.print("Choose menu[1..3]: ");
			select = in.nextInt();
			in.nextLine();
		} while (select < 1 || select > 3);
		return select;
	}
}
