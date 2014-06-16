    #include<fstream>
    #include<iostream>

    #include <vector>

    #include "vector_io.h"
    using namespace std;


    int x1=0,y1=0;
    int max_sub_sum(std::vector<int> a,int lower,int upper){
      int x,y;
     int maxSum;
     int mid= lower+(upper-lower)/2;
     if(lower == upper) if(a[lower]>0) return a[lower];
                           else return 0;

      int max_left_sum=max_sub_sum(a,lower,mid);
      int max_right_sum=max_sub_sum(a,mid+1,upper);
      int left=0;
      int right=0;
      int max_right=-42000;
      int max_left=-42000;

      //stanga
       for(int i=mid;i>=lower;i--) {
          left +=a[i];
           if(max_left<left) {max_left=left;x=i;}
       }
     //dreapta
        for(int i=mid+1;i<=upper;i++){
         right+=a[i];
        if(max_right<right) {max_right=right;y=i;}
         }
       if( ((max_right+max_left) > max_right_sum) && ((max_right+max_left)  > max_left_sum)){
       x1=x;
       y1=y;
       }

      return max(max_left_sum,max(max_right_sum,max_right+max_left));
    }

    int main(void)
    {
       std::ifstream f("date.in");
        std::vector<int> v1;
        f>>v1;
        std::cout << "v1: " << v1 << std::endl;
        int maxsum=max_sub_sum(v1,0,v1.size()-1);
       cout<<"Suma maxima este : " <<maxsum<<" iar subsecventa este: ";
       for(int i=x1;i<=y1;i++ )  cout<<v1[i]<<" ";

     f.close();
    }
