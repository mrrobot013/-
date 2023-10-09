#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort (int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort (int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort (int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quickSort (int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low-1;
        for (int j = low; j <= high-1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        int pi = i+1;
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void merge (int arr[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid+j+1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void shellSort (int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

void heapify (int arr[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort (int arr[], int n) {
    for (int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr)); // инициализация генератора случайных чисел
    const int N = 10000;
    int C[N], D[N], E[N*2]; // объявление массивов
    for (int i = 0; i < N; i++) {
        C[i] = rand() % 51; // заполнение массива C случайными числами от 0 до 50
        D[i] = rand() % 501; // заполнение массива D случайными числами от 0 до 500
    }
    clock_t start, end;
    double time_taken;
    
    // сортировка массива C пузырьком
    start = clock();
    bubbleSort(C, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Bubble sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D пузырьком
    start = clock();
    bubbleSort(D, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Bubble sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C выбором
    start = clock();
    selectionSort(C, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Selection sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D выбором
    start = clock();
    selectionSort(D, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Selection sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C вставками
    start = clock();
    insertionSort(C, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Insertion sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D вставками
    start = clock();
    insertionSort(D, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Insertion sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C быстрой сортировкой
    start = clock();
    quickSort(C, 0, N-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Quick sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D быстрой сортировкой
    start = clock();
    quickSort(D, 0, N-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Quick sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C слиянием
    start = clock();
    mergeSort(C, 0, N-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Merge sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D слиянием
    start = clock();
    mergeSort(D, 0, N-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Merge sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C Шелла
    start = clock();
    shellSort(C, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Shell sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D Шелла
    start = clock();
    shellSort(D, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Shell sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // сортировка массива C кучей
    start = clock();
    heapSort(C, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Heap sort for [0,50]: " << time_taken << " seconds" << endl;
    
    // сортировка массива D кучей
    start = clock();
    heapSort(D, N);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Heap sort for [0,500]: " << time_taken << " seconds" << endl;
    
    // объединение отсортированных массивов C и D в массив E
    int i = 0, j = 0, k = 0;
    while (i < N && j < N) {
        if (C[i] <= D[j]) {
            E[k++] = C[i++];
        } else {
            E[k++] = D[j++];
        }
    }
    while (i < N) {
        E[k++] = C[i++];
    }
    while (j < N) {
        E[k++] = D[j++];
    }
    // сортировка массива E
    start = clock();
    mergeSort(E, 0, N*2-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Merge sort for [0,10000]: " << time_taken << " seconds" << endl;
    // сортировка массива E быстрой сортировкой
    start = clock();
    quickSort(E, 0, N*2-1);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Quick sort for [0,10000]: " << time_taken << " seconds" << endl;
    return 0;
}
