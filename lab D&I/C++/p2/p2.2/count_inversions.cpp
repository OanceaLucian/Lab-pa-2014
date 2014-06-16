#include <iostream>
#include <fstream>
#include "vector_io.h"


int merge( std::vector<int> a, int *b, int low, int mid, int high)
{
    int i,j,k;
    int inv_count=0;
    i=low;
    j=mid;
    k=low;

    while((i <= mid -1) && (j<=high)){

    if(a[i] <= a[j]){
     b[k++] = a[i++];
    }
   else {

   b[k++] = a[j++];

   inv_count += mid -low+1 -i;

   }
    }

 while(i<=mid -1)
    b[k++] = a[i++];
  while(j<=high)
     b[k++] =a[j++];
   for(i=low;i<=high;i++)
    a[i]=b[i];
return inv_count;
}




int mergesort( std::vector<int> a, int*b, int low, int high)
{
    int inv_count =0;
    if(high > low)
    { int mid = low + (high-low)/2;
      inv_count += mergesort(a,b,low,mid);
      inv_count += mergesort(a,b,mid+1,high);
      inv_count += merge(a,b,low,mid,high);

    }
return inv_count;
}





int count_inversions(std::vector<int> v)
{
    //TODO Intoarceti numarul de inversiuni din vectorul v

  int temp[v.size()];
  return mergesort(v, temp, 0, v.size() -1);


}





int main(void) {
    std::ifstream f("date.in");
    std::vector<int> v1, v2;
    f >> v1 >> v2;
    f.close();
    std::cout << "In " << v1 << std::endl
              << "sunt " << count_inversions(v1)
              << " inversiuni." << std::endl;

    std::cout << "In " << v2<< std::endl
              << "sunt " << count_inversions(v2)
              << " inversiuni." << std::endl;
    return 0;
}
