#include<bits/stdc++.h>
using namespace std;
int inf=1000000;
int dist[101][101];
void floydwarshall()
{
    for(int k=1;k<=100;k++)
    {
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(dist[i][k]!=inf&&dist[k][j]!=inf)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}
int main()
{
    int t;
    int a,b,cnt=1;
    while(1)
    {
        cin>>a>>b;
        if(a==0&&b==0)break;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(i==j)dist[i][j]=0;
                else dist[i][j]=inf;
            }
        }
        dist[a][b]=1;
        int c,d;
        while(1)
        {
            cin>>c>>d;
            if(c==0&&d==0)break;
            dist[c][d]=1;

        }
        floydwarshall();
        int r=0,sum=0;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                if(dist[i][j]!=0&&dist[i][j]!=inf)
                {
                    sum+=dist[i][j];
                    r++;
                }
            }
        }
        printf("Case %d: average length between pages = ",cnt);
        cout<<fixed<<setprecision(3)<<sum/(float)r<<" clicks"<<endl;
        cnt++;

    }
}
