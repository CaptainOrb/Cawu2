import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Data user = new Data();

        System.out.print("Input your name: ");
        user.name = input.next();
        System.out.print("Input your age: ");
        user.age = input.nextInt();
        System.out.print("Input your temperature: ");
        user.temperature = input.nextDouble();

        System.out.println("Your name is " + user.name);
        System.out.println("Your age is " + user.age);
        System.out.println("Your temperature is " + user.temperature);

    }
}

