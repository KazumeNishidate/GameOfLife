#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "rw.h"
#include "prototypes.h"

/* LIFE CA uder cyclic boundary condition */

int main(void){

  get_control_param();
  init_mem();

  set_init_conf();
  //  set_blinker();

  mk_copy(sys.mat0, sys.mat1);
  
  for(sys.time_step=0;sys.time_step<ctl.max_time_step;
      sys.time_step++){
    egg_disp();
    life();
    usleep(100000);
    mk_copy(sys.mat1, sys.mat0);
  }
  return 0;
}

