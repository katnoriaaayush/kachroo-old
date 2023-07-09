#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int D,E,F,Sp;
}data;

int D,E,F,d,e;
data m[9];
int num;
int answer;

void solve(int index, int count, int D, int E, int F, int cost)
{
    if(count == 3 || index>=num)
    {
        cost+=D*d+E*e;
        if(cost>answer)
        {
            cout << "LOG: "<<cost<<endl;
            answer=cost;
            
        }
        return;
    }

    solve(index+1,count, D, E ,F ,cost);

    int i=1;

    while(true)
    {
        if(D-m[index].D*i>=0 && E-m[index].E*i>=0 && F-m[index].F*i>=0)
        {
            solve(index+1, count+1,D-m[index].D*i,E-m[index].E*i, F-m[index].F*i, cost+m[index].Sp*i);
            ++i;
        }
        else
        {
            break;
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> D >> E >> F >> d >> e;

        
        cin >> num;  

        for(int i=0;i<num;i++)
        {
            cin >> m[i].D >> m[i].E >> m[i].F >> m[i].Sp;
        }   
    }
    
    solve(0,0,D,E,F,0);

    cout << "Answer: " << answer<<endl;
    
}