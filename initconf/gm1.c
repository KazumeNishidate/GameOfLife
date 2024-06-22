#include <stdio.h>
#include <stdlib.h>
#include <eggx.h>  
FILE *fpout;
#define SCALE 20
#define NX 100
#define NY 100

int main(void){
  int *mat;
  int i, j, cnt=0;
  int win,b ;                                                                 
  int ix, iy;
  float x=0,y=0 ;      

  mat = (int *)calloc(NX*NY, sizeof(int));
  win = gopen(NX*SCALE,NY*SCALE) ;
  fpout = fopen("./position.txt","w");
  
  newcolor(win, "Black");                                                      
  gclr(win);

  newcolor(win, "Yellow");             
  while( 1 ){
    int type ;
    if ( ggetxpress(&type,&b,&x,&y) == win ) {
      if( type == ButtonPress ){

	ix = x/SCALE; x = (double)ix*SCALE;
	iy = y/SCALE; y = (double)iy*SCALE;
	 
	fillrect(win,x,y,SCALE,SCALE);
	printf("button=%d x=%g y=%g\n",b,x,y) ;
	mat[ix*NX+iy] = 1;
	cnt++;
	if(cnt>10) break;
      } else if( type == KeyPress ){
	if( b=='q' ) break ;
	printf("key code = %d\n",b) ;
      }
    }
  }
  
  for(i=0;i<NX;i++){
    for(j=0;j<NY;j++){
      printf("%2d", mat[i*NX+j]);
      fprintf(fpout,"%2d", mat[i*NX+j]);      
    }
    printf("\n");
    fprintf(fpout,"\n");    
  }
  fclose(fpout);
  gclose(win);
  free(mat);
  return 0;
}
