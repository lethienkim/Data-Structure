 /******************************************
 * File: bintree.cpp
 * Author: Thienkim Le
 *
 * Description: 
 *	 Implementation of the BinTree class, which represents a Binary Search Tree (BST).
 *   The BinTree class provides methods to create, manipulate, and traverse a BST.
 *   It uses a recursive approach to implement the various operations on the tree.
******************************************/

#include "bintree.h"

BinTree::BinTree() {
	/*********************************************
 	 Constructor for BinTree class.
 	 Initializes the BinTree object by setting the
 	 root pointer to nullptr and the count of nodes to zero.
	*********************************************/
    root = nullptr;
    count = 0;
}

BinTree::~BinTree() {
	/*********************************************
 	 Destructor for the BinTree class. 
	 Calls the clear() method to deallocate memory 
	 and remove all nodes from the binary tree. 
 	*********************************************/
    clear();
}

bool BinTree::isEmpty() {
	/*********************************************
 	Determines whether the binary tree is empty.
 
 	@param None 
 	@return true if the tree is empty, false otherwise.
 	@exception None
 	@note None
	*********************************************/
    return root == nullptr;
}

int BinTree::getCount() {
	/*********************************************
	Returns the number of nodes in the binary tree.

	@param None
	@exception None
	@note None
	*********************************************/
    return count;
}

bool BinTree::getRootData(Data* data) {
	/*********************************************
	Displays the entire binary tree by printing
	its structure, height, node count, and traversals.

	@param None
	@return None
	@exception None
	@note The function checks if the tree is empty
		  before displaying its contents.
*********************************************/
    bool ret = true;
    if (isEmpty()) {
        data->id = -1;
        data->information = "";
        ret = false;
    } else {
        *data = root->data;
    }
    return ret;
}

void BinTree::displayTree() {
	/*********************************************
 	Displays the entire binary tree by printing
 	its structure, height, node count, and traversals.
 
 	@param None 
 	@return None 
 	@exception None
 	@note The function checks if the tree is empty
       	  before displaying its contents.
	*********************************************/
    if (isEmpty()) {
    	cout << "DISPLAY TREE" << endl;
    	cout << "==============================================" << endl;
        cout << "Tree is empty" << endl;
    } else {
    	cout << "DISPLAY TREE" << endl;
    	cout << "==============================================" << endl;
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << count << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << "==============================================\n" << endl;
}

void BinTree::clear() {
	/*********************************************
 	Clears the binary tree by recursively deleting
 	all nodes, setting root to nullptr, and resetting
 	the node count.

 	@param None 
 	@return None 
 	@exception None
 	@note None
	*********************************************/
    clear(root);
    root = nullptr;
    count = 0;
}

bool BinTree::addNode(int id, const string* info) {
	/*********************************************
 	Adds a new node to the binary tree with the given
 	ID and information. If the addition is successful,
 	increments the node count and returns true, otherwise
 	returns false.

 	@param id : ID of the new node
 	@param info : Pointer to the string information of the new node
 	@return true if the node is successfully added, false otherwise
 	@exception None
 	@note None
	*********************************************/
    bool ret = false;
    DataNode* newNode = new DataNode;
    newNode->data.id = id;
    newNode->data.information = *info;
    newNode->left = newNode->right = nullptr;

    if (addNode(newNode, &root)) {
        count++;
        ret = true;
    }
    return ret;
}

bool BinTree::removeNode(int id) {
	/*********************************************
 	Remove a node with the given ID from the binary tree.
 	If the removal is successful, decrements the node count and returns true,
 	otherwise returns false.

 	@param id : ID of the node to be removed
 	@return true if the node is successfully removed, false otherwise
 	@exception None
 	@note None
 	*********************************************/
    int tempCount = count;
    root = removeNode(id, root);
    bool ret = false;
    if (count < tempCount) {
        ret = true;
    }
    return ret;
}

bool BinTree::getNode(Data* data, int id) {
	/*********************************************
 	Retrieves the data of the node with the given ID from the binary tree.
 
 	@param data : Pointer to the Data structure where the retrieved data will be stored
 	@param id : ID of the node to be retrieved
 	@return true if the node is found and its data is retrieved, false otherwise
 	@exception None
 	@note None
	*********************************************/
    return getNode(data, id, root);
}

bool BinTree::contains(int id) {
	/*********************************************
 	Checks whether the binary tree contains a node with the given ID.
 
 	@param id : ID of the node to be searched for
 	@return true if the tree contains a node with the given ID, false otherwise
 	@exception None
 	@note None
*********************************************/
    return contains(id, root);
}

int BinTree::getHeight() {
	/*********************************************
 	Retrieves the height of the binary tree.
 
 	@param None
 	@return The height of the binary tree
 	@exception None
 	@note None
	*********************************************/
    return getHeight(root);
}

void BinTree::displayPreOrder() {
	/*********************************************
 	Traverses the binary tree in pre-order and displays the nodes.
 
 	@param None
 	@return None
	@exception None
 	@note None
	*********************************************/
    displayPreOrder(root);
    cout << endl;
}

void BinTree::displayPostOrder() {
	/*********************************************
 	Traverses the binary tree in post-order and displays the nodes.
 
 	@param None
 	@return None
 	@exception None
 	@note None
	*********************************************/
    displayPostOrder(root);
    cout << endl;
}

void BinTree::displayInOrder() {
	/*********************************************
 	Traverses the binary tree in in-order and displays the nodes.
 
 	@param None
 	@return None
 	@exception None
 	@note None
	*********************************************/
    displayInOrder(root);
    cout << endl;
}

void BinTree::clear(DataNode* node) {
	/*********************************************
 	Recursively clears the binary tree by deleting each node.
 
 	@param node: Pointer to the current node being processed
 	@return None
 	@exception None
 	@note None
	*********************************************/
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool BinTree::addNode(DataNode* newNode, DataNode** parent) {
	/*********************************************
 	Recursively adds a new node to the binary tree.
 
 	@param newNode: Pointer to the new node to be added
 	@param parent: Pointer to the parent node
 	@return bool: True if the node is successfully added, false otherwise
 	@exception None
 	@note None
	*********************************************/
    bool ret = false;

    if (*parent == nullptr) {
        *parent = newNode;
        ret = true;
    } else {
        if (newNode->data.id < (*parent)->data.id) {
            ret = addNode(newNode, &((*parent)->left));
        } else {
            ret = addNode(newNode, &((*parent)->right));
        }
    }
    return ret;
}

DataNode* BinTree::removeNode(int id, DataNode* root) {
	/*********************************************
 	Recursively removes a node with the given ID from the binary tree.
 
 	@param id : ID of the node to be removed
 	@param root : Pointer to the root of the subtree being processed
 	@return Pointer to the root of the modified subtree after removal
 	@exception None
 	@note None
	*********************************************/

    if (root != nullptr) {
    
		// If the ID is less than the current node's ID, traverse left
    	if (id < root->data.id) {
        	root->left = removeNode(id, root->left);
    	// If the ID is greater than the current node's ID, traverse right
    	} else if (id > root->data.id) {
        	root->right = removeNode(id, root->right);
    	// If the node to be removed is found
    	} else {
    		// If the node has no left child
        	if (root->left == nullptr) {
            	DataNode* temp = root->right;
            	delete root;
            	count--;
            	root = temp;
        	} else if (root->right == nullptr) {
            	DataNode* temp = root->left;
            	delete root;
            	count--;
            	root = temp;
        	}
			else {
				// Node with two children
	        	DataNode* temp = root->right;
	        	while (temp->left != nullptr) {
	            	temp = temp->left;
	        	}
		        root->data = temp->data;
		        root->right = removeNode(temp->data.id, root->right);
		    }
    	}
	}
    return root;
}

bool BinTree::getNode(Data* data, int id, DataNode* node) {
	/*********************************************
 	Recursively searches for a node with the given ID in the binary tree.
 
 	@param data: Pointer to store the data of the found node
 	@param id: ID of the node to be searched
 	@param node: Pointer to the current node being checked
 	@return bool: True if the node is found, false otherwise
 	@exception None
 	@note None
	*********************************************/
    bool ret = false;
    if (node != nullptr) {
        if (id == node->data.id) {
            *data = node->data;
            ret = true;
        } else if (id < node->data.id) {
            ret = getNode(data, id, node->left);
        } else {
            ret = getNode(data, id, node->right);
        }
    }
    return ret;
}

bool BinTree::contains(int id, DataNode* node) {
	/*********************************************
 	Recursively checks if a node with the given ID exists in the binary tree.
 
 	@param id: ID of the node to be checked
 	@param node: Pointer to the current node being checked
 	@return bool: True if the node is found, false otherwise
 	@exception None
 	@note None
	*********************************************/
    bool ret = false;

    if (node != nullptr) {
        if (id == node->data.id) {
            ret = true;
        } else if (id < node->data.id) {
            ret = contains(id, node->left);
        } else {
            ret = contains(id, node->right);
        }
    }

    return ret;
}

int BinTree::getHeight(DataNode* node) {
	/*********************************************
 	Recursively calculates the height of the binary tree starting from the given node.
 
 	@param node: Pointer to the current node being processed
 	@return int: Height of the binary tree
 	@exception None
 	@note None
	*********************************************/
    int height = 0;
    if (node != nullptr) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        height = 1 + std::max(leftHeight, rightHeight);
    }
    return height;
}

void BinTree::displayPreOrder(DataNode* node) {
	/*********************************************
 	Recursively traverses the binary tree in pre-order starting from the given node,
 	printing the data of each node.
 
 	@param node: Pointer to the current node being processed
 	@return None
 	@exception None
 	@note None
	*********************************************/
    if (node != nullptr) {
        cout << node->data.id << " " << node->data.information << endl;
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void BinTree::displayPostOrder(DataNode* node) {
	/*********************************************
 	Recursively traverses the binary tree in post-order starting from the given node,
	printing the data of each node.
 
 	@param node: Pointer to the current node being processed
 	@return None
 	@exception None
 	@note None
	*********************************************/
    if (node != nullptr) {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        cout << node->data.id << " " << node->data.information << endl;
    }
}

void BinTree::displayInOrder(DataNode* node) {
	/*********************************************
 	Recursively traverses the binary tree in in-order starting from the given node,
 	printing the data of each node.
 
 	@param node: Pointer to the current node being processed
 	@return None
	@exception None
 	@note None
	*********************************************/
    if (node != nullptr) {
        displayInOrder(node->left);
        cout << node->data.id << " " << node->data.information << endl;
        displayInOrder(node->right);
    }
}