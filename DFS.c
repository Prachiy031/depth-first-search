#include<stdio.h>
#define n 3
void DFS(int v);
int pop();
int e,f;
int visited[n];
int stack[10];
int top = -1;
int a[n][n];
void main()
{
    int v;   //v for vertex
    int e,f=0;    //f is flag
    printf("Enter matrix representation of graph: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;   //initialised
        printf("Enter vertices:\n");
        scanf("%d",&v);
        DFS(v);
    }
}
int pop()
{
    
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        top--;
    }
    return stack[top];
}
void DFS(int v)
{
    
    visited[v] = 1; //updating values
    printf("%d ",v);    //visited nodes
    stack[++top] = v;
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 && !visited[i])   //if edge is there and havent visited yet
        {
            DFS(i);
        }
    }
    while(top!=-1)
    {
        f = 0;
        e = stack[top];
        for(int i=0;i<n;i++)
        {
            if(a[e][i]==1 && !visited[i])
            {
                DFS(i);
                f =1;
            }
        }
        if(f==0)
        printf("%d ",pop());          //if all nodes are already visited
    }
}
