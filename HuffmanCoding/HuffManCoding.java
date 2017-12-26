import java.util.*;
import java.io.*;

public class Project3{

	static class listBinTreeNode{
		String chStr;
		int prob;
		String charCode;
		listBinTreeNode next;
		listBinTreeNode left;
		listBinTreeNode right;
		listBinTreeNode(){
		}
		listBinTreeNode(String charIn, int pr){
			chStr = charIn;
			prob = pr;
		}
		String printNode(listBinTreeNode T) {
		     String line="(";
		     line+=T.chStr;
		     line+=", ";
		     line+=T.prob;
		     line+=", ";
		     if(T.next==null) {
		    	 line+="NULL";
		     }
		     else {
		    	 line+=T.next.chStr;
		     }
		     line+=", ";
		     if(T.left==null) {
		    	 line+="NULL";
		     }
		     else {
		    	 line+=T.left.chStr;
		     }
		     line+=", ";
		     if(T.right==null) {
		    	 line+="NULL";
		     }
		     else {
		    	 line+=T.right.chStr;
		     }
		     line+=")";
		     return line;
		}
	}

	static class HuffmanLinkedList{
		listBinTreeNode listHead;
		listBinTreeNode oldListHead;
		listBinTreeNode nodePTR;
		listBinTreeNode spot;
		HuffmanLinkedList(){
			String f = "dummy";
			listHead = new listBinTreeNode(f,0);
			listHead.next = null;
		}
		void constructHuffmanLList(Scanner sc) {
		     listBinTreeNode dummy = listHead;
		     String inChar;
		     int inProb;
		     while(sc.hasNext()){
		          inChar = sc.next();
		          inProb = sc.nextInt();
		          spot = findSpot(inProb);
		          listBinTreeNode newNode = new listBinTreeNode(inChar, inProb);
		          listInsert(spot, newNode);
		          }
		}
		listBinTreeNode findSpot(int pr) {
		     listBinTreeNode temp = listHead;
		     if(isEmpty()){
		          return null;
		     }
		     while(temp.next!=null && temp.next.prob < pr){
		          temp = temp.next;
		     }
		     return temp;
		}
		void listInsert(listBinTreeNode spot, listBinTreeNode newNode) {
			newNode.next = spot.next;
		     spot.next = newNode;
		}
		boolean isEmpty() {
			return listHead==null;
		}
		void printList(PrintWriter pw) {
		     listBinTreeNode current = listHead;
		     String line = "listHead";
		     while(current!=null){
		    	 line+=" --> (";
		    	 line+=current.chStr;
		    	 line+=",";
		    	 line+=current.prob;
		    	 line+=",";
		          if(current.next!=null){
		        	  line+=current.next.chStr;
		          }
		          else{
		        	  line+="NULL";
		          }
		          line+=")";
		          current = current.next;
		     }
		     pw.println(line);
		}
	}

	static class HuffmanBinaryTree{
	     listBinTreeNode root;
	     void constructHuffmanBinTree(PrintWriter pw, HuffmanLinkedList LList) {
		     LList.oldListHead = LList.listHead;
		     LList.oldListHead.next = LList.listHead.next;
		     while(LList.listHead.next!=null&&LList.listHead.next.next!=null){
		          listBinTreeNode newNode = new listBinTreeNode();
		          newNode.prob = LList.listHead.next.prob + LList.listHead.next.next.prob;
		          newNode.chStr = LList.listHead.next.chStr + LList.listHead.next.next.chStr;
		          newNode.left = LList.listHead.next;
		          newNode.right = LList.listHead.next.next;
		          LList.listHead =  LList.listHead.next;
		          LList.listHead =  LList.listHead.next;
		          LList.spot = LList.findSpot(newNode.prob);
		          LList.listInsert(LList.spot, newNode);
		          root = newNode;
		          pw.println(root.chStr+" "+ root.prob);
		     }

	     }
	     void preOrder(PrintWriter pw, listBinTreeNode T) {
	    	 if(T==null) {
	    		 //do nothing
	    	 }
	    	 else {
	    		 pw.println(T.printNode(T));
		    	 preOrder(pw, T.left);
		    	 preOrder(pw, T.right);
	    	 }

	     }
	     void inOrder(PrintWriter pw,listBinTreeNode T) {
	    	 if(T==null) {
	    		 //do nothing
	    	 }
	    	 else {
	    		 inOrder(pw, T.left);
	    		 pw.println(T.printNode(T));
		    	 inOrder(pw, T.right);
	    	 }
	     }
	     void postOrder(PrintWriter pw, listBinTreeNode T) {
	    	 if(T==null) {
	    		 //do nothing
	    	 }
	    	 else {
	    		 postOrder(pw, T.left);
		    	 postOrder(pw, T.right);
	    		 pw.println(T.printNode(T));
	    	 }
	     }
	     boolean isLeaf(listBinTreeNode T) {
	    	 return T.left==null&&T.right==null;
	     }
	     HuffmanBinaryTree(){

	     }
	     void constructCharCode(PrintWriter pw, listBinTreeNode T, string code) {
	    	 if(T==null) {
	    		 System.out.println("This is an empty tree");
	    		 System.exit(0);
	    	 }
	    	 else if(isLeaf(T)) {
	    		 String line = "<"+T.chStr+" "+code+">";
	    		 T.charCode=code;
	    		 pw.println(line);
	    	 }
	    	 else {
	    		 constructCharCode(pw,T.left,code+"0");
	    		 constructCharCode(pw,T.right,code+"1");
	    	 }
	     }
	}

	public static void main(String []args) throws FileNotFoundException {
		Scanner inFile = new Scanner(new FileReader(args[0]));
		PrintWriter outFile1 = new PrintWriter(args[1]);
		PrintWriter outFile2 = new PrintWriter(args[2]);
		PrintWriter outFile3 = new PrintWriter(args[3]);
		PrintWriter outFile4 = new PrintWriter(args[4]);
		PrintWriter outFile5 = new PrintWriter(args[5]);
	     HuffmanLinkedList LL = new HuffmanLinkedList();
	     LL.constructHuffmanLList(inFile);
	     LL.printList(outFile5);
	     inFile.close();
	     HuffmanBinaryTree BT = new HuffmanBinaryTree();
	     BT.constructHuffmanBinTree(outFile5, LL);
	     BT.constructCharCode(outFile1, BT.root, " ");
	     BT.preOrder(outFile2, BT.root);
	     BT.inOrder(outFile3, BT.root);
	     BT.postOrder(outFile4, BT.root);
	     outFile1.close();
	     outFile2.close();
	     outFile3.close();
	     outFile4.close();
	     outFile5.close();

	}
}//Project3 class
