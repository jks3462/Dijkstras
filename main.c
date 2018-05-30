//dijkstras
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
//in this example nodes = 8
//for nodes= n ... globally declared n
  int costt[10][10]; //cost [n+2][n+2]
  int edge[10][10];  // edge same
  int sss[10]; // n+2
  int dist[10]; //n+2
  int n=8;
  int k;
  int ti;
int shortestpaths(int v)
{
    int j,i,u=0,min=32767,w;
    for(i=1;i<=n;i++)
    {
        sss[i]=0;
        dist[i]=costt[v][i];
    }
    sss[v]=1;
    dist[v]=0;
    for(i=2;i<=n;i++)
    {
        min=32768;
        for(k=1;k<=n;k++)
        {
          if(sss[k] ==0)
        {
           if(min>dist[k])
           {
               min=dist[k];
               u=k;
           }
        }
        }
    sss[u]=1;
    for(j=1;j<=n;j++)
    {
        if(edge[u][j]==1 && sss[j]==0)
        {
            w=j;
            if (dist[w]>dist[u]+costt[u][w])
            {
                dist[w]=dist[u]+costt[u][w];
            }
        }
    }
    }
}
void main()
{
    int i,j,k;
    printf("there are 8 nodes \n");
//it is a directed graph
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            edge[i][j]=0;
            costt[i][j]=32767;
        }
    }
    costt[5][4]=1500;
    costt[5][6]=250;
    costt[6][4]=1000;
    costt[6][8]=1400;
    costt[6][7]=900;
    costt[7][8]=1000;
    costt[4][3]=1200;
    costt[3][2]=800;
    costt[3][1]=1000;
    costt[2][1]=300;
    costt[8][1]=1700;


    edge[5][4]=1;
    edge[5][6]=1;
    edge[6][4]=1;
    edge[6][8]=1;
    edge[6][7]=1;
    edge[7][8]=1;
    edge[4][3]=1;
    edge[3][2]=1;
    edge[3][1]=1;
    edge[2][1]=1;
    edge[8][1]=1;
    shortestpaths(5);
    printf("from \n");
        for(i=1;i<=8;i++)
        {
                printf("shortest path to %d is %d \t",i,dist[i]);
            printf("\n");
        }
}
