# Longest Common SubString - Java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Implementación Iterativa](#implementación-iterativa)
* [Implementación Recursiva](#implementación-recursiva)
* [Obtener SubStrings](#obtener-substrings)
* [Ejemplo](#ejemplo)
* [Complexity](#complexity)

## Ilustración

<img alt="Ilustración Longest Common SubString" src="https://timetocode.files.wordpress.com/2017/06/longest-common-substring-21.png?w=376" width="300">

## Problema a Resolver

Dado dos strings `X` and `Y`, encontrar la longitud y las cadenas del substring común mas largo.


## Implementación Iterativa

```java
// Main:
String s1 = "LCLC";
String s2 = "CLCL";

int maxLength = commonSubStrings(s1, s2);
System.out.println(maxLength);
// 3

// -- // -- // --
public static int commonSubStrings(String s1, String s2) {
    int n = s1.length();
    int m = s2.length();

    int[][] dp = new int[n][m];
    int max = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {

            if(s1.charAt(i) == s2.charAt(j)) {
                if(i==0 || j==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                
                max = Math.max(max, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return max;
}
```

## Implementación Recursiva

```java
// Main:
String s1 = "LCLC";
String s2 = "CLCL";

int size1 = s1.length();
int size2 = s2.length();

Integer[][] dp = new Integer[size1+1][size2+1];

int maxLength = lcs(s1, s2, size1, size2);
System.out.println(maxLength);
// 3

// -- // -- // --
public static int lcs(String s1, String s2, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    
    if(dp[n][m] != null) return dp[n][m];
    
    if (s1.charAt(n-1) == s2.charAt(m-1)) { 
        return 1 + lcs(s1, s2, n - 1, m - 1); 
    } 
    dp[n][m] = Math.max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m)); 
    return dp[n][m];
}
```

## Obtener SubStrings

```java
// Main:
List<String> ans = commonSubStrings("LCLC", "CLCL");

for(String sub: ans) {
    System.out.println(sub);
}
// LCL
// CLC

// -- // -- // --
public static List<String> commonSubStrings(String s1, String s2) {
    int n = s1.length();
    int m = s2.length();
    int[][] dp = new int[n][m];
    List<String> substrings = null;
    int max = Integer.MIN_VALUE;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {

            if(s1.charAt(i) == s2.charAt(j)) {
                if(i==0 || j==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                
                if(dp[i][j] > max) {
                    max = dp[i][j];
                    substrings = new ArrayList<>();
                    substrings.add(s1.substring(i - max+1, i+1));
                } else if(dp[i][j] == max) {
                    substrings.add(s1.substring(i - max+1, i+1));
                }
                
            } else {
                dp[i][j] = 0;
            }
        }
    }
    // max: length of Longest Common Substring
    return substrings;
}
```

## Ejemplo

* **Input:** X = "GeeksforGeeks", y = "GeeksQuiz"
* **Output:** 5

    El SubString Común mas largo es `Geeks` y la longitud es 5.

* **Input:** X = "abcdxyz", y = "xyzabcd"
* **Output:** 4

    El SubString Común mas largo es `abcd` y la longitud es 4.

* **Input:** X = "zxabcdezy", y = "yzabcdezx"
* **Output:** 6

    El SubString Común mas largo es `abcdez` y la longitud es 6.

## Complexity

<img alt="Complexity Longest Common SubString" src="https://i.ibb.co/YRGpRNC/O-n-mul-m.png" width="450">