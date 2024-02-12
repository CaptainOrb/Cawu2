package Utils.Display;

import java.util.HashMap;

import Models.User;

public class DisplayUser {
	public static void displayUsers(HashMap<Integer, User> users) {
		System.out.println(users);
	}
	public static void displayUserDetail(HashMap<Integer, User> users, Integer userId) {
		System.out.println(users.get(userId).name);
		System.out.println(users.get(userId).getEmail());
		System.out.println(users.get(userId).username);
		System.out.println(users.get(userId).getId());
	}
}
