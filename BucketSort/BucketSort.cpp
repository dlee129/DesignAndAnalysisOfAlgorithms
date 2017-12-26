#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int hashfunction(int &x){
     return x;
}

int main(int argc, char **argv){
     ifstream inFile;
     inFile.open(argv[1]);
     ofstream outFile;
     outFile.open(argv[2]);
     int maxSize = 0;
     int data;
     while(inFile>>data){
          if(data > maxSize) maxSize = data;
     }
     inFile.close();
     inFile.open(argv[1]);
     int *bucketAry = new int[maxSize + 1];
     for(int i=0; i <= maxSize; i++){
          bucketAry[i] = 0;
     }
     while(inFile>>data){
          int index = hashfunction(data);
          bucketAry[index]++;
     }
     int index = 0;
     stringstream ss;
     string line = "";
     ss<<"Bucket Array Sorted: ";
     ss<<'\n';
     while(index <= maxSize){
          while(bucketAry[index]>0){
               ss<<index;
               ss<<" ";
               bucketAry[index]--;
          }
          index++;
     }
     line = ss.str();
     outFile<<line;
     inFile.close();
}
