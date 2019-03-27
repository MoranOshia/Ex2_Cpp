

namespace ariel{
struct Node{
    int value;
    Node *left;
    Node *right;
    public:
    Node();
    Node(int val);
    Node(int val, Node  *left, Node *right);
};

class Tree{

   Node *roo;
   
    public:
    
    Tree();
    ~Tree();
    void addHelper(Node *root, int val);
    void printHelper(Node *root);
    int nodesCountHelper(Node *root);
    int heightHelper(Node *root);
    void printMaxPathHelper(Node*root);
    bool deleteValueHelper(Node *parent, Node *current, int value);
    bool containsNode(Node* top, int data) ;
    Node* getParent(Node *root, int key);
    Node* getNodeByIndex(Node* top, int data);
    void insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    void destroyTree(Node* leaf);
    };
}
