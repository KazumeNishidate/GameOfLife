#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

void life()
{
  int i, j, x, y;
  int n, e, s, w;
  int ne, se, sw, nw, nn_sum;

  for (i = 2; i < ctl.mat_size+2; i++){
    for (j = 2; j < ctl.mat_size+2; j++){

      x  = sys.mat0[ctl.shift*i+j];

      n  = sys.mat0[ctl.shift*(i-1)+j];
      e  = sys.mat0[ctl.shift*i+j+1];
      s  = sys.mat0[ctl.shift*(i+1)+j];
      w  = sys.mat0[ctl.shift*i+j-1];

      ne  = sys.mat0[ctl.shift*(i-1)+j+1];
      se  = sys.mat0[ctl.shift*(i+1)+j+1];
      sw  = sys.mat0[ctl.shift*(i+1)+j-1];
      nw  = sys.mat0[ctl.shift*(i-1)+j-1];
      nn_sum = n+e+s+w+ne+se+sw+nw;

      if(x==0 && nn_sum==3) y = 1;  /* rule set 1 */
      else if(x==1 && nn_sum==2) y = 1;  /* rule set 2 */
      else if(x==1 && nn_sum==3) y = 1;  /* rule set 2 */
      else if(x==1 && nn_sum==0) y = 0;  /* rule set 3 */
      else if(x==1 && nn_sum==1) y = 0;  /* rule set 3 */
      else if(x==1 && nn_sum>=4) y = 0;  /* rule set 3 */
      else y=x;

      *(sys.mat1+ctl.shift*i+j) = y;
    }
  }
  set_bc(sys.mat1);
}

void set_bc(int *ants)
{
  int i;

/* corner adjustment 1 */
  *ants     = *(ants+( ctl.shift*(ctl.mat_size+1) - 4));
  *(ants+1) = *(ants+( ctl.shift*(ctl.mat_size+1) - 3));
  *(ants+ctl.shift) = *(ants+( ctl.shift*(ctl.mat_size+2) - 4));
  *(ants+(ctl.mat_size+5)) = *(ants+( ctl.shift*(ctl.mat_size+2) - 3));

/* corner adjustment 2 */
  *(ants+(ctl.mat_size+2))   = *(ants+(ctl.shift*ctl.mat_size + 2));
  *(ants+(ctl.mat_size+3))   = *(ants+(ctl.shift*ctl.mat_size + 3));
  *(ants+2*(ctl.mat_size+3)) = *(ants+(ctl.shift*(ctl.mat_size+1)+2));
  *(ants+2*(ctl.mat_size+3)+1) = *(ants+(ctl.shift*(ctl.mat_size+1)+3));

/* corner adjustment 3 */
  *(ants+(ctl.mat_size+3)*(ctl.mat_size+3)-1) = *(ants+3*ctl.shift-4);
  *(ants+(ctl.mat_size+3)*(ctl.mat_size+3)) = *(ants+3*ctl.shift-3);
  *(ants+(ctl.mat_size+3)*ctl.shift) = *(ants+4*ctl.shift-4);
  *(ants+(ctl.mat_size+3)*ctl.shift+1) = *(ants+4*ctl.shift-3);

/* corner adjustment 4 */
  *(ants+ctl.shift*(ctl.mat_size+3)-2) = *(ants+2*ctl.shift+2);
  *(ants+ctl.shift*(ctl.mat_size+3)-1) = *(ants+2*ctl.shift+3);
  *(ants+ctl.shift*ctl.shift-2) = *(ants+3*ctl.shift+2);
  *(ants+ctl.shift*ctl.shift-1) = *(ants+3*ctl.shift+3);

/* border adjustment   */

  for (i = 2; i < ctl.mat_size+2; i++){
      *(ants+i) = *(ants+ctl.shift*ctl.mat_size+i);
      *(ants+ctl.mat_size+4+i) = *(ants+ctl.shift*(ctl.mat_size+1)+i); 
      *(ants+ctl.shift*(ctl.mat_size+2)+i)=*(ants+2*ctl.shift+i);
      *(ants+ctl.shift*(ctl.mat_size+3)+i) = *(ants+3*ctl.shift+i); 

      *(ants+i*ctl.shift)   = *(ants+(i+1)*ctl.shift-4);
      *(ants+i*ctl.shift+1) = *(ants+(i+1)*ctl.shift-3);

      *(ants+(i+1)*ctl.shift-2)   = *(ants+i*ctl.shift+2);
      *(ants+(i+1)*ctl.shift-1)   = *(ants+i*ctl.shift+3);
    }

}

void mk_copy(int *original, int *copy)
{
  int i, j;

  for(i=0; i<ctl.mat_size+4; i++){
    for(j=0; j<ctl.mat_size+4; j++){
      *(copy+ctl.shift*i+j)  = *(original+ctl.shift*i+j);
    }
  }
}

