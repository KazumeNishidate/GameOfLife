#include <eggx.h>
#include <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include  <X11/Xlib.h>
#include  <X11/Xutil.h>
#include "rw.h"
#include "prototypes.h"
#define SCALE 5


void egg_disp(void){
  static int cnt=0, win;
  int i, j;
  if(cnt==0){
    win=gopen(ctl.mat_size*SCALE,ctl.mat_size*SCALE);
    layer(win,0,1);
  }
  gclr(win);
  newcolor(win, "Green");
  
  for (i = 2; i < ctl.mat_size+2; i++){
    for (j = 2; j < ctl.mat_size+2; j++){
      if(sys.mat0[ctl.shift*i+j]>0){
	fillrect(win,i*SCALE,j*SCALE,SCALE-1,SCALE-1);
      }
    }
  }
  copylayer(win,1,0);
  cnt++;  


}
