#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	map<int,int>my_map;
	int n;
	cin>>n;
	while(true)
	{
		int t;
		cin>>t;
		
		if(t==-1) break;
		else
		my_map[t]++;
	}
	cout<<endl<<"------Printing--------"<<endl;
	map<int,int>::iterator it;
	for(it=my_map.begin();it!=my_map.end();it++)
	{
	cout<<endl<<"Element "<<it->first<<"has frequency"<<it->second<<endl;
		
	}
	return 0;
}
