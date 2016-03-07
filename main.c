#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);

  color c;
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  //printf("WHERE ARE U SEG FAULT 0 \n");
  //Make a triangle
  add_edge(edges, 10, 10, 0, XRES / 4, (YRES-10) / 2, 0);
  //printf("WHERE ARE U SEG FAULT 1 \n");
  add_edge(edges, XRES / 4, (YRES-10) / 2, 0, (XRES-10) / 2, 10, 0);
  //printf("WHERE ARE U SEG FAULT 2 \n");
  add_edge(edges, (XRES-10) / 2, 10, 0, 10, 10, 0);
  //printf("WHERE ARE U SEG FAULT 3 \n");
  //print_matrix(edges);
  draw_lines(edges, s, c);

  transform = new_matrix(4, 4);
  ident(transform);
  transform = make_translate(50, 30, 0);
  matrix_mult(transform, edges);
  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = MAX_COLOR;
  draw_lines(edges, s, c);

  display(s);

  free_matrix( transform );
  free_matrix( edges );
}  

/*
  printf("Testing that edges has been initialized and\npopulated so that m[i][j] = 1...\n");
  print_matrix(edges);
  printf("Complete √\n");

  
  printf("\nTesting ident on transform...\n");
  ident(transform);
  print_matrix(transform);
  printf("Complete √\n");

  printf("\nTesting scalar_mult on edges...\n");
  printf("times 3\n");
  scalar_mult(3, edges);
  print_matrix(edges);
  printf("Complete √\n");

  printf("\nTesting copy_matrix...\n");
  struct matrix *copy_me;
  copy_me = new_matrix(4,4);
  pop(copy_me);
  scalar_mult(5, copy_me);
  printf("Matrix A\n");
  print_matrix(copy_me);
  printf("Matrix B\n");
  print_matrix( edges );
  copy_matrix(copy_me, edges);
  printf("Post copy\n");
  print_matrix( edges );
  printf("Complete √\n");

  printf("Testing matrix_mult...\n");
  printf("Matrix A\n");
  pop( copy_me );
  print_matrix( copy_me );
  printf("Matrix B\n");
  pop( edges );
  print_matrix( edges );
  matrix_mult(copy_me, edges);
  printf("Result ---->\n");
  print_matrix( edges );
  printf("Complete √\n");
  printf("**Disclaimer: This was not tested on non-square matricies.\n");

  free_matrix( copy_me );
  */