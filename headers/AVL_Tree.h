#pragma once
#ifndef AVL_Tree_H
#define AVL_Tree_H

#include "../headers/Point.h"

struct point;

struct node {
	point data;
	node* left;
	node* right;
	int balance;
	node(point _data = point()) : data(_data), left(nullptr), right(nullptr), balance(0) {};
};

int treeHeight(node* root);

void setBalance(node* (&root));

void turnRight(node* (&root));

void turnLeft(node* (&root));

void push(node* (&root), point _point, point referencePoint = point());

void clear(node* (&root));

static int flagLTR;
void LTR(const node* _node, point* arr = nullptr);

void treeSort(point* arr, int size);

#endif