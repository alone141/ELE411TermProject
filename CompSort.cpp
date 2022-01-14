#include <iostream>
#include <stdlib.h>
#include "math.h"
#include <chrono>
using namespace std::chrono;

// Utility Function Prototypes
void swap(int *x, int *y);                   // Swap function
int partition(int arr[], int low, int high); // For quickSort
void merge(int *array, int l, int m, int r); // For mergeSort
void heapify(int arr[], int n, int i);       // For heapSort
void countSort(int arr[], int n, int exp);   // For radixSort
int getMax(int arr[], int n);                // For radixSort

// Sorting Algorithms
void selectionSort(int numbers[], int length);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void CocktailSort(int a[], int n);
void shellSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void mergeSort(int *array, int l, int r);
void heapSort(int arr[], int n);
void radixSort(int arr[], int n);
void combSort(int *arr, int length);

int length = 10;


int main()
{
    int numbersTemp[length] , numbers[length];

    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        numbers[i] = (rand());
    }
    memcpy(numbersTemp, numbers, length);

    auto start = high_resolution_clock::now();
    selectionSort(numbers, length);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by Selection Sort: " << duration.count() << " microseconds" << ' ';
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;

    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    bubbleSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by Bubble Sort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    insertionSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by Insertion Sort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    CocktailSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by Cocktail Sort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    shellSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by shell Sort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    quickSort(numbers, 0, length-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by quickSort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    mergeSort(numbers, 0,length-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by mergeSort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    heapSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by heapSort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    radixSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by radixSort: " << duration.count() << " microseconds" << std::endl;
    for(int i =0; i!=10; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    memcpy(numbers, numbersTemp, length);
    start = high_resolution_clock::now();
    combSort(numbers, length);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by combSort: " << duration.count() << " microseconds" << std::endl;

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int numbers[], int length)
{
    int i, j, min_idx;

    for (i = 0; i < length - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < length; j++)
            if (numbers[j] < numbers[min_idx])
                min_idx = j;

        swap(&numbers[min_idx], &numbers[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}


void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];

    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];

    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{

    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void combSort(int *arr, int length)
{
    int sm;
    float shrink = 1.3;
    int gap = length;
    bool sorted = false;

    while (!sorted)
    {
        gap = floor(gap / shrink);
        if (gap <= 1)
        {
            sorted = true;
            gap = 1;
        }

        for (int i = 0; i < length - gap; i++)
        {
            sm = gap + i;
            if (arr[i] > arr[sm])
            {
                int temp = arr[i];
                arr[i] = arr[sm];
                arr[sm] = temp;
                sorted = false;
            }
        }
    }
}