# Template Java for Programming Contest

### Contenido
* [Codeforces](#codeforces)
    * [Codigo Fuente](#codigo-fuente)

### Codeforces

* ### Codigo Fuente
```java
import java.io.*;
import java.util.*;

public class Solution {

    static PrintStream out = System.out;
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {

        if (System.getProperty("LOCAL") != null) {
            try {
                File file = new File("input.txt");
                in = new Scanner(file);
            } catch (Exception ex) {}
        }
        // your code goes here
       
        in.close();
    } 
}

```

**Compiler:**

```bash
javac Solution.java 
java -DLOCAL="" Solution
```
