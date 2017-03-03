#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10010

int numbers[MAX_SIZE];

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        if (k == 0) break;
        for (int i = 0; i < k; ++i)
            scanf("%d", &numbers[i]);
        int sum = 0, f = -1, e = -1;
        int m_sum = -1, m_f, m_e;
        for (int i = 0; i < k; ++i) {
            if (sum + numbers[i] >= 0) {
                if (f == -1) f = i;
                e = i;
                sum = sum + numbers[i];
                if (sum > m_sum) {
                    m_sum = sum;
                    m_f = f;
                    m_e = e;
                }
            } else {
                sum = 0;
                f = -1;
                e = -1;
            }
        }
        if (m_sum == -1) {
            m_sum = 0;
            m_f = 0;
            m_e = k - 1;
        }
        printf("%d %d %d\n", m_sum, numbers[m_f], numbers[m_e]);
    }
    return 0;
}
