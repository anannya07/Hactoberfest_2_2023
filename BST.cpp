#include <iostream>

using namespace std;

// Define the structure for a BST node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() {
        root = NULL;
    }

    // Function to insert a new node into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Function to perform an in-order traversal of the BST
    void inOrderTraversal() {
        inOrderRecursive(root);
        cout << endl;
    }

    // Function to perform a pre-order traversal of the BST
    void preOrderTraversal() {
        preOrderRecursive(root);
        cout << endl;
    }

    // Function to perform a post-order traversal of the BST
    void postOrderTraversal() {
        postOrderRecursive(root);
        cout << endl;
    }

    // Function to search for a given key in the BST
    bool search(int key) {
        return searchRecursive(root, key);
    }

    // Function to find and display the smallest element in the BST
    int findSmallest() {
        TreeNode* smallest = findSmallestRecursive(root);
        if (smallest)
            return smallest->data;
        else
            return -1; // Return -1 if the tree is empty
    }

    // Function to find and display the largest element in the BST
    int findLargest() {
        TreeNode* largest = findLargestRecursive(root);
        if (largest)
            return largest->data;
        else
            return -1; // Return -1 if the tree is empty
    }

    // Function to delete a specific element from the BST
    void deleteNode(int key) {
        root = deleteRecursive(root, key);
    }

    // Function to count the total number of nodes in the BST
    int countTotalNodes() {
        return countTotalNodesRecursive(root);
    }

    // Function to count the total number of external (leaf) nodes in the BST
    int countExternalNodes() {
        return countExternalNodesRecursive(root);
    }

    // Function to count the total number of internal (non-leaf) nodes in the BST
    int countInternalNodes() {
        return countTotalNodes() - countExternalNodes();
    }

    // Function to determine the height of the BST
    int getHeight() {
        return getHeightRecursive(root);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (!node) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    void inOrderRecursive(TreeNode* node) {
        if (!node) {
            return;
        }

        inOrderRecursive(node->left);
        cout << node->data << " ";
        inOrderRecursive(node->right);
    }

    void preOrderRecursive(TreeNode* node) {
        if (!node) {
            return;
        }

        cout << node->data << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }

    void postOrderRecursive(TreeNode* node) {
        if (!node) {
            return;
        }

        postOrderRecursive(node->left);
        postOrderRecursive(node->right);
        cout << node->data << " ";
    }

    bool searchRecursive(TreeNode* node, int key) {
        if (!node) {
            return false;
        }

        if (key == node->data) {
            return true;
        } else if (key < node->data) {
            return searchRecursive(node->left, key);
        } else {
            return searchRecursive(node->right, key);
        }
    }

    TreeNode* findSmallestRecursive(TreeNode* node) {
        if (!node) {
            return NULL;
        }

        while (node->left) {
            node = node->left;
        }

        return node;
    }

    TreeNode* findLargestRecursive(TreeNode* node) {
        if (!node) {
            return NULL;
        }

        while (node->right) {
            node = node->right;
        }

        return node;
    }

    TreeNode* deleteRecursive(TreeNode* node, int key) {
        if (!node) {
            return NULL;
        }

        if (key < node->data) {
            node->left = deleteRecursive(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRecursive(node->right, key);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findSmallestRecursive(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }

        return node;
    }

    int countTotalNodesRecursive(TreeNode* node) {
        if (!node) {
            return 0;
        }

        return 1 + countTotalNodesRecursive(node->left) + countTotalNodesRecursive(node->right);
    }

    int countExternalNodesRecursive(TreeNode* node) {
        if (!node) {
            return 0;
        }

        if (!node->left && !node->right) {
            return 1;
        }

        return countExternalNodesRecursive(node->left) + countExternalNodesRecursive(node->right);
    }

    int getHeightRecursive(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int leftHeight = getHeightRecursive(node->left);
        int rightHeight = getHeightRecursive(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BinarySearchTree bst;

    while (true) {
    	cout <<"=========================="<<endl;
        cout << "Binary Search Tree Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. In-order Traversal" << endl;
        cout << "3. Pre-order Traversal" << endl;
        cout << "4. Post-order Traversal" << endl;
        cout << "5. Search" << endl;
        cout << "6. Find Smallest Element" << endl;
        cout << "7. Find Largest Element" << endl;
        cout << "8. Delete" << endl;
        cout << "9. Count Total Nodes" << endl;
        cout << "10. Count External Nodes" << endl;
        cout << "11. Count Internal Nodes" << endl;
        cout << "12. Determine Height" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insert(val);
                break;
            case 2:
                cout << "In-order Traversal: ";
                bst.inOrderTraversal();
                break;
            case 3:
                cout << "Pre-order Traversal: ";
                bst.preOrderTraversal();
                break;
            case 4:
                cout << "Post-order Traversal: ";
                bst.postOrderTraversal();
                break;
            case 5:
                cout << "Enter key to search: ";
                cin >> val;
                if (bst.search(val)) {
                    cout << "Key found in the BST." << endl;
                } else {
                    cout << "Key not found in the BST." << endl;
                }
                break;
            case 6:
                cout << "Smallest Element: " << bst.findSmallest() << endl;
                break;
            case 7:
                cout << "Largest Element: " << bst.findLargest() << endl;
                break;
            case 8:
                cout << "Enter key to delete: ";
                cin >> val;
                bst.deleteNode(val);
                break;
            case 9:
                cout << "Total Nodes: " << bst.countTotalNodes() << endl;
                break;
            case 10:
                cout << "External Nodes: " << bst.countExternalNodes() << endl;
                break;
            case 11:
                cout << "Internal Nodes: " << bst.countInternalNodes() << endl;
                break;
            case 12:
                cout << "Height of the BST: " << bst.getHeight() << endl;
                break;
            case 13:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
