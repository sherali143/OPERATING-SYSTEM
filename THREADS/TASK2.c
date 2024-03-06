
#include <stdio.h>
#include <pthread.h>

#define MAX_RECTANGLES 10

void* processRectangle(void* arg) {
    double* dimensions = (double*)arg;

    double length = dimensions[0];
    double width = dimensions[1];
    int id = (int)dimensions[2];

    double area = length * width;
    double perimeter = 2 * (length + width);

    printf( id, length, width, area, perimeter);

    return NULL;
}

int main() {
    int numRectangles;
    printf("Enter the number of rectangles",MAX_RECTANGLES);
    scanf(&numRectangles);

    pthread_t threads[MAX_RECTANGLES];

    for (int i = 0; i < numRectangles; i++) {
        double length, width;
        printf("Enter dimensions for Rectangle ", i + 1);
        scanf(&length, &width);

        double dimensions[3] = {length, width, i + 1};
        pthread_create(&threads[i], NULL, processRectangle, (void*)dimensions);
    }

    for (int i = 0; i < numRectangles; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

