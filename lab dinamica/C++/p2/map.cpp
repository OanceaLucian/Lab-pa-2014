#include <fstream>
#include <iostream>
#include <vector>


int road ( std::vector <std::vector<int> > & v,int n,int m )
{

 std::vector< std::vector<int> > sum(n,std::vector<int>(m,0));
 std::vector<std::vector<int> > road(n,std::vector<int>(m,0));
 sum[0][0]=v[0][0];
 road[0][0]=0;
 for(int i=1;i<m;i++)
 { if(v[0][i]!=-1)
 {

   sum[0][i] = sum[0][i-1]+v[0][i];
   road[0][i] = 1;
 }
  }
 for(int i=1;i<n;i++)
 { if(v[i][0!=-1])
   {sum[i][0]=sum[i-1][0]+v[i][0];
   road[i][0]= -1;}
 }

 for(int i=1;i<n;i++)
  for(int j=1;j<m;j++)
  { if(v[i][j]!=-1)
      { int maxim =std::max(sum[i-1][j],sum[i][j-1]);
         sum[i][j]=maxim + v[i][j];
         if(maxim == sum[i-1][j])
            road[i][j]=-1;
            else road[i][j]=1;

      }

  }
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
     std::cout<<road[i][j]<<" ";
     std::cout<<std::endl;
}
return sum[n-1][m-1];
}


int main(void)
{

int table[2][2] = {{2,-1},{1,2}};

   std::vector< std::vector<int> > t(2,std::vector<int>(2,0));
   for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            t[i][j]=table[i][j];

   std::cout<<road(t,2,2);
}
