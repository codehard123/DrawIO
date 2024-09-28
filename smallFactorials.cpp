#include<bits/stdc++.h>
using namespace std;

// let's first replace stoi with to_no
int to_no(char x)
{
	return x-'0';
}
string addition(string a,string b)
{
	int carry=0;
	string result;
	string shortString=a.length()!=b.length() && a.length()<b.length()?a:b;
	string longString=a.length()!=b.length()&&a.length()>b.length()?a:b;
	
	if(a.length()==b.length())
	{
		shortString=a;
		longString=b;
	}
	// Equalizing length by prepending zeroes
	while(shortString.length()!=longString.length())
	{
		shortString="0"+shortString;
	}
		int slen=shortString.length(); //small length 
	int llen=largeString.length(); 
	int a=0;
	string answerString="";
	int remainder=0;
	while(llen)
	{
		// llen llen-1 , llen -2 , llen-3.... 1 (that is  llen times)
		// we can find digit and append it to right side
		
		a=carry+to_no(shortString[llen-1])+to_no(largeString[llen-1]);
		carry=a/10;
		remainder=a%10;
		// now we can add to answerString
		answerString=to_string(remainder)+answerString;
		llen=llen-1;
	}
	if(carry!=0)
	{
		// If a carry results from addition of the values at leftmost index then
		answerString=to_string(carry)+answerString; 
	}
	return answerString;
}
string multiply(string a,string b)
{
	string result;
	string shortString=a.length()!=b.length() && a.length()<b.length()?a:b;
	string longString=a.length()!=b.length()&&a.length()>b.length()?a:b;
	if(a.length()==b.length())
	{
		shortString=a;
		longString=b;
	}
	int slen=shortString.length(); //small length 
	int llen=largeString.length(); //large length 
	//multiply longString by shortString using digits of shortString
 // Responsible for adding additional zeroes at the end of intermediate result
	for(int i=slen-1,int addingZeroesCounter=0;;i>=0;i--,addingZeroesCounter++)
	{
		// we will read string from right to left and multiply digits
		int carry=0;
		for(int j=llen-1;j>=0;j--)
		{
			int number1=to_no(longString[j]);
			// stoi stands for string to integer
			
			int number2=to_no(shortString[i]);
			long int product=(number1*number2)+carry;
			carry=product/10;
			int digit=product%10;
			// 8 98 798 .. so resultss are at front
			answerString=to_string(digit)+answerString;
			//Now we need to add carry to the next results
			
		}
		
		if(addingZeroesCounter)
		{
		
			// add that many zeroes as the value of addingZeroesCounter variable
			for(int zeroes=1;zeroes<=addingZeroesCounter;zeroes++)
			{
				answerString=answerString+"0";
			}
		}
	}
}
