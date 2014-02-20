#include <iostream>
#include <string>

using namespace std;

void PrintAllRecurs(int left, int right, string sBase)
{
    if(left < 0 || left > right) 
        return;

    if(left == 0 && right == 0)
        cout << sBase << endl;

    if(left)
    {
        sBase.append("(");
        PrintAllRecurs(left-1, right, sBase);
        sBase.erase(sBase.length() - 1);
    }

    if(left < right)
    {
        sBase.append(")");    
        PrintAllRecurs(left, right - 1, sBase);
    }
}


void PrintAll(int count)
{
    PrintAllRecurs(count, count, string());    
}

int main(void)
{
    cout << "------------One-----------------" << endl;
    PrintAll(1);
    
    
    cout << "------------Two-----------------" << endl;
    PrintAll(2);
    
    
    cout << "-----------Three----------------" << endl;
    PrintAll(3);

    cout << "-----------Four----------------" << endl;
    PrintAll(4);
    cout << "-----------Ten----------------" << endl;
    PrintAll(10);
    return 0;
}


