# tree_algorithms
**Nonlinear Data Structure and Algorithms**

This implementation aims to understand the structure and main concepts of the trees, an abstract type of data.

First, we build a binary character tree, using the **constroi_arv** function, and **cria_arv_vaz** for the empty branches.

Always, throughout the executions, we check if a subtree has "children", with the function **verifica_arv_vazia** and if you do, avoid going through that non-existent branch.

There are three functions to get the Tree Transversals, whose courses are:
- *Pre-order*  (R,E,D) 
- *In-order*   (E,R,D)
- *Post-order* (E,D,R)

In addition, we will search, through binary search in the function **pertence_arv**, a specific character (typed by the user) in the created tree.

We will also calculate, using properties, the fundamental characteristics of the tree, which are:
* *Nodes* (**conta_nos**)
* *Height* (**calcula_altura_arv**)
* *Leafs* (**conta_nos_folha**)
