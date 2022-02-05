// 本题有个重要的性质，那就对于原始输入数据，奇数位置的数之和与偶数位置的数之和，两者的差永远不变。可根据此性质直接计算出操作完成后，整个序列都变成了同一个数D=h[1]+h[3]+h[5]+...+h[n]-h[2]-h[4]-...-h[n-1]。所以，为了判断序列h[1]，h[2]...h[n]是否合法，我们可以在将所有数减去D之后，再判断得到的序列能否全部变成0。 
bool check(int n) {
    for (int j = 1; j <= n; j++) {
        diff[j] = h[j] - D;
    }
    for (int j = 2; j <= n; j++) {
        diff[j] -= diff[j - 1];
        if (diff[j] < 0) {
            return false;
        }
    }
    return diff[n] == 0;
}

long long ans = -1;
if (check(n)) {
    for (int i = 1; i <= n; i++) {
        ans += h[j] - D;
    }
}
cout << ans << endl;
