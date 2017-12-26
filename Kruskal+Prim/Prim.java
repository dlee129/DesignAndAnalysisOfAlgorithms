import java.util.*;
import java.io.*;

public class project7{
	
	static class undirectedEdge{
		
		int Ni;
		int Nj;
		int edgeCost;
		undirectedEdge next;
		
		undirectedEdge(int n1, int n2, int cost){
			Ni = n1;
			Nj = n2;
			edgeCost = cost;
		}
		
		String printEdge(undirectedEdge edge) {
			return "";
		}
		
	}//end of undirectedEdge class
	
	static class PrimMST{
		
		int numNodes;
		int inWhichSet[];
		undirectedEdge edgeListHead;
		undirectedEdge MSTofG;
		int totalMSTCost;
		
		PrimMST(int n){
			numNodes = n;
			inWhichSet = new int[numNodes+1];
			totalMSTCost = 0;
			edgeListHead = new undirectedEdge(0,0,0);
			edgeListHead.next = null;
			MSTofG = new undirectedEdge(0,0,0);
			MSTofG.next = null;
			inWhichSet[1]=1;
			for(int i=2; i <= numNodes;i++) {
					inWhichSet[i]=2;
				}
			}
		
		void insertEdge(undirectedEdge edge) {
			undirectedEdge edgePTR = edgeListHead;
		    while(edgePTR.next != null && edge.edgeCost > edgePTR.next.edgeCost){
				edgePTR = edgePTR.next;
			}
			edge.next = edgePTR.next;
			edgePTR.next = edge;			
		}
		
		undirectedEdge removedEdge() {
			undirectedEdge current = edgeListHead, front = current.next;
	        while (inWhichSet[front.Ni] == inWhichSet[front.Nj]){
	            current = front;
	            front = front.next;
	        }
	        
	        current.next = front.next;

	        return front;
		}
		
		void pushEdge(undirectedEdge edge){
			edge.next = MSTofG;
			MSTofG = edge;
		}
		
		void move2Set(int node) {
			inWhichSet[node]=1;
		}
		
		String printSet(int array[]) {
		     String line = "";
		     line+="inWhichSet contains these nodes: ";
		     line+='\n';
		     for(int i=0; i < numNodes+1; i++){
		          line+=array[i];
		          line+=" ";
		     }
		     line+='\n';
		     line+='\n';
		     return line;
		}
		
		String printList(undirectedEdge listHead) {
			undirectedEdge current = listHead;
		    String line = "";
		    line+="listHead ";
		    while(current != null){
		         line+="-> <";
		         line+=current.Ni;
		         line+=" ";
		         line+=current.Nj;
		         line+=" ";
		         line+=current.edgeCost;
		         line+="> ";
		         current = current.next;
		    }
		    line+='\n';
		    line+='\n';
		    return line;
		}
		
		boolean checkAllOne() {
			for(int i=1; i <= numNodes; i++) {
				if(inWhichSet[i]==2) {
					return false;
				}
			}
			return true;
		}
		
		String entireMST(undirectedEdge MST) {
			undirectedEdge current = MST;
		    String line= "";
		    line+="MST of G: ";
		    line+='\n';
		    while(current != null && current.edgeCost!=0){
		         line+=current.Ni;
		         line+=" ";
		         line+=current.Nj;
		         line+=" ";
		         line+=current.edgeCost;
		         line+='\n';
		         current = current.next;
		    }
		    line+='\n';
		    line+='\n';
		    line+="Total cost of MST is: ";
		    line+=totalMSTCost;
		    return line;
		}
		
		void constructPrim(Scanner sc, PrintWriter pw1, PrintWriter pw2) {
			int node1, node2, cost;
			undirectedEdge nextEdge;
			pw2.println(printSet(inWhichSet));
			while(sc.hasNext()) {	
				node1 = sc.nextInt();
				node2 = sc.nextInt();
				cost = sc.nextInt();
				undirectedEdge newEdge = new undirectedEdge(node1, node2, cost);
		        insertEdge(newEdge);
		        pw2.println(printList(edgeListHead));
			}
			
			while(!checkAllOne()) {
				nextEdge = removedEdge();
				pushEdge(nextEdge);
				totalMSTCost += nextEdge.edgeCost;
				move2Set(nextEdge.Ni);
				move2Set(nextEdge.Nj);
				pw2.println(printSet(inWhichSet));
				pw2.println(printList(MSTofG));
			}
			pw1.println(entireMST(MSTofG));
		}
	}
	
	public static void main(String []args) throws FileNotFoundException{
		
		Scanner inFile = new Scanner(new FileReader(args[0]));
		PrintWriter outFile1 = new PrintWriter(args[1]);
		PrintWriter outFile2 = new PrintWriter(args[2]);
		
		int numOfNodes = inFile.nextInt();
		PrimMST Prim = new PrimMST(numOfNodes);
		Prim.constructPrim(inFile, outFile1, outFile2);
		
		inFile.close();
		outFile1.close();
		outFile2.close();
		
	}
}