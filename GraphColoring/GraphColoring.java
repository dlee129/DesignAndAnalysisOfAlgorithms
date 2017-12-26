// package edu.qc.cs323;

import java.util.*;
import java.io.*;

public class Main {

    static class Node{
        int ID;
        int color;
        int numEdges;
        Node next;

        Node(int nID, int c, int edges){
            ID = nID;
            color = c;
            numEdges = edges;
            next = null;
        }
    }

    static class graphColoring{
        int adjacencyMatrix[][];
        Node listHead;
        int uncolorNode;
        int newColor;
        int numNode;

        graphColoring(int n){
            numNode = n;
            adjacencyMatrix = new int [numNode+1][numNode+1];
            for(int i=0; i <= numNode; i++){
                for(int j=0; j <=numNode; j++){
                    adjacencyMatrix[i][j]=0;
                }
            }
            listHead = new Node(0,0,0);
        }

        void loadMatrix(Scanner sc){
            while(sc.hasNext()){
                int i = sc.nextInt();
                int j = sc.nextInt();
                adjacencyMatrix[i][j] = 1;
                adjacencyMatrix[j][i] = 1;

            }
        }
        void insertOneNode(Node listHead, Node newNode){
            Node PTR = listHead;
            if(listHead.next == null){
                newNode.next = listHead.next;
                listHead.next = newNode;
            }
            else{
                while(PTR.next!=null && newNode.numEdges > PTR.next.numEdges){
                    PTR = PTR.next;
                }
                newNode.next = PTR.next;
                PTR.next = newNode;
            }
        }
        void constructNodeList(Node pointer){
            for(int i=1; i <= numNode; i++){
                int countEdges = 0;
                for(int j=1; j <=numNode; j++){
                    if(adjacencyMatrix[i][j]!=0 && i!=j) countEdges++;
                }
                Node newNode = new Node(i, 0, countEdges);
                insertOneNode(pointer, newNode);
            }

        }
        int checkAdjacent(int nodeID, int color){
            for(int i=1; i <=numNode; i++){
                if(adjacencyMatrix[nodeID][i]!=0 && i!=nodeID){
                    if(adjacencyMatrix[i][i] == color) return 1;
                }
            }
            return 0;
        }

        void printMatrix(PrintWriter pw) {
            pw.println("The AdjacencyMatrix :");
            for (int i = 0; i <= numNode; i++) {
                String line = "";
                for (int j = 0; j <= numNode; j++) {
                    line += adjacencyMatrix[i][j] + " ";
                }
                pw.println(line);
            }
            pw.print('\n');
        }

        boolean allColored(){
            Node PTR = listHead.next;
            while(PTR!=null){
                if(PTR.color==0) return false;
                PTR = PTR.next;
            }
            return true;
        }
    }

    public static void main(String[] args) throws FileNotFoundException{
        Scanner inFile = new Scanner(new FileReader(args[0]));
        PrintWriter outFile1 = new PrintWriter(args[1]);

        int numOfNodes = inFile.nextInt();
        graphColoring gc = new graphColoring(numOfNodes);
        gc.loadMatrix(inFile);
        gc.printMatrix(outFile1);
        gc.constructNodeList(gc.listHead);
        gc.newColor = 0;

        while(!gc.allColored()) {
            gc.newColor++;
            Node currentNode = gc.listHead.next;
            while (currentNode != null) {
                if (currentNode.color == 0 && gc.checkAdjacent(currentNode.ID, gc.newColor) == 0) {
                    gc.adjacencyMatrix[currentNode.ID][currentNode.ID] = gc.newColor;
                    currentNode.color = gc.newColor;
                }
                currentNode = currentNode.next;
                if(currentNode == null) gc.printMatrix(outFile1);
            }
        }

        outFile1.print("The Total Number of colors is: ");
        outFile1.println(gc.newColor);
        outFile1.print('\n');

        gc.printMatrix(outFile1);

        inFile.close();
        outFile1.close();
    }
}
