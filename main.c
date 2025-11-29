#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void puzir(int* arr, int size) {
    int flag;
    for (int x = 0; x < size-1; x++) {
        flag = 0;
        for (int y = 0; y < size-x-1; y++) {
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
    int k, j;
    for (int i = 1; i < size; i++) {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && k < arr[j]) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = k;
    }
    
}

void slianie(int* arr, int size) {
    if (size < 2) return;
    int s = size/2;
    slianie(arr, s);
    slianie(arr + s, size - s);
    
    int* v = malloc(size * sizeof(int));
    int l = 0, r = 0, g = 0;
    
    while (l < s) {
    v[g++] = arr[l++];
}
while (r < size - s) {
    v[g++] = arr[s + r++];
}
    
    for (l = 0; l < size; l++) arr[l] = v[l];
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
