#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

/****
 set the initial configuration of the system
****/
void set_blinker(){
  int i, j;
  int *field=sys.mat0;

  FILE *fp = fopen("../initconf/position.txt","r");
  for(i=2; i<ctl.mat_size+2; i++){
    for(j=2; j<ctl.mat_size+2; j++){
      fscanf(fp, " %2d", &field[(ctl.mat_size+4)*i+j]);
            printf(" %d",field[(ctl.mat_size+4)*i+j]);
    }
        printf("\n");
  }
    printf("\n");
}

void set_init_conf()
{
  int i, j, cnt=0;

  while(cnt==0){  /*=== to avoid a vacant system ===*/
    cnt = 0; 

    for (i = 2; i < ctl.mat_size+2; i++){
      for (j = 2; j < ctl.mat_size+2; j++){
	sys.mat0[(ctl.mat_size+4)*i+j] = (int)(ran1()+1)*
	((int)(ran1()+ctl.concentration));
	if(sys.mat0[(ctl.mat_size+4)*i+j]>0) cnt++;
      }
    }
  } 
  sys.number_of_walkers = cnt;
  set_bc(sys.mat0);
}

void init_mem(void){
  int *mat_mem0, *mat_mem1, *mat_mem2;
  int n;
  
  n = ctl.mat_size+4;

  mat_mem0 = (int *)calloc(n*n, sizeof(int)); 
  mat_mem1 = (int *)calloc(n*n, sizeof(int)); 
  mat_mem2 = (int *)calloc(n*n, sizeof(int)); 
  sys.mat0 = mat_mem0;
  sys.mat1 = mat_mem1;
  sys.mat2 = mat_mem2;

}

void show_matrix(int *field){
  int i, j;
  for(i=2; i<ctl.mat_size+2; i++){
    for(j=2; j<ctl.mat_size+2; j++){
      printf(" %2d",field[(ctl.mat_size+4)*i+j]);
    }
    printf("\n");
  }
  printf("\n");

}

