#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > getSubsets(vector<int> a){
    //base case
    //if there is just one item then its subsets are that item and empty item
    //for example all subsets of {1} are {1}, {}
    if(a.size() == 1){
        vector<vector<int> > temp;
        temp.push_back(a);

        vector<int> b;
        temp.push_back(b);

        return temp;
    }
    else
    {
        //here is what i am doing
        // getSubsets({1, 2, 3})
        //without = getSubsets({1, 2})
        //without = {1}, {2}, {}, {1, 2}
        //with = {1, 3}, {2, 3}, {3}, {1, 2, 3}
        //total = {{1}, {2}, {}, {1, 2}, {1, 3}, {2, 3}, {3}, {1, 2, 3}}
        //return total

        int last = a[a.size() - 1];
        a.pop_back();
        vector<vector<int> > without = getSubsets(a);
        vector<vector<int> > with;
        for(int i=0;i<without.size();i++){
            vector<int> base = without[i];
            for(int j=0; j < base.size(); ++j)
            {
                vector<int> permutation = base;
                permutation.insert(permutation.begin()+j, last);
                with.push_back(permutation); 
            }

            vector<int> permutation = base;
            permutation.push_back(last);
            with.push_back(permutation);
        }

        vector<vector<int> > total;
        for(int j=0;j<without.size();j++){
            total.push_back(without[j]);
        }
        for(int k=0;k<with.size();k++){
            total.push_back(with[k]);
        }
        return total;
    }
}


int main(void)
{
    vector<int>    vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vector<vector<int> > result = getSubsets(vec);
    for(int i=0; i < result.size(); ++i)
    {
        vector<int>& inVec = result[i];    
        for(int j=0; j < inVec.size(); ++j )
        {
            cout << inVec[j] << "\t";
        }
        cout << endl;
    }

   return 0; 
}

