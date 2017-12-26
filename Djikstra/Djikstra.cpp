#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class DijkstraSSS{
public:
     int numNodes;
     int sourceNode;
     int minNode;
     int currentNode;
     int newCost;
     int **costMatrix;
     int *fatherAry;
     int *toDoAry;
     int *bestCostAry;
     DijkstraSSS(int dNums, int sNode){
          numNodes = dNums;
          sourceNode = sNode;
          costMatrix = new int*[numNodes+1];
          for(int i = 0; i < numNodes+1; i++){
               costMatrix[i] = new int[numNodes+1]();
          }// initializing an array of column in each row
          fatherAry = new int[numNodes+1];
          toDoAry = new int[numNodes+1];
          bestCostAry = new int[numNodes+1];
          for(int i=1; i < numNodes+1; i++){
               for(int j=1; j < numNodes+1; j++){
                    if(i==j){
                         costMatrix[i][j] = 0;
                    }else{
                         costMatrix[i][j] = 99999;
                    }
               }
          }
          for(int i=0; i< numNodes; i++){
               fatherAry[i] = i;
          }for(int i=0; i< numNodes; i++){
               toDoAry[i] = 1;
          }
          for(int i=0; i< numNodes; i++){
               bestCostAry[i] = 99999;
          }
     } //constructor
     void loadCostMatrix(ifstream &inFile);
     void setBestCostAry(int sNode);
     void setFatherAry(int sNode);
     void setToDoAry(int sNode);
     int findMinNode();
     int computeCost(int mNode, int cNode);
     void markMinNode(int mNode);
     void changeFather(int node, int mNode);
     void changeCost(int node, int newCost);
     void debugPrint(ofstream &outFile2);
     string printShortestPaths(int cNode);
     void constructDijkstras(ofstream &outFile1, ofstream &outFile2);
     bool checkAllZero();
};

int main(int argc, char**argv){
     ifstream inFile;//Step 0
     inFile.open(argv[1]);
     ofstream outFile1;
     outFile1.open(argv[2]);
     ofstream outFile2;
     outFile2.open(argv[3]);
     int numOfnodes;
     int sourceOfnodes;
     inFile>>numOfnodes;
     inFile>>sourceOfnodes;
     DijkstraSSS Dijk(numOfnodes, sourceOfnodes);//End of Step 0
     Dijk.loadCostMatrix(inFile);//Step 1
     Dijk.constructDijkstras(outFile1, outFile2);
     inFile.close();
     outFile1.close();
     outFile2.close();
}

void DijkstraSSS::constructDijkstras(ofstream &outFile1, ofstream &outFile2){
     setBestCostAry(sourceNode);//Step 2
     setFatherAry(sourceNode);
     setToDoAry(sourceNode);//End of Step 2
     while(!checkAllZero()){//End of Step 8
          minNode = findMinNode();//Step 3
          markMinNode(minNode);
          debugPrint(outFile2);//End of Step 3
          currentNode = 1;//Step 4
          while(currentNode <= numNodes){//Step 7
               if(toDoAry[currentNode] == 1){//Step 5
                    newCost = computeCost(minNode, currentNode);
                    if(newCost < bestCostAry[currentNode]){
                         changeCost(currentNode, newCost);
                         changeFather(currentNode, minNode);
                         debugPrint(outFile2);//End of Step 5
                    }
               }
               currentNode++;//Step 6
          }//End of Step 7
     }//End of Step 8
     currentNode = 1;//Step 9
     while(currentNode <= numNodes){//Step 12
          outFile1<<printShortestPaths(currentNode);//Step 10
          currentNode++;//Step 11
     }
}

void DijkstraSSS::loadCostMatrix(ifstream &inFile){
     int node1;
     int node2;
     int edgeCost;
     while(!inFile.eof()){
          inFile>>node1;
          inFile>>node2;
          inFile>>edgeCost;
          costMatrix[node1][node2] = edgeCost;
     }
}

void DijkstraSSS::setBestCostAry(int sNode){
     bestCostAry = costMatrix[sNode];
}

void DijkstraSSS::setFatherAry(int sNode){
     for(int i=1; i < numNodes+1; i++){
          fatherAry[i] = sNode;
     }
}

void DijkstraSSS::setToDoAry(int sNode){
     for(int i=1; i < numNodes+1; i++){
          if(i==sNode){
               toDoAry[i] = 0;
          }else{
               toDoAry[i] = 1;
          }
     }
}

int DijkstraSSS::findMinNode(){
     int mNode = 0;
     int mCost = 99999;
     for(int i=1; i < numNodes+1; i++){
          if(toDoAry[i] == 1){
               if(bestCostAry[i] < mCost){
                    mCost = bestCostAry[i];
                    mNode = i;
               }
          }
     }
     return mNode;
}

int DijkstraSSS::computeCost(int mNode, int cNode){
     int cost = 0;
     cost = bestCostAry[mNode] + costMatrix[mNode][cNode];
     return cost;
}

void DijkstraSSS::markMinNode(int mNode){
     toDoAry[mNode] = 0;
}

void DijkstraSSS::changeFather(int node, int mNode){
     fatherAry[node] = mNode;
}

void DijkstraSSS::changeCost(int node, int newCost){
     bestCostAry[node] = newCost;
}

void DijkstraSSS::debugPrint(ofstream &outFile2){
     stringstream ss1;
     string line1 = "";
     stringstream ss2;
     string line2 = "";
     stringstream ss3;
     string line3 = "";
     outFile2<<"The sourceNode is: "<<sourceNode<<endl;
     for(int i=1; i < numNodes+1; i++){
          ss1<<fatherAry[i];
          ss1<<" ";
     }
     line1 = ss1.str();
     outFile2<<"The fatherAry is: "<<line1<<endl;
     for(int i=1; i < numNodes+1; i++){
          ss2<<bestCostAry[i];
          ss2<<" ";
     }
     line2 = ss2.str();
     outFile2<<"The bestCostAry is: "<<line2<<endl;
     for(int i=1; i < numNodes+1; i++){
          ss3<<toDoAry[i];
          ss3<<" ";
     }
     line3 = ss3.str();
     outFile2<<"The toDoAry is: "<<line3<<endl;
     outFile2<<'\n';
}

string DijkstraSSS::printShortestPaths(int cNode){
     stringstream ss;
     string line;
     int pathNode = cNode;
     stringstream path;
     string pathLine = "";
     ss<<"The shortest path from ";
     ss<<sourceNode;
     ss<<" to ";
     ss<<cNode;
     ss<<" : ";
     ss<<cNode;
     ss<<" <- ";
     while(fatherAry[pathNode]!=sourceNode){
          pathNode = fatherAry[pathNode];
          path<<pathNode;
          path<<" <- ";
     }
     ss<<path.str();
     ss<<sourceNode;
     ss<<" : ";
     ss<<"cost = ";
     ss<<bestCostAry[cNode];
     ss<<'\n';
     line = ss.str();
     return line;
}

bool DijkstraSSS::checkAllZero(){
     for(int i=1; i < numNodes+1; i++){
          if(toDoAry[i]==1){
               return false;
          }
     }
     return true;
}
