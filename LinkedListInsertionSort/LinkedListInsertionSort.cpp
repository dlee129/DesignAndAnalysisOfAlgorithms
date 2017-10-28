#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class listnode{
     public:
          string data;
          listnode *next;
          listnode(){

          }
          listnode(string name){
               data = name;
          }

};

class LinkedList{
     public:
          listnode *ListHead, *nodePTR;
          void listInsert(string nodeData);
          void listDelete(string nodeData);
          bool isEmpty();
          string printList();
          LinkedList(){
               string f = "dummy";
               ListHead = new listnode(f);
               ListHead->next = NULL;
          }
};


int main(int argc, char **argv){
     string token;
     ifstream inFile;
     inFile.open(argv[1]);
     ofstream outFile;
     outFile.open(argv[2]);
     LinkedList *list = new LinkedList();
     while(!inFile.eof()){
          inFile>>token;
          list->listInsert(token);
          outFile<<list->printList();
     }
     inFile.close();
     outFile.close();
     return 0;
}

void LinkedList::listInsert(string nodeData){
     listnode* newNode;
	nodePTR = ListHead;
	if(nodePTR->next != NULL && nodeData > nodePTR->next->data){
		nodePTR = nodePTR->next;
	}
	newNode = new listnode();
	newNode->data = nodeData;
	newNode->next = nodePTR->next;
	nodePTR->next = newNode;
}

bool LinkedList::isEmpty(){
     return ListHead=NULL;
}

void LinkedList::listDelete(string nodeData){
     //Did not need to implement according to Project outline
}

string LinkedList::printList(){
     listnode *current = ListHead;
     string nodeList = "listHead";
     while(current != NULL&&current->next!=NULL){
          nodeList += " --> (";
          nodeList += current->data;
          nodeList += ", ";
          nodeList += current->next->data;
          nodeList += ")";
          current = current->next;
     }
     nodeList += '\n';
     return nodeList;
}
