#ifndef __GLTHREADS_H__
#define __GLTHREADS_H__

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
public:
	Node *head;
	unsigned int offset;

public:
	void addNode(Node *node); /* adding a new head to the list */
	void removeNode(Node *);

	// iterative micro to iterate over the GLThread
#define ITERATE_GL_THREADS_BEGIN(threadptr, struct_type, ptr) \
                                                              \
	{                                                         \
		Node *node = nullptr, *next = nullptr;                \
		for (node = threadptr.head; node; node = next)       \
		{                                                     \
			next = node->getRight();                          \
			ptr = (struct_type *)((char *)node - threadptr.offset);
#define ITERATE_GL_THREADS_END \
	}                          \
	}

	void initThread(unsigned int offset);

};



#endif
