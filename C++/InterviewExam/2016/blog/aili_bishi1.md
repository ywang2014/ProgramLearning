vector<double> BatchQueryExecutionTime(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {
         // your code
    vector<double> result;
    
    vector<string>::const_iterator key = keywords.begin();
    for (; key != keywords.end(); ++key){
        double aveTime = 0.0;
        int counts = 0;
        for (int i = 0; i < sqls.size(); i++){
            string str = sqls[i];
            int pos = str.find(*key);
            if (pos != -1){
                aveTime += times[i];
                counts++;
            }
        }
        if (counts != 0){
            aveTime = aveTime / counts;
        }
        
        result.push_back(aveTime);
    }
    
    return result;
}


	struct SQL {
		string text; //SQL语句
		int kind;//所属分类
		double time;//执行时间
	};
	 
	struct Query {
		string keyword;// 查询关键词
		int kind;// 查询分类
		int id;// 查询标示，为传入查询列表的下标
	};


2.vector<double> BatchQueryExecutionTime(int kindSize, const vector<vector<int>>&kindsTree, const vector<SQL>&sqls, const vector<Query>&queries);

	// 1. 寻找该一类的关键字sql操作的所花费的总时间，和计数。
	// 2. 如果该类含有子分类，将子分类加入队列中，然后依次遍历队列中分类的关键字sql操作所花费的总时间和计数。
	// 3. 重复一二步，直到队列为空。
	// 4. 计算平均sql时间。 遍历树
	
	searchTree{
		kind = getkind()	// 获得其子分类
		pair<timeSum, counts> = getKindExcutionTime(kind, sqls, queries);   // 类似于问题1，只是添加了分类标签而已
	}
    return getAverage(timeSum, counts);
	
3. 和第二题一样，数据量更大。

	将分类合并，生成独立分类。子分类合并到父分类中，集合并的操作。
	然后单独分类，单独分类查找了。
	
