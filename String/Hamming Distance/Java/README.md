# Hamming Distance

La distancia de Hamming entre dos cadenas de igual longitud es el número de posiciones en las que los símbolos correspondientes son diferentes.

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Ilustración Iterativa](#ilustración-iterativa)
* [Complexity](#complexity)

## Ilustración Iterativa

<img alt="Levenshtein Distance 1" src="https://miro.medium.com/max/643/1*Q4rdY5KN91aZjvGXl7SRug.png" width="500">

## Problema a Resolver

Calcular el minimo numero de sustituciones de un carácteres requeridos para cambiar una palabra a la otra.

**Nota:** La condicion es que sean de la misma longitud

## Implementación

```java
public static int hammingDistance(String s1, String s2) {
    int distance = 0;
    int size1 = s1.length();
    int size2 = s2.length();
    
    if(size1 == size2) {
        for(int i = 0; i < size1; ++i) {
            if(s1.charAt(i) != s2.charAt(i)) {
                distance++;
            }
        }
        return distance;
    }
    return -1;
}
```

## Complexity

<img alt="Complexity Hamming Distance" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">