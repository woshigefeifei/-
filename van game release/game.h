#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define row 3//��������
#define col 3//��������


void intboard(char arr[row][col], int a, int b);
void board(char arr[row][col], int a, int b);
void move(char arr[row][col], int a, int b);
void move2(char arr[row][col], int a, int b);
char iswin(char arr[row][col], int a, int b);
int isfull(char arr[row][col], int a, int b);


