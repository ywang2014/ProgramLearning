/**
	B-树的页的API
*/
public class Page<Key>{
	public Page(boolean bottom){
		//
	}
	
	public void close()
	
	public void add(Key key)	// 将键插入到外部的页中
	
	public void add(Page p)		// 打开P，向内部页中插入条目，将p与p中最小的键相关联
	
	public boolean isExternal()
	
	public boolean contains(Key key)
	
	public Page next(Key key)
	
	public boolean isFull()
	
	public Page split()
	
	public Iterable<Key> keys()
}