#include<stdio.h>
#include<string.h>
const int N=100000;
int pr[N+10],p[N];
int pi[N+5][30],ki[N+5][30];//这里数组大小开成log2(N)左右即可
int cnt,lp;
int ans;
int n,m;
void gp()
{
	for(int i=2;i<=N;i++)
	{
		if(!pr[i])
			p[++lp]=pr[i]=i;
		for(int j=1;j<=lp && i*p[j]<=N;j++)
		{
			pr[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	return;
}
void fenjie(int n,int* pi,int* ki)
{
	cnt=0;
	memset(ki,0,sizeof(ki));
    while(n!=1)
	{
        int t=pr[n];
        pi[++cnt]=t;
        ki[cnt]=0;
        while(n%t==0)
        {
            n/=t;
            ki[cnt]++;
        }
    }
    pi[0]=cnt;
    return;
}
void dfs(int flag,int x,int num,int d)
{
    if(flag&1)
        ans+=m/num;
    else
        ans-=m/num;
    for(int i=x+1;i<=pi[d][0];i++)
        dfs(flag+1,i,num*pi[d][i],d);
    return;
}
int rongchi(int n)
{
    ans=0;
    for(int i=1;i<=pi[n][0];i++)
        dfs(1,i,pi[n][i],n);
    ans=m-ans;
    return ans;
}

long long int solve()
{
    int i;
    long long int result=0;
    for(i=1;i<=n;i++)
    {
        result+=(long long int)rongchi(i);
    }

    return result;
}

int main()
{
    int i;
    int t;
    gp();
    for(i=2;i<=N;i++)
        fenjie(i,pi[i],ki[i]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(n==1 || m==1)
        {
            int ans=(n==1?m:n);
            printf("%d\n",ans);
            continue;
        }
        long long int result=solve();
        printf("%lld\n",result);

    }

    return 0;
}

