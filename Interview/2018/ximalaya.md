##喜马拉雅面试经验
知识面检查最广的一次面试，一面面试官非常nice，人很好。技术背景非常深，问题一个接一个，都是复杂的基础问题。第一次知识被检查得这么彻底。

#### 一面：Team Leader
	
	1.Object有哪些方法
		1.hashCode()
		2.equals()
		3.toString()
		4.wait()
		5.notify()
		6.notifyAll()
		
	2.equals和hashCode有什么关联，hashCode相等，equals可以不等。equals相等，hashCode一定相等
	
	3.wait() 和 sleep()的区别
		sleep() 在操作系统层面是可以中断的，在Java语言里面不能中断
	
	4.Dubbo通信原理
		1.域名解析
		2.应用层 --> TCP --> ip --> 物理链路层，一层层的封装报头协议，一层层的解析协议。
		3.客户端调用服务端全过程：
			1.客户端去注册中心找到Service对应的ip
			2.客户端封装调用信息：唯一标识ID、接口服务、接口、接口参数等信息
			3.客户端建立连接：connRequest、IOSession流处理
			4.服务端解析调用信息，去调用本地服务，返回结果，将结果和ID封装在一起返回。
			5.客户端轮询检查服务端返回结果，根据ID，知道返回的结果是哪个客户端的调用。
		4.注册中心：轮询服务器，检查是否有新的服务，是否有服务挂掉了。维护一个service和ip地址的映射关系
		5.客户端调用也是轮询注册中心，去检查请求的service的ip地址，如果服务挂掉了，自动就发现了其他可用的服务ip地址。
		
		dubbo调用的连接是怎么样的，依赖注册中心交互吗？不是的，客户端和服务端直接建立连接的。
		
	5.Socket连接是阻塞的，为什么？
		单线程在执行它，一个线程管理着一个socket的整个生命周期。面试官说是因为协议，TCP连接的原因。但是我认为这不是的，之后说了NIO和AIO，应该也是基于TCP链接的，但是它们和BIO同步阻塞是不一样的。
		
	6.buffer的作用
		1.socket里面的buffer作用？
			操作系统对硬盘的读写是按照磁盘块为单位处理的，存在预读。因为磁盘一般是操作系统的性能瓶颈，批处理能够显著地提高性能等。
		2.服务端如何实现buffer？
			服务端在接受socket传过来的流的时候，不是接收一个字节，就立马去解析处理，而是将流的输出放在buffer中，读满一个buffer，或者读完了，再一起去处理这些内容。提高性能和效率。
		3.客户端如何实现buffer？
			客户端与服务端建立好连接之后，不是直接向socket发送数据流，而是先将要发送数据往本地的buffer中装，装完或者装满一个buffer之后，一起往socket中传输的。不可能是客户端找到一个字节，就发送一次，再去找或者解析一个字节，再去发送一个字节。
		
	7.两个非常大的文件：100G、100G，内存只有2G，如果找到两个文件中相同的记录，输出到一个文件中。
		思路：使用hash，计算文件记录的hash值，依据hash值，将文件中的记录分类，很容易就可以找到相同的记录。
	
	8.数据库事务隔离级别。
		7个隔离级别：主要讲解清楚Requires_new 和 nested的相同点和区别点。
	
	9.HashMap实现原理，链表转化为红黑树的边界条件。
		数组+链表+红黑树
	
	9.线程池了解吗？
		Java Executors四个线程池：
			newCachedThreadPool
			newFixedThreadPool
			newScheduledThreadPool
			newSingleThreadExecutor
			newSingleThreadScheduledExecutor
	
	10.Spring源代码有研究吗？
		没有研究，主要是知道一些注解原理，现在主要是使用SpringBoot，注解非常多。看过《J2EE development without EJB》这本书，了解一些Spring的实现原理。spring有一些模板Template，比如RestTemplate；还有一些support，特别是事务实现中。
		
	11.BeanFactory原理？Bean的生成过程
		1.xml配置bean，Spring有一些类似于SpringFactoryLoader类，会去加载并解析这些配置文件，得到类名之类的信息。
		2.spring的IOC容器，会根据JVM中相关类的信息，去new一个这个类的对象，并将这个对象装进容器中，这样就生成了Bean，可以直接用了。
		3.中间会有一些AOP处理的工作。
		核心就是IOC自动创建对象，管理对象依赖。
	
	12.数据库优化方法：如何分析一个select语句。
		使用explain，关注的对象：1.是否利用了索引，2.rows大小
			1.建立索引
			2.关联表查询时，先查询数据量小的表，再去大表筛选，可以优化性能。
		limit 分页原理。limit 1 100
			查询10000后面的100条数据，怎么做？
			先查询10000的记录，再查询大于它的100条记录即可，不能使用limit实现。
	
	13.写一个生产者、消费者模型
		wait 和 notiyAll过程交互
		
	14.Lock实现 lock() unlock()
		1.使用一个flag标记字段。
		2.如果需要区分锁是谁的，自己加的锁，只有自己可以释放，模仿分布式锁的实现。加一个id字段。
		3.lock如果遇到已经被加锁，则不能加锁，可以直接返回，没有问题。如果不返回，该如何实现？
			while(flag) ，不是if(flag) 存在性能问题，while一直在执行，浪费资源
			优化：再使用另一个线程，在轮询这个锁，控制轮询的时间间隔，不使用while，提高性能。模拟wait阻塞状态。
	
#### 二面：技术大牛

	1.写一个缓存服务：存放Key-Value，线程安全的，支持LRU淘汰策略。
		1.使用Map存储
		2.使用List记录key的操作顺序，新操作的在前面。淘汰的时候，优先淘汰后面。
		3.使用一颗平衡树维护这个key和List的下标，快速找到key。(知道链表的下标，好像是不能提高性能的)
		使用两个平衡树，维护key的update：对象有两个属性：(Key, timestamp), 一棵树以key为键排序，一棵树以timestamp为键排序。
		既可以实现log(n)时间的修改和查找。
		
		这个一下子给我干蒙了，这么复杂的问题，我写10几分钟，发现纸上有办法写，因为无法修改，这样复杂的东西，在纸上怎么写出来呢？
		只能和面试官沟通，如何实现的思路，开始想维护一个基于时间戳的小根堆，堆满的时候，直接淘汰堆顶元素。但是基于时间戳的堆，找到key的复杂度是O(n)的。淘汰策略非常简单，堆顶的就是最小时间戳的。
		
	2.数据库非聚集索引、聚集索引的区别？MyISAM 和 InnoDB的查询性能等。
	
	3.关联索引的原理，那些情况可以使用索引，where A = a 和 where A = a and B = b都可以利用关联索引，区别是什么？
	
	4.数据库事务传播机制
	
	5.多线程的包有哪些类？
		Thread、Runnable、ExcutorService、Excutors、concurrentHashMap
		
		线程池的关键属性：
			corePoolSize：核心池的大小，这个参数跟后面讲述的线程池的实现原理有非常大的关系。在创建了线程池后，默认情况下，线程池中并没有任何线程，而是等待有任务到来才创建线程去执行任务，除非调用了prestartAllCoreThreads()或者prestartCoreThread()方法，从这2个方法的名字就可以看出，是预创建线程的意思，即在没有任务到来之前就创建corePoolSize个线程或者一个线程。默认情况下，在创建了线程池后，线程池中的线程数为0，当有任务来之后，就会创建一个线程去执行任务，当线程池中的线程数目达到corePoolSize后，就会把到达的任务放到缓存队列当中；
			maximumPoolSize：线程池最大线程数，这个参数也是一个非常重要的参数，它表示在线程池中最多能创建多少个线程；
			keepAliveTime：表示线程没有任务执行时最多保持多久时间会终止。默认情况下，只有当线程池中的线程数大于corePoolSize时，keepAliveTime才会起作用，直到线程池中的线程数不大于corePoolSize，即当线程池中的线程数大于corePoolSize时，如果一个线程空闲的时间达到keepAliveTime，则会终止，直到线程池中的线程数不超过corePoolSize。但是如果调用了allowCoreThreadTimeOut(boolean)方法，在线程池中的线程数不大于corePoolSize时，keepAliveTime参数也会起作用，直到线程池中的线程数为0；
			unit：参数keepAliveTime的时间单位，有7种取值，在TimeUnit类中有7种静态属性。
	
	6.concurrentHashMap实现原理，JDK1.8
	
	7.TreeMap原理
	
	8.一致性hash了解吗？如何实现的
	
	9.CMS了解吗？如何实现的，有stopTheWorld吗？回收的年老代的垃圾，标记清除方法，也有整理功能，处理内存碎片。
	10.年轻的垃圾回收算法，年轻的内存模型等。
	
	11.项目，性能优化的列子。
	12.分布式事务实现原理。数据库方法实现，如何处理回滚？MQ方法实现分布式事务。