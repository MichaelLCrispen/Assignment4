#ifndef NODE
#define NODE


/*
 * Node Declaration
 */
struct Node
{
	int key;
	struct Node *left = nullptr;
	struct Node *right = nullptr;
	struct Node *parent = nullptr;
};

typedef Node* NodePtr;


#endif