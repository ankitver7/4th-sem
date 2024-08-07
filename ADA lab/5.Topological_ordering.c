#include<stdio.h>
int n, a[10][10], p[10][10];
void path()
{
    int i, j, k;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    p[i][j]=a[i][j];
    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(p[i][k]==1&&p[k][j]==1)p[i][j]=1;
}
void main()
{
    int i,j;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d", &a[i][j]);
    path();
    printf("\nThe path matrix is shown below\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d",p[i][j]);
        printf("\n");
    }
}

or

#include<stdio.h>
int toposort(int a[10][10],int n,int indeg[10]);
int main()
{
	int a[10][10],indeg[10]={0},i,j,n;
	printf("Enter the no of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				indeg[j]++;
		}
	}
	printf("The topological sorted array is:\n");
	toposort(a,n,indeg);
	return 0;
}
int toposort(int a[10][10],int n,int indeg[10])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
			printf("%d\t",i);
			indeg[i]--;
			for(j=1;j<=n;j++)
				if(a[i][j]==1)
					indeg[j]--;
			i=1;
		}
	}
	printf("\n");
}
