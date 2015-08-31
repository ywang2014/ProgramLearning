# 随机森林
# install.packages("randomForest") #安装randomForest
library("randomForest")
data(iris) #iris数据集，是R语言自带的数据集
set.seed(100)
ind = sample(2, nrow(iris), replace = TRUE, prob = c(0.8, 0.2))
iris.rf = randomForest(Species~., iris[ind == 1,], ntree = 50, nPerm = 10, 
                       mtry = 3, proximity = TRUE, importance = TRUE)
print(iris.rf)
iris.pred = predict(iris.rf, iris[ind == 2, ])
table(observed = iris[ind == 2, "Species"], predicted = iris.pred)

# randomForest()对训练集的数据进行处理，生成决策树
# Species~.:代表需要预测的列，species是列的名称。
# iris[ind==1,]：生成决策树的训练集
# ntree：生成决策树的数目
# nperm：计算importance时的重复次数
# mtry：选择的分裂属性的个数
# proximity=TRUE：表示生成临近矩阵
# importance=TRUE：输出分裂属性的重要性
# iris.pred=predict( iris.rf,iris[ind==2,] )
# iris.rf：表示生成的随机森林模型
# iris[ind==2,] ：进行预测的测试集
