import java.util.*;
import java.io.*;

public class project6{
	
	static class DijkstraSSS{
		
		int numNodes;
		int sourceNode;
		int minNode;
		int currentNode;
		int newCost;
		int costMatrix[][];
		int fatherAry[];
		int toDoAry[];
		int bestCostAry[];
		
		DijkstraSSS(int num, int source){
			numNodes = num;
			sourceNode = source;
			costMatrix = new int [numNodes+1][numNodes+1];
			fatherAry = new int[numNodes+1];
			toDoAry = new int[numNodes+1];
			bestCostAry = new int[numNodes+1];
			for(int i=0; i < numNodes+1; i++) {
				for(int j=0; j< numNodes +1; j++) {
					if(i==j) {
						costMatrix[i][j]=0;
					}else {
						costMatrix[i][j]=99999;
					}
				}
			}
			for(int i=0; i < numNodes+1; i++) {
				fatherAry[i] = i;
			}
			for(int i=0; i < numNodes+1; i++) {
				toDoAry[i] = 1;
			}
			for(int i=0; i < numNodes+1; i++) {
				bestCostAry[i] = 99999;
			}
		}//class Constructor
		
		void loadCostMatrix(Scanner sc){
			int node1;
			int node2;
			int edgeCost;
			while(sc.hasNext()) {
				node1 = sc.nextInt();
				node2 = sc.nextInt();
				edgeCost = sc.nextInt();
				costMatrix[node1][node2] = edgeCost;
			}
		}//loadCostMatrix method

		void setBestCostAry(int sNode){
			bestCostAry = costMatrix[sNode];
		}//setBestCostAry method

		void setFatherAry(int sNode){
		     for(int i=1; i < numNodes+1; i++){
		          fatherAry[i] = sNode;
		     }
		}//setFatherAry method

		void setToDoAry(int sNode){
		     for(int i=1; i < numNodes+1; i++){
		          if(i==sNode){
		               toDoAry[i] = 0;
		          }else{
		               toDoAry[i] = 1;
		          }
		     }
		}//setToDoAry method

		int findMinNode(){
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
		}//findMinNode method

		int computeCost(int mNode, int cNode){
		     int cost = 0;
		     cost = bestCostAry[mNode] + costMatrix[mNode][cNode];
		     return cost;
		}//computeCost method

		void markMinNode(int mNode){
			toDoAry[mNode] = 0;
		}//markMinNode method

		void changeFather(int node, int mNode){
			fatherAry[node] = mNode;
		}//changeFather method

		void changeCost(int node, int newCost){
			bestCostAry[node] = newCost;
		}//changeCost method

		void debugPrint(PrintWriter pw2){
		     String line1 = "";
		     String line2 = "";
		     String line3 = "";
		     pw2.write("The sourceNode is: "+sourceNode+System.lineSeparator());
		     for(int i=1; i < numNodes+1; i++){
		          line1+=fatherAry[i]+" ";
		     }
		     pw2.write("The fatherAry is: "+line1+System.lineSeparator());
		     for(int i=1; i < numNodes+1; i++){
		          line2+=bestCostAry[i]+" ";
		     }
		     pw2.write("The bestCostAry is: "+line2+System.lineSeparator());
		     for(int i=1; i < numNodes+1; i++){
		          line3+=toDoAry[i]+" ";
		     }
		     pw2.write("The toDoAry is: "+line3+System.lineSeparator());
		     pw2.write(System.lineSeparator());
		}//deugPrint method

		String printShortestPaths(int cNode){
			String line = "The path from " + sourceNode + " to "+ cNode + " : " + cNode + " <- ";
			int pathNode = cNode;
			String line2 = "";
			while(fatherAry[pathNode]!=sourceNode) {
				pathNode = fatherAry[pathNode];
				line2 = line2 + pathNode + " <- "; 
			}
			line = line + line2;
			line += sourceNode;
			line += " : cost = " + bestCostAry[cNode];
			line += System.lineSeparator();
			return line;
		}//printShortestPaths method
		
		void constructDijkstras(PrintWriter pw1, PrintWriter pw2){
			setBestCostAry(sourceNode);//Step 2
			setFatherAry(sourceNode);
		    setToDoAry(sourceNode);//End of Step 2
		    while(!checkAllZero()){//Start of Step 8
		    	while(!checkAllZero()){//End of Step 8
		            minNode = findMinNode();//Step 3
		            markMinNode(minNode);
		            debugPrint(pw2);//End of Step 3
		            currentNode = 1;//Step 4
		            while(currentNode <= numNodes){//Step 7
		                 if(toDoAry[currentNode] == 1){//Step 5
		                      newCost = computeCost(minNode, currentNode);
		                      if(newCost < bestCostAry[currentNode]){
		                           changeCost(currentNode, newCost);
		                           changeFather(currentNode, minNode);
		                           debugPrint(pw2);//End of Step 5
		                      }
		                 }
		                 currentNode++;//Step 6
		            }//End of Step 7
		       }//End of Step 8
		       currentNode = 1;
		       while(currentNode <= numNodes){//Step 12
		            pw1.write(printShortestPaths(currentNode));//Step 10
		            currentNode++;//Step 11
		       }
		    }
		}//constructDijkstras method
		
		boolean checkAllZero() {
			for(int i=0; i < numNodes+1; i++) {
				if(toDoAry[i]==1) {
					return false;
				}
			}
			return true;
		}
	}
	
	public static void main(String []args) throws FileNotFoundException{
		
		Scanner inFile = new Scanner(new FileReader(args[0]));
		PrintWriter outFile1 = new PrintWriter(args[1]);
		PrintWriter outFile2 = new PrintWriter(args[2]);
		int numOfNodes = inFile.nextInt();
		int sourceOfNodes = inFile.nextInt();
		DijkstraSSS Dijk = new DijkstraSSS(numOfNodes, sourceOfNodes);
		Dijk.loadCostMatrix(inFile);
		Dijk.constructDijkstras(outFile1, outFile2);
		inFile.close();
		outFile1.close();
		outFile2.close();
	}
	
}