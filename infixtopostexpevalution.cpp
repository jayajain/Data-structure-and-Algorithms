#include<bits/stdc++.h>

using namespace std;

char p[100];
char op[100];
int top=-1;
int opt=-1;

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }
   else {
      return 0;
   }
}

int main()
{
	op[++opt]='#';
	string s;
	cin>>s;

	for(int i=0;i<s.length();i++)
	{
		if(isalnum(s[i]))
		{
				p[++top]=s[i];
		}
		else if(preced(s[i])>preced(op[opt]))
		{
			op[++opt]=s[i];	
		}
		else
		{
			while(opt!=0 && preced(s[i])<=preced(op[opt]))
			{
				p[++top]=op[opt--];
			}
			op[++opt]=s[i];
		}
	
	}
	while(opt!=0)
	{
		p[++top]=op[opt];
		opt--;
	}
	cout<<p;


}
