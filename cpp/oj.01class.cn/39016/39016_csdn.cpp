#include <bits/stdc++.h>
using namespace std;

struct node1
{
    int num;
    int ui, ci;
};
node1 a[105];

struct node2
{
    int next, to;
    int val;
};
node2 edge[100005];

int n, m, counter = 0, head[105], w[105];
vector<node1> answer;
queue<node1> q;

void added(int u, int v, int value)
{
    edge[counter].to = v;
    edge[counter].next = head[u];
    edge[counter].val = value;
    head[u] = counter++;
}

bool rule1(node1 p, node1 q)
{
    return p.num < q.num;
}

void solve()
{
    while (!q.empty())
    {
        node1 now = q.front();
        int u = now.num;
        if (head[u] == -1 && a[u].ci > 0)
            answer.push_back(now);
        for (int i = head[now.num]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (a[u].ci > 0)
            {
                a[v].ci += (edge[i].val * a[u].ci);
                cout << v << " : " << edge[i].val << " * " << a[u].ci << " + " << a[v].ci - (edge[i].val * a[u].ci) << " = " << a[v].ci << endl;
            }
            if ((--w[v]) == 0)
                q.push(a[v]);
        }
        q.pop();
    }

    sort(answer.begin(), answer.end(), rule1);
    if (answer.size() != 0)
        for (int i = 0; i != answer.size(); i++)
            printf("%d %d\n", answer[i].num, answer[i].ci);
    else
        printf("NULL\n");
    return;
}

int main()
{
    freopen("csdn.out", "w", stdout);
    memset(head, -1, sizeof(head));
    memset(w, 0, sizeof(w));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].ci, &a[i].ui);
        a[i].num = i;
        if (a[i].ci == 0)
            a[i].ci -= a[i].ui;
    }

    for (int num = 0; num < m; num++)
    {
        int u, v, value;
        scanf("%d%d%d", &u, &v, &value);
        added(u, v, value);
        w[v]++;
    }

    for (int i = 1; i <= n; i++)
        if (w[i] == 0)
            q.push(a[i]);

    solve();
    return 0;
}