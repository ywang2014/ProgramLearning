/**
	Flow Network
*/
public class FlowNetwork{
	private final int v;
	private int e;
	
	public FlowNetwork(int v){
		this.v = v;
	}
	
	public FlowNetwork(In in){
		this.v = in.readInt();
	}
	
	public int V(){
		return this.v;
	}
	
	public int E(){
		return this.e;
	}
	
	public void addEdge(FlowEdge e){
		//
	}
	
	public Iterable<FlowEdge> adj(int v){
		//
	}
	
	Iterable<FlowEdge> edges(){
		// 
	}
	
	public String toString(){
		//
	}
}