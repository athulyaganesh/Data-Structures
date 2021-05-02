#include <iostream>
using namespace std; 

struct EachNode
{
	int value, weight; 
	EachNode* next;
};

struct EachEdge
{
	int source, dest, weight; 
};

class Graph
{
private: 
	int N; 
	EachNode* createNode(int value, int weight, EachNode* head)
	{
		EachNode* newN = new EachNode; 
		newN->value = value; 
		newN->weight = weight; 
		newN->next = head;
		return newN;
	}
	//head = {node=head->connected nodes->null, node=head->connected nodes->null, node=head->connected nodes->null}
public: 
	EachNode** head; // adjacency list, as array of Pointers 

	Graph(EachEdge edges[], int n, int N)
	{
		head = new EachNode * [N]();  //array of pointers, size N(num nodes) 
		this->N = N; 

		for (int i = 0; i < N; i++) //for each node that exists, initialise the adjacency list to hold nullptrs for all of the nodes
		{
			head[i] = nullptr; 
		}
		for (unsigned i = 0; i < n; i++) //n = num of edges
		{
			int start = edges[i].start; 
			int end = edges[i].end; 
			int weight = edges[i].weight; 

			EachNode* newNode = createNode(end, weight, head[start]); // this connects all the end nodes to the 
			head[start] = newNode; 
		}
	}
	~Graph() 
	{
		for (int i = 0; i < N; i++)
		{
			delete[] head[i]; 
		}
		delete[] head;
	}
};

void print(EachNode* ptr, int i)
{
	while (ptr != nullptr)
	{
		cout << "( " << i << ", " << ptr->value
			<< ", " << ptr->cost << ") "; 
		ptr = ptr->next; 
	}
	cout << endl; 
}
int main()
{
	graphEdges edges[] = {
		//start, end, weight 
		{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
	}
	int N = 6; 
	int n = sizeof(edges) / sizeof(edges[0]); 

	Graph g(edges, n, N); 
	
	for (int i = 0; i < N; i++)
	{
		print(g.head[i], i); //i is the start value
	}
}