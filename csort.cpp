// csort.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "csort.h"
#include "framework.h"

namespace csort {
	// ### SORT CLASS -- PUBLIC FUNCTIONS

	// bubble sort
	void sort::bubble(int* arr, int n) {
		int temp;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	// counting sort
	void sort::counting(int* a, int n) {
		int max = utils::max(a, n);
		int* counts = new int[max + 1];

		// init counts
		for (int i = 0; i < max + 1; i++) {
			counts[i] = 0;
		}
		
		// generate counts
		for (int i = 0; i < n; i++) {
			counts[a[i]]++;
		}

		// add previous to current
		for (int i = 1; i < max + 1; i++) {
			counts[i] += counts[i - 1];
		}

		// generate final array
		int* fin = utils::copy(a, n);
		for (int i = 0; i < n; i++) {
			int v = fin[i];
			int p = counts[v] - 1;

			a[p] = v;
			counts[v]--;
		}

		// clean up
		delete[] counts;
	}

	// insertion sort
	void sort::insertion(int* a, int n) {
		for (int i = 1; i < n; i++) {
			int key = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > key) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = key;
		}
	}

	// quicksort, with chosen pivot
	void sort::quicksort(int* a, int n) {
		return sort::quick(a, 0, n - 1);
	}

	// selection sort
	void sort::selection(int* a, int n) {
		for (int i = 0; i < n; i++) {
			int minidx = i;
			for (int j = i; j < n; j++) {
				if (a[j] < a[minidx]) {
					minidx = j;
				}
			}
			// swap
			int temp = a[i];
			a[i] = a[minidx];
			a[minidx] = temp;
		}
	}

	// ##### SORT CLASS -- PRIVATE METHODS

	// helper to implement the recurrence for quicksort
	void sort::quick(int* a, int l, int r) {
		if (l < r) {
			int pivot = sort::partition(a, l, r);
			quick(a, l, pivot - 1);
			quick(a, pivot + 1, r);
		}
	}

	// computes the partition
	int sort::partition(int* a, int l, int r) {
		while (l < r) {
			// adjust right
			while (l < r && a[l] <= a[r]) {
				r--;
			}
			if (l < r) {
				// swap elements at l & r
				int temp = a[l];
				a[l] = a[r];
				a[r] = a[l];
			}

			// adjust left
			while (l < r && a[l] <= a[r]) {
				l++;
			}
			if (l < r) {
				// swap again
				int temp = a[l];
				a[l] = a[r];
				a[r] = a[l];
				r--;
			}
		}
		return l;
	}

	// #################### UTILS CLASS #################
	// ### utils class definitions

	// finds the max of an array
	int utils::max(int* a, int n) {
		int max = a[0];
		for (int i = 1; i < n; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		return max;
	}

	// checks an array. true if sorted. false otherwise.
	bool utils::is_sorted(int* a, int n) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				return false;
			}
		}
		return true;
	}

	// performs a deep copy of the array
	int* utils::copy(int* a, int n) {
		int* b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}
		return b;
	}

}
