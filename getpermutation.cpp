#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> GetPermutationRecurs(string sInput, int low, int high)
{
    vector<string> result;
    if(low == high)    
    {
        result.push_back(sInput);
        return result;    
    }

    vector<string> preResult = GetPermutationRecurs(sInput, low+1, high);
    for(size_t i = 0; i < preResult.size(); ++i)
    {
        string base(preResult[i]); 
        for(int j = low; j <= high; ++j)
        {
            string permutation(base);
            char tmp = permutation[low];
            permutation[low] = permutation[j];
            permutation[j] = tmp;
            result.push_back(permutation);
        }
    }
    
    return result; 
}



vector<string> GetPermutaion(string sInput)
{
    return GetPermutationRecurs(sInput, 0, sInput.length() - 1);    
    
}

int main(void)
{
    string s("abcd");
    vector<string> output = GetPermutaion(s);
    for(size_t i = 0; i < output.size(); ++i)
    {
        cout << output[i] << endl;    
    }

    return 0;
    
    
    
}


