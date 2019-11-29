#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <stdio.h>

using namespace std;

//regex_match��ʹ�ã�
void test_regex_match()
{
	string src = "Hello_2019_Romeo";
	smatch result;
	//��ƥ������У���()�����������˹������顣
	regex reStr("(.{5})_(\\d{4})_(.{5})"); //ƥ������5�����ַ� + �»��� + �ĸ����� + 5�����ⵥ�ַ�
	if (regex_match(src, result, reStr))
	{
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}
	cout << "result.size() = " << result.size() << endl;


	//��ʱ����Ҫ���Դ�Сд:��Ҫ�õ��﷨ѡ��
	cout << "���Դ�Сд" << endl;
	
	cout << regex_match("aaaAAA", regex("a*", regex::icase)) << endl;
	cout << regex_match("aaaAAA", regex("a*")) << endl;
}


//regex_search��ʹ��
void test_regex_search()
{
	//�����Ƚ����ߵ�����
	cout << regex_match("123", regex("\\d")) << endl;  //0
	cout << regex_match("123", regex("\\d+")) << endl;  // 1
	cout << regex_match("123", regex("\\d{3}")) << endl;//1
	cout <<regex_search("123", regex("\\d")) << endl; //1
	//���Եó���regex_search�������������ģ��������ַ������Ƿ���ڷ��ϵ����ַ�����

	string str = " Hello 2020, Bye 2019";
	smatch result;
	regex pattern("([0-9]{4})"); // ���� regex pattern("(.{4})");

	string::const_iterator c_begin = str.cbegin();
	string::const_iterator c_end = str.end();
	string temp;
	while (regex_search(c_begin, c_end, result, pattern))
	{
		temp = result[0];
		cout << temp << " ";
		c_begin = result[0].second; //���µ�������λ�ã���������ʣ�µĽ��
	}
}

//regex_replace()��ʹ��
void test_regex_replace()
{
	//����������������÷�
	string str = "hello_2020!!!";
	//regex pattern("hello");
	//cout << regex_replace(str, pattern, "") << endl;
	//cout << regex_replace(str, pattern, "Hello") << endl;

	//�����Ե����ַ�������
	regex pattern("(.{2})(.{3})_(\\d{4})"); //ƥ�����������ַ�+3���ַ�+�»���+4������
	cout << regex_replace(str, pattern, "$1$2") << endl; //��Դ�����������ƥ�䵽�ĵ�һ���ֺ͵ڶ����ִ���hello!!!
	cout << regex_replace(str, pattern, "$2$3") << endl; //...�õڶ��͵������ִ��� llo_2020!!!
	//$n  ��ʾ��n��ƥ������
}

int main()
{
	test_regex_match();

	//test_regex_search();

	//test_regex_replace();
	system("pause");
	return 0;
}