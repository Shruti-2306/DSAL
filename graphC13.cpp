#include <iostream>
class Stack
{
	int *arr, top, capacity;

public:
	Stack()
	{
		capacity = 5;
		arr = new int[capacity];
		top = -1;
	}
	Stack(int n)
	{
		capacity = n;
		arr = new int[capacity];
		top = -1;
	}
	bool empty();
	void push(int p);
	int pop();
};
bool Stack::empty()
{
	if (top == -1)
		return true;
	return false;
}
void Stack::push(int p)
{
	if (top == capacity - 1)
		return;
	top++;
	arr[top] = p;
}
int Stack::pop()
{
	int t = arr[top];
	top--;
	return t;
}
struct node
{
	int data;
	node *next;
};
class LinkedList
{
public:
	node *head;
	LinkedList()
	{
		head = NULL;
	}
	void insert(int p);
};
void LinkedList::insert(int p)
{
	node *t;
	t = head;
	if (head == NULL)
	{
		t = new node;
		t->data = p;
		t->next = NULL;
		head = t;
	}
	else
	{
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = new node;
		t->next->data = p;
		t->next->next = NULL;
	}
}
class Queue
{
	int *arr, capacity, front, rear;

public:
	Queue()
	{
		capacity = 5;
		arr = new int[capacity];
		front = rear = -1;
	}
	Queue(int n)
	{
		capacity = n;
		arr = new int[capacity];
		front = rear = -1;
	}
	bool empty();
	void enqueue(int p);
	int dequeue();
};
bool Queue::empty()
{
	if (front == -1 && rear == -1)
		return true;
	return false;
}
void Queue::enqueue(int p)
{
	if (rear == capacity - 1)
		return;
	if (front == -1)
		front = 0;

	rear++;
	arr[rear] = p;
}
int Queue::dequeue()
{
	int t = arr[front];
	if (front == rear)
		front = rear = -1;
	else
		front++;
	return t;
}
class Graph
{
	int noOfVertices;
	std::string *vertex;
	int **adjacencyMatrix;
	bool *visited;
	LinkedList *edgeList;

public:
	Graph();
	Graph(int n);
	void matrixRep();
	void listRep();
	void matrixDisplay();
	void listDisplay();
	void matrixDFS(std::string v);
	void listBFS(std::string v);
};
Graph::Graph()
{
	noOfVertices = 5;
	vertex = new std::string[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		std::cout << "Enter (" << i + 1 << ")th vertex data: ";
		std::cin >> vertex[i];
	}
}
Graph::Graph(int n)
{
	noOfVertices = n;
	vertex = new std::string[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		std::cout << "Enter (" << i + 1 << ")th vertex data: ";
		std::cin >> vertex[i];
	}
}
void Graph::matrixRep()
{
	adjacencyMatrix = new int *[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		adjacencyMatrix[i] = new int[noOfVertices];
		for (int j = 0; j < noOfVertices; j++)
		{
			adjacencyMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < noOfVertices; i++)
	{
		for (int j = i; j < noOfVertices; j++)
		{
			int edge;
			std::cout << vertex[i] << "-" << vertex[j] << " Edge value - "; // Value of edge in the matrix, 0 if not present 1 if present
			std::cin >> edge;
			adjacencyMatrix[i][j] = edge;
			adjacencyMatrix[j][i] = edge;
		}
	}
}
void Graph::matrixDisplay()
{
	for (int i = 0; i < noOfVertices; i++)
	{
		for (int j = 0; j < noOfVertices; j++)
		{
			std::cout << adjacencyMatrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
void Graph::matrixDFS(std::string v)
{
	int p;
	visited = new bool[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i] = false;
		if (vertex[i] == v)
		{
			p = i;
		}
	}
	Stack s(noOfVertices);
	s.push(p);
	while (!(s.empty()))
	{
		p = s.pop();
		if (!(visited[p]))
		{
			std::cout << vertex[p] << "   ";
			visited[p] = true;
		}
		for (int i = 0; i < noOfVertices; i++)
		{
			if (adjacencyMatrix[p][i] == 1 && !(visited[i]))
				s.push(i);
		}
	}
	std::cout << std::endl;
}
void Graph::listRep()
{
	edgeList = new LinkedList[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		for (int j = 0; j < noOfVertices; j++)
		{
			if (adjacencyMatrix[i][j] == 1)
			{
				edgeList[i].insert(j);
			}
		}
	}
}
void Graph::listDisplay()
{
	for (int i = 0; i < noOfVertices; i++)
	{
		std::cout << vertex[i] << ": ";
		node *t = edgeList[i].head;
		while (t->next != NULL)
		{
			std::cout << vertex[t->data] << "->";
			t = t->next;
		}
		std::cout << vertex[t->data];
		std::cout << std::endl;
	}
}
void Graph::listBFS(std::string v)
{
	int p;
	visited = new bool[noOfVertices];
	for (int i = 0; i < noOfVertices; i++)
	{
		visited[i] = false;
		if (vertex[i] == v)
		{
			p = i;
		}
	}
	Queue q(noOfVertices);
	std::cout << vertex[p] << "   ";
	visited[p] = true;
	q.enqueue(p);
	while (!(q.empty()))
	{
		p = q.dequeue();
		node *t = edgeList[p].head;
		while (t != NULL)
		{
			if (visited[t->data] == false)
			{
				std::cout << vertex[t->data] << "   ";
				visited[t->data] = true;
				q.enqueue(t->data);
			}
			t = t->next;
		}
	}
}
int main()
{
	int n;
	std::cout << "Enter number of vertices: ";
	std::cin >> n;
	Graph G1(n);
	G1.matrixRep();
	std::cout << "\nThe Matrix representation is: " << std::endl;
	G1.matrixDisplay();
	std::string vtx;
	std::cout << "\nEnter which vertex you want to start with for DFS: " << std::endl;
	std::getline(std::cin >> std::ws, vtx);
	G1.matrixDFS(vtx);
	std::cout << "\nThe Edge List representation is: " << std::endl;
	G1.listRep();
	G1.listDisplay();
	std::cout << "\nEnter which vertex you want to start with for BFS: " << std::endl;
	std::getline(std::cin >> std::ws, vtx);
	G1.listBFS(vtx);
	return 0;
}