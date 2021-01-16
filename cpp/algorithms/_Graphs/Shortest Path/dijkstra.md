

![Alt text](https://g.gravizo.com/svg?  digraph g {
  A->B [label="12"];
  A->E [label="16"];
  A->F [label="14"];
  B->C [label="10"]; 
  B->E [label="7"];
  C->D [label="5"];
  C->E [label="6"];
  D->E [label="2"];
  D->F [label="8"];
  E->F [label="9"];} )



|      | A       | B       | C       | D       | E       | F       |
| ---- | ------- | ------- | ------- | ------- | ------- | ------- |
| A    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| B    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| C    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| D    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| E    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| F    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |



```c++
int INF = 0x3f3f3f3f;
int graph[2000][2000]; //邻接矩阵
int n；//n为顶点数
for(i=1;i<=n;i++){
   for(j=1;j<=n;j++){
       graph[i][j]=INF;
   }
}
```

```c++
int INF = 0x3f3f3f3f;
int n;
int graph[2000][2000];
memset(graph,INF,sizeof(graph));
```








```c++
for(int i = 1 ;i <= n; i++){
    graph[i][i] = 0; 
C}
```



|      | A       | B       | C       | D       | E       | F       |
| ---- | ------- | ------- | ------- | ------- | ------- | ------- |
| A    | 0       | &infin; | &infin; | &infin; | &infin; | &infin; |
| B    | &infin; | 0       | &infin; | &infin; | &infin; | &infin; |
| C    | &infin; | &infin; | 0       | &infin; | &infin; | &infin; |
| D    | &infin; | &infin; | &infin; | 0       | &infin; | &infin; |
| E    | &infin; | &infin; | &infin; | &infin; | 0       | &infin; |
| F    | &infin; | &infin; | &infin; | &infin; | &infin; | 0       |




|      | A       | B       | C       | D       | E    | F       |
| ---- | ------- | ------- | ------- | ------- | ---- | ------- |
| A    | 0       | 12      | &infin; | &infin; | 16   | 14      |
| B    | &infin; | 0       | 10      | &infin; | 7    | &infin; |
| C    | &infin; | 10      | 0       | 5       | 6    | &infin; |
| D    | &infin; | &infin; | 5       | 0       | 2    | 8       |
| E    | 16      | 7       | 6       | 2       | 0    | 9       |
| F    | 14      | &infin; | &infin; | 8       | 9    | 0       |



```c++
int m;//m为边的个数；
int x,y;  //x,y 为同一边的两个顶点；
int d; //d 边的权值；
for(i=1; i<=m ;i++){
   cin>>x>>y>>d;
   if(graph[x][y]>d){
      graph[x][y]=d;
      graph[y][x]=d;
   }
}
```



| A    | B    | C       | D       | E    | F    |
| ---- | ---- | ------- | ------- | ---- | ---- |
| 0    | 12   | &infin; | &infin; | 16   | 14   |





| A    | B    | C       | D       | E    | F    |
| ---- | ---- | ------- | ------- | ---- | ---- |
| 0    | 12   | 22		| &infin; | 16   | 14   |



| A    | B    | C       | D       | E    | F    |
| ---- | ---- | ------- | ------- | ---- | ---- |
| 0    | 12   | 22		| 18	  | 16   | 14   |