#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sorter {
public:
    void mergeSort(int arr[], int l, int r);
    void quickSort(int arr[], int low, int high, long long &counter);
    void quickSortM3(int arr[], int low, int high, long long &counter);

private:
    void merge(int arr[], int l, int m, int r);
    int partition(int arr[], int low, int high, long long &counter);
    int partitionM3(int arr[], int low, int high, long long &counter);
    int medianOfThree(int arr[], int low, int high);
};



void Sorter::merge(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}


// MERGE SORT
void Sorter::mergeSort(int arr[], int l, int r) {

    if (l < r) {

        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


// PARTITION
int Sorter::partition(int arr[], int low, int high, long long &counter) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        counter++;

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}


// QUICK SORT
void Sorter::quickSort(int arr[], int low, int high, long long &counter) {

    if (low < high) {

        int p = partition(arr, low, high, counter);

        quickSort(arr, low, p - 1, counter);
        quickSort(arr, p + 1, high, counter);
    }
}


// MEDIAN OF THREE
int Sorter::medianOfThree(int arr[], int low, int high) {

    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);

    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);

    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high]);

    return high;
}


// PARTITION M3
int Sorter::partitionM3(int arr[], int low, int high, long long &counter) {

    medianOfThree(arr, low, high);

    return partition(arr, low, high, counter);
}


// QUICK SORT M3
void Sorter::quickSortM3(int arr[], int low, int high, long long &counter) {

    if (low < high) {

        int p = partitionM3(arr, low, high, counter);

        quickSortM3(arr, low, p - 1, counter);
        quickSortM3(arr, p + 1, high, counter);
    }
}


int main() {

    Sorter s;

    // -------------------------
    // ORIGINAL TEST DRIVER
    // -------------------------

    int tmp[8];

    int a[] = {64,25,12,22,11,90,45,34};
    int n = 8;

    long long counter = 0;


    // Merge Sort
    copy(a, a + n, tmp);

    s.mergeSort(tmp, 0, n - 1);

    cout << "MS: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    // Quick Sort
    copy(a, a + n, tmp);

    counter = 0;

    s.quickSort(tmp, 0, n - 1, counter);

    cout << "QS: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    // Sorted array
    int sorted8[] = {1,2,3,4,5,6,7,8};

    copy(sorted8, sorted8 + n, tmp);

    counter = 0;

    s.quickSort(tmp, 0, n - 1, counter);

    cout << "QS sorted: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    // Median of Three
    copy(sorted8, sorted8 + n, tmp);

    counter = 0;

    s.quickSortM3(tmp, 0, n - 1, counter);

    cout << "QSM3 sorted: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;



    // -------------------------
    // COMPARISON TESTS
    // n = 16
    // -------------------------

    int random[16] =
    {23, 5, 17, 9, 31, 2, 40, 12,
     7, 28, 15, 1, 35, 19, 10, 25};

    int sorted[16] =
    {1,2,3,4,5,6,7,8,
     9,10,11,12,13,14,15,16};

    int reverse[16] =
    {16,15,14,13,12,11,10,9,
     8,7,6,5,4,3,2,1};


    int temp1[16];
    int temp2[16];

    long long qsCounter;
    long long m3Counter;


    // RANDOM
    copy(random, random + 16, temp1);
    copy(random, random + 16, temp2);

    qsCounter = 0;
    m3Counter = 0;

    s.quickSort(temp1, 0, 15, qsCounter);
    s.quickSortM3(temp2, 0, 15, m3Counter);

    cout << endl;
    cout << "Random array" << endl;
    cout << "QS comparisons: " << qsCounter << endl;
    cout << "QSM3 comparisons: " << m3Counter << endl;


    // SORTED
    copy(sorted, sorted + 16, temp1);
    copy(sorted, sorted + 16, temp2);

    qsCounter = 0;
    m3Counter = 0;

    s.quickSort(temp1, 0, 15, qsCounter);
    s.quickSortM3(temp2, 0, 15, m3Counter);

    cout << endl;
    cout << "Sorted array" << endl;
    cout << "QS comparisons: " << qsCounter << endl;
    cout << "QSM3 comparisons: " << m3Counter << endl;


    // REVERSE SORTED
    copy(reverse, reverse + 16, temp1);
    copy(reverse, reverse + 16, temp2);

    qsCounter = 0;
    m3Counter = 0;

    s.quickSort(temp1, 0, 15, qsCounter);
    s.quickSortM3(temp2, 0, 15, m3Counter);

    cout << endl;
    cout << "Reverse sorted array" << endl;
    cout << "QS comparisons: " << qsCounter << endl;
    cout << "QSM3 comparisons: " << m3Counter << endl;


    return 0;
}