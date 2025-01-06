// https://www.hackerearth.com/practice/notes/mos-algorithm/
// https://www.youtube.com/watch?v=RENzmNgIZ4A

#include <bits/stdc++.h>
using namespace std;

int N, Q;

long long current_answer;
long long cnt[100];

long long answers[100500];
int BLOCK_SIZE;
int arr[100500];

pair< pair<int, int>, int> queries[100500];

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

inline void add(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += cnt[x] * cnt[x] * x;
}

// Removing is much like adding.
inline void remove(int x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N >> Q;
    BLOCK_SIZE = static_cast<int>(sqrt(N));

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    sort(queries, queries + Q, mo_cmp);

    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) {
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        while(mo_right < right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arr[mo_left]);
        }

        answers[queries[i].second] = current_answer;
    }

    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";

    return 0;
}


// 18 7
// 0 1 1 0 2 3 4 1 3 5 1 5 3 5 4 0 2 2
// 0 8
// 2 5
// 2 11
// 16 17
// 13 14
// 1 17
// 17 17
