mi = 0x3f3f3f3f3f3f3f3f;
rep(k, 1, n) {
	rep(i, 1, k - 1)
	rep(j, 1, i - 1) {
		ll tmp = (ll)dis[i][j] + vl[i][k] + vl[k][j];
		if ((tmp < mi) && (tmp < inf)) {
			mi = tmp;
			ans = cnt[i][j];
		} else if (tmp == mi)
			ans += cnt[i][j];
	}
	rep(i, 1, n)
	rep(j, 1, n)
	if (dis[i][k] + dis[k][j] < dis[i][j]) {
		dis[i][j] = dis[i][k] + dis[k][j];
		cnt[i][j] = cnt[i][k] * cnt[k][j];
	} else if (dis[i][j] == dis[i][k] + dis[k][j])
		cnt[i][j] += cnt[i][k] * cnt[k][j];
}

