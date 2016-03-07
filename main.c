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
  c.green = 0;
  c.blue = 100;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  add_edge(edges, 10, 10, 0, XRES / 2, YRES-10, 0);
  add_edge(edges, XRES / 2, YRES-10, 0, XRES-10, 10, 0);
  add_edge(edges, XRES-10, 10, 0, 10, 10, 0);


  print_matrix(edges);
  transform = new_matrix(4, 4);
  ident(transform);

  //draw_lines(edges, s, c);

  transform = make_scale( 0.5, 0.5, 0);
  matrix_mult(transform, edges);
  transform = make_translate( XRES/2, YRES/2, 0);
  matrix_mult(transform, edges);
  draw_lines(edges, s, c);

  for (int i = 0; i < 400; i ++){
    int x_dis = edges->m[0][0];
    int y_dis = edges->m[1][0];
    transform = make_translate( -x_dis, -y_dis, 0);
    matrix_mult(transform, edges);
    transform = make_rotZ( .04 );
    matrix_mult(transform, edges);
    transform = make_translate( x_dis, y_dis, 0);
    matrix_mult(transform, edges);
    if (c.blue < MAX_COLOR) {
      c.blue += 1;
    }
    else if (c.green < MAX_COLOR) {
      c.red += 1;
    }
    else{
      c.green += 30;
    }
    draw_lines(edges, s, c);
  }



  draw_lines(edges, s, c);

  display(s);

  save_ppm( s, "img.ppm");
  save_extension(s, "img.png");

  free_matrix( transform );
  free_matrix( edges );
  exit(0);
}  

/*
  edges = new_matrix(4, 4);
  //Make a triangle
  add_edge(edges, 300, 300, 0, XRES / 4, (YRES-10) / 2, 0);
  add_edge(edges, XRES / 4, (YRES-10)/2 , 0, (XRES-10) /2, 300, 0);
  add_edge(edges, (XRES-10)/2 , 300, 0, 300, 300, 0);
  transform = make_translate(300, 50, 1);
  matrix_mult(transform, edges);
  edges_orig = edges;
  draw_lines(edges, s, c);

  transform = new_matrix(4, 4);
  ident(transform);

  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = MAX_COLOR;
  draw_lines(edges, s, c);

  //transform = make_scale( 0.5, 0.5, 1);
  //matrix_mult(transform, edges);


  c.red = MAX_COLOR;
  c.blue = 0;
  c.green = MAX_COLOR;
  draw_lines(edges, s, c);
  for (int j = 0; j < 100; j++){
    for (int i = 0; i < 100; i ++){
      transform = make_rotY( .2 );
      matrix_mult(transform, edges);
      transform = make_rotX( .01 );
      matrix_mult(transform, edges);
      c.red = 0;
      if(i%3 == 0) {
        c.red = MAX_COLOR;
      }
      c.blue = 0;
      if(i%2 == 0) {
        c.blue = MAX_COLOR;
      }
      c.green = 0;
      if(i % 5 == 0) {
        c.green = MAX_COLOR;
      }
      draw_lines(edges, s, c);
    }
    transform = make_translate(0, -50, 0);
    matrix_mult(transform, edges);
    */  

/*
  transform = make_rotX( 3.14 );
  printf("transform---\n");
  print_matrix(transform);
  matrix_mult(transform, edges);
  printf("rotx---\n");
  print_matrix(edges);
  transform = make_translate(1, 400, 1);
  matrix_mult(transform, edges);
  printf("rotx + trans---\n");
  print_matrix(edges);
  c.red = 0;
  c.blue = 0;
  c.green = MAX_COLOR;
  draw_lines(edges, s, c);

  transform = make_rotY( 3.14/4 );
  matrix_mult(transform, edges);
  printf("roty---\n");
  print_matrix(edges);
  c.red = 0;
  c.blue = MAX_COLOR;
  c.green = 0;
  draw_lines(edges, s, c);
  */


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