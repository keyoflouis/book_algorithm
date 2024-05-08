#include"header.h"

int fakeIndex(vector<coin> coins) {
	int numbers = coins.size();
	int fakeIdx = -1;

	if (numbers % 2 == 0) {
		auto mid = coins.begin() + numbers / 2;
		int lsum = 0, rsum = 0;

		for (int i = 0; i < numbers / 2; i++) {
			lsum = coins[i] + lsum;
			rsum = coins[i + numbers / 2] + rsum;
		}

		if (lsum < rsum) {
			if (numbers / 2 == 1) {
				return coins[0].index;
			}
			fakeIdx = fakeIndex(vector<coin>(coins.begin(), mid));
		}
		else if (rsum < lsum) {
			if (numbers / 2 == 1) {
				return coins[1].index;
			}
			fakeIdx = fakeIndex(vector<coin>(mid, coins.end()));
		}
	}
	else if (numbers % 2 != 0) {
		auto mid = coins.begin() + numbers / 2;
		int lsum = 0, rsum = 0;

		for (int i = 0; i < numbers / 2; i++) {
			lsum = coins[i] + lsum;
			rsum = coins[i + numbers / 2 + 1] + rsum;
		}

		if (lsum < rsum) {
			if (numbers / 2 == 0) {
				return coins[0].index;
			}
			fakeIdx = fakeIndex(vector<coin>(coins.begin(), mid));
		}
		else if (rsum < lsum) {
			if (numbers / 2 == 0) {
				return coins[1].index;
			}
			fakeIdx = fakeIndex(vector<coin>(mid + 1, coins.end()));
		}
		else {
			fakeIdx = coins[numbers / 2].index;
		}
	}

	return fakeIdx;
}