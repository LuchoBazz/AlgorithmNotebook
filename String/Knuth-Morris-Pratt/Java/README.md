# KMP - Knuth-Morris-Pratt algorithm - Java

## Contenido

* [Contenido](#contenido)
* [Implementación](#implementación-iterativa)
    * [Search](#search)
    * [Longest Prefix Suffix Array](#longest-prefix-suffix-array)
    * [Main](#main)
* [Time Complexity](#time-complexity)

## Implementación

* ### Search

```java
public List<Integer> search(String txt, String pat) {
    List<Integer> output = new ArrayList<>();
    
    int N = txt.length();
    int M = pat.length();
    
    if(M > N) return output;
    
    // Longest Prefix Suffix
    int lps[] = new int[M]; 
    int j = 0; // index for pat[] 
    
    // Calcular el array con los datos del 'Longest Prefix Suffix'
    LPS(pat, lps); 

    int i = 0; // index for txt[] 
    
    while (i < N) { 
        if (pat.charAt(j) == txt.charAt(i)) { 
            j++; 
            i++; 
        }
        
        if (j == M) {
            // Found pattern at index (i-j)
            output.add(i-j);
            j = lps[j - 1]; 
        } else if (i < N && pat.charAt(j) != txt.charAt(i)) { 
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i = i + 1; 
            }
        } 
    }
    return output;
} 
```

* ### Longest Prefix Suffix Array

```java
private void LPS(String pat, int lps[]) { 
    int M = pat.length();
    int len = 0; 
    int i = 1; 
    lps[0] = 0; // lps[0] siempre es 0

    // Calcular lps[i] para i = 1 to M-1 
    while (i < M) { 
        if (pat.charAt(i) == pat.charAt(len)) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } else { 
                lps[i] = len; 
                i++; 
            } 
        } 
    }
}
```

* ### Main

```java
public static void main(String[] args) {
    String txt = "ABABDABACDABABCABAB"; 
    String pat = "ABAB"; 
    List<Integer> ans = new KMP().search(txt, pat);
    
    for(Integer index: ans) {
        System.out.println("Found pattern at index: "+ index);
    }

    // Output[1]:
    // Found pattern at index: 0
    // Found pattern at index: 10
    // Found pattern at index: 15
}
```

## Time Complexity

<img alt="KMP Time Complexity" src="https://i.ibb.co/swGGZrY/O-n-n-string-length.png" width="250">