#include <iostream>
#include <fstream>
#include <vector>

#include "vector_io.h"



int partition ( std::vector<int> &v,int lower,int upper){
    int i=lower,j=upper;
    int tmp;
    int pivot=v[lower+(upper-lower)/2];
    while(i<=j) {
    while(v[i] < pivot )
              i++;
     while(v[j] > pivot)
             j--;

      if(i<=j){
        tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
        i++;
        j--;

      }
    }
    return i;
}
void qsort(std::vector<int> &v, int lower, int upper)
{
    int index = partition( v, lower, upper );
    if( lower < index -1 )
       qsort( v, lower, index -1);
    if( index < upper )
       qsort( v, index, upper );

    //TODO Completati codul pentru a realiza quicksort

}

int find_kth_min(std::vector<int> &v, int lower, int upper, int k)
{
    // TODO Completati codul pentru a afla al k-lea minim din vectorul v

    int index = partition( v , lower , upper ) -1;

    if( index > k ) return find_kth_min ( v , lower , index , k);
        else  if( index  < k ) return find_kth_min( v , index+1 , upper , k );
            else if( index  == k ) return v[index];
  return 0;
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> v1, v2;
    f >> v1;
    f >> v2;
    std::cout << "v1: " << v1 << std::endl;
    for (unsigned int i = 0; i < v1.size(); i++) {
        std::cout << "Al " << i << "-lea minim din v1 este: ";
        std::cout << find_kth_min(v1, 0, v1.size() - 1, i) << std::endl;
    }
    qsort(v1, 0, v1.size() - 1);
    qsort(v2, 0, v2.size() - 1);
    std::cout << "Vectorii sortati:\n";
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    f.close();
}
