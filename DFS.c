#include<stdio.h>
#include<stdlib.h>
#define N 20
#define BIG 1000

int vis[N]={0}, pre[N], num=0, comp[N], time=0, st[N], fn[N];

typedef struct NODE
{
	int v;
	struct NODE* next;
}node;

void printTime(int n)
{
	int i;
	printf("\nVertex\tStart\tFinish");
	for(i=1;i<=n;i++)
		printf("\n%d\t%d\t%d",i,st[i],fn[i]);
}

void DFS(node *L[], int n,int u)
{
	int i,v;
	vis[u]=1;
	st[u]=time++;
	
	node *p=L[u];
	while(p!=NULL)
	{
		v=p->v;
		if(vis[v]==0)
			DFS(L,n,v);
		p=p->next;
	}
	fn[u]=time++;
}

int main()
{
	int u,v,i,j,k,w,n,e;
	
	printf("Enter the no. of vertex:");
	scanf("%d",&n);
	printf("\nEnter the no. of edges:");
	scanf("%d",&e);
	node *List[N]={NULL};
	for(i=1;i<n+1;i++)
		pre[i]=-1;
	
	for(k=0;k<e;k++)
	{
		node *t = (node *)malloc(sizeof(node));
		printf("\nEnter an edge(in form i j):");
		scanf("%d %d",&i,&j);
		t->v=j;
		t->next = List[i];
		List[i] = t;
		
		/*
		**for undirected graph
		*/
		t = (node *)malloc(sizeof(node));
		t->v=i;
		t->next=List[j];
		List[j]=t;
	}
	
	printf("\nInput Graph:\n");
	for(i=1;i<n+1;i++)
	{
		comp[i]=0;
		printf("\n\n%d",i);
		node *p=List[i];
		while(p!=NULL)
		{
			printf("->%d",p->v);
			p=p->next;
		}
	}
	
	printf("\n\nDFS:");
	for(i=1;i<n+1;i++)
	{
		if(vis[i]==0)
		{
			num++;
			DFS(List,n,i);
		}	
		
	}
	printTime(n);
	printf("\n\nComponets: ");
	for(i=1;i<n+1;i++)
		printf("%d ",comp[i]);
	
	
	return 0;
}
