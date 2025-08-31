#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(200000, false);   
vector<int> destinations(200000);     
vector<int> pathlength(200000, 0);
queue<int> path;
int steps = 0;


void dfs(int planet) {
	// add planet to path
	path.push(planet);
	if (visited[planet]) {
		// add pathlength of the repeat planet to current step count
		steps += pathlength[planet];
		return;
	}
	visited[planet] = true;
	steps++;
	dfs(destinations[planet]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> destinations[i];
		destinations[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			steps = 0;
			dfs(i);
			int decrement = 1;
			// for each planet in current path, calculate pathlength
			while (!path.empty()) {
				// we are in the cycle; all nodes have same pathlength
				if (path.front() == path.back()) { decrement = 0; }
				pathlength[path.front()] = steps;
				steps -= decrement;
				path.pop();
			}
		}
	}
	for (int i = 0; i < n; i++) { cout << pathlength[i] << " "; }
	cout << endl;
	return 0;
}

