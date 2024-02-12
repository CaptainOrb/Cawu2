package Utils.DataManagement;

import java.util.HashMap;

import Models.User;

public class UserManagement {
	public static void addUser(HashMap<Integer, User> users, String n, String e, String u) {
		if (users.isEmpty()) {
			users.put(1,  new User(1, n, e, u));
		}
		else {
			Integer[] keys = users.keySet().toArray(new Integer[users.size()]);
			Integer lastId = keys[keys.length-1];
			users.put(lastId+1, new User(lastId+1, n, e, u));
		}
	}

	public static User getUser(HashMap<Integer, User> users, int userId) {
		return users.get(userId);
	}
	
	public static void deleteUser(HashMap<Integer, User> users, int userId) {
		users.remove(userId);
	}
}
