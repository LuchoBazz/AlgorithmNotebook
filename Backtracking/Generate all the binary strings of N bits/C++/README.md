# Generate all the binary strings of N bits - C++

Calcular todos los string binarios de N bits

## Contenido

* [Contenido](#contenido)
* [Implementacion](#implementacion)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

### Implementacion

```c++
const int n = 3;
vector<bool> bits(n);

void printBits() {
	for(int i = 0; i < n; ++i) {
		cout << (bits[i])?1:0;
	}
	cout << endl;
}

void backtracking(int i) {
	if(i == n) {
		printBits();
	} else {
		bits[i] = true;
		backtracking(i+1);
		bits[i] = false;
		backtracking(i+1);
	}
}
```

### Time Complexity

```c++
O(2^n)

Donde n es el numero de bits
```

### Space Complexity

```c++
Si no almaceno los resultados en un array
O(n)

Si almaceno los resultados en un array
O((2^n)*n)
Donde n es el numero de bits
```