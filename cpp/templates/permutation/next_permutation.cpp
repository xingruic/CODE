#include <bits/stdc++.h>
using namespace std;

template<typename It>
bool next_permutation(It begin, It end){
    if (begin == end)
        return false;
    It i = begin;
    ++i;
    if (i == end)
        return false;
    i = end;
    --i;
    while (true) {
        It j = i;
        --i;
        if (*i < *j){
            It k = end;
            while (!(*i < *--k))
                /* pass */;
            iter_swap(i, k);
            reverse(j, end);
            return true;
        }
        if (i == begin) {
            reverse(begin, end);
            return false;
        }
    }
}

template<typename It>
bool prev_permutation(It begin, It end){
    if (begin == end)
        return false;
    It i = begin;
    ++i;
    if (i == end)
        return false;
    i = end;
    --i;
    while (true) {
        It j = i;
        --i;
        if (*i < *j){
            It k = end;
            while (!(*i < *--k))
                /* pass */;
            iter_swap(i, k);
            reverse(j, end);
            return true;
        }
        if (i == begin) {
            reverse(begin, end);
            return false;
        }
    }
}

int main(){
		int a[5] = {1,2,3,4};
		string v = "abcde";
		do{
		cout<<v<<endl;
		}
		while (::next_permutation(v.begin(), v.end()));
}