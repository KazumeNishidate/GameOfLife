
# Game of Life

This code simulates the Game of Life using [GSL](https://www.gnu.org/software/gsl/) and [EGGX](https://www.ir.isas.jaxa.jp/~cyamauch/eggx_procall/index.html). To compile the code, type 'make' in the program directory.

The maximum timesteps, the matrix size, and the concentration are set in the **control.c** as:

``` c
 ctl.max_time_step = 20000;
 ctl.mat_size = 100;
 ctl.concentration = 0.2;  
```

Type 'make' to recompile the code whenever you change any of these parameters.

## Mouse input

The directory **initiconf** contains the EGGX program, **gm1.c**, which supports the creation of an initial configuration using the mouse. Use the egg to compile the code.

``` bash {.copy}
 egg gm1.c
```

You can create your own life by drawing the mouse and pressing its button. Type 'q' to quit the mouse input. Then, a file, **positions.txt**, which stores position data, will be created in the same directory. Also, the function set_blinker() must be enabled instead of set_init_conf() in the **main.c** to read the file.

```
 //set_init_cont()
 set_blinker()
```

## Lexicon

The directory **initconf2** contains a Perl script, which translates the map of a 'life' registered in the [Life Lexicon](http://www.radicaleye.com/lifepage/lexicon.html) into a readable format and can be used as an initial configuration of the Game of Life.

Copy one of the 'life' from the [Life Lexicon](http://www.radicaleye.com/lifepage/lexicon.html) site and paste it into a data file, data.txt. The Perl script lex2pos.pl will translate it into positions.txt, which can be used as the input file.

``` bash
 lex2pos.pl data.txt
```

To read the positions.txt in this directory, you must modify the following line in the init.c

from

```
 FILE *fp=fopen("../initconf/position.txt","r");
```

to

```
> FILE *fp=fopen("../initconf2/position.txt","r");
```
