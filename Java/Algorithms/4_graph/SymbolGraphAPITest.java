/**
	符号图的测试用例
*/
public class SymbolGraphAPITest{
	public static void main(String[] args){
		String filename = args[0];
		String delim = args[1];
		SymbolGraph sg = new SymbolGraph(filename, delim);
		Graph g = sg.G();
		
		while (StdIn.hasNextLine()){
			String source = StdIn.readLine();
			for (int w : g.adj(sg.index(source))){
				StdOut.println(" " + sg.name(w));
			}
		}
	}
}