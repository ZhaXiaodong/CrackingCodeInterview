#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int>& vec, int low, int high)
{
    if(low == high)
        return;

    int middle = (low+high)/2;
    merge_sort(vec, low, middle);
    merge_sort(vec, middle+1, high);

    vector<int> tem;

    int lowCount = low;
    int highCount = middle + 1;

    while(lowCount <= middle && highCount <= high)
    {
        if(vec[lowCount] < vec[highCount])
        {
            tem.push_back(vec[lowCount]);    
            ++lowCount;
        }
        else
        {
            tem.push_back(vec[highCount]);
            ++highCount;
        }        
    }

    if(lowCount <= middle)
    {
//        tem.push_back(vec[lowCount++]);
        tem.insert(tem.end(), vec.begin()+lowCount, vec.begin()+middle+1);
    }

    if(highCount <= high)
    {
//        tem.push_back(vec[highCount++]);
        tem.insert(tem.end(), vec.begin()+highCount, vec.begin()+high+1);    
    }

    for(int i=low, index = 0; i <= high; ++i, ++index)
    {
        vec[i] = tem[index];
    }
}

int main(void)
{
    vector<int>     vec;
    for(int i=11; i > 0; --i)
    {
        vec.push_back(i);    
    }

    for(int i=0; i < vec.size(); ++i)
    {
        cout << vec[i] << "\t";    
    }
    cout << endl;
    merge_sort(vec, 0, vec.size() - 1);
    
    for(int i=0; i < vec.size(); ++i)
    {
        cout << vec[i] << "\t";    
    }
    cout << endl;

    
    
}
