#ifndef GLTHREADS_H__
#define GLTHREADS_H__

#include <string>

template <typename T>
class Node
{
private:
	T *left;
	T *right;
	protected:
	std::string name;

public:
	static void addNext(T *currNode, T *newNode);
	static void removeNode(T *node);
	T *getLeft();
	T *getRight();
	void setLeft(T *);
	void setRight(T *);
	void init();
	virtual void setName(std::string name) = 0;
	virtual std::string getName() const = 0;
};


template <typename T>
class glthread
{
private:
	T *head;
	unsigned int offset;

public:
	void addNode(T *); /* adding a new head to the list */
	void removeNode(T *);

	void initThread(unsigned int offset);
};

#endif
