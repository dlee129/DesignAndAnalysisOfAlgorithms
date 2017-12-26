#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//class for HeapSort with methods and constructor
class HeapSort{
     public:
          int rootIndex;
          int fatherIndex;
          int leftKidIndex;
          int rightKidIndex;
          int minKidIndex;
          int *heapAry;
          HeapSort(int count){
               heapAry = new int[count+1];
               heapAry[0] = 0;
          }
          void buildHeap(ifstream &inFile);
          void deleteHeap(ofstream &outFile1, ofstream &outFile2);
          void insertOneDataItem(int data);
          int getRoot();
          void deleteRoot();
          void bubbleUp(int kidindex);
          void bubbleDown(int fatherindex);
          bool isLeaf(int index);
          bool isRoot(int index);
          int findMinKidIndex(int leftKidindex, int rightKidindex);
          bool isHeapEmpty();
          bool isHeapFull();
          string printHeap(int dataArray[]);
};

//main method to implement Program
int main(int argc, char** argv){
     ifstream inFile;
     ofstream outFile1;
     ofstream outFile2;
     inFile.open(argv[1]);
     outFile1.open(argv[2]);
     outFile2.open(argv[3]);
     int count = 0;
     int data;
     while(!inFile.eof()){
          inFile>>data;
          count++;
     }
     inFile.close();
     inFile.open(argv[1]);
     HeapSort hs(count);
     hs.buildHeap(inFile);
     outFile1<<hs.printHeap(hs.heapAry);
     hs.deleteHeap(outFile1, outFile2);
     inFile.close();
     outFile1.close();
     outFile2.close();
}

//buildHeap method that turns the data into a heap
void HeapSort::buildHeap(ifstream &inFile){
     rootIndex = 1;
     while(!inFile.eof()){
          int data;
          inFile>>data;
          insertOneDataItem(data);
     }
     printHeap(heapAry);
}

/*deleteHeap prints and deletes the root one by one
and prints the root into outFile2
eventually giving an ordered heap
*/
void HeapSort::deleteHeap(ofstream &outFile1, ofstream &outFile2){
     while(!isHeapEmpty()){
          int data = getRoot();
          outFile2<<data;
          outFile2<<" ";
          deleteRoot();
          fatherIndex = rootIndex;
          bubbleDown(fatherIndex);
          outFile1<<endl;
          outFile1<<printHeap(heapAry);
     }
}

//inserts data value at the end of heap
void HeapSort::insertOneDataItem(int data){
     heapAry[0]++;
     heapAry[heapAry[0]]=data;
     int kidIndex = heapAry[0];
     bubbleUp(kidIndex);
}

//retrieves root value
int HeapSort::getRoot(){
     return heapAry[rootIndex];
}

//deletes root and replaces it with heapAry[heapAry[0]] value
void HeapSort::deleteRoot(){
     heapAry[rootIndex] = heapAry[heapAry[0]];
     heapAry[0]--;
}

//bubbles up the heap when a new value is inserted and is
//less than its father index
void HeapSort::bubbleUp(int kidindex){
     if(isRoot(kidindex)){
          //do nothing returns that kidIndex is the root
     }
     else{
          fatherIndex = kidindex/2;
          if(heapAry[kidindex] < heapAry[fatherIndex]){
               int temp = heapAry[kidindex];
               heapAry[kidindex] = heapAry[fatherIndex];
               heapAry[fatherIndex] = temp;
          }
          bubbleUp(fatherIndex);
          }
}

//bubbles down the heap when the root value is deleted
//and replaces the fatherindex with the child if it is larger
void HeapSort::bubbleDown(int fatherindex){
     if(isLeaf(fatherindex)){
          //do nothing returns that fatherIndex is now a leaf
     }//outer if statement
     else{
          leftKidIndex = fatherindex * 2;
          rightKidIndex = fatherindex * 2 + 1;
          if(isHeapFull()){
               //skip minKidIndex
          }//inner if statement
          else{
               minKidIndex = findMinKidIndex(leftKidIndex, rightKidIndex);
               if(heapAry[minKidIndex] < heapAry[fatherindex]){
                    int temp = heapAry[minKidIndex];
                    heapAry[minKidIndex] = heapAry[fatherindex];
                    heapAry[fatherindex] = temp;
               }
               bubbleDown(minKidIndex);
          }//inner else statement
     }//outer else statement

}

//checks if the current index is at a leaf
bool HeapSort::isLeaf(int index){
     return leftKidIndex==0&&rightKidIndex==0;
}

//checks if the current index is the rootIndex
bool HeapSort::isRoot(int index){
     return rootIndex==index;
}

//finds the smaller of the values of the kids
//and returns the index of the smaller data
int HeapSort::findMinKidIndex(int leftKidindex, int rightKidindex){
     if(heapAry[leftKidindex]<heapAry[rightKidindex]){
          return leftKidindex;
     }
     else{
          return rightKidindex;
     }
}

//checks if heap is empty and that happens when heapAry[0]==0
bool HeapSort::isHeapEmpty(){
     return heapAry[0]==0;
}

//checks if heap is full and that happens when
//leftKidIndex > heapAry[0] || rightKidIndex > heapAry[0]
bool HeapSort::isHeapFull(){
     return leftKidIndex > heapAry[0] || rightKidIndex > heapAry[0];
}

//prints the heap from initially inserting and bubbling up
string HeapSort::printHeap(int dataArray[]){
     stringstream ss;
     string line;
     int index = 1;
     while(index < dataArray[0]){
          ss<<dataArray[index];
          ss<<" ";
          index++;
     }
     line = ss.str();
     return line;
}
