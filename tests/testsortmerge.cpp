#include "catch.hpp"
#include <merge.h>

SCENARIO("SORT") {	
	int nums3[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	merge_sort(nums3, nums3+9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums3[i] == nums_proverka3[i]);
	}
}
