## DP Description
for example you have these numbers
```
4 7 2 9 5 2
```
for example you have the sums of
```
4 7 2 9 5 2
  ^   ^   ^
```
in best[1+1][5],
and you want the score of the other player after his turn aka
```
4 7 2 9 5 2
^   ^   ^
```
in best[1][5],
you can get the old score of the current player (aka opposite score of the other player (aka total[1+1][5]-best[1+1][5])),
and add the board value (board[1] in this case).

## for loop notes
all the ones with len=2 needs other ones with len=1 completed first, so we do it that way, with len increasing.

if you cant understand, this might help https://suzyz.github.io/2017/07/26/game1/