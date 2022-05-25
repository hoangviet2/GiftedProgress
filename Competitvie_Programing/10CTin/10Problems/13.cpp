#include <bits/stdc++.h>
using namespace std;

struct Triangle {
	vector<pair<double, double>> V;
	Triangle() {}
	Triangle(vector<pair<double,double>> _V) {
		V = _V;
	}
	double area() const {
		double res = 0;
		for (int i = 0; i < 3; i++)
			res += V[i].first * V[(i + 1) % 3].second,
			res -= V[(i + 1) % 3].first * V[i].second;
		res = abs(res) / 2.0;
		return res;
	}
	bool covers(const Triangle& T) const {
		double outerArea = this->area();
		for (int i = 0; i < 3; i++) {
			auto s1 = Triangle({ T.V[i], V[0], V[1] });
			auto s2 = Triangle({ T.V[i], V[0], V[2] });
			auto s3 = Triangle({ T.V[i], V[1], V[2] });
			double sSum = s1.area() + s2.area() + s3.area();
			if (abs(sSum - outerArea) > 1e-9) return false;
		}
		return true;
	}
};

vector<Triangle> triangles;
vector<int> choice;
vector<int> dp;

int main() {
	int n; cin >> n;
	triangles = vector<Triangle>(n);
	dp = vector<int>(n, 1);
	choice = vector<int>(n, -1);
	for (int i = 0; i < n; i++) {
		pair<double, double> p1, p2, p3;
		cin >> p1.first >> p1.second;
		cin >> p2.first >> p2.second;
		cin >> p3.first >> p3.second;
		triangles[i] = Triangle({ p1,p2,p3 });
	}
	auto sortByArea = [](const Triangle& a, const Triangle& b) {
		return a.area() < b.area();
	};
	sort(triangles.begin(), triangles.end(), sortByArea);
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			if (triangles[j].covers(triangles[i]))
				if (1 + dp[j] > dp[i])
					dp[i] = 1 + dp[j],
					choice[i] = j;

	int res = 1, howToRes = 0;
	for (int i = 0; i < n; i++)
		if (dp[i] > res)
			res = dp[i],
			howToRes = i;

	if (res == 1) {
		cout << 0;
		return 0;
	}

	int p = howToRes;
	for (; choice[p] != -1; p = choice[p])
		cout << p << ' ';
	cout << p;
}
