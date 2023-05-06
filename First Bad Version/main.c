#include <stdio.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int	first;
	int last;
	int mid;

	first = 1;
	last = n;
	while (first <= last)
	{
		mid = (first + last + 1) / 2;
		if (!isBadVersion(mid))
			first = mid + 1;
		else
			last = mid - 1;
	}
	return (first);
}