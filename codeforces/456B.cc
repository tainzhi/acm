#include <stdio.h>
#include <string.h>
#define MIN(a, b) (a < b? a : b)
const int SLEN = 100010;

int main()
{
	char num[SLEN];
	while (scanf("%s", num) != EOF)
	{
		int len = strlen(num);
		int value = 0;
        for (int i=MIN(2, len); i >=1; i--)
            value = value * 10 + num[len - i] - '0';
        //printf("value = %d\n", value);
		printf("%d\n", value % 4 == 0 ? 4: 0);
	}
	return 0;
}
        
