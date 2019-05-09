# Binary Tree Traversals

## InOrder Traversal
```
inOrder(Node* nd) {
	if (nd != NULL) {
		inOrder(nd->leftChild);
		visit(nd);
		inOrder(nd->rightChild);
	}
}
```

## PreOrder Traversal
```
visit(nd)
preOrder(nd->leftChild)
preOrder(nd->rightChild)
```

## PostOrder Traversal
```
postOrder(nd->leftChild)
postOrder(nd->rightChild)
visit(nd)
```

## Accessing Sorted Data
 - goal is to perform insert, delete, look up operations in at most O(logn) time
 - and be able to create an empty dictionary

# Binary Search Tree
- for any node in a BST, all nodes to its left <= node <= all nodes to its right (aka fully ordered)
- inorder traversal on BST retrieves data in sorted order

## BST Implementation
Reference structure:
1. Node* leftChild
2. data
3. Node* rightChild

## BST Search
```
bool search(Node* nd, T data){
	if(nd == NULL){
		return false;
	}
	else if(x == nd->data){
		return true;
	}
	else if (x < nd->data){
		return search(nd->left, data);
	}
	else {
		return search(nd->right, data);
	}
}
```
Operation count: one for each node on the path
- worst case: height of the tree + 1

## BST Insertion
Perform search and insert node as new leaf:
- if search ends at the NULL left child of a node, insert node as left child
- if search ends at the NULL right child of a node, insert node a sright child
Operation count: same as the cost of the search algorithm, O(height)

## BST Deletion
Cases:
1. Node to be deleted has no children
	- remove it (assign NULL to its parent's reference)
2. node to be deleted has one child
	- replace node with its subtree
3. node to be deleted has two children
	- comlicated

### Looking Ahead (Case 2)
- check node is not null before accessing its member variables
- check if node a left or right child
```
while(target != nd->data)
	if (nd == NULL)
		return
	if (target < nd->data)
		parent = nd
		nd = nd -> left
		isLeftChild = true
	else
		parent = nd
		nd = nd->right
		isLeftChild = false
```

### Case 3 (Node to be deleted has two children)
Cannot delete and replace with one of its childrens (subtree)
- ex. the replacement node also has two children, then it now needs to take on three children

__Predecessor__ of a node is the rightmost node of its left subtree (that is, largest value less than the node's value).
- has at most one child
- greater than the rest of the (to-be-deleted) node's left subtree
- less than the node's right subtree

Likewise a __successor__ of a node.

Steps:
1. find predecessor (or successor)
2. attach predecessor's subtree to the predecessor's parent
3. attach (to-be-deleted) node's children to predecessor
4. attach predecessor to the node's parent
5. delete node

## BST Deletion alternatives

1. mark as deleted (setting to null)
	- for insertion, insert new item in an empty node that is found on the way down the tree
2. copy predecessor data into node to be "deleted", then delete the predecessor node
	- avoids complicated pointer assignments

## BST Efficiency
Search, insert, delete are O(height).
- if tree is complete (every level except possibly the last is completely filled, and all nodes are as far left as possible), then the height is floor(logn)

## Sorting array using BST
1. insert array item into empty tree
2. retrieve data into array using InOrder traversal on BST









