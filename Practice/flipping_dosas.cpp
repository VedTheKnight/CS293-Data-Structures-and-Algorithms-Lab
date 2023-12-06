#include <iostream>
using namespace std;

class Tawa {
public:
    int *tawa;
    int N = 0;

    void inputTawa(int *a, int size) {
        N = size;
        tawa = a;
    }
    int serveTop() {
        return *(tawa++);
    }
    void flipDosas(int k) {
        int *temp = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = tawa[i];
        }
        for (int i = 0; i < k; i++) {
            tawa[i] = temp[k - i - 1];
        }
        delete[] temp; // Release the temporary array
    }
};

int main() {
    int N = 5;
    int *dosas = new int[N]{3, 1, 4, 5, 2};

    Tawa tawa;
    tawa.inputTawa(dosas, N);

    for (int last = N; last > 0; last--) {
        int max = -1;
        int max_index = -1;
        for (int k = 1; k <= last; k++) {
            if (tawa.tawa[k - 1] > max) {
                max = tawa.tawa[k - 1];
                max_index = k;
            }
        }
        tawa.flipDosas(max_index);
        tawa.flipDosas(last);
    }
    for (int i = 0; i < N; i++) {
        cout << tawa.serveTop() << endl;
    }

    return 0;
}
