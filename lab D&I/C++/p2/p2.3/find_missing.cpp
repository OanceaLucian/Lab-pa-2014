#include <iostream>
#include <fstream>
#include <vector>

#include "vector_io.h"






		/*TODO Cautati binar elementul lipsa din vector
		 * va trebui sa adaugati si o functie de partitionare, ca la quick sort
		 */

void swap ( std::vector<int> v,int a, int b)
	{
	int x;
	x = v[a];
	v[a] = v[b];
	v[b] = x;
	}

	int partition(std::vector<int> v, int l, int h)
	{
		int i, p=h, first=l;
		for(i=l;i<h;i++)
			if(v[i]<v[p]) {
				swap(v,i,first);
				first++;
			}
		swap(v,p,first);
		return first;
	}


int find(std::vector<int> v,int lower,int upper){



   int index = partition(v,lower,upper) -1;
   int m=lower+(upper-lower)/2;

while (lower<upper) {

			if(v[index]!=index) { upper=index-1; index=partition(v,lower,upper); }
			else { lower=upper+1; index=partition(v,lower,upper); }

		}

		if(lower==upper) return v[index]-1;
		else return v[index]+1;

     return 0;


}
int find_missing(std::vector<int> v)
{
    find(v,0,v.size()-1);


    return 0;
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> v1, v2;
    f >> v1;
    f >> v2;
    std::cout << find_missing(v1) << std::endl;
    std::cout << find_missing(v2) << std::endl;
    f.close();
}
