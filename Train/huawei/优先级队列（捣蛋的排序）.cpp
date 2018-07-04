#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const string &A,const string&B)
{
	int size_A = A.size()-1;
	int size_B = B.size()-1;

	return A[size_A] > B[size_B];
}

int main()
{
	string str;
	cin >> str;
	vector<string> res;
	int pos_start = 0;
	int pos_end;
	int size = str.size();

	while (1)
	{
		pos_end = str.find(',');
		if (pos_end == -1)
		{
			res.push_back(str);
			break;
		}
			

		string temp =str.substr(0,pos_end);  //截取
		res.push_back(temp);

		str = str.substr(pos_end+1);  //接着看下面
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i]<<endl;

	cout << endl;
	sort(res.begin(),res.end(),cmp);
	for (int i = 0; i < res.size()-1; i++)
		cout << res[i] << ',';
	cout << endl;
		 
	return 0;
}
