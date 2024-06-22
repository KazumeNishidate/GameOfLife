/*------------------ global definitions ----------------------------------*/

/* input and output files */
FILE *fpin;

/*------------------ global variables -------------------------------------*/
typedef	struct {

  int max_time_step;    /* max time step */
  int mat_size;         /* system size   */
  int shift;            /* column shift = mat_size + 4               */
  double concentration; /* initial concentration probability         */
} calc_control;

typedef	struct {

  long tdumy;   /* dummy variable for time() function     */ 
  long seed;    /* seed for random number genelater       */

  int time_step;    /* current number of time step */
  int average_step; /* current average step        */

  int *mat0; 
  int *mat1; 
  int *mat2;  /* not used */

  double *accumulation;
  double *distinct_sites;
  int number_of_walkers;

  long *random_seed;
  float random;

} system_property;

/*------------------- declaration for the structures ----------------------*/

calc_control ctl;
system_property sys;


