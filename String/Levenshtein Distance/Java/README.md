# Levenshtein Distance

La distancia de Levenshtein es una métrica de `strings` para medir la diferencia entre dos secuencias. Informalmente, la distancia de _Levenshtein_ entre dos palabras es el número mínimo de ediciones (insertando, eliminando o sustituiendo) de un solo carácter requeridos para cambiar una palabra a la otra.

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Función](#función)
* [Implementación Iterativa](#implementación-iterativa)
* [Complexity](#complexity)

## Ilustración

<img alt="Levenshtein Distance 1" src="https://camo.githubusercontent.com/6abc54ac1673ed8ba5ab86aa5a767da6a082b71b/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313630302f312a6154756e53556f7930424a795942566e3474574772412e706e67" width="500">

<img alt="Levenshtein Distance 2" src="https://camo.githubusercontent.com/3b44aa1117054ea0d35df1da737bde312810f85f/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313630302f312a7738554234445376426e414b366d4258524751446a772e706e67" width="500">

<img alt="Levenshtein Distance 3" src="https://camo.githubusercontent.com/33de0697ab4dc333b323c8cdfe30e2cedd78fad2/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f313630302f312a386a4430717672354239507752464d5f397a377139412e706e67" width="500">

<img alt="Levenshtein Distance 3" src="https://camo.githubusercontent.com/cdaf8a4804d2312fb4eee2d9bb3621ffffcbe665/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6d61782f323630302f312a343937674d614645727a4a70435847376b535f3764772e706e67" width="500">

## Problema a Resolver

Calcular el minimo numero de ediciones (insertando, eliminando o sustituiendo) de un carácter requeridos para cambiar una palabra a la otra.

## Función

<img alt="Levenshtein Distance 3" src="https://i.ibb.co/JQ4vtwk/Levenshtein-Distance.png" width="500">

## Implementación Iterativa

```java
public int minDistance(String word1, String word2) {
    
    int size1 = word1.length();
    int size2 = word2.length();
    
    int[][] dp = new int[size1+1][size2+1];

    char c1=' ', c2=' ';
    int indicator = 0;
    
    // Llenar la columna 0
    for(int i = 0; i <= size1; ++i) {
        dp[i][0] = i;
    }
    
    // Llenar la fila 0
    for(int j = 0; j <= size2; ++j) {
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= size1; ++i) {
        c1 = word1.charAt(i-1);

        for(int j = 1; j <= size2; ++j) {
            c2 = word2.charAt(j-1);
            
            // Si son iguales no hay que cambiar nada
            if(c1 == c2) indicator = 0;
            else indicator = 1;

            dp[i][j] = min(
                dp[i - 1][j] + 1,  // Deletion
                dp[i][j - 1] + 1,  // Insertion
                dp[i - 1][j - 1] + indicator // Substitution
            );
        }
    }   
    
    return dp[size1][size2];
}

private int min(int x, int y, int z) {
    return Math.min(x, Math.min(y, z));
}
```

## Complexity

<img alt="Complexity Levenshtein Distance" src="https://i.ibb.co/YRGpRNC/O-n-mul-m.png" width="450">