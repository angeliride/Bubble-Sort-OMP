#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;
int n = 2000;

void bubbleSortParallel(std::vector<float>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        float temp;
        int j;
        #pragma omp parallel for schedule(static) shared(arr, n, i) private(temp, j)
        for (j = (i % 2); j < n - 1; j += 2) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {  
    vector<float> arr(n);

    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        arr[i] = static_cast<float>(rand()) / RAND_MAX * 1000.0f;

    double start_time = omp_get_wtime();
    bubbleSortParallel(arr);
    double end_time = omp_get_wtime();

    cout << "Czas wykonania (sekundy): " << (end_time - start_time) << endl;
    return 0;
}


//Kompliacja: g++ -fopenmp omp.cpp -o program_omp
