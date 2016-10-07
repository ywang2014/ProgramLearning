/**
	软缓存技术
	T 3.4.25
*/
public class Transaction{
	private final String who;
	private final Date when;
	private final double amount;
	private int hash = -1;
	
	private int hashCode(){
		int hash = 17;
		hash = 31 * hash + who.hashCode();
		hash = 31 * hash + when.hashCode();
		hash = 31 * hash + ((Double) amount).hashCode();
		
		return hash;
	}
	
	public int getHash(){
		if (hash == -1){
			hash = hashCode();
		}
		return hash;
	}
}