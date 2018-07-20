#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <sstream>
#define MAX 255
using namespace std;

int TimKiem(string &output, int ln, char s[MAX], char s1[MAX]) 
{
	int len = strlen(s); 
    int len1 = strlen(s1); 
    char *p=strstr(s,s1);
    int i; 
    int dem =0;
    ostringstream stm;
    while (p) 
    { 		i = p - s + 1;
           p++;
			p=strstr(p,s1);
           cout << "Line " << ln << " Col " << i << endl;
           stm << "Line " << ln << " Col " << i<< "\n";
           dem ++;
    }
    output= output + stm.str()+ "\n";
    return dem;
}

void Xoa(char s[MAX], int n, int i) 
{ 
    char p[MAX];

    strncpy(p, s, i - 1); 
    int len = strlen(s); 
    strcpy(p + i - 1, s + (i - 1) + n); 
    p[len - n] = '\0'; 
    strcpy(s,p); 
} 

void Them(char s[MAX], int i, char ch[MAX]) 
{ 
    int len = strlen(s); 
    int lench = strlen(ch); 
    for (int j = len; j >= i - 1; j--) 
        s[j + lench] = s[j]; 
    for (int j = 0; j < lench; j++) 
        s[i - 1 + j] = ch[j]; 
} 

void ThayThe(char s[MAX], char s1[MAX], char s2[MAX]) 
{ 
    int len = strlen(s); 
    int len1 = strlen(s1); 
    int len2 = strlen(s2); 
    char *p;
	int i; 
    while ((p = strstr(s,s1)) != NULL) 
    { 
           i = p - s + 1; 
           Xoa(s,len1,i); 
           Them(s,i,s2); 
    } 
} 

int main()  {
	char link[MAX];
	
	char s [MAX], s1 [MAX], s2 [MAX], line[MAX];
	int t;
	int ln=1 , d=0;
	printf("> Nhap duong dan file: bai2_input.txt ");
	gets(link); fflush(stdin);
	fstream file;
    file.open(link, ios::in );
    ofstream fileout;
    fileout.open("bai2_output.txt", ios::out | ios::trunc) ;
   	string text;
   	string output;
   	ostringstream stm;
   	int i;
    if (access(link, 0) != -1)
    {
        printf("> File ton tai, moi ban dua ra lua chon: \n");
        printf("------------------------------ \n");
        printf("\t 1. Tim kiem \n");
        printf("\t 2. Sua \n");
        printf("\t 3. Exit \n");
        printf("------------------------------ \n");
		printf("> ");
		cin >> t;
		fflush(stdin);
		switch(t) {
   	case 1 :
   		printf("Moi nhap tu khoa: ");
	  	gets(s1); 
	  	fileout << "Tim kiem tu khoa " << s1 << "\n";
	  	while(!file.eof()) 
		{
		file.getline(s,255);
	  	d= d+ TimKiem(output, ln, s, s1);
	  	ln++;
	  	}
	  	
	  	cout << "so lan xuat hien " << d << endl;
	  	stm << "so lan xuat hien " << d << endl;
	  	fileout << stm.str() +"\n";
		  fileout << output;
	  	
	  	fileout.close();
	  	break;
	
   	case 2 :
   		cout << "Moi nhap tu khoa: ";
	  	gets(s1);
	  	cout << "Moi nhap tu khoa moi: ";
	  	gets(s2);
	  	stm << "Tu khoa ban dau "<< s1 << "\nTu khoa thay the " << s2 << endl;
	  	fflush(stdin);
	  	
	  	while(!file.eof()) 
		{
		file.getline(line,255);
		d= d+ TimKiem(output, ln, line, s1);
	  	ln++;
	  	}
	  	cout << "so vi tri thay the " << d << endl;
	  	stm << "so vi tri thay the " << d << endl;
	  	fileout << stm.str()<< endl ;
		fileout << output;
		fileout.close();
		file.close();
		file.open(link, ios::in);
	  	while(file.getline(s,255)) {
		ThayThe( s, s1 , s2 );
	  	text= text+s+"\n";
	  	}
	  	cout << text;
	  	file.close();
		file.open(link, ios::out | ios::trunc);
		file << text ;
		file.close();
		
      	break;
	case 3 :
      exit(0);
      break;	    
    default :
      cout << "Gia tri khong hop le" << endl;
      break;
   	}
	}
    	
    else
    {
        printf("\nFile \"%s\" doesn't exist \n", link);
        printf("> Nhap lai duong dan file: ");
    }
   
    return 0;
}
