#include <iostream>
using namespace std;

int FindIndex(int* a, int low, int high, int value)
{
    cout << "low: " << low << "\t" << "high: " << high << endl;
    if(low > high)    
        return -1;


    int middle = (low+high)/2;

    if(value == a[middle])
        return middle;

    if(value > a[middle])
    {
        if(a[high] <= a[middle])    
            return FindIndex(a, middle+1, high, value);
        else
        {
            if(a[high] >= value)    
                return FindIndex(a, middle+1, high, value);
            else
                return FindIndex(a, low, middle-1, value);
        }
    }
    else
    {
        if(a[low] >= a[middle])     
            return FindIndex(a, low, middle - 1, value);
        else
        {
            if(a[low] <= value)    
                return FindIndex(a, low, middle - 1, value);
            else
                return FindIndex(a, middle + 1, high, value);
        }
    }
}

int main(void) 
{
    int a[12] = {15,16,19,20,25,1,3,4,5,7,10,14};
    int index = FindIndex(a, 0, 11, 10);
    cout << index << endl;
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    

