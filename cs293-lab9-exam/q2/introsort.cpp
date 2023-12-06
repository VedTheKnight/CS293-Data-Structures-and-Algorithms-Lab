#include <cmath>
#include "partition.cpp"
#include "hsort.cpp"
#include "isort.cpp"
#include <vector>
using std::vector;

// Implement introsort. It is like quicksort but clever enough to avoid worst case.
void introsort(vector<int>& v, int l, int r, int thresold) {
}

void introsort(vector<int>& v) {
  int thresold = 0; // Choose a thresold such the performance is best
  introsort(v, 0, v.size() - 1, thresold*std::log2(v.size())); // depth is logarithmic meaning worst case is nlogn
}
