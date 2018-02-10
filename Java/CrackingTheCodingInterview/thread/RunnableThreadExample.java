/**
	线程实现	实现Runnable接口
*/
public class RunnableThreadExample implements Runnable{
	public int count = 0;
	
	public void run(){
		System.out.println("RunnableThread starting.");
		try{
			while (count < 5){
				Thread.sleep(500);
				count++;
			}
		}
		catch (InterruptedException exc){
			System.out.println("RunnableThread interrupted.");
		}
		System.out.println("RunnableThread terminating.");
	}
	
	public static void main(String[] args){
		RunnableThreadExample instance = new RunnableThreadExample();
		Thread thread = new Thread(instance);
		thread.start();
		
		while (instance.count != 5){
			try{
				Thread.sleep(250);
			}
			catch (InterruptedException exc){
				exc.printStackTrace();
			}
		}
	}
}