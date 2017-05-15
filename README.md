# How to use

## Dependencies
To plot `mapn.dat` coordinates is needed install gnuplot. To debian distributions run:

```
sudo apt-get install gnuplot
```

## Running

Just compile with gcc:

```
gcc -Wall fractal.c -lm -o fractal
```

And run:

```
$ ./fractal 10 > fractal.html
```

One number of interations will be request, choose one integer, when it is finished, open with your web browser the fractal.html file created.
