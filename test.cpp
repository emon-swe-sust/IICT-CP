#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

using namespace std;

int N;

void move(int from, int to, int depth){
    if(depth == 1){
        printf("%d %d\n", from, to);
        return;
    }

    int other = 6 - from - to;
    move(from, other, depth-1);
    printf("%d %d\n", from, to);
    move(other, to, depth-1);
}

int main(){
    scanf("%d", &N);
    printf("%d\n", (1<<N)-1);
    move(1, 3, N);
}