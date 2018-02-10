/**
	自定义hashCode()
*/
public class NewType{
	private final String id;
	private final Date when;
	private final String type;
	private final double d;
	private final int i;
	
	public int hashCode(){
		int hash = 17;
		hash = 31 * hash + id.hashCode();
		hash = 31 * hash + when.hashCode();
		hash = 31 * hash + type.hashCode();
		hash = 31 * hash + ((Double) d).hashCode();
		hash = 31 * hash + ((Integer) i).hashCode();
		
		return hash;
	}
}