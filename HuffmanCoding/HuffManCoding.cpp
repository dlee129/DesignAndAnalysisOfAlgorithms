#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class listBinTreeNode{
     public:
          string chStr;
          int prob;
          string charCode;
          listBinTreeNode *next;
          listBinTreeNode *left;
          listBinTreeNode *right;
          listBinTreeNode(){
          }
          listBinTreeNode(string charIn, int pr){
               chStr = charIn;
               prob = pr;
          }
          string printNode(listBinTreeNode *T);
};

class HuffmanLinkedList{
     public:
          listBinTreeNode *listHead;
          listBinTreeNode *oldListHead;
          listBinTreeNode *nodePTR;
          listBinTreeNode *spot;
          HuffmanLinkedList(){
               string f = "dummy";
               listHead = new listBinTreeNode(f,0);
               listHead->next = NULL;
          }
          void constructHuffmanLList(ifstream &inData);
          listBinTreeNode *findSpot(int pr);
          void listInsert(listBinTreeNode *spot, listBinTreeNode *newNode);
          bool isEmpty();
          void printList(ofstream &outData);
};

class HuffmanBinaryTree{
public:
     listBinTreeNode *root;
     void constructHuffmanBinTree(ofstream &outFile5, HuffmanLinkedList *LList);
     void preOrderTraversal(ofstream &outFile2, listBinTreeNode *T);
     void inOrderTraversal(ofstream &outFile3, listBinTreeNode *T);
     void postOrderTraversal(ofstream &outFile4, listBinTreeNode *T);
     bool isLeaf(listBinTreeNode *T);
     HuffmanBinaryTree(){

     }
     void constructCharCode(ofstream &outFile1, listBinTreeNode *T, string code);
};

int main(int argc, char** argv){
     ifstream inFile;
     ofstream outFile1;
     ofstream outFile2;
     ofstream outFile3;
     ofstream outFile4;
     ofstream outFile5;
     inFile.open(argv[1]);
     outFile1.open(argv[2]);
     outFile2.open(argv[3]);
     outFile3.open(argv[4]);
     outFile4.open(argv[5]);
     outFile5.open(argv[6]);
     HuffmanLinkedList *LL = new HuffmanLinkedList();
     LL->constructHuffmanLList(inFile);
     LL->printList(outFile5);
     inFile.close();
     HuffmanBinaryTree *BT = new HuffmanBinaryTree();
     BT->constructHuffmanBinTree(outFile5, LL);
     BT->constructCharCode(outFile1, BT->root, " ");
     BT->preOrderTraversal(outFile2, BT->root);
     BT->inOrderTraversal(outFile3, BT->root);
     BT->postOrderTraversal(outFile4, BT->root);
     outFile1.close();
     outFile2.close();
     outFile3.close();
     outFile4.close();
     outFile5.close();

}

void HuffmanLinkedList::constructHuffmanLList(ifstream &inData){
     listBinTreeNode *dummy = listHead;
     string inChar;
     int inProb;
     while(!inData.eof()){
          inData>>inChar;
          inData>>inProb;
          spot = findSpot(inProb);
          listBinTreeNode *newNode = new listBinTreeNode(inChar, inProb);
          listInsert(spot, newNode);
          }
}

void HuffmanLinkedList::printList(ofstream &outData){
     listBinTreeNode *current = listHead;
     stringstream ss;
     string line;
     ss<<"listHead";
     while(current!=NULL){
          ss<<" --> (";
          ss<<current->chStr;
          ss<<",";
          ss<<current->prob;
          ss<<",";
          if(current->next!=NULL){
               ss<<current->next->chStr;
          }
          else{
               ss<<"NULL";
          }
          ss<<")";
          current = current->next;

     }
          line = ss.str();
     outData<<line;
}

void HuffmanLinkedList::listInsert(listBinTreeNode *spot, listBinTreeNode *newNode){
     newNode->next = spot->next;
     spot->next = newNode;
}

listBinTreeNode *HuffmanLinkedList::findSpot(int pr){
     listBinTreeNode *temp = listHead;
     if(isEmpty()){
          return NULL;
     }
     while(temp->next!=0 && temp->next->prob < pr){
          temp = temp->next;
     }
     return temp;
}

bool HuffmanLinkedList::isEmpty(){
     return listHead==NULL;
}

string listBinTreeNode::printNode(listBinTreeNode *T){
     stringstream ss;
     string line;
     ss<<"(";
     ss<<T->chStr;
     ss<<", ";
     ss<<T->prob;
     ss<<", ";
     if(T->next==NULL) {
      ss<<"NULL";
     }
     else {
      ss<<T->next->chStr;
     }
     ss<<", ";
     if(T->left==NULL) {
      ss<<"NULL";
     }
     else {
      ss<<T->left->chStr;
     }
     ss<<", ";
     if(T->right==NULL) {
      ss<<"NULL";
     }
     else {
      ss<<T->right->chStr;
     }
     ss<<")";
     line = ss.str();
     return line;

}

void HuffmanBinaryTree::constructHuffmanBinTree(ofstream &outFile5, HuffmanLinkedList *LList){
     LList->oldListHead = LList->listHead;
     LList->oldListHead->next = LList->listHead->next;
     stringstream ss;
     string line;

     while(LList->listHead->next!=NULL&&LList->listHead->next->next!=NULL){
          listBinTreeNode *newNode = new listBinTreeNode();
          newNode->prob = LList->listHead->next->prob + LList->listHead->next->next->prob;
          newNode->chStr = LList->listHead->next->chStr + LList->listHead->next->next->chStr;
          newNode->left = LList->listHead->next;
          newNode->right = LList->listHead->next->next;
          LList->listHead =  LList->listHead->next;
          LList->listHead =  LList->listHead->next;
          LList->spot = LList->findSpot(newNode->prob);
          LList->listInsert(LList->spot, newNode);
          root = newNode;
          outFile5<<'\n';
          outFile5<<root->chStr;
          outFile5<<" ";
          outFile5<<root->prob;
     }
}

void HuffmanBinaryTree::preOrderTraversal(ofstream &outFile2, listBinTreeNode *T){
     if(T==NULL) {
          //do nothing
     }
     else {
          outFile2<<T->printNode(T);
          preOrderTraversal(outFile2, T->left);
          preOrderTraversal(outFile2, T->right);
     }
}

void HuffmanBinaryTree::inOrderTraversal(ofstream &outFile3, listBinTreeNode *T){
     if(T==NULL) {
          //do nothing
     }
     else {
          inOrderTraversal(outFile3, T->left);
          outFile3<<T->printNode(T);
          inOrderTraversal(outFile3, T->right);
     }
}

void HuffmanBinaryTree::postOrderTraversal(ofstream &outFile4, listBinTreeNode *T){
     if(T==NULL) {
          //do nothing
     }
     else {
          postOrderTraversal(outFile4, T->left);
          postOrderTraversal(outFile4, T->right);
          outFile4<<T->printNode(T);
     }
}

bool HuffmanBinaryTree::isLeaf(listBinTreeNode *T){
     return T->left==NULL&&T->right==NULL;
}

void HuffmanBinaryTree::constructCharCode(ofstream &outFile1, listBinTreeNode *T, string code){
     stringstream ss;
     if(T==NULL) {
          cout<<"This is an empty tree";
     }
     else if(isLeaf(T)) {
          ss<<'\n';
          ss<<"<";
          ss<<T->chStr;
          ss<<" ";
          ss<<code;
          ss<<">";
          string line = ss.str();
          T->charCode=code;
          outFile1<<line;
     }
     else {
          constructCharCode(outFile1,T->left,code+"0");
          constructCharCode(outFile1,T->right,code+"1");
     }
}
