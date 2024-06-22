/* prototypes.h */

/* control.c */
void get_control_param(void);

/* main.c */
int main(void);

/* dynamics.c */
void life();
void set_bc(int *ants);
void mk_copy(int *original, int *copy);

/* init.c */
void set_blinker();
void set_init_conf();
void init_mem(void);  
void show_matrix(int *field);
void print_averaged_msd(void);
void print_matrix(int *field);
void print_averaged_velocity(void);

void egg_disp(void);

/* ran.c */
double ran1(void);


