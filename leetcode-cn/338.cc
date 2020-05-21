class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> ret(num + 1);
        for (int i = 0; i <= num; i++) {
            ret[i] = popCount(i);
        }
        return ret;
    }

    // 计算有多少个1
    int popCount(int x) {
        int count = 0;
        for (; x!=0; count++) {
            x &= (x-1);
        }
        return count;
    }

    // dp[x + b] = dp[x] + 1, b<= x <= 2b
    // (101)3由 (100)2 + (01)1可得
    // (111)4由 (100)2 + (11)1可得, (100)必定有1个1, 而(01)和(11)已经计算过了
    vector<int> countBits2(int num) {
        vector<int> dp(num + 1);
        int b = 1, i = 0;
        dp[0] = 0;
        while (b <= num) {
            while ((b+i) <= 2 * b && (b+i) <= num) {
                dp[b+i] = dp[i] + 1;
                i++;
            }
            i = 0;
            b <<= 1;
        }
        return dp;
    }

    //低位关键字    
    // (10111)可由(1011)加上一个1可得, 而1011由10111右移可得
    vector<int> countBits3(int num) {
        vector<int> ret(num + 1);

        ret[0] = 0;
        for (int i =1 ; i <= num ; i++) {
            ret[i] = ret[i>>1] + i & 1;
        }
        return ret;
    }

    //最后设置位是从右到左第一个为1的位。使用 x &= x - 1 将该位设置为0，就可以得到以下状态转移函数：
    // P(x) = P(x \mathrel{\&} (x - 1)) + 1;
    // P(x)=P(x&(x−1))+1;
    vector<int> countBits(int num) {
        vector<int> ret(num + 1);
        ret[0] = 0;
        for (int i = 1; i <= num; ++i) {
            ret[i] = ret[i & (i-1)] + 1;
        }
        return ret;
    }
};