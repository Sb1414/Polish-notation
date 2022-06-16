// "Copyright 2022 <Copyright Plastiqu>"

#include <stdlib.h>
#include <math.h>

double polska_math(char a[100], double x) {
  double polska_line[300];
  int exi = 0;
  int sp = 0;
  int id = 0;
  while (exi == 0) {
    int c = a[id];
    if (c != '\0') {
      switch (c) {
        case  ' ':
          break;
        case '+':
          polska_line[sp-2] = polska_line[sp-2] + polska_line[sp-1];
          sp--;
          break;
        case '-':
          polska_line[sp-2] = polska_line[sp-2] - polska_line[sp-1];
          sp--;
          break;
        case '*':
          polska_line[sp-2] = polska_line[sp-2] * polska_line[sp-1];
          sp--;
          break;
        case '/':
          polska_line[sp-2] = polska_line[sp-2] / polska_line[sp-1];
          sp--;
          break;
        case 'S':
          polska_line[sp-1] = sin(polska_line[sp-1]);
          break;
        case 'C':
          polska_line[sp-1] = cos(polska_line[sp-1]);
          break;
        case 'T':
          polska_line[sp-1] = tan(polska_line[sp-1]);
          break;
        case 'G':
          polska_line[sp-1] = 1.0/tan(polska_line[sp-1]);
          break;
        case 'Q':
          polska_line[sp-1] = sqrt(polska_line[sp-1]);
          break;
        case 'L':
          polska_line[sp-1] = log(polska_line[sp-1]);
          break;
        case 'x':
          polska_line[sp] = x;
          sp++;
          break;
        default:
          if (c >= '0' && c <= '9') {
            char buffer[10];
            int count = 0;
            while (a[id + count] != ' ') {
              buffer[count] = a[id + count];
              count++;
            }
            id += count;
            buffer[count + 1] = '\0';
            polska_line[sp] = atof(buffer);
            sp++;
          }
        }
    } else {
      exi = 1;
    }
    id++;
  }
  return polska_line[sp-1];
}
