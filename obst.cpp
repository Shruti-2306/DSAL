#include<iostream>
using namespace std;
#define MAX 10

int find(int i, int j);
void print(int ,int);

int w[10][10], c[10][10], r[10][10], i, j, k , n, m;
float p[MAX], q[MAX];

char iden[MAX][10];

int main()
{
	cout<<"\nEnter number of identifiers: ";
	cin>>n;

	cout<<"\nEnter identifiers: ";
	for( i = 1; i <= n; i++)
	{
		cout<<"identifier number "<<i <<" :";
		cin>>iden[i];
	}
	cout<<"Enter probablity  of success: ";
	for(i = 1; i<= n ; i++)
	{
		cout<<"\n p["<< i << "] :";
		cin>>p[i];
	}
	cout<<"Enter probablity  of failure: ";
	for(i = 0; i<= n ; i++)
	{
		cout<<"\n q["<< i << "] :";
		cin>>q[i];
	}

	for( i = 0; i<= n; i++)
	{
		w[i][i] = q[i];
		c[i][i] = r[i][i] = 0;
		w[i][i+1] = q[i]+q[i+1] +p[i+1];
		r[i][i+1] = i+1;
		c[i][i+1] = q[i] +q[i+1] +p[i+1];

	}
	for( m= 2; m<=n; m++)
	{
		for(i = 0; i<= n-m; i++)
		{
			j = i+m;
			w[i][j] = w[i][j -1] + p[j] + q[j];
			k = find(i, j);
			r[i][j] = k;
			c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];

		}
	}

	cout<<"\n root of bost : "<<r[0][n]<<"\t that is\t"<<iden[r[0][n]];
	cout<<"\ncost of obst: "<<c[0][n];
	
	return 0;
}
int find(int i, int j)
{
	int min = 2000, m, l;
	for(m= i+1; m <= j; m++)
	{
		if(c[i][m-1] + c[m][j] < min)
		{
			min = c[i][m - 1] + c[m][j];
			l = m;
		}
		return 1;
	}
}

void print(int i, int j)
{
	if(i < j)
	{
		cout<<"\n"<<iden[r[i][j]];
	}
	else
	{
		return; print(i, r[i][j] -1);
		print(r[i][j], j);
	}
}