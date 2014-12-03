
#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;


typedef GraphArc<int, int> Arc;
typedef GraphNode<int, int> Node;

void visit( Node * pNode ) {
	cout << "Visiting: " << pNode->data() << endl;
}

int main(int argc, char *argv[]) {
   
    //Graph<char, int> graph( 9 );
	//Graph<int, int> graphNum( 13 );
	Graph<int, int> graphNum3( 25 );
	
	int c = 0;
	int i = 0;
	ifstream myfile;
	//myfile.open ("nodes.txt");
	myfile.open ("nodes3.txt");
	//myfile.open ("nodes3.txt");

	while ( myfile >> c ) {
		graphNum3.addNode(c, i++);		//remember graph noide seperate for all 3 arcs.txt
	}

	myfile.close();
	myfile.open("arcs3.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graphNum3.addArc(from, to, weight);
	}

    myfile.close();

	//graphNum.breadthFirst(graphNum.nodeArray()[0], visit );

	Node targetNode = graphNum3.previousPointer(graphNum3.nodeArray()[0], graphNum3.nodeArray()[15]);
	targetNode = *targetNode.getPreviousNode();

	while (targetNode.getPreviousNode() != NULL)
	{
		visit(&targetNode);
		targetNode = *targetNode.getPreviousNode();
	}

	system("PAUSE");	
}