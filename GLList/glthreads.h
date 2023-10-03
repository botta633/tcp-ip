#ifndef GLTHREADS_H__
#define GLTHREADS_H__

#include <string>

class Node
{
private:
	Node *left;
	Node *right;

public:
	static void addNext(Node *currNode, Node *newNode);
	static void removeNode(Node *node);
	Node *getLeft();
	Node *getRight();
	void setLeft(Node *);
	void setRight(Node *);
	void init();
};

class glthread
{
private:
	Node *head;
	unsigned int offset;

public:
	void addNode(Node *); /* adding a new head to the list */
	void removeNode(Node *);
	Node *getHead();
	void initThread(unsigned int offset);
};

#endif
