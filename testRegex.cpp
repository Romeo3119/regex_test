#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <stdio.h>

using namespace std;

//regex_match的使用：
void test_regex_match()
{
	string src = "Hello_2019_Romeo";
	smatch result;
	//在匹配规则中，用()来划分组别，因此共有三组。
	regex reStr("(.{5})_(\\d{4})_(.{5})"); //匹配任意5个单字符 + 下划线 + 四个数字 + 5个任意单字符
	if (regex_match(src, result, reStr))
	{
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}
	cout << "result.size() = " << result.size() << endl;


	//有时候需要忽略大小写:就要用到语法选项
	cout << "测试大小写" << endl;
	
	cout << regex_match("aaaAAA", regex("a*", regex::icase)) << endl;
	cout << regex_match("aaaAAA", regex("a*")) << endl;
}


//regex_search的使用
void test_regex_search()
{
	//先来比较两者的区别
	cout << regex_match("123", regex("\\d")) << endl;  //0
	cout << regex_match("123", regex("\\d+")) << endl;  // 1
	cout << regex_match("123", regex("\\d{3}")) << endl;//1
	cout <<regex_search("123", regex("\\d")) << endl; //1
	//可以得出，regex_search是来进行搜索的，级搜索字符串中是否存在符合的子字符串。

	string str = " Hello 2020, Bye 2019";
	smatch result;
	regex pattern("([0-9]{4})"); // 或者 regex pattern("(.{4})");

	string::const_iterator c_begin = str.cbegin();
	string::const_iterator c_end = str.end();
	string temp;
	while (regex_search(c_begin, c_end, result, pattern))
	{
		temp = result[0];
		cout << temp << " ";
		c_begin = result[0].second; //更新迭代器的位置，用来遍历剩下的结果
	}
}

//regex_replace()的使用
void test_regex_replace()
{
	//先试试这个函数的用法
	string str = "hello_2020!!!";
	//regex pattern("hello");
	//cout << regex_replace(str, pattern, "") << endl;
	//cout << regex_replace(str, pattern, "Hello") << endl;

	//还可以调整字符串内容
	regex pattern("(.{2})(.{3})_(\\d{4})"); //匹配任意两个字符+3个字符+下划线+4个数字
	cout << regex_replace(str, pattern, "$1$2") << endl; //将源串里的内容用匹配到的第一部分和第二部分代替hello!!!
	cout << regex_replace(str, pattern, "$2$3") << endl; //...用第二和第三部分代替 llo_2020!!!
	//$n  表示第n组匹配数据
}

int main()
{
	test_regex_match();

	//test_regex_search();

	//test_regex_replace();
	system("pause");
	return 0;
}