int solve(int i,int st)
{
	if (i==n+1)
		return 0;
	if (st<t[i])
		return solve(i,t[i]);
	if (mem[i][st-t[i]])
		return mem[i][st-t[i]];
	int sum=0,j=i;
	
	while (j<=n && t[j]<=st)
		sum+=t[j++];
	int best=st*(j-i)-sum+solve(j,st+m); 
	
	for (;j<=n;j++)
	{
		sum+=t[j];
		best=min(t[j]*(j-i+1)-sum+solve(j+1,t[j]+m),best);
	}
	return mem[i][st-t[i]]=best;
} 