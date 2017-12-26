import java.io.*;
import java.util.Scanner;

public class LeeD_Project2_Java{
	
	static char charIn;
	static int index;
	static int charCounts[] = new int[256];
	static Scanner inFile;
	static File file;
	static PrintWriter outFile;
	
	public static void printAry() {
		index = 0;
		for(int i=0; i<256; i++) {
			char symbol = (char) index;
				if(charCounts[index]>0) {
					String charLine ="";
					charLine+= symbol;
					charLine+= " # ";
					charLine+= charCounts[index];
					outFile.println(charLine);
			}
			else {
				//do nothing
			}
			index++;
		}
	}
	
	public static void main(String []args) throws FileNotFoundException{
		inFile = new Scanner(new FileReader(args[0]));
		file = new File(args[1]);
		outFile = new PrintWriter(file);
		
		while(inFile.hasNext()) {
			String token = inFile.next();
			for(int i=0; i<token.length();i++) {
				charIn = token.charAt(i);
				index = (int)charIn;			
				charCounts[index]++;
			}
		}//while until reaches end of data
		
		printAry();
		
		inFile.close();
		outFile.close();
	}//main constructor
	
}//Project class
