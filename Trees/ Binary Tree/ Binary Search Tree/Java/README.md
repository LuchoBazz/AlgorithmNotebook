# Binary Search Tree

## Contenido
* [Ilustración](#ilustración)
* [Problema a Resolver](#problema-a-resolver)
* [Implementación por Partes](#implementación-por-partes)
    * [Insertar](#insertar)
    * [Buscar](#buscar)
    * [Eliminar](#eliminar)
* [Recorridos](#recorridos)
    * [Depth-first Search](#depth-first-search)
        * [Pre-Order](#pre-order)
        * [In-Order](#in-order)
        * [Post-Order](#post-order)
    * [Breadth-first Search](#breadth-first-search)
* [Comparación Recorridos](#comparación-recorridos)
* [Complejidad](#complejidad)

## Ilustración


<img alt="Binary Search Tree" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/280px-Binary_search_tree.svg.png" width="250">

## Problema a Resolver

* Inserción y búsqueda de datos de manera óptima

## Implementación por Partes

* ### Insertar

```java
public void insert(T key) {
    if(this.root == null) {
        this.root = new TreeNode(key);
    } else {
        this.root = insert(this.root, key);
    }
}

private TreeNode insert(TreeNode<T> node, T key) {
    if(node == null) {
        return new TreeNode(key);
    }

    if(key.compareTo(node.value) < 0) { // key < node.value
        node.left = insert(node.left, key);
    } else if( key.compareTo(node.value) > 0) { // key > node.value
        node.right = insert(node.right, key);
    }
    return node;
}
```

* ### Buscar

```java
public T search(T key) {
    TreeNode<T> ans = search(this.root, key);

    if(ans == null) {
        return null;
    } else {
        return ans.value;
    }
}

private TreeNode<T> search(TreeNode<T> node, T key) {
    if(node == null || key.compareTo(node.value) == 0) {
        return node;
    }
    if(key.compareTo(node.value) < 0) { // key < node.value
        return search(node.left, key);
    }
    return search(node.right, key);
}
```

* ### Eliminar

```java
public TreeNode<T> delete(T key) {
    this.root = delete(this.root, key);
    return this.root;
}

private TreeNode<T> delete(TreeNode<T> node, T key) {
    if(isEmpty(node)) return null;

    if(key.compareTo(node.value) < 0) { // key < node.value
        node.left = delete(node.left, key);
    } else if(key.compareTo(node.value) > 0) { // key > node.value
        node.right = delete(node.right, key);
    } else {
        if(isLeaf(node)) {
            node = null;
        } else if(hasOneChild(node)) {
            if(node.left!=null) {
                node = node.left;
            } else { // node.right != null
                node = node.right;
            }
        } else { // hasTwoChild
            node.value = (T) minNode(node.right);
            node.right = delete(node.right, node.value);
        }
    }
    return node;
}

public T minNode(TreeNode<T> node) {
    TreeNode<T> ans = node;
    T out = node.value;

    while(ans != null) {
        out = ans.value;
        ans = ans.left;
    }
    return out;
}

private boolean isEmpty(TreeNode node) {
    return node == null;
}

private boolean isLeaf(TreeNode node) {
    if(isEmpty(node)) return false;
    return node.left == null && node.right == null;
}

private boolean hasOneChild(TreeNode node) {
    if(isEmpty(node)) return false;
    return (node.left!=null&&node.right==null)||(node.left==null&&node.right!=null);
}
```

## Recorridos

* ### Depth-first Search

    * ### Pre-Order
    ```java
    public void preOrder() {
        System.out.print("Pre-Order: ");
        preOrder(this.root);
        System.out.println();
    }

    private void preOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        System.out.print(node.value + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
    ```
    * ### In-Order

    ```java
    public void inOrder() {
        System.out.print("In-Order: ");
        inOrder(this.root);
        System.out.println();
    }

    private void inOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.value+" ");
        inOrder(node.right);
    }
    ```
    * ### Post-Order

    ```java
    public void postOrder() {
        System.out.print("Post-Order: ");
        postOrder(this.root);
        System.out.println();
    }

    private void postOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value+" ");
    }
    ```

* ### Breadth-first Search

```java
private void bfs(TreeNode<T> node) {
    if(isEmpty(node)) return;

    Queue<TreeNode<T>> queue = new LinkedList<>();
    queue.add(node);

    while(!queue.isEmpty()) {
        TreeNode<T> tmp = queue.remove();
        System.out.print(tmp.value + " ");

        if(!isEmpty(tmp.left)) {
            queue.add(tmp.left);
        }

        if(!isEmpty(tmp.right)) {
            queue.add(tmp.right);
        }
    }
    System.out.println();
}

public void bfs() {
    System.out.print("BFS: ");
    bfs(this.root);
    System.out.println();
}
```

### Comparación Recorridos

<img alt="Binary Search Tree" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/280px-Binary_search_tree.svg.png" width="200">

* **Pre-Order:** `8 3 1 6 4 7 10 14 13`
* **In-Order:** `1 3 4 6 7 8 10 13 14`
* **Post-Order:** `1 4 7 6 3 13 14 10 8`
* **BFS:** `8 3 10 1 6 14 4 7 13`

## Complejidad

* _Insertar_:

![Complejidad de Insertar](https://i.ibb.co/RzJ8t4m/Log-n.png)

* _Buscar_:

![Complejidad de Buscar](https://i.ibb.co/RzJ8t4m/Log-n.png)

* _Eliminar_:

![Complejidad de Eliminar](https://i.ibb.co/RzJ8t4m/Log-n.png)