#include "../headers/AVL_Tree.h"

int treeHeight(node* root)
{
	if (root == nullptr)
		return 0;
	int hLeft = treeHeight(root->left), hRight = treeHeight(root->right);
	if (hLeft > hRight)
		return hLeft + 1;
	else
		return hRight + 1;
}

void setBalance(node* (&root))
{
	if (root != nullptr)
		root->balance = treeHeight(root->right) - treeHeight(root->left);
}

void turnRight(node* (&root))
{
	node* leftSubTree = root->left, * leftSubTreeRightSubTree = leftSubTree->right;
	leftSubTree->right = root;
	root->left = leftSubTreeRightSubTree;
	root = leftSubTree;
	setBalance(root->right);
	setBalance(root);
}

void turnLeft(node* (&root))
{
	node* rightSubTree = root->right, * rightSubTreeLeftSubTree = rightSubTree->left;
	rightSubTree->left = root;
	root->right = rightSubTreeLeftSubTree;
	root = rightSubTree;
	setBalance(root->left);
	setBalance(root);
}

void push(node* (&root), point _point, point referencePoint)
{
	if (root == nullptr)
	{
		root = new node;
		root->data = _point;
		root->balance = 0;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		if (!pointsCompare(referencePoint, root->data, _point))
		{
			push(root->right, _point);
			if (treeHeight(root->right) - treeHeight(root->left) > 1)
			{
				if (treeHeight(root->right->right) < treeHeight(root->right->left))
					turnRight(root->right);
				turnLeft(root);
			}
		}
		else
		{
			push(root->left, _point);
			if (treeHeight(root->left) - treeHeight(root->right) > 1)
			{
				if (treeHeight(root->left->left) < treeHeight(root->left->right))
					turnLeft(root->left);
				turnRight(root);
			}
		}
		setBalance(root);
	}
}

void clear(node* (&root))
{
	if (root != nullptr)
	{
		clear(root->left);
		clear(root->right);

		delete root;
		root = nullptr;
	}
}

void LTR(const node* _node, point* arr) {
	if (_node == nullptr) return;
	LTR(_node->left, arr);
	arr[++flagLTR] = _node->data;
	LTR(_node->right, arr);
}

void treeSort(point* arr, int size)
{
	flagLTR = 0;
	node* root = nullptr;
	for (int i = 1; i < size; i++)
	{
		push(root, arr[i], arr[0]);
	}
	LTR(root, arr);
	clear(root);
}