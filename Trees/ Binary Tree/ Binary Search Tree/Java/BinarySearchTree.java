
// Notebook
// https://github.com/LuisMBaezCo/AlgorithmNotebook/tree/master/Tree/%20Binary%20Search%20Tree/Java

class BinarySearchTree <T extends Comparable<T>> {

    TreeNode<T> root;

    BinarySearchTree() {
        this.root = null;
    }

    BinarySearchTree(TreeNode<T> root) {
        this.root = root;
    }

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

    public boolean isEmpty() {
        return this.root == null;
    }

    private void preOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        System.out.print(node.value + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    private void inOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.value + " ");
        inOrder(node.right);
    }

    private void postOrder(TreeNode node) {
        if(node == null) {
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value+" ");
    }

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

    public void preOrder() {
        System.out.print("Pre-Order: ");
        preOrder(this.root);
        System.out.println();
    }

    public void inOrder() {
        System.out.print("In-Order: ");
        inOrder(this.root);
        System.out.println();
    }

    public void postOrder() {
        System.out.print("Post-Order: ");
        postOrder(this.root);
        System.out.println();
    }

    public void bfs() {
        System.out.print("BFS: ");
        bfs(this.root);
        System.out.println();
    }

    static class TreeNode<T extends Comparable<T>> {
       public T value;
       public TreeNode left;
       public TreeNode right;
       TreeNode(T value) {
           this.value = value;
       }
    }

    static class Data implements Comparable <Data> {
        int number;

        Data(int number) {
            this.number = number;
        }

        @Override
        public int compareTo(Data data) {
            return Integer.compare(this.number, data.number);
        }

        @Override
        public String toString() {
            return Integer.toString(this.number);
        }
    }

    public static void main(String args[]) {
        BinarySearchTree<Data> bst = new BinarySearchTree<>();

        //     5
        //    / \
        //   3   6
        //  / \   \
        // 2   4   7
        bst.insert(new Data(5));
        bst.insert(new Data(3));
        bst.insert(new Data(6));
        bst.insert(new Data(2));
        bst.insert(new Data(4));
        bst.insert(new Data(7));

        bst.delete(new Data(5));

        Data ans = bst.search(new Data(2));

        if(ans != null) {
            System.out.println(ans);
        } else {
            System.out.println("Data not Found");
        }
    }
}