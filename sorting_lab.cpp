#include <iostream>
using namespace std;

// ------- Bubble Sort -------
void bubbleSort(int a[], int n) {
    bool swapped;
    for (int pass = 0; pass < n - 1; pass++) {
        swapped = false;
        for (int j = 0; j < n - pass - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ------- Insertion Sort -------
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int pos = i - 1;

        while (pos >= 0 && a[pos] > temp) {
            a[pos + 1] = a[pos];
            pos--;
        }

        a[pos + 1] = temp;
    }
}

// ------- Selection Sort -------
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minLoc = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minLoc])
                minLoc = j;
        }
        swap(a[i], a[minLoc]);
    }
}

// ------- Merge Sort -------
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

// ------- Quick Sort -------
int divide(int a[], int low, int high) {
    int pivot = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = divide(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ------- Heap Sort -------
void heapify(int a[], int n, int i) {
    int big = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[big]) big = left;
    if (right < n && a[right] > a[big]) big = right;

    if (big != i) {
        swap(a[i], a[big]);
        heapify(a, n, big);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// ------- Shell Sort -------
void shellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;
        }
    }
}

int main() {
    int arr[10];
    int n = 10;

    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nSorting options:\n";
    cout << "1 - Bubble Sort\n";
    cout << "2 - Insertion Sort\n";
    cout << "3 - Selection Sort\n";
    cout << "4 - Merge Sort\n";
    cout << "5 - Quick Sort\n";
    cout << "6 - Heap Sort\n";
    cout << "7 - Shell Sort\n";
    cout << "Pick: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: selectionSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        case 5: quickSort(arr, 0, n - 1); break;
        case 6: heapSort(arr, n); break;
        case 7: shellSort(arr, n); break;
        default: cout << "Invalid choice.\n"; return 0;
    }

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
