#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

// wooooooow
string copeStr(string& str) {

	string result;
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (result.size() >= 2) {
			if (result.size() == 2) {
				char a = result[index - 2];
				char b = result[index - 1];
				char c = str[i];
				if (a == b && b == c) {
					continue;
				}

				result.push_back(c);
				index++;
			}
			else {
				char a = result[index - 3];
				char b = result[index - 2];
				char c = result[index - 1];
				char d = str[i];

				if (b == c && c == d) {
					continue;
				}

				if (a == b && b != c && c == d) {
					continue;
				}
				
				result.push_back(d);
				index++;
			}
		}
		else {
			result.push_back(str[i]);
			index++;
		}
	}

	return result;
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		cout << copeStr(s) << endl;
	}

	return 0;
}

