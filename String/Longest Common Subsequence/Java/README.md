# Longest Common Subsequence

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Implementación Iterativa](#implementación-iterativa)
* [Implementación Recursiva](#implementación-recursiva)
* [Obtener Subsecuencia](#obtener-subsecuencia)
* [Ejemplo](#ejemplo)
* [Complexity](#complexity)

## Ilustración

<img alt="Ilustración Longest Common Subsequence" src="https://www.dotnetlovers.com/images/coolnikhilj2265da340b-f1ff-41a2-8f17-670bf36a4ab1.png?1/3/2017%201:08:47%20AM" width="300">

## Problema a Resolver

Calcula la subsecuencia común más larga de todas las secuencias en un conjunto de secuencias.

## Implementación Iterativa

```java
public int longestCommonSubsequence(String text1, String text2) {
    int size1 = text1.length();
    int size2 = text2.length();
    
    int[][] dp = new int[size1+1][size2+1];
    
    for(int i = 0; i <= size1; ++i) {
        for(int j = 0; j <=size2; ++j) {
            if(i==0 || j==0) {
                // Llenar de 0's la primera fila y primera columna
                dp[i][j] = 0;
            } else if(text1.charAt(i-1) == text2.charAt(j-1)) {
                // if hay un match: tomar la diagonal anterior y sumarle 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                // Tomar los valores maximos de los anteriores
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[size1][size2];
}
```

## Implementación Recursiva

```java
int size1 = s1.length();
int size2 = s2.length();
Integer[][] dp = new Integer[size1+1][size2+1];

longestCommonSubsequence(s1, s2, size1, size2);

public int longestCommonSubsequence(String s1, String s2, int n, int m) {
    if(n==0 || m==0) return 0;
    
    if(dp[n][m] != null) return dp[n][m];
    
    if(s1.charAt(n - 1) == s2.charAt(m - 1)) {
        return 1 + longestCommonSubsequence(s1, s2, n - 1, m - 1);
    } 
    
    dp[n][m] = Math.max(
        longestCommonSubsequence(s1, s2, n - 1, m),
        longestCommonSubsequence(s1, s2, n, m - 1)
    );
    return dp[n][m];
}
```

## Obtener Subsecuencia

```java
public String getSubsequence(String s1, String s1, Integer[][] dp) {
    int n = s1.length();
    int m = s2.length();
    
    StringBuilder sb = new StringBuilder();
    
    while(n >0 && m > 0) {
        if(text1.charAt(n-1) == text2.charAt(m-1)) {
            // Diagonal
            sb.append(text1.charAt(n-1));
            n--;
            m--;
        } else {
            if(dp[n-1][m] >= dp[n][m-1]){
                // Izquierdo
                n--;
            } else {
                // Arriba
                m--;
            }
        }
    }
    return sb.reverse().toString();
}
```

## Ejemplo

AG**GTAB** y **G**X**T**X**A**Y**B** = **GTAB**

----A G G T A B<br/>
---0 0 0 0 0 0 0<br/>
G 0 0 **1** 1 1 1 1 **G**<br/>
X 0 1 1 1 1 1 1<br/>
T 0 1 1 1 **2** 2 2 **T**<br/>
X 0 1 1 1 2 2 2<br/>
A 0 1 1 1 2 **3** 3 **A**<br/>
Y 0 1 1 1 2 3 3<br/>
B 0 1 1 1 2 3 **4** **B**<br/>
## Complexity

<img alt="Complexity Longest Common Subsequence" src="https://i.ibb.co/YRGpRNC/O-n-mul-m.png" width="450">