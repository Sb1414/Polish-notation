// "Copyright 2022 <Copyright Plastiqu>"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "./polska_parcer.h"

#define WIDTH 80
#define HEIGHT 25
#define void_sym 46
#define sym 42
#define Null 12

void fill_graph(int matrix[HEIGHT][WIDTH]);
void print_graph(int matrix[HEIGHT][WIDTH]);
void create_graphic(int matrix[HEIGHT][WIDTH]);

int main() {
    int graph[HEIGHT][WIDTH];
    fill_graph(graph);
    create_graphic(graph);
    print_graph(graph);
    return 0;
}

void create_graphic(int matrix[HEIGHT][WIDTH]) {
    int count = 0;
    char formula[100];
    fgets(formula, 100, stdin);
    for (double x = 0; x <= 4.0*M_PI; x+=4.0*M_PI/80.0) {
        double res = polska_parcer(formula, x);
        int y = round(res*Null);
        if (y <= Null&& y >= -Null) {
          matrix[Null + y][count] = sym;
        }
        count++;
    }
}

void fill_graph(int matrix[HEIGHT][WIDTH]) {
  for (int i = 0; i <HEIGHT; i++)
    for (int j = 0; j <WIDTH; j++) {
        matrix[i][j] = void_sym;
    }
}

void print_graph(int matrix[HEIGHT][WIDTH]) {
  for (int rows = 0; rows <HEIGHT; rows++) {
    for (int cols = 0; cols <WIDTH; cols++)
      printf("%c", matrix[rows][cols]);
      printf("\n");
    }
}
