import java.util.ArrayList;
import java.util.Scanner;

public class UserManagement {
    private ArrayList<User> userArrayList;

    public UserManagement(){
        this.userArrayList = new ArrayList<>();
    }

    public void addUser(String username, String email){
        User user = new User(username, email);
        userArrayList.add(user);
    }

    public void addUsersFromInput(){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of user: ");
        int numUsers = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < numUsers; i++) {
            String username = sc.nextLine();
            String email = sc.nextLine();
            addUser(username, email);
        }
    }

    public User findUser(String username){
        for (User user : userArrayList){
            if (user.getUsername().equals(username)){
                return user;
            }
        }
        return null;
    }
}