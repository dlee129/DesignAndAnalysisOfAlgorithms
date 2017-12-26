#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string printAry(int charArray[]){
     stringstream ss;
     int index = 0;
     string charLine;
     while(index < 256){
          if(charArray[index]>0){
               char symbol = (char) index;
               ss<<symbol;
               ss<<" # ";
               ss<<charArray[index];
               ss<<'\n';
               charLine = ss.str();
          }
          else{
               //do nothing
          }
          index++;
     }
     return charLine;
}

int main(int argc, char **argv){
     char charIn;
     int index = 0 ;
     int charCounts[256] = {0};
     ifstream inFile;
     ofstream outFile;
     inFile.open(argv[1]);
     outFile.open(argv[2]);
     while(!inFile.eof()){
          inFile>>charIn;
          index = (int)charIn;
          charCounts[index]++;
     }
     outFile<<printAry(charCounts);
     inFile.close();
     outFile.close();
     return 0;
}
