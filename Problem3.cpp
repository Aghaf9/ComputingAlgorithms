#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

class AVLTree {

private:
	struct Node {
		//this is for the weight
		int weight;
		//multiple items can share the same weight
		vector<string> items;
		//for the height
		int getheight;
		
		//left anf right child pointers
		Node* left;
		Node* right;
		
		//constructor
		Node(int w, const string& item) : weight(w), items{item}, getheight(1), left(nullptr), right(nullptr) {}
	};
		//AVL tree root node 
		Node* root = nullptr;

	//helper funcions

		//returning the height of nodes
		//Null nodes contain a height of 0
		int height(Node* node){
			return node ? node->getheight : 0;
		}
		
		int balanceTheTree(Node* node) {
			return node ? height(node->left) - height(node->right) : 0;
		}
		
		//update node height after insertion/deletion
		void updateHeight(Node* node) {
		//height = 1 + tallest child
			node->getheight = 1 + max(height(node->left), height(node->right));	
		}
		Node* rotateRight(Node* y){

    //x becomes the new root
  		  Node* x = y->left;

    //store subtree
  		  Node* T2 = x->right;

    //perform rotation
  		  x->right = y;
  		  y->left = T2;

    //update heights
  		  updateHeight(y);
  		  updateHeight(x);

    //return new subtree root
    return x;
}
		//roations
		Node* rotateLeft(Node* x){

    //y becomes the new root
   		 Node* y = x->right;

    //store subtree
   		 Node* T2 = y->left;

    //perform rotation
 		   y->left = x;
  		  x->right = T2;

    //update heights
 		   updateHeight(x);
  		  updateHeight(y);

    //return new subtree root
 		   return y;
		}

		



		//rebalancing
		
		Node* rebalance(Node* node){
			if (node == nullptr) return node;

			//updating height first
			updateHeight(node);
			
			//get balance
			int balance = balanceTheTree(node);
			
			//left side
			if (balance > 1) {
				//left right case
				//double rotation
				if (balanceTheTree(node->left)<0)
					node->left = rotateLeft(node->left);
				//left left case
				return rotateRight(node);
			}
		        if (balance < -1) {

            			//right left case
            			if (balanceTheTree(node->right) > 0)
                		node->right = rotateRight(node->right);

            			//right right case
            			return rotateLeft(node);
        		}

			
        // Already balanced
        return node;

    }

	//insertion
	Node* insert(Node* node, int weight, const string& item) {	
		//perform normal BST insertion
		if (!node) return new Node(weight, item);
		if (weight < node->weight)
			node->left = insert(node->left, weight, item);
		else if (weight > node->weight)
			node->right = insert(node->right, weight, item);
		else {
			//if the weight already exists, add the item to the existing node
			node->items.push_back(item);
			return node;
		}
		//rebalance the tree after insertion
		return rebalance(node);
	}
		
		//searching for an item by weight
		Node* search(Node* node, int weight) {
			if (!node) return nullptr;
			if (weight < node->weight)
				return search(node->left, weight);
			else if (weight > node->weight)
				return search(node->right, weight);
			else
				return node; //found the weight	
		}

		//find the minimum node 
		//used in deletion
		Node* minValueNode(Node* node) {
			Node* current = node;
			while (current->left) current = current->left;
			return current;
	}
	//deletion	
	Node* deleteNode(Node* node, int weight) {
		if (!node) return node;
		if (weight < node->weight)
			node->left = deleteNode(node->left, weight);
		else if (weight > node->weight)
			node->right = deleteNode(node->right, weight);
		else {
			//node with only one child or no child
			if (!node->left || !node->right) {
				Node* temp = node->left ? node->left : node->right;
				if (!temp) {
					temp = node;
					node = nullptr;
				} else
					*node = *temp; //copy the contents of the non-empty child
				delete temp;
			} else {
				//node with two children: get the inorder successor
				Node* temp = minValueNode(node->right);
				node->weight = temp->weight;
				node->items = temp->items; //copy items as well
				node->right = deleteNode(node->right, temp->weight);
			}
		}
		return rebalance(node); //rebalance after deletion
	}


	// inorder traversal for testing
	void inorder(Node* node) {
		if (node) {
			inorder(node->left);
			cout << "Weight: " << node->weight << " Items: ";
			for (const auto& item : node->items) cout << item << " ";
			cout << endl;
			inorder(node->right);
		}
	}
	Node* searchClosestNode(Node* node, int weight, Node* closest) {

    		//if node is null return closest found
    		if (!node) return closest;

    		//update closest if current node is nearer
    		if (!closest ||
     		   abs(node->weight - weight) <
     		   abs(closest->weight - weight)) {

     		   closest = node;
  		  }

  		  //exact match
 		   if (weight == node->weight) {
  		      return node;
   		 }

    		//search left
 		   if (weight < node->weight) {
   		     return searchClosestNode(node->left, weight, closest);
   		 }

 		   //search right
  		  return searchClosestNode(node->right, weight, closest);
}
public:
	void insert(int weight, const string& item) {
		root = insert(root, weight, item);
	}
	
	void remove(int weight) {
		root = deleteNode(root, weight);
	}
	
	vector<string> search(int weight) {
		Node* node = search(root, weight);
		return node ? node->items : vector<string>{}; //return items or empty vector if not found
	}
	
	void display() {
		inorder(root);
	}
	vector<string> searchClosest(int weight, int& returnedWeight, bool& exactMatch) {

    		//find exact match first
  		  Node* exact = search(root, weight);

  		  //if exact found
  		  if (exact) {
   		     returnedWeight = exact->weight;
   		     exactMatch = true;
   		     return exact->items;
  		  }

   		 //find nearest node
 		   Node* closest =
   		     searchClosestNode(root, weight, nullptr);

  			  //if tree empty
		    if (!closest) {
			returnedWeight = -1;
			exactMatch = false;
      			  return {};
    			}

    //return nearest weight
    returnedWeight = closest->weight;
    exactMatch = false;

    return closest->items;
}
};



int main() {
    AVLTree warehouse;

    warehouse.insert(50, "Box A");
    warehouse.insert(30, "Box B");
    warehouse.insert(70, "Box C");
    warehouse.insert(50, "Box D");
    warehouse.insert(20, "Box E");
    warehouse.insert(65, "Box F");

    cout << "Inventory sorted by weight:\n";
    warehouse.display();

    int returnedWeight;
    bool exactMatch;

    cout << "\nSearching for 50kg:\n";
    vector<string> found = warehouse.searchClosest(50, returnedWeight, exactMatch);
    cout << "Returned weight: " << returnedWeight << " exact: " << exactMatch << endl;
    for (const string& item : found) cout << item << endl;

    cout << "\nSearching for 68kg, which is not exact:\n";
    found = warehouse.searchClosest(68, returnedWeight, exactMatch);
    cout << "Returned closest weight: " << returnedWeight << " exact: " << exactMatch << endl;
    for (const string& item : found) cout << item << endl;

    warehouse.remove(30);
    cout << "\nAfter removing 30kg:\n";
    warehouse.display();

    return 0;
}
