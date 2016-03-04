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

  
  printf("\nTesting ident on transform...\n");
  ident(transform);
  print_matrix(transform);

  printf("\nTesting scalar_mult on edges...\n");
  printf("times 3\n");
  scalar_mult(3, edges);
  print_matrix(edges);

  printf("\nTesting copy_matrix...\n");

  free_matrix( transform );
  free_matrix( edges );
}  
