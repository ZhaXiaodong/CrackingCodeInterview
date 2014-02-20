#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;    
};

vector<vector<Point> > GetAllLayoutRecurs(int indexX, vector<int> vecY, int N)
{
    vector<vector<Point> >  result;
    if(indexX == N)
    {
        vector<Point> vec;
        result.push_back(vec);
        return result;
    }

    Point point;
    point.x = indexX;

    for(int j=0; j < N; ++j)
    {
        if(vecY[j] == 0)    
        {
            vecY[j] = 1;    
            point.y = j;
            vector<vector<Point> > nextResult = GetAllLayoutRecurs(indexX + 1, vecY, N);

            for(int i = 0; i < nextResult.size(); ++i)
            {
                nextResult[i].push_back(point);
            }

            result.insert(result.end(), nextResult.begin(), nextResult.end());
            vecY[j] = 0;    
        }
    }

    return result;    
}


vector<vector<Point> > GetAllLayout(int N)
{
    vector<int> vecY(N, 0);
    return GetAllLayoutRecurs(0, vecY, N);    
}

int main(void)
{
    vector<vector<Point> > result = GetAllLayout(5);
    for(int i = 0; i < result.size(); ++i)
    {
        cout << "-----------Way: " << i << "-------------------------" << endl;    
        vector<Point>& vec = result[i];
        for(int j = 0; j < vec.size(); ++j)
        {
            cout << "(" << vec[j].x << ", " << vec[j].y << ")" << "\t"    ;
        }
        cout << endl;
    }

    return 0;



}


