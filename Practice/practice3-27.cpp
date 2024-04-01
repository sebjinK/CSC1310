/*
Binary search trees
- 
trees are just lined lists but each node has two next pointers instead of one. 
The "depth" of a tree or the height is the number of generations

Binary search trees are organized in order to simplify searches


Creating a new node:
newNode = new TreeNode;
newNode->value = data;

inserting a new node
- 
1 - if empty:
    insert new node as root node
2 - else compare values against each other
    if newNode1->value < newNdoe2->value;
        newNode2 = left value
    else
        newNode2 = right value

searchNode
create a temp node thats equal to root
check value ==, < , >
< go left
> go right

*/