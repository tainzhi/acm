#include <stdio.h>
#include <stdlib.h>
double mx(double a,double b){
    if(a>b)
        return a;
    else
        return b;
}
 
 
int main()
{
    double P,T,G1,G2,G3,GJ;
    double ans;
    while(scanf("%lf %lf %lf %lf %lf %lf",&P,&T,&G1,&G2,&G3,&GJ) != EOF){
        if(abs(G1-G2) <= T)
            ans = (G1+G2)/2.0;
        else{
            if(abs(G1-G3)<= T && abs(G2-G3) <= T)
                ans = mx(G1,G2);
            else if(abs(G1-G3)<=T )
                ans = (G1+G3)/2.0;
            else if(abs(G2-G3)<=T)
                ans = (G2+G3)/2.0;
            else
                ans = GJ;
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}
