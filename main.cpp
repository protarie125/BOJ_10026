#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;

const auto& dx = vi{ -1,1,0,0 };
const auto& dy = vi{ 0,0,-1,1 };

void dfs1(int n, const vs& f, vvb& isVisited, int y, int x) {
	const auto& c = f[y][x];
	isVisited[y][x] = true;

	for (auto d = 0; d < 4; ++d) {
		const auto& nx = x + dx[d];
		const auto& ny = y + dy[d];

		if (nx < 0 || n <= nx ||
			ny < 0 || n <= ny) {
			continue;
		}

		if (isVisited[ny][nx]) {
			continue;
		}

		if (c != f[ny][nx]) {
			continue;
		}

		dfs1(n, f, isVisited, ny, nx);
	}
}

void dfs2(int n, const vs& f, vvb& isVisited, int y, int x) {
	const auto& c = f[y][x];
	isVisited[y][x] = true;

	for (auto d = 0; d < 4; ++d) {
		const auto& nx = x + dx[d];
		const auto& ny = y + dy[d];

		if (nx < 0 || n <= nx ||
			ny < 0 || n <= ny) {
			continue;
		}

		if (isVisited[ny][nx]) {
			continue;
		}

		if ('B' == c) {
			if ('B' != f[ny][nx]) {
				continue;
			}
		}
		else {
			if ('B' == f[ny][nx]) {
				continue;
			}
		}

		dfs2(n, f, isVisited, ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto f = vs(n);
	for (auto i = 0; i < n; ++i) {
		cin >> f[i];
	}

	auto ans1 = int{ 0 };
	auto isVisited1 = vvb(n, vb(n, false));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (isVisited1[i][j]) {
				continue;
			}

			dfs1(n, f, isVisited1, i, j);
			++ans1;
		}
	}

	auto ans2 = int{ 0 };
	auto isVisited2 = vvb(n, vb(n, false));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (isVisited2[i][j]) {
				continue;
			}

			dfs2(n, f, isVisited2, i, j);
			++ans2;
		}
	}

	cout << ans1 << ' ' << ans2;

	return 0;
}