
namespace ariel{
struct Node{
    double value;
    Node *left;
    Node *right;
    public:
    Node();
    Node(double val);
    Node(double val, Node  *left, Node *right);
};

class Tree{

   Node *roo;
   
    public:
    
    Tree();
   void addHelper(Node *root, double val);
   void printHelper(Node *root);
   int nodesCountHelper(Node *root);
    int heightHelper(Node *root);
    void printMaxPathHelper(Node*root);
    bool deleteValueHelper(Node *parent, Node *current, double value);
    void insert(double i);
    void remove(double i);
    int size();
    bool contains(double i);
    double root();
    double parent(double i);
    double left(double i);
    double right(double i);
    void print();

    };
}