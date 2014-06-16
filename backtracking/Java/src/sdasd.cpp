int sauron(std::vector<int>& master_kills, std::vector<int>& slave_kills,int number_of_pairs)
{   std::ofstream out ("partial.out");
    int suma=0;
     std::vector<int> binary_counter(number_of_pairs,-1);
    binary_counter[0]=0;
    binary_counter[1]=1;

    int all_counter=2,sum_master_master=0,sum_slave_master=0,loss=0,counter=0;

    for(int i = 2; i < number_of_pairs -1;i+=2)
    {
        int max;
        if(master_kills[i] < slave_kills[i])
        {
            max=INT_MIN;
         for(int j=0;j<all_counter;j++)
         if(binary_counter[j]==1)
         {
             loss=master_kills[j]-slave_kills[j];
             if(loss>max)
             {
                 max=loss;
                 counter=j;
             }

         }
        if(master_kills[i]-slave_kills[i] < max)
        {   binary_counter[counter]=0;
            binary_counter[all_counter]=1;
            binary_counter[all_counter+1]=1;
            all_counter+=2;
        }
        else
        {
        binary_counter[all_counter]=0;
        binary_counter[all_counter+1]=1;
        all_counter+=2;

        }

        }
    else
    {
    binary_counter[all_counter]=0;
    binary_counter[all_counter+1]=1;
    all_counter+=2;

    }

    }
    std::vector<int> a,b;
    suma=0;
    for(int i=0;i<number_of_pairs;i++)
    if(binary_counter[i]==1) {
        a.push_back(i);
        suma+=master_kills[i];
        }
     else
     {
         b.push_back(i);
         suma+=slave_kills[i];
         }
    out<<"123"<<std::endl;
    for(int i=0;i<a.size();i++)
    out<<a[i]+1<<" "<<b[i]+1<<std::endl;


    return suma;
}