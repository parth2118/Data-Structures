#include <stdio.h>
#include <stdlib.h>
int adj_matrix[20][20];
int visited_node[20];
int no_vertices = 0;
void dfs(int i)
{
    int j;
    printf("\n%d",i);
    visited_node[i]=1;
    for(j = 0; j < no_vertices; j++)
       if(!visited_node[j]&&adj_matrix[i][j]==1)
            dfs(j);
}

int main()
{
    int i,j;
    printf("Enter no. of Vertices < 20\n");
    scanf(" %d",&no_vertices);
    for(i = 0; i < no_vertices; i++)
        visited_node[i] = 0;
    printf("Enter Graph data : \n");
    for(i = 0; i < no_vertices; i++)
    {
      printf("Enter Data for connections of Node %d : ",i);
        for(j = 0; j < no_vertices; j++)
        {
            scanf(" %d",&adj_matrix[i][j]);
        }
    }
    printf("DFS is : \n");
    dfs(0);
    printf("\n");

}
