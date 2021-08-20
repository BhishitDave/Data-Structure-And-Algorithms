int countWays(int n, int m)
{
	int count[n + 1];
	count[0] = 0;

	for (int i = 1; i <= n; i++) {
		// recurrence relation
		if (i > m)
			count[i] = count[i - 1] + count[i - m];
		// base cases and for i = m = 1
		else if (i < m || i == 1)
			count[i] = 1;
		// i = = m
		else
			count[i] = 2;
	}
	return count[n];
}