#include <iostream>
using namespace std;

void merge(int* a, int aSize, int* b, int bSize)
{
    int end = aSize + bSize;
    int aIndex = aSize - 1;
    int bIndex = bSize - 1;
    
    for(int index = end - 1; index >= 0 && aIndex >=0 && bIndex >=0; --index)
    {
        if(a[aIndex] > b[bIndex])    
        {
            a[index] = a[aIndex--];
        }
        else
        {
            a[index] = b[bIndex--];
        }
    }

    for(int i=0; i <= bIndex; ++i)
    {
        a[i] = b[i];
    }

}

int main(void)
{
    int* a = new int[10];
    a[0] = 1;
    a[1] = 3;
    a[2] = 5;
    a[3] = 7;
    a[4] = 9;

    int * b = new int[2];
    b[0] = -2;
    b[1] = -1;
    
    merge(a, 5, b, 2); 

    for(int i=0; i <7; ++i)
    {
        cout << a[i] << '\t';
    }
    cout << endl;

    return 0;
}

