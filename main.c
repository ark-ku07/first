#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void puzir(int* arr, int n) {
    int flag;
    for (int x = 0; x < n-1; x++) {
        flag = 0;
        for (int y = 0; y < n-x-1; y++) {
            if (arr[y] > arr[y+1]) {
                int t = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = t;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void vstavka(int *arr, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    
}

void slianie(int* arr, int n) {
    if (n < 2) return;
    int s = n/2;
    slianie(arr, s);
    slianie(arr + s, n - s);
    
    int* v = malloc(n * sizeof(int));
    int l = 0, r = 0, g = 0;
    
    while (l < s && r < n - s) {
        if (arr[l] < arr[s + r]) 
            v[g++] = arr[l++];
        else 
            v[g++] = arr[s + r++];
    }
    while (l < s) v[g++] = arr[l++];
    while (r < n - s) v[g++] = arr[s + r++];
    
    for (l = 0; l < n; l++) arr[l] = v[l];
    free(v);
}

int main() {
    srand(time(0));
    int r[] = {10, 1000, 10000, 100000};
    
    printf("Размер массива | puzir | vstavka | slianie\n");
    printf("---------------------------------------------------\n");
    
    for (int z = 0; z < 4; z++) {
        int size = r[z];
        int* arr = malloc(size * sizeof(int));
        
        for (int w = 0; w < size; w++) 
            arr[w] = rand() % 100000;
        
        double time[3];
        
        for (int alg = 0; alg < 3; alg++) {
            int* copy = malloc(size * sizeof(int));
            for (int c = 0; c < size; c++) 
                copy[c] = arr[c];
            
            clock_t start = clock();
            if (alg == 0) puzir(copy, size);
            else if (alg == 1) vstavka(copy, size);
            else slianie(copy, size);
            clock_t end = clock();
            
            time[alg] = (double)(end - start) / CLOCKS_PER_SEC;
            free(copy);
        }
        
        printf("%d | %f | %f | %f\n", size, time[0], time[1], time[2]);
        free(arr);
    }
    
    return 0;
}
