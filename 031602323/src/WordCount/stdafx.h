// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 在此处引用程序需要的其他头文件
#include "Count.h"

class File
{
public:
	void CharCount();
	void WordCount();
	void WordSeq();
	void LineCount();
	void writeTxt();
	void print();
	File()
	{
		Char = 0;
		Word = 0;
		Line = 0;
	}
	File(string s)
	{
		this->name = s;
		Char = 0;
		Word = 0;
		Line = 0;
	}
	~File() {}

private:
	string name;
	int Char;
	int Word;
	int Line;
	pair<string, int> str[15];

	void Delete(string &s, const string &mark)
	{
		size_t nSize = mark.size();
		while (1)
		{
			size_t pos = s.find(mark);
			if (pos == string::npos)
			{
				return;
			}
			s.erase(pos, nSize);
		}
	}

};