
/*
 * Author : πÊ¿Â
 * 2017-07-23
 */

#include <cstdio> // printf
#include <random> // std::random_device, std::mt19937
#include <chrono> // get elapsed time 
#define get_now() std::chrono::system_clock::now()

template< class IT >
void    sort(IT first, IT last)
{
	auto*   ptr = &(*first);
	auto    size = last - first;

	// to do

}

int child = 16;
template <typename T>
void heapify(T* src,const int n,int i) {
	int largest = i;
	int idx;
	
	for (int j = 1; j <= child; ++j) {
		idx = child * i + j;
		if (idx < n && src[idx] > src[largest])
			largest = idx;
	}

	if (largest != i)
	{
		std::swap(src[i], src[largest]);
		heapify(src, n, largest);
	}
}

template<typename T>
void your_sort(T* src, const int size) { // T src[size] = {...};
	// your code goes here
	for (int i = size / child - 1; i >= 0; i--)
		heapify(src, size, i);

	// One by one extract an element from heap
	for (int i = size - 1; i >= 0; i--)
	{
		// Move current root to end
		std::swap(src[0], src[i]);

		// call max heapify on the reduced heap
		heapify(src, i, 0);
	}
}

void proc(const int arr_size) {
	int *a = new int[arr_size];
	int length = arr_size;
	std::random_device rd;
	std::mt19937 gen(rd());

	// generate random array
	for (int i = 0; i < length; ++i) {
		a[i] = rd();
	}

	std::chrono::system_clock::time_point start;
	start = get_now();
	your_sort(a, length);
	std::chrono::duration<double> elapsedTime = get_now() - start;

	// check
	bool flag = true;
	for (int i = 1; i < length; ++i) {
		if (a[i - 1] > a[i]) {
			flag = false;
			break;
		}
	}

	printf("  %-9d|  %-6s| %lf second\n", arr_size, flag ? "PASS" : "FAIL", elapsedTime.count());
}

int main() {
	int a[] = { 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22 };
	printf("array size | result | elapsed time\n");
	for (auto x: a)
		proc(x);
	return 0;
}