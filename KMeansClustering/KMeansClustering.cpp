#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

class Point{
public:
     int X_coordinate;
     int Y_coordinate;
     int label;
     double distance; //the distance to its own cluster centroid.
     Point(){

     }
     Point(int x, int y){
          X_coordinate = x;
          Y_coordinate = y;
     }
     void PrintPoint(Point p); //this method to print the info of a given point
};

class KMeans{
public:
     int K; //given in the input file. number of clusters
     struct xyCoord{
          int X_coordinate;
          int Y_coordinate;
          int label;
     };
     xyCoord *Kcentroids; // to be dynamically allocated in  class constructor
     int numPts;
     Point *pointSet; // to be dynamically allocated in  class constructor
     int numRow;
     int numCol;
     int **imageArray; // a 2-D integer array to be dynamically allocated in  class  constructor. Size: numRows X numCol
     int changeLabel;
     KMeans(int KClust, int KnumPts, int KnumRow, int KnumCol){
          K = KClust;
          Kcentroids = new xyCoord[K+1];
          numPts = KnumPts;
          pointSet = new Point[numPts];
          numRow = KnumRow;
          numCol = KnumCol;
          imageArray = new int*[numRow];
          for(int i = 0; i < numRow; i++){
               imageArray[i] = new int[numCol]();
          }// initializing an array of column in each row
     } //constructor
     void loadPointSet(ifstream &inFile); // read each point from input file and store it onto the struct pointSet array.
     void assignLabel(); // assighn each point a label from 1 to K sequentially in pointSet array.
     void mapPoint2Image(); // read each point from pointSet and its label and map the label on the imageArray.
     void kMeanClustering(ifstream &inFile, ofstream &outFile1, ofstream &outFile2);
     void printPointSet();
     void PrettyPrint(ostream &outFile2); //Print the imageArray to output-2 if imageArray(i,j) > 0 print imageArray(i,j) else print one blank space.
};


int main(int argc, char **argv){
     ifstream inFile;
     inFile.open(argv[1]);
     ofstream outFile1;
     outFile1.open(argv[2]);
     ofstream outFile2;
     outFile2.open(argv[3]);
     int KInput;//Step 0
     int PtsInput;
     int RowInput;
     int ColInput;
     inFile>>KInput;
     inFile>>PtsInput;
     inFile>>RowInput;
     inFile>>ColInput;//end of Step 0 
     KMeans KM(KInput, PtsInput, RowInput, ColInput);
     KM.kMeanClustering(inFile, outFile1, outFile2);
     inFile.close();
     outFile1.close();
     outFile2.close();
}

void KMeans::kMeanClustering(ifstream &inFile, ofstream &outFile1, ofstream &outFile2){
     loadPointSet(inFile);//Step 1
     assignLabel();//Step 2
     changeLabel = 1;
     while(changeLabel > 0){//Step 8
          mapPoint2Image();//Step 3
          PrettyPrint(outFile2);// Step 4
          changeLabel = 0; //Step 5.1
          for(int i=1; i <= K; i++){//Step 5.2
               Kcentroids[i].label = i;
               double x_total = 0;
               double y_total = 0;
               int x_count = 0;
               int y_count = 0;
               for(int j=0; j < numPts; j++){
                    if(pointSet[j].label==Kcentroids[i].label){
                         x_total = x_total + pointSet[j].X_coordinate;
                         y_total = y_total + pointSet[j].Y_coordinate;
                         x_count++;
                         y_count++;
                    }
               }
               Kcentroids[i].X_coordinate = x_total/x_count;
               Kcentroids[i].Y_coordinate = y_total/y_count;
          }//end of Step 5.2

          for(int i=0; i < numPts; i++){//Step 6.1 - Step 7
               int min_i = 1;
               pointSet[i].distance = sqrt(pow(Kcentroids[1].X_coordinate - pointSet[i].X_coordinate, 2) + pow(Kcentroids[1].Y_coordinate - pointSet[i].Y_coordinate, 2));
               double distance1 = pointSet[i].distance;
               for(int j=2; j<=K; j++){
                    pointSet[i].distance = sqrt(pow(Kcentroids[j].X_coordinate - pointSet[i].X_coordinate, 2) + pow(Kcentroids[j].Y_coordinate - pointSet[i].Y_coordinate, 2));
                    double distance2 = pointSet[i].distance;
                    if(distance1 > distance2){
                         distance1 = distance2;
                         min_i = j;
                    }
                    else if(distance1 == distance2){
                         min_i = pointSet[i].label;
                    }
               }
               if(min_i != pointSet[i].label){
                    pointSet[i].label = min_i;
                    changeLabel++;
               }
          }//Step 6.1 - Step 7
     }//Step 8
     PrettyPrint(outFile1);
}

void KMeans::loadPointSet(ifstream &inFile){
     int X;
     int Y;
     int index = 0;
     while(!inFile.eof()){
          inFile>>X;
          inFile>>Y;
          pointSet[index].X_coordinate = X;
          pointSet[index].Y_coordinate = Y;
          index++;
     }
}

void KMeans::assignLabel(){
     int labelcounter = 1;
     for(int i=0; i < numPts; i++){
          pointSet[i].label = labelcounter;
          labelcounter++;
          if(labelcounter > K){
               labelcounter = 1;
          }
     }
}

void KMeans::mapPoint2Image(){
     for(int i=0; i < numPts; i++){
          int x = pointSet[i].X_coordinate;
          int y = pointSet[i].Y_coordinate;
          imageArray[x][y] = pointSet[i].label;
     }
}

void KMeans::PrettyPrint(ostream &outFile2){
     for(int i=0; i < numRow; i++){
          for(int j=0; j < numCol; j++){
               if(imageArray[i][j] > 0){
                    outFile2<<imageArray[i][j];
                    outFile2<<" ";
               }
               else{
                    outFile2<<" ";
               }
          }
          outFile2<<'\n';
     }
}
