import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        /*
            ArrayList: Dynamic, size can be modified, and the index is sorted.
            (ordered list)
        */
        System.out.println("\nArrayList");
        ArrayList<String> students = new ArrayList<String>();
        students.add("Wesley");
        students.add("Artika");
        students.add("Christo");

        String firstStudent = students.getFirst(); // or get(0)
        System.out.println(firstStudent);

        System.out.println("\nUsing for-each loop:");
        for (String student : students){
            System.out.println(student);
        }

        // ========================================================================

        /*
            HashSet: Value has to be unique and there is no such thing as index.
            Basically, it's a set of data. You can convert HashSet to Array using toArray().
            (unordered list)
        */
        System.out.println("\n\nHashSet");
        HashSet<String> friends = new HashSet<String>();

        friends.add("Baylee");
        friends.add("Jason");
        friends.add("Olivio");
        friends.add("Naomi");
        friends.add("Olivio");

        System.out.println("Friends: " + friends);

        // ========================================================================

        /*
            HashMap: It maps a key into a value. Similar to the concept of Dictionary.
            Basically, key is the index here. The key has to be unique.
            Key and value can be NULL.
        */
        System.out.println("\n\nHashMap");
        HashMap<String, Integer> grades = new HashMap<String, Integer>();
        grades.put("Artika", 100);
        grades.put("Wesley", 97);
        grades.put("Naomi", 99);
        grades.put("Olivio", 101);

        System.out.println("All grades: " + grades);

        System.out.println("Artika's grade: " + grades.get("Artika"));
    }
}
