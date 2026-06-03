//#include <iostream>
//using namespace std;
//
//// Node class for BST
//class Node
//{
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value)
//    {
//        data = value;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class BST
//{
//private:
//    Node* root;
//
//    // Recursive insertion
//    Node* insert(Node* node, int value)
//    {
//        // Create new node if tree/subtree is empty
//        if (node == NULL)
//        {
//            return new Node(value);
//        }
//
//        // Insert in left subtree
//        if (value < node->data)
//        {
//            node->left = insert(node->left, value);
//        }
//
//        // Insert in right subtree
//        else if (value > node->data)
//        {
//            node->right = insert(node->right, value);
//        }
//
//        // Duplicate values are ignored
//        else
//        {
//            cout << "Duplicate value " << value
//                << " not inserted.\n";
//        }
//
//        return node;
//    }
//
//    // Recursive inorder traversal
//    void inorder(Node* node)
//    {
//        if (node != NULL)
//        {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//
//    // Recursive preorder traversal
//    void preorder(Node* node)
//    {
//        if (node != NULL)
//        {
//            cout << node->data << " ";
//            preorder(node->left);
//            preorder(node->right);
//        }
//    }
//
//    // Recursive postorder traversal
//    void postorder(Node* node)
//    {
//        if (node != NULL)
//        {
//            postorder(node->left);
//            postorder(node->right);
//            cout << node->data << " ";
//        }
//    }
//
//    // Recursive search
//    bool search(Node* node, int key)
//    {
//        // Key not found
//        if (node == NULL)
//        {
//            return false;
//        }
//
//        // Key found
//        if (node->data == key)
//        {
//            return true;
//        }
//
//        // Search left subtree
//        if (key < node->data)
//        {
//            return search(node->left, key);
//        }
//
//        // Search right subtree
//        return search(node->right, key);
//    }
//
//public:
//    BST()
//    {
//        root = NULL;
//    }
//
//    void insert(int value)
//    {
//        root = insert(root, value);
//    }
//
//    void inorder()
//    {
//        inorder(root);
//    }
//
//    void preorder()
//    {
//        preorder(root);
//    }
//
//    void postorder()
//    {
//        postorder(root);
//    }
//
//    bool search(int key)
//    {
//        return search(root, key);
//    }
//};
//
//int main()
//{
//    BST tree;
//
//    int n, value;
//
//    cout << "=====================================\n";
//    cout << " Binary Search Tree - Task 1\n";
//    cout << "=====================================\n";
//
//    cout << "Enter number of values: ";
//    cin >> n;
//
//    cout << "Enter " << n << " integers:\n";
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> value;
//        tree.insert(value);
//    }
//
//    cout << "\nBST Traversals\n";
//
//    cout << "\nInorder Traversal (Sorted Order): ";
//    tree.inorder();
//
//    cout << "\nPreorder Traversal: ";
//    tree.preorder();
//
//    cout << "\nPostorder Traversal: ";
//    tree.postorder();
//
//    int key;
//
//    cout << "\n\nEnter a key to search: ";
//    cin >> key;
//
//    if (tree.search(key))
//    {
//        cout << "Key found in BST.\n";
//    }
//    else
//    {
//        cout << "Key not found in BST.\n";
//    }
//
//    return 0;
//}
//TAsk 2
//#include <iostream>
//using namespace std;
//
//// Node class for BST
//class Node
//{
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value)
//    {
//        data = value;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class BST
//{
//private:
//    Node* root;
//
//    // Recursive insertion
//    Node* insert(Node* node, int value)
//    {
//        if (node == NULL)
//        {
//            return new Node(value);
//        }
//
//        if (value < node->data)
//        {
//            node->left = insert(node->left, value);
//        }
//        else if (value > node->data)
//        {
//            node->right = insert(node->right, value);
//        }
//        else
//        {
//            cout << "Duplicate value " << value
//                << " not inserted.\n";
//        }
//
//        return node;
//    }
//
//    // Recursive inorder traversal
//    void inorder(Node* node)
//    {
//        if (node != NULL)
//        {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//
//    // Find minimum value node in right subtree
//    Node* findMin(Node* node)
//    {
//        while (node && node->left != NULL)
//        {
//            node = node->left;
//        }
//
//        return node;
//    }
//
//    // Recursive delete function
//    Node* deleteNode(Node* node, int key)
//    {
//        // Tree is empty
//        if (node == NULL)
//        {
//            return NULL;
//        }
//
//        // Search for node to delete
//        if (key < node->data)
//        {
//            node->left = deleteNode(node->left, key);
//        }
//        else if (key > node->data)
//        {
//            node->right = deleteNode(node->right, key);
//        }
//        else
//        {
//            // ===== CASE 1: Leaf Node =====
//            if (node->left == NULL && node->right == NULL)
//            {
//                delete node;
//                return NULL;
//            }
//
//            // ===== CASE 2: One Child (Right) =====
//            if (node->left == NULL)
//            {
//                Node* temp = node->right;
//                delete node;
//                return temp;
//            }
//
//            // ===== CASE 2: One Child (Left) =====
//            if (node->right == NULL)
//            {
//                Node* temp = node->left;
//                delete node;
//                return temp;
//            }
//
//            // ===== CASE 3: Two Children =====
//            Node* successor = findMin(node->right);
//
//            // Replace value with inorder successor
//            node->data = successor->data;
//
//            // Delete successor node
//            node->right =
//                deleteNode(node->right, successor->data);
//        }
//
//        return node;
//    }
//
//public:
//    BST()
//    {
//        root = NULL;
//    }
//
//    void insert(int value)
//    {
//        root = insert(root, value);
//    }
//
//    void inorder()
//    {
//        inorder(root);
//    }
//
//    void deleteValue(int key)
//    {
//        if (root == NULL)
//        {
//            cout << "Tree is empty.\n";
//            return;
//        }
//
//        root = deleteNode(root, key);
//    }
//};
//
//int main()
//{
//    BST tree;
//
//    int n, value;
//
//    cout << "=====================================\n";
//    cout << " BST Deletion Program - Task 2\n";
//    cout << "=====================================\n";
//
//    cout << "Enter number of values: ";
//    cin >> n;
//
//    cout << "Enter " << n << " integers:\n";
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> value;
//        tree.insert(value);
//    }
//
//    cout << "\nBST (Inorder Traversal): ";
//    tree.inorder();
//
//    int key;
//
//    cout << "\n\nEnter value to delete: ";
//    cin >> key;
//
//    tree.deleteValue(key);
//
//    cout << "\nBST After Deletion (Inorder): ";
//    tree.inorder();
//
//    cout << endl;
//
//    return 0;
//}
//Task 3
//#include <iostream>
//using namespace std;
//
//// Node class
//class Node
//{
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value)
//    {
//        data = value;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class BST
//{
//private:
//    Node* root;
//
//    // Recursive insertion
//    Node* insert(Node* node, int value)
//    {
//        if (node == NULL)
//        {
//            return new Node(value);
//        }
//
//        if (value < node->data)
//        {
//            node->left = insert(node->left, value);
//        }
//        else if (value > node->data)
//        {
//            node->right = insert(node->right, value);
//        }
//        else
//        {
//            cout << "Duplicate value " << value
//                << " not inserted.\n";
//        }
//
//        return node;
//    }
//
//    // Recursive inorder traversal
//    void inorder(Node* node)
//    {
//        if (node != NULL)
//        {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//
//public:
//    BST()
//    {
//        root = NULL;
//    }
//
//    void insert(int value)
//    {
//        root = insert(root, value);
//    }
//
//    void inorder()
//    {
//        inorder(root);
//    }
//
//    Node* getRoot()
//    {
//        return root;
//    }
//};
//
//// Recursive function to check if two BSTs are identical
//bool isIdentical(Node* root1, Node* root2)
//{
//    // Both trees are empty
//    if (root1 == NULL && root2 == NULL)
//    {
//        return true;
//    }
//
//    // One tree is empty and the other is not
//    if (root1 == NULL || root2 == NULL)
//    {
//        return false;
//    }
//
//    // Check current node data and both subtrees
//    return (root1->data == root2->data) &&
//        isIdentical(root1->left, root2->left) &&
//        isIdentical(root1->right, root2->right);
//}
//
//int main()
//{
//    BST tree1, tree2;
//
//    int n, value;
//
//    cout << "=====================================\n";
//    cout << " Task 3 - Check Identical BSTs\n";
//    cout << "=====================================\n";
//
//    // Input first BST
//    cout << "\nEnter number of nodes for BST 1: ";
//    cin >> n;
//
//    cout << "Enter values:\n";
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> value;
//        tree1.insert(value);
//    }
//
//    // Input second BST
//    cout << "\nEnter number of nodes for BST 2: ";
//    cin >> n;
//
//    cout << "Enter values:\n";
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> value;
//        tree2.insert(value);
//    }
//
//    // Display BSTs
//    cout << "\nBST 1 (Inorder Traversal): ";
//    tree1.inorder();
//
//    cout << "\nBST 2 (Inorder Traversal): ";
//    tree2.inorder();
//
//    cout << "\n";
//
//    // Check if identical
//    if (isIdentical(tree1.getRoot(), tree2.getRoot()))
//    {
//        cout << "\nBoth BSTs are IDENTICAL.\n";
//    }
//    else
//    {
//        cout << "\nBoth BSTs are NOT IDENTICAL.\n";
//    }
//
//    return 0;
//}
//Task 4
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ================================
//// BST Node (Book Information)
//// ================================
//class BSTNode
//{
//public:
//    int isbn;
//    string title;
//
//    BSTNode* left;
//    BSTNode* right;
//
//    BSTNode(int isbn, string title)
//    {
//        this->isbn = isbn;
//        this->title = title;
//
//        left = NULL;
//        right = NULL;
//    }
//};
//
//// ================================
//// Linked List Node
//// ================================
//class ListNode
//{
//public:
//    int isbn;
//    string title;
//
//    ListNode* next;
//
//    ListNode(int isbn, string title)
//    {
//        this->isbn = isbn;
//        this->title = title;
//
//        next = NULL;
//    }
//};
//
//// ================================
//// Library BST Class
//// ================================
//class LibraryBST
//{
//private:
//    BSTNode* root;
//
//    // Recursive BST insertion
//    BSTNode* insert(BSTNode* node, int isbn, string title)
//    {
//        if (node == NULL)
//        {
//            return new BSTNode(isbn, title);
//        }
//
//        if (isbn < node->isbn)
//        {
//            node->left = insert(node->left, isbn, title);
//        }
//        else if (isbn > node->isbn)
//        {
//            node->right = insert(node->right, isbn, title);
//        }
//        else
//        {
//            cout << "Duplicate ISBN not allowed!\n";
//        }
//
//        return node;
//    }
//
//    // Recursive inorder traversal
//    void inorder(BSTNode* node)
//    {
//        if (node != NULL)
//        {
//            inorder(node->left);
//
//            cout << "ISBN: "
//                 << node->isbn
//                 << " | Title: "
//                 << node->title
//                 << endl;
//
//            inorder(node->right);
//        }
//    }
//
//    // Recursive BST → Linked List Conversion
//    void convertToList(BSTNode* node,
//                       ListNode*& head,
//                       ListNode*& tail)
//    {
//        if (node == NULL)
//        {
//            return;
//        }
//
//        // Visit left subtree first
//        convertToList(node->left, head, tail);
//
//        // Create linked list node
//        ListNode* newNode =
//            new ListNode(node->isbn, node->title);
//
//        if (head == NULL)
//        {
//            head = newNode;
//            tail = newNode;
//        }
//        else
//        {
//            tail->next = newNode;
//            tail = newNode;
//        }
//
//        // Visit right subtree
//        convertToList(node->right, head, tail);
//    }
//
//public:
//    LibraryBST()
//    {
//        root = NULL;
//    }
//
//    void insertBook(int isbn, string title)
//    {
//        root = insert(root, isbn, title);
//    }
//
//    void displayBST()
//    {
//        inorder(root);
//    }
//
//    ListNode* createCatalog()
//    {
//        ListNode* head = NULL;
//        ListNode* tail = NULL;
//
//        convertToList(root, head, tail);
//
//        return head;
//    }
//};
//
//// ================================
//// Display Linked List Catalog
//// ================================
//void displayCatalog(ListNode* head)
//{
//    if (head == NULL)
//    {
//        cout << "Catalog is empty.\n";
//        return;
//    }
//
//    cout << "\n===== Library Catalog =====\n";
//
//    while (head != NULL)
//    {
//        cout << "ISBN: "
//             << head->isbn
//             << " | Title: "
//             << head->title
//             << endl;
//
//        head = head->next;
//    }
//}
//
//// ================================
//// Main Function
//// ================================
//int main()
//{
//    LibraryBST library;
//
//    int n;
//
//    cout << "=====================================\n";
//    cout << " Library Catalog System (Task 4)\n";
//    cout << "=====================================\n";
//
//    cout << "\nEnter number of books: ";
//    cin >> n;
//
//    cin.ignore();
//
//    for (int i = 1; i <= n; i++)
//    {
//        int isbn;
//        string title;
//
//        cout << "\nBook " << i << endl;
//
//        cout << "Enter ISBN: ";
//        cin >> isbn;
//
//        cin.ignore();
//
//        cout << "Enter Title: ";
//        getline(cin, title);
//
//        library.insertBook(isbn, title);
//    }
//
//    cout << "\n\nBooks Stored in BST (Inorder Traversal)\n";
//    cout << "---------------------------------------\n";
//
//    library.displayBST();
//
//    // Convert BST into Linked List
//    ListNode* catalog = library.createCatalog();
//
//    // Display Sorted Catalog
//    displayCatalog(catalog);
//
//    return 0;
//}