#include <stdio.h>
#include <string.h>

int lex(char str[], int x, int y)
{
	int i, flag=1, mid=((y-x)/2);
	for (i=x; i<mid; i++)
		if (str[i]>str[i+1])
			flag=0;
	return flag;
}

void pal(char str[])
{
	int i, j, k, n=strlen(str);
	int table[n][n];
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			table[i][j]=0;

	int start=0, maxlength=1;

	for (i=0; i<n; i++)
		table[i][i]=1;

	for (i=0; i<n-1; i++)
	{
		if (str[i]==str[i+1])
		{
			table[i][i+1]=table[i+1][i]=1;
			if (str[start]>str[i])
				start=i;
			maxlength=2;
		}

	}

	for (k=3; k<=n; k++)
	{
		for (i=0; i<n-k+1; i++)
		{
			int j=i+k-1;
			if (lex(str, i, j)&&(table[i+1][j-1]!=0)&&str[i]==str[j])
			{
				
				table[i][j]=table[j][i]=k;
				if (k>=maxlength)
				{
					if (k==maxlength)
					{
						int x;
						for (x=0; x<maxlength;x++)
							if (str[start+x]>str[i+x])
							{
								start=i;
								break;
							}
					}
					else
						start=i;
					maxlength=k;
				}
			}
		}
	}
	printf("\n");
	
	if (maxlength>1)
		for (i=start; i<start+maxlength; i++)
			printf("%c", str[i]);
	else
		printf("-1");
}

int main()
{
	char str[100];
	printf("\nEnter string:\n");
	scanf("%s", str);
	pal(str);
	return 0;
}