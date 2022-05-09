typedef struct _node {
	int value;
	struct _node *left;
	struct _node *right;
	struct _node *parent;
} node;

node *initTree(int value);
node *search(node *tree, int value);
bool insert(node *tree, bool side, int value, int parent);
bool removeLeaf(node *tree, int value);

int depth(node *tree);
int size(node *tree);

// Parcours
void prefixe(node *tree);
void infixe(node *tree);
void postfixe(node *tree);
