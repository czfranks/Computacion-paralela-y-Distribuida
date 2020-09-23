#include <bits/stdc++.h>
using namespace std;

unsigned t0, t1;

const int n=256;

int a[n][n];
int b[n][n];
int c[n][n];

void trivial(){

  t0=clock();

  for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
          for (int k = 0; k < n; ++k)
              c[i][j] += a[i][k] * b[k][j];

  t1=clock();

  double cost = (double(t1-t0)/CLOCKS_PER_SEC);
  cout<<fixed;
  cout <<setprecision(5)<< cost << endl;
}

void bloques(int bsize){
  int i,j,k,kk,jj;
  double sum;
  int en = bsize*(n/bsize);

  t0=clock();

  for (kk=0; kk<en; kk+=bsize){
    for (jj=0; jj<en; jj+=bsize){
      for (i=0; i<n; ++i){
        for (j=jj; j<jj+bsize; ++j){
          sum=c[i][j];
          for (k=kk; k<kk+bsize; ++k){
            sum+=a[i][k]*b[k][j];
          }
          c[i][j] = sum;
        }
      }
    }
  }
  t1=clock();
  double cost = (double(t1-t0)/CLOCKS_PER_SEC);
  cout<<fixed;
  cout <<setprecision(5)<< cost << endl;
}

int main(void)
{
  memset(a, 1, sizeof a);
  memset(b, 1, sizeof b);
  memset(c, 1, sizeof c);


  //trivial();

  bloques(16);



  return 0;
}
