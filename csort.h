#pragma once

namespace csort {
	// includes various helper functions
	class utils {
	public:
		static int max(int*, int);
		static bool is_sorted(int*, int);
		static int* copy(int*, int);
	};

	class sort {
	public:
		static void bubble(int*, int);
		static void counting(int*, int);
		static void insertion(int*, int);
		static void quicksort(int*, int);
		static void selection(int*, int);
	private:
		static void quick(int*, int, int);
		static int partition(int*, int, int);
	};
	
}