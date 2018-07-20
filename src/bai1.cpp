#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
fstream finput;
finput.open("BRACKET.INP", ios::in );
ofstream foutput;
foutput.open("BRACKET.OUT", ios::out|ios::trunc);
char str[200];
finput.getline(str,200);
finput.close();
stack<int>ngoac;

for (int i=0;i<sizeof(str);i++)
{
if (str[i]=='(')
ngoac.push(i);
if (str[i]==')')
	{
		if (!ngoac.empty()&&(str[ngoac.top()]!=')'))
		ngoac.pop();
		else
		ngoac.push(i);
	}
}

if (ngoac.empty())
printf("0");
else
{
	printf("%i \n", ngoac.size());
	foutput << ngoac.size() + " \n";
	while (!ngoac.empty())
	{
	if (str[ngoac.top()]=='(') {
	printf(") %i \n", (ngoac.top()+1));
	foutput << ")" + (ngoac.top()+1);
	ngoac.pop();
	}
	else {
	printf("( %i \n" , ngoac.top());
	foutput << "(" + (ngoac.top());
	ngoac.pop();
	}
}
}
getch();
}
