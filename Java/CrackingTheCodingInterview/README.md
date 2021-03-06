#程序员面试金典-Gayle Laakmann McDowell，李琳骁译
Cracking the Coding Interview 150 Programming Questions and Solutions

这是一本关于程序员技术面试指导的书，是我看的第三本专门指导程序员面试的书，非常经典，揭示了许多IT名企招聘的秘密。
全书300多页，共9章，涉及的内容很多，包含150个编程问题，以及精巧的解决方案；应对棘手算法，5种分析方法；指导面试
相关的注意事项，和面试相关的准备策略。

1-7章主要涉及面试流程解析、面试官的幕后决策，以及可能提出的问题、面试前的准备工作、对面试结果的处理等内容；
8-9章从数据结构、概念与算法、知识类问题和附加题等4个方面，为读者呈现了出自微软、苹果、谷歌等多家知名公司的150道
编程面试题，和详细解决方案。

帮助读者加深对计算机科学基础知识的理解，并学会该如何运用这些基础知识，成功闯过技术面试的难关。

充分准备，会让你在技术和人际沟通技能等方面，更进一步。不管结果如何，拼尽全力，无怨无悔！


#### 章节学习小结
第1章：面试流程
	
	十大常见错误：
		只在计算机上练习：多在纸上练习写代码
		不做行为面试题演练：总结项目和经历
		不做模拟面试训练：提前准备，让朋友、同学帮忙面试一下，发现不足等
		死记硬背答案：自己想、理解才是王道，质量胜于数量
		不大声说出你的解题思路：说出来，才能被人知道，凸显你的沟通能力
		过于仓促：仔细检查，注意细节
		代码不够严谨：注重可维护性
		不做测试：审查一下程序代码，再提交
		修正错误漫不经心：遇见bug很正常，应该仔细修正，绝对不能胡乱修改。
		轻言放弃：碰到棘手问题，请不要惊慌，也不要轻言放弃。
		
第2章：面试揭秘

	Macrosoft：“聪明人”，热衷于技术
	Amazon：扩展性、面向对象设计
	Google：设计可扩展的系统、位操作
	Apple：技术功底、“果粉”
	Facebook：“忍术”(灵活应变)、注重创新创造、优雅、可扩展解决方案
		在线工程难题：www.facebook.com/careers/puzzles.php
	Yahoo：系统设计
	
第3章：特殊情况

	算法、编程能力都是核心和基础，必备技能
	沟通能力、团队协作能力、对技术的热情
	
第4章：面试之前

	想方设法提高技术(非技术)水平
	培养自己的领导才能
	广交朋友，保持广度，紧密联系，保持深度，真诚待人，乐于助人
	
	写好简历，一页篇幅即可，简介重点突出，展示自己的技术和聪明才智
	工作经历：列举要点	使用Y实现了X，从而达到了Z效果(量化结果)
	项目经历：项目描述简明扼要，使用那些技术和语言等
	
第5章：行为面试题

	做好准备：项目如何讲解，常见问题等
	案例说明：开门见山，直接说；SAR方法：情景、行动、结果依次展开说明
	简明扼要，不要啰里啰嗦的，抓不住重点
	
第6章：技术面试题

	模拟面试 (www.careercup.com)
	基础数据结构和算法
	2的幂表
	
	解决技术面试五步法：
		向面试官提问，消除疑义，歧义
		设计一种算法
		先写伪码
		写代码不紧不慢
		测试完成的代码，仔细纠正错误
		
	算法题通用解法：
		举例法：熟悉的东西更加容易解决，具体的东西比抽象的东西容易理解
		模式匹配法：类比与此问题近似问题的解法
		简化推广法：先处理最简单的情况，再推广到复杂问题
		简单构造法：递归算法，从n=1开始，n=2, n=3, ...
		数据结构头脑风暴法：依次试探所有的数据结构，看看哪一种最有效
			数组、链表、哈希表、队列、栈、堆、树、二叉树、二叉搜索树、平衡树、红黑树、kd树、...
	
	善用数据结构，学会代码重用
	模块化代码：易于测试，更易阅读和维护
	
第7章：录用通知及其他

	礼貌对待被拒，可以询问何时可以参加下一次面试，下一次面试需要注意些什么等
	礼貌拒绝公司的邀请，也许下一次你又想去该公司
	工作开始做好职业规划，百尺竿头更进一步
	
第8章：面试考题

	数据结构：
		数组、字符串
			散列表hashMap、ArrayList(动态数组)、StringBuffer
		链表
			单链表、双链表
			检查空指针，更新头结点(head)、尾节点(tail)
			快行指针：同时使用两个指针来迭代访问链表，一个指针超前，且走的快
		栈与队列
			栈：后进先出
			队列：先进先出
		树与图
			树的遍历：前序、中序、后序
			树的平衡：红黑树、平衡树
			单词查找树trie
			
			深度优先搜索 DFS
			广度优先搜搜 BFS
	概念和算法：
		位操作
			^(xor)	~(compl)	
			a^(~a) = 1 
			x&(~0 << n) 将x最右边的n位清零
			| & ~ << 
		智力题
			不知道没有关系，大声说出你的思路
			数学规律和科学规律结合
		数学与概率
			gcd lcm
			韦恩图：
				P(AB) = P(B|A)*P(A)
				P(A+B) = P(A) + P(B) - p(AB)
			独立与互斥：切忌盲目将概率相乘或相加
		面向对象设计
			1.处理不明确的地方：问清楚问题，了解需求
			2.定义核心对象：
			3.分析对象关系
			4.研究对象的动作
			
			单例设计模式：一个类只有一个实例，只能通过类方法，访问此实例
			工厂方法设计模式：专门创建类的实例，生产实例基地，其他地方都不创建实例
		递归与动态规划
			自上而下的递归
			自下而上的递归
			动态规划：缓存结果+递归 
		扩展性与存储限制
			循序渐进法
				大胆假设：找出思路
				切合实际：考虑实际问题要处理好哪些方面
				解决问题：检查方案
			信息、策略、问题
		查找与排序
			冒泡排序：O(n^2) O(1)
			选择排序：O(n^2) O(1)	不稳定的
			归并排序：O(nlog(n)) NA
			快速排序：平均时间O(nlog(n)) 最差O(n^2) 空间O(log(n))
			基数排序：O(kn)
			二分查找、二叉搜索树、散列表
		测试 
			全局观、懂整合、会组织，有条理、可操作，能够合理执行
			黑盒测试、白盒测试
		C和C++
			类、继承
			构造函数，成员初始化列表，析构函数
			虚函数、纯虚函数、抽象类(不能实例化)、虚析构函数
			参数默认值：所有默认参数必须放在函数声明的右边
			操作符重载
			引用：对象的别名(即同一个对象，修改谁，都是一样的)
			模板：
		Java
			final：
				变量，说明变量是常量，不能修改值
				方法，说明该方法不能重写(override)
				类，说明该类不能派生子类
			finally：try catch一起使用，确保代码一定被执行
			finalize(): 真正销毁对象前，自动垃圾收集器，会调用finalize()方法。(类似于C++析构函数)
			重载：方法名称相同，函数签名不同
			重写：方法与父类方法完全相同
			Java的集合框架：
				ArrayList：可动态调整数组大小
				Vector：类似于ArrayList，是同步的(synchronized)
				LinkedList：迭代器语法 list.iterator()方法，返回迭代器
				HashMap：put(), get()方法 
		数据库
			SQL查询：
				explicit join:
					select courseName, teacherName
					from courses inner join teachers
					on courses.teacherId = teachers.teacherId 
				implicit join:
					select courseName, teacherName
					from courses, teachers
					where courses.teacherId = teachers.teacherId 
				显示连接和隐式连接是等价的
			非规范化数据库：存在冗余，优化读取时间，构建高可扩展性系统
			规范化数据库：将冗余降到最低
			数据库设计：
				处理不明确的地方 
				定义核心对象
				分析表之间的关系
				有哪些操作
		线程和锁
			Java实现线程两种方式：
				实现java.lang.Runnable接口
				扩展java.lang.Thread类
			同步：synchronized 同步方法、同步块
			锁：lock
			静态方法会以类锁进行同步
			死锁：
				互斥
				持有并等待
				没有抢占
				循环等待
			预防死锁：避免条件，循环等待最好
	
第9章：解题技巧
	
	问题解答与技巧分析，最喜欢的一章，因为不会的东西太多，看着答案最轻松了，希望看过之后，以后就会了！

###### Date
开始时间：2016-05-06

结束时间：2016-05-25

这本书的内容很薄，主要是对于程序员找工作的一些指导和建议，实用性强。然后就是面试题目的分析和讲解，这部分不仅可以整体归纳知识，
还能学习很多的解题技巧，非常漂亮！在这之前，看了一遍《剑指offer》，也是面向于程序的技术指导，看完之后，做算法题目，感觉非常轻松，
很多技巧非常有帮助。非常感谢这本书，感谢作者的付出和分享！