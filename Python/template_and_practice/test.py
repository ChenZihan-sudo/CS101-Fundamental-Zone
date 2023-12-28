from sklearn.datasets import fetch_20newsgroups
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB  # 多项式朴素贝叶斯模型
from sklearn.metrics import classification_report

# 步骤 1.数据获取
news = fetch_20newsgroups(subset="all")
print("输出数据的条数:", len(news.data))  # 输出数据的条数:18846
# 步骤 2.数据预处理
# 分割训练集和测试集，随机采样 25%的数据样本作为测试集
X_train, X_test, y_train, y_test = train_test_split(
    news.data, news.target, testsize=0.25, random_state=33
)
# 文本特征向量化
vec = CountVectorizer()
X_train = vec.fit_transform(X_train)
X_test = vec.transform(X_test)
# 步骤 3.使用多项式朴素贝叶斯进行训练
model = MultinomialNB()
model.fit(X_train, y_train)  # 利用训练数据对模型参数进行估计
y_predict = model.predict(X_test)  # 对参数进行预测
# 步骤 4.获取结果报告
print("准确率:", model.score(X_test, y_test))
print(classification_report(y_test, y_predict, target_names=news.target_names))