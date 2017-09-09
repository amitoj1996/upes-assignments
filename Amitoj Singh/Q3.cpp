#include<iostream>
using namespace std;
//this function reversed the array L from the index i to N
void reverse(int i,int N,int L[])
{
	int temp,j;
	for(i,j = N-1;i<(N+i)/2;i++,j--)
	{
		temp=L[i];
		L[i]=L[j];
		L[j]=temp;
	}
}
//the ancient algorithm
int TAA(char S[],int L[], int A, int B, int C,int N)
{
	for(int i=0;i<N;i++)
	{
		if(S[i]=='R')
		{
			reverse(i,N,L);
		}
		if(S[i]=='A')
		{
			for(i;i<N;i++)
			{
				L[i]=L[i]+A;
			}
		}
		if(S[i]=='M')
		{
			for(i;i<N;i++)
			{
				L[i]=L[i]%C;
			}
		}
		
	}
}

int main()
{
	int N,A,B,C,T,E[3];
	cout<<"enter the number of test cases";
	cin>>T;
	for(int j=0;j<T;j++)
	{
	
		cout<<"Enter the number of integers in list L: ";
		cin>>N;
		char S[N];
		int L[N];
		
		cout<<"enter the list of integers L: ";
		for(int i=0;i<N;i++)
		{
			cin>>L[i];
		}
		cout<<endl;
		cout<<"enter the values of A,B,C"<<endl;
		for(int i=0;i<3;i++)
		{
			cin>>E[i];
		}
		A=E[0];
		B=E[1];
		C=E[2];
		cout<<"enter the list of characters S: ";
		for(int i=0;i<N;i++)
		{
		a:	cin>>S[i];
			if(!(S[i]=='R' || S[i]=='A' || S[i]=='M'))
			{
				cout<<"Please enter a R,A or M only"<<endl;
				goto a;
				
			}	
		}
		cout<<endl;
		
		
		//The ancient algorithm 
		TAA(S,L,A,B,C,N);
		//output the result
		for(int i=0;i<N;i++)
		{
			cout<<L[i];
		}
		cout<<endl;
	}
		return 0;
}
