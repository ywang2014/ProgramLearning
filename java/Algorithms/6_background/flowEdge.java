/**
	Flow Edge
*/
public class FlowEdge{
	private final int v;
	private final int w;
	private final double cap;
	private double flow;
	
	public FlowEdge(int v, int w, double cap){
		this.v = v;
		this.w = w;
		this.cap = cap;
	}
	
	public int from(){
		return this.v;
	}
	
	public int to(){
		return this.w;
	}
	
	public int other(int v){
		if (this.v = v){
			return this.w;
		}
		else if (this.w = v){
			return this.v;
		}
		else{
			// throw exception
		}
	}
	
	public double capacity(){
		return this.cap;
	}
	
	public double flow(){
		return this.flow;
	}
	
	public double residualCapacityTo(int v){
		//
	}
	
	public double addFlowTo(int v, double delta){
		//
	}
	
	public String toString(){
		//
	}
}