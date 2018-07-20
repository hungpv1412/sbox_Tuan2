#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	int points;
	int lines;
	int start;
	int finish;
	int way[points];
	ifstream inp;
	inp.open("bai3_input.txt",ios::in);
	if (!inp) cout << "ko co file " << endl;
	else
	{
	inp >> points >> lines >> start >> finish;
	cout << points<<" " << lines<<" " << start<<" " << finish<<" "<< endl;
	int ln[lines][2];
	for (int j = 0; j<lines ; j++)
	{
		for ( int i =0; i<2; i++) 
		{
		
			inp >> ln[j][i];
			cout << ln[j][i] << " ";
		}
		cout << endl;
	}
	inp.close();
	way[0]= start;
	int i;
	for (i =0; i< points;i++)
	{ 
		for (int j = 0; j<lines ; j++)
		{
			if ((ln[j][0]==way[i])&&(way[i+1]!=ln[j][1])&&(way[i-1]!=ln[j][1]))
			{
			way[i+1]=ln[j][1];
			break;
			}
		}
	
	} 
	bool ketqua = false;
	ofstream fileout;
	fileout.open("bai3_output.txt", ios::out|ios::trunc);
	string text;
	for (int j =0; j<points; j++) 
	{
		text +=(char)(way[j]+'0');
		text +=" ";
		if(way[j]==finish) ketqua=true;
	}
	cout << text << endl;
	if(ketqua) 
	{	fileout << text;
		printf("\n da tim thay duong di" );
	}
	else cout <<"\n khong tim thay duong di " << endl;
	fileout.close();
	}
	return 0;
}
	
