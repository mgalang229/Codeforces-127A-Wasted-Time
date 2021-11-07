#include <bits/stdc++.h>

using namespace std;

struct Point {
	double x;
	double y;
};

double Calculate(Point p1, Point p2) {
	double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	double res = distance / 50;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	// calculate the sum of distances between adjacent points and divide
	// them by 50 since we need every second the pen moves 50 millimeters
	// note: don't forget to multiply it to k 
	// (since Scrooge repeats this exact process for k papers)
	double time = 0;
	for (int i = 0; i + 1 < n; i++) {
		time += Calculate(a[i], a[i + 1]);
	}
	double ans = time * (double) k;
	cout << fixed << setprecision(9) << ans << '\n';
	return 0;
}
