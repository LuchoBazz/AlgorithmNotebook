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
        // INPUT
        String s = in.next();
        int x =    in.nextInt();
        short y =  in.nextShort();
        long z =   in.nextLong();
        float a =  in.nextFloat();
        double b = in.nextDouble();
        
        //OUTPUT
        out.println("Hello World: " + x);
        out.print(y);
        out.printf("%d %d %d = %s", x, y, z, s);
    } 
}
```

**Compiler:**

```bash
javac Solution.java 
java Solution
```
