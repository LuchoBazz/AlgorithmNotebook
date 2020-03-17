import java.io.*;
import java.util.*;

public class Solution {

    static PrintStream out = System.out;
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {

        if (System.getProperty("LOCAL") != null) {
            try {
                File file = new File("input-[1].txt");
                in = new Scanner(file);
            } catch (Exception ex) {}
        }
        // your code goes here
       
        in.close();
    } 
}
// javac Solution.java 
// java -DLOCAL="" Solution
