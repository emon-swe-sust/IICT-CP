#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}

int main() {
	string s = "ababba";
	s += "$";

	int n = 7;
	vector<int> p(n), c(n); // p - ordering of the strings, c - equivalence classes

	{
		// k = 0
		vector<pair<char, int> > a(n);
		for(int i = 0; i < n; i++) {
			a[i] = {s[i], i};
		}

		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++) {
			p[i] = a[i].second;
		}
		c[p[0]] = 0;


		for(int i = 1; i < n; i++) {
			if(a[i].first == a[i - 1].first) {
				c[p[i]] = c[p[i-1]];
			} else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		} 
	}

	int k = 0;

	while((1 << k) < n) {
		// k -> k + 1
		vector< pair < pair<int, int> ,int> > a(n);

		for(int i = 0; i < n; i++) {
			a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
		}

		sort(a.begin(), a.end(), compare);

		for(int i = 0; i < n; i++) {
			p[i] = a[i].second;
		}

		c[p[0]] = 0;

		for(int i = 1; i < n; i++) {
			if(a[i].first == a[i-1].first) {
				c[p[i]] = c[p[i-1]];
			} else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
		k++;
	}

	for(int i = 0; i < n; i++) {
		cout << p[i] << " " << s.substr(p[i], n - p[i]) <<  endl;
	}
}

<<<<<<< HEAD
// https://codeforces.com/edu/course/2/lesson/2
=======
// https://codeforces.com/edu/course/2/lesson/2
>>>>>>> 48ca8eda14c2910ed0f292c25912f8983facaf00
