// ConsoleApplicationHot100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include <iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int solution1()
{
	vector<int> nums;
	int target = 0;
	vector<int> resV;	//resulut container 
	char* s = (char*)malloc(sizeof(char) * 100);		//input string
	cin.getline(s,100);

	int elm = 0;	//calculate num[i]
	int flag = 0;
	int i=0;
	while (s[i] != ']') {
		elm = 0;
		while (isdigit(s[i])) {
			elm = elm * 10 + (s[i] - '0');
			flag = 1; i++;
		}
		if (flag) {
			nums.push_back(elm);
			flag = 0;
		}
		else { 
			i++; 
		}
	}

	//target
	while (s[i] != '=') { i++; }
	i += 2;
	while (isdigit(s[i])) {
		target = target * 10 + (s[i] - '0');
		i++;
	}
	/*
	for (int j1 = 0; j1 < numV.size(); j1++) {
		for (int j2 = j1 + 1; j2 < numV.size(); j2++) {
			if (numV[j1] + numV[j2] == target) {
				resV.push_back(j1);
				resV.push_back(j2);
				return 0;
			}
		}
	}
	*/
	unordered_map<int, int> mMap;
	for (int i = 0; i < nums.size(); i++) {
		auto it =mMap.find(target - nums[i]);
		if (it != mMap.end()) {
			cout << i;
			cout<<mMap[target - nums[i]];
		}
		else {
			//mMap.insert({i,nums[i]} );
			mMap[nums[i]] = i;
		}
	}
	return 0;
}

int solution3() {
	string s = " ";
	bool t[256];
	for (int i = 0; i < 256; i++) {
		t[i] = false;
	}

	int maxLen = 0;

	int len = 0;
	int begin = 0;
	int end = 0;
	while (end < s.length()) {
		if (t[s[end]]) {          //如果新字母以前出现过
			len = end - begin;  //统计长度
			maxLen = maxLen > len ? maxLen : len;
			while (s[begin] != s[end]) {    //找到以前出现字母后的下一个字母
				t[s[begin]] = false;
				begin++;
			}
			begin++;
		}
		else {
			t[s[end]] = true; //没出现过end后移
		}
		end++;
	}
	len = end - begin;
	if (len > maxLen) { maxLen = len; }
	cout<< maxLen;
}

int main() {
	string s="{}";
	vector<char> sta;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			sta.push_back(s[i]);
		}
		else {
			if (sta.size() == 0) { cout<<"false"; }
			char t = sta[sta.size() - 1];
			sta.pop_back();
			if (s[i] == '(' && t == ')') { continue; }
			if (s[i] == '[' && t == ']') { continue; }
			if (s[i] == '{' && t == '}') { continue; }
			cout << "false";
		}
	}
	if (sta.size() == 0) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}
