#include<bits/stdc++.h>
using namespace std;
string In, Post;
// We first push right subtree to a stack, then left subtree, and finally, we push root. Finally, we print contents of stack.
stack<char> pre;
void push_pre(string in, string post, char lbl) {
    int len = in.size();
    if (len == 0) return;

    int i;
    for (i = 0; i < len; i++) if (in[i] == lbl) break;

    string next_in = in.substr(i + 1, len - i - 1);
    string next_post = post.substr(i, len - i - 1);
    push_pre(next_in, next_post, next_post[next_post.size() - 1]);

    next_in = in.substr(0, i);
    next_post = post.substr(0, i);
    push_pre(next_in, next_post, next_post[next_post.size() - 1]);

    pre.push(post[len - 1]);

    return;
}
void print_pre() {
    while (!pre.empty()) {
        cout << pre.top();
        pre.pop();
    }
    return;
}
int main() {
    cin >> In >> Post;
    push_pre(In, Post, Post[Post.size() - 1]);
    print_pre();
}
// BADC BDCA
