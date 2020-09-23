#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

double A[MAX][MAX], x[MAX], y[MAX];
int i,j;

unsigned t0, t1;

void first()
{
	memset(y, 0, sizeof y);

	t0=clock();
	for(i=0; i<MAX; i++)
 		for(j=0; j<MAX; j++)
 			y[i] += A[i][j]*x[j];
 	t1=clock();

 	double cost = (double(t1-t0)/CLOCKS_PER_SEC);
 	cout << cost << endl;
}

void second()
{
	memset(y, 0, sizeof y);

	t0=clock();
	for(j=0; j<MAX; j++)
		for(i=0; i<MAX; i++)
 			y[i] += A[i][j]*x[j];
 	t1=clock();

 	double cost = (double(t1-t0)/CLOCKS_PER_SEC);
 	cout << cost << endl;
}

int main(void)
{
 	memset(A, 1, sizeof A);
	memset(x, 1, sizeof x);

	first();
	second();
 	


  return 0;
}

