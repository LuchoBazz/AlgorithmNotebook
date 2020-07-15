# N-ary Tree / Java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Recorridos](#recorridos)
    * [Depth-first Search](#depth-first-search)
        * [Pre-Order (Recursive)](#pre-order-recursive)
        * [Pre-Order (Iterative)](#pre-order-iterative)
        * [Post-Order (Recursive)](#post-order-recursive)
        * [Post-Order (Iterative)](#post-order-iterative)
    * [Breadth-first Search](#breadth-first-search)
* [Comparación Recorridos](#comparación-recorridos)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="N-ary Tree" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" width="300">

## Recorridos

* ### Depth-first Search
    * ### Pre-Order (Recursive)
    ```java
    public static void preOrden(TreeNode node) {
        if(isEmpty(node)) return;
        
        System.out.println(node.value);
        
        for(TreeNode child: node.children) {
            preOrden(child);
        }
    }
    ```
    * ### Pre-Order (Iterative)
    ```java
    public List<Integer> preOrder(TreeNode root) {
        List<Integer> output = new ArrayList<>();
        
        Stack<TreeNode> stack = new Stack<>();
        
        stack.push(root);
        
        TreeNode tmp = null;
        
        while(!stack.isEmpty()) {
            tmp = stack.pop();
            if(!isEmpty(tmp)) {
                output.add(tmp.val);
                List<TreeNode> children = tmp.children;
            
                for(int i = children.size() - 1; i >= 0; --i) {
                    if(children.get(i) != null) {
                        stack.push(children.get(i));    
                    }
                }
            }
            
        }
        return output;
        
    }

    private boolean isEmpty(TreeNode node) {
        return node == null;
    }
    ```

    * ### Post-Order (Recursive)
    ```java
    public static void postOrden(TreeNode node) {
        if(isEmpty(node)) return;
        
        for(TreeNode child: node.children) {
            postOrden(child);
        }
        System.out.println(node.value);
    }
    ```

    * ### Post-Order (Iterative)
    ```java
    public static void postOrden(TreeNode root) {
        List<Integer> output = new ArrayList<>();
        
        Stack<TreeNode> stack = new Stack<>();
        
        stack.add(root);
        
        TreeNode tmp = root;
        
        while(!stack.isEmpty()) {
            tmp = stack.pop();
            
            if(!isEmpty(tmp)) {
                output.add(tmp.value);
                for(TreeNode node: tmp.children) {
                    stack.add(node);
                }
            }
            
        }
        
        Collections.reverse(output);
        
        for(Integer number: output) {
            System.out.println(number);
        }
    }
    ```

* ### Breadth-first Search

```java
public void bfs(TreeNode root) {
    List<List<Integer>> output = new ArrayList<>();
    
    Queue<TreeNode> queue = new LinkedList<>();
    
    queue.add(root);
    
    TreeNode tmp = null;
    
    while(!queue.isEmpty()) {
        tmp = queue.remove();
        
        if(!isEmpty(tmp)) {
            System.out.println(tmp.value);
            
            for(TreeNode node: tmp.children) {
                queue.add(node);
            }
        }
    }
}
```

## Comparación Recorridos

<img alt="N-ary Tree" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" width="250">

* **Pre-Order:** `1 2 3 6 7 11 14 4 8 12 5 9 13 10`
* **Post-Order:** `2 6 14 11 7 3 12 8 4 13 9 10 5 1`
* **BFS:** `1 2 3 4 5 6 7 8 9 10 11 12 13 14`

## Time Complexity

<img alt="N-ary Tree" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">

## Space Complexity

<img alt="N-ary Tree" src="https://i.ibb.co/brG8ZMM/O-n.png" width="50">