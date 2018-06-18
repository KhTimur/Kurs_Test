#include "catch.hpp"
#include <kurs_test.h>



SCENARIO("SORT") {
	int nums1[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	inser(nums1, 9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums1[i] = nums_proverka1[i]);
	}
	int nums2[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	heapSort(nums2, 9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums2[i] = nums_proverka2[i]);
	}
	int nums3[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	merge_sort(nums3, 9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums3[i] = nums_proverka3[i]);
	}
	int nums4[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	quick_sort(nums4, 9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums4[i] = nums_proverka4[i]);
	}
}
