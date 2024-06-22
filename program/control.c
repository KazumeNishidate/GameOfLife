#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

void get_control_param(void){ 
  long time_dumy;

  ctl.max_time_step = 20000;
  ctl.mat_size = 100;        
  ctl.concentration = 0.2;  

  ctl.shift = ctl.mat_size+4;

  /* set a "seed" for random number generator */
  sys.random_seed = (long *)calloc(1, sizeof(long)); 
  *sys.random_seed=-time(&time_dumy);
}
