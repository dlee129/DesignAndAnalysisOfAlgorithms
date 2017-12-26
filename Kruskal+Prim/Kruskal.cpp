#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class undirectedEdge{
public:
     int Ni;
     int Nj;
     int edgeCost;
     undirectedEdge *next;
     undirectedEdge(){

     }
     undirectedEdge(int N1, int N2, int cost){
          Ni = N1;
          Nj = N2;
          edgeCost = cost;
     }
     void printEdge();
     ~undirectedEdge();
};

class KruskalMST{
public:
     int numNodes;
     int *inWhichSet;
     int numSets;
     int totalMSTCost;
     undirectedEdge *MSTofG;
     undirectedEdge *edgeListHead;
     void insertEdge(undirectedEdge *edge);
     undirectedEdge *removedEdge();
     void pushEdge(undirectedEdge *edge);
     void merge2Sets(int node1, int node2);
     KruskalMST(int n){
          numNodes = n;
          numSets = numNodes;
          totalMSTCost = 0;
          MSTofG = new undirectedEdge(0,0,0);
          MSTofG->next = NULL;
          edgeListHead = new undirectedEdge(0,0,0);
          edgeListHead->next = NULL;
          inWhichSet = new int[numNodes+1];
          for(int i = 0; i < numNodes+1; i++){
               inWhichSet[i] = i;
          }
     }
     string printSet();
     string printList(undirectedEdge *listHead);
     string entireMST(undirectedEdge *MST);
     void constructKruskal(ifstream &inFile, ofstream &outFile1, ofstream &outFile2);
};

int main(int argc, char **argv){
     ifstream inFile;
     ofstream outFile1;
     ofstream outFile2;
     inFile.open(argv[1]);
     outFile1.open(argv[2]);
     outFile2.open(argv[3]);
     int numOfNodes;
     inFile>>numOfNodes;
     KruskalMST krus(numOfNodes);
     outFile2<<krus.printSet();
     krus.constructKruskal(inFile, outFile1, outFile2);
     inFile.close();
     outFile1.close();
     outFile2.close();
}

void KruskalMST::constructKruskal(ifstream &inFile, ofstream &outFile1, ofstream &outFile2){
     int node1, node2, cost;
     while(inFile>>node1>>node2>>cost){
          undirectedEdge *newEdge = new undirectedEdge(node1, node2, cost);
          cout<<newEdge->Ni<<" "<<newEdge->Nj<<" "<<newEdge->edgeCost<<endl;
          insertEdge(newEdge);
          outFile2<<printList(edgeListHead);
     }
     while(numSets!=1){
          undirectedEdge *nextEdge;
          nextEdge = removedEdge();
          while(inWhichSet[nextEdge->Ni]==inWhichSet[nextEdge->Nj]){
               nextEdge = removedEdge();
          }
          pushEdge(nextEdge);
          totalMSTCost += nextEdge->edgeCost;
          merge2Sets(nextEdge->Ni,nextEdge->Nj);
          numSets--;
          outFile2<<printSet();
          outFile2<<printList(MSTofG);
     }
     outFile1<<entireMST(MSTofG);

}

string KruskalMST::entireMST(undirectedEdge *MST){
     undirectedEdge *current = MST->next;
     stringstream ss;
     string line;
     ss<<"MST of G: ";
     ss<<'\n';
     while(current != NULL){
          ss<<current->Ni;
          ss<<" ";
          ss<<current->Nj;
          ss<<" ";
          ss<<current->edgeCost;
          ss<<'\n';
          current = current->next;
     }
     ss<<'\n';
     ss<<'\n';
     ss<<"Total cost of MST is: ";
     ss<<totalMSTCost;
     line = ss.str();
     return line;
}

void KruskalMST::merge2Sets(int node1, int node2){
     if(node1 > node2){
          int tempSet = node1;
          node1 = node2;
          node2 = tempSet;
     }
     int newSet = inWhichSet[node2];
     for(int i =1; i <= numNodes; i++){
          if(inWhichSet[i] == newSet)inWhichSet[i] = inWhichSet[node1];
     }
}

void KruskalMST::pushEdge(undirectedEdge *edge){
	edge->next = MSTofG->next;
	MSTofG->next = edge;
}

undirectedEdge *KruskalMST::removedEdge(){
     undirectedEdge *front = edgeListHead;
     edgeListHead = edgeListHead->next;
     return front;
}


string KruskalMST::printSet(){
     stringstream ss;
     string line;
     ss<<"inWhichSet contains these nodes: ";
     ss<<'\n';
     for(int i=0; i <= numNodes; i++){
          ss<<inWhichSet[i];
          ss<<" ";
     }
     ss<<'\n';
     ss<<'\n';
     line = ss.str();
     return line;
}

void KruskalMST::insertEdge(undirectedEdge *edge){
     undirectedEdge* edgePTR = edgeListHead;
     while(edgePTR->next != NULL && edge->edgeCost > edgePTR->next->edgeCost){
		edgePTR = edgePTR->next;
	}
	edge->next = edgePTR->next;
	edgePTR->next = edge;
}

string KruskalMST::printList(undirectedEdge *listHead){
     undirectedEdge *current = listHead;
     int count = 0;
     stringstream ss;
     string line;
     ss<<"listHead ";
     while(current != NULL && current->next != NULL && count != 10){
          ss<<"-> <";
          ss<<current->Ni;
          ss<<" ";
          ss<<current->Nj;
          ss<<" ";
          ss<<current->edgeCost;
          ss<<"> ";
          current = current->next;
          count++;
     }
     ss<<'\n';
     ss<<'\n';
     line = ss.str();
     return line;
}
