![Alt text](https://g.gravizo.com/svg?  digraph g {
1->2 [label=12];
1->5 [label=16];
1->6 [label=14];
2->3 [label=10];
2->5 [label=7];
3->4 [label=5];
3->5 [label=6];
4->5 [label=2];
4->6 [label=8];
5->6 [label=9];} )

|      | 1       | 2       | 3       | 4       | 5       | 6       |
| ---- | ------- | ------- | ------- | ------- | ------- | ------- |
| 1    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| 2    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| 3    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| 4    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| 5    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |
| 6    | &infin; | &infin; | &infin; | &infin; | &infin; | &infin; |

|      | 1       | 2       | 3       | 4       | 5       | 6       |
| ---- | ------- | ------- | ------- | ------- | ------- | ------- |
| 1    | 0 | &infin; | &infin; | &infin; | &infin; | &infin; |
| 2    | &infin; | 0 | &infin; | &infin; | &infin; | &infin; |
| 3    | &infin; | &infin; | 0 | &infin; | &infin; | &infin; |
| 4    | &infin; | &infin; | &infin; | 0 | &infin; | &infin; |
| 5    | &infin; | &infin; | &infin; | &infin; | 0 | &infin; |
| 6    | &infin; | &infin; | &infin; | &infin; | &infin; | 0 |

|      | 1       | 2       | 3       | 4       | 5       | 6       |
| ---- | ------- | ------- | ------- | ------- | ------- | ------- |
| 1    | 0 | &infin; | &infin; | &infin; | &infin; | &infin; |
| 2    | &infin; | 0 | &infin; | &infin; | &infin; | &infin; |
| 3    | &infin; | &infin; | 0 | &infin; | &infin; | &infin; |
| 4    | &infin; | &infin; | &infin; | 0 | &infin; | &infin; |
| 5    | &infin; | &infin; | &infin; | &infin; | 0 | &infin; |
| 6    | &infin; | &infin; | &infin; | &infin; | &infin; | 0 |

|      | 1       | 2       | 3       | 4       | 5    | 6       |
| ---- | ------- | ------- | ------- | ------- | ---- | ------- |
| 1    | 0       | 12      | &infin; | &infin; | 16   | 14      |
| 2    | 12      | 0       | 10      | &infin; | 7    | &infin; |
| 3    | &infin; | 10      | 0       | 5       | 6    | &infin; |
| 4    | &infin; | &infin; | 5       | 0       | 2    | 8       |
| 5    | 16      | 7       | 6       | 2       | 0    | 9       |
| 6    | 14      | &infin; | &infin; | 8       | 9    | 0       |



dist[] 数组

| 1    | 2    | 3       | 4       | 5    | 6    |
| ---- | ---- | ------- | ------- | ---- | ---- |
| 0    | 12   | &infin; | &infin; | 16   | 14   |

| 1    | 2    | 3        | 4       | 5                 | 6    |
| ---- | ---- | -------- | ------- | ----------------- | ---- |
| 0    | 12   | 10+12=22 | &infin; | 16 < 19，没有更新 | 14   |

| 1    | 2    | 3    | 4       | 5               | 6    |
| ---- | ---- | ---- | ------- | --------------- | ---- |
| 0    | 12   | 22   | 22+5=27 | 16 < 28，没更新 | 14   |

| 1    | 2    | 3    | 4    | 5               | 6    |
| ---- | ---- | ---- | ---- | --------------- | ---- |
| 0    | 12   | 22   | 27   | 16 < 29，没更新 | 14   |

| 1    | 2    | 3    | 4    | 5    | 6               |
| ---- | ---- | ---- | ---- | ---- | --------------- |
| 0    | 12   | 22   | 27   | 16   | 14 < 25，没更新 |