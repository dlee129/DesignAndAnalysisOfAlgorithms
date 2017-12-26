#include <iostream>
#include <fstream>
using namespace std;

class Node{
public:
     int colorID;
     Node *next;
     Node(){
          colorID = 0;
          next = NULL;
     }
     Node(int cID){
          colorID = cID;
          next = NULL;
     }
};

class graphColoring{
public:
     int **adjacencyMatrix;
     Node *usedColorTop;
     int newColor;
     int numNode;
     graphColoring(int n){
          numNode = n;
          adjacencyMatrix = new int*[numNode+1];
          for(int i=0; i <= numNode; i++){
               adjacencyMatrix[i] = new int[numNode+1]();
          }
          for(int i=0; i <= numNode; i++){
               for(int j=0; j<=numNode; j++){
                    adjacencyMatrix[i][j] = 0;
               }
          }
          usedColorTop=NULL;
     }
     void loadMatrix(ifstream &inFile);
     int checkAdjacent(int nodeID, int color);
     void pushUsedColor(int newColor);
     int findUsedColor(int currentNode);
     void printMatrix(ofstream &outFile);
     void constructColorGraph(ifstream &inFile, ofstream &outFile);
     bool allColored();
};

int main(int argc, char **argv){
     ifstream inFile;
     inFile.open(argv[1]);
     ofstream outFile;
     outFile.open(argv[2]);
     int numNodes;
     inFile>>numNodes;
     graphColoring gc(numNodes);
     gc.constructColorGraph(inFile, outFile);
}

void graphColoring::constructColorGraph(ifstream &inFile, ofstream &outFile){
     loadMatrix(inFile);
     newColor = 0;
     int currentNode = 0;
     printMatrix(outFile);

     while(!allColored()){
          currentNode++;
          int usedColor = findUsedColor(currentNode);
          if(usedColor > 0){
               adjacencyMatrix[currentNode][currentNode] = usedColor;
          }
          else{
               newColor++;
               adjacencyMatrix[currentNode][currentNode] = newColor;
               pushUsedColor(newColor);
          }
     }
     outFile<<"The total number of colors used is: ";
     outFile<<newColor;
     outFile<<'\n';
     printMatrix(outFile);
}

void graphColoring::printMatrix(ofstream &outFile){
     string line;
     outFile<<"The Adjacency Matrix: ";
     outFile<<'\n';
     for(int i=0; i<=numNode; i++){
          for(int j=0; j <=numNode; j++){
               outFile<<adjacencyMatrix[i][j];
               outFile<<" ";
          }
          outFile<<'\n';
     }
     outFile<<'\n';
}

void graphColoring::loadMatrix(ifstream &inFile){
     int node1, node2;
     while(inFile>>node1>>node2){
          adjacencyMatrix[node1][node2] = 1;
          adjacencyMatrix[node2][node1] = 1;
     }
}

int graphColoring::checkAdjacent(int nodeID, int color){
     for (int i = 1; i <= numNode; i++){
          if (adjacencyMatrix[nodeID][i] > 0 && adjacencyMatrix[i][i] == color) return 1;
     }
     return 0;
}

void graphColoring::pushUsedColor(int newColor){
     Node *topColor = new Node(newColor);
     if(usedColorTop == NULL){
          usedColorTop = topColor;
     }
     else{
          topColor->next = usedColorTop;
          usedColorTop= topColor;
     }

}

int graphColoring::findUsedColor(int currentNode){
     Node *PTR = usedColorTop;
     while(PTR!=NULL){
          if(checkAdjacent(currentNode, PTR->colorID)==0){
               return PTR->colorID;
          }
          PTR = PTR->next;
     }
     return 0;
}

bool graphColoring::allColored(){
   for(int i=1; i<=numNode; i++){
        if(adjacencyMatrix[i][i]==0){
             return false;
        }
   }
   return true;
}
