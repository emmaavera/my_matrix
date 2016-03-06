#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  pop(edges);
  transform = new_matrix(4, 4);
  pop(transform);

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
  free_matrix( transform );
  free_matrix( edges );
}  
