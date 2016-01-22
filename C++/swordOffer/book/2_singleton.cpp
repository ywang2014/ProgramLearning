/*
	Theme 2.实现Singleton模式
	
	设计一个类，只能生成该类的一个实例
*/

class Single
{
	private:
		Single(){};	// 构造函数私有即可
		
	public:
		~Single(void);
		static Single getInstance()
		{
			Single instance;
			return instance;
		}
}；

// C#版本
public sealed class Singleton2
{
	private Singleton2(){};
	
	private static Singleton2 instance = null;
	public static Singleton2 getInstance
	{
		get
		{
			if (instance == null)
			{
				instance = new Singleton2();
			}
			
			return instance;
		}
	}
}

// C#版本，多线程安全
public sealed class Singleton3
{
	private Singleton3(){};
	
	private static readonly object syncObj = new object();
	
	private static Singleton3 instance = null;
	public static Singleton3 getInstance
	{
		get
		{
			lock(syncObj)
			{
				if (instance == null)
				{
					instance = new Singleton3();
				}
			}
			return instance;
		}
	}
}

// C#版本，多线程安全，高效率的
public sealed class Singleton4
{
	private Singleton4(){};
	
	private static object syncObj = new object();
	
	private static Singleton4 instance = null;
	public static Singleton3 getInstance
	{
		get
		{
			if (instance == null)
			{
				lock(syncObj)
				{
					if (instance == null)
					{
						instance = new Singleton4();
					}
				}
			}
			
			return instance;
		}
	}
}

// C#版本，利用静态构造函数，确保只调用一次
public sealed class Singleton5
{
	private Singleton5(){};
	
	private static Singleton5 instance = new Singleton5();
	public static Singleton5 getInstance{
		get
		{
			return instance;
		}
	}
}

// C#版本，实现按需创建实例
public sealed class Singleton6
{
	Singleton6(){};
	
	public static Singleton6 getInstance{
		get
		{
			return Nested.instance;
		}
	}
	
	class Nested
	{
		static Nested(){};
		
		internal static readonly Singleton6 instance = new Singleton6();
	}
}
