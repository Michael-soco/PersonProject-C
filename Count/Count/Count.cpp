// Count.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Count.h"

DLL_API int charCount(string fname)
{
	ifstream infile;
	infile.open(fname, ifstream::in);
	if (!infile.is_open())
		cout << "open error!" << endl;

	char c;
	int Char = 0;
	infile >> noskipws;

	while (infile.peek() != EOF)
	{
		infile >> c;
		Char++;
//		cout << Char << endl;
	}
	return Char;
}

DLL_API int wordCount(string fname)
{
	ifstream infile;
	infile.open(fname, ifstream::in);
	if (!infile.is_open())
		cout << "open error!" << endl;

	char c;
	int Word=0;
	infile >> noskipws;

	infile.clear();
	infile.seekg(0);

	while (infile.peek() != EOF)
	{
		string w;
		infile >> c;
		while ((c != ' ') && (c != '\t') && (c != '\n'))
		{
			if (c >= 65 && c <= 90)   //大写转小写
				c = c + 32;

			w = w + c;				//越界
			infile >> c;
		}
		if (isWord(w))  //w是单词，将其加入map
			Word++;
	}
	return Word;
}

DLL_API void wordSeq(string fname,pair<string,int> str_cnt[])
{
	typedef pair<string, int> PAIR;
	vector<PAIR> vec;
	map<string, int> cnt;
	map<string, int>::iterator curr;
	vector<PAIR>::iterator it;

	ifstream infile;
	infile.open(fname, ifstream::in);
	if (!infile.is_open())
		cout << "open error!" << endl;

	char c;
	int i=0;
	infile >> noskipws;

	infile.clear();
	infile.seekg(0);

	while (infile.peek() != EOF)
	{
		string w;
		infile >> c;
		while ((c != ' ') && (c != '\t') && (c != '\n'))
		{
			if (c >= 65 && c <= 90)   //大写转小写
				c = c + 32;

			w = w + c;				//越界
			infile >> c;
		}
		if (isWord(w))  //w是单词，将其加入map
		{
			if (cnt.count(w) == 0)
			{
				cnt[w] = 1;
			}
			else
			{
				cnt[w]++;
			}
		}
	}

	for (curr = cnt.begin();curr != cnt.end();curr++)
	{
		vec.push_back(make_pair(curr->first, curr->second));
	}

	sort(vec.begin(), vec.end(), cmp);

	for (it = vec.begin(),i=0;it != vec.end()&&i<10;it++,i++)
	{
	//	cout << '<' << (*it).first << '>' << ':' << (*it).second << endl;
		str_cnt[i].first = (*it).first;
		str_cnt[i].second = (*it).second;
	}

}

bool isWord(string w)
{
	int l = w.length();
	if (l < 4) return false;
	for (int i = 0;i < 4;i++)
	{
		if (!(w[i] >= 97 && w[i] <= 122)) return false;
	}
	for (int i = 4;i < l;i++)
	{
		if (!((w[i] >= 97 && w[i] <= 122) || (w[i] >= 48 && w[i] <= 57)))
			return false;
	}
	return true;
}

int cmp(const pair<string, int> &x, const pair<string, int> &y)	//从大到小排序
{
	return x.second > y.second;
}



