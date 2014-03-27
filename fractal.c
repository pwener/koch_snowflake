#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main(){
	int size = 3;
	char filename[size];
	char base[size];
	int k = 1;
	int i;
	for(i = 0; i < sizeof(filename); i++){
	sprintf(base, "map%d.dat\0", k-1);
	sprintf(filename, "map%d.dat\0", k);
	printf("base é %s\n", base);
	printf("filename é %s\n", filename);
	FILE *mapa = fopen(base, "r"),
	     *nmapa   = fopen(filename, "w");

	float xa, ya, xb, yb, xc, yc, xd, yd, xe, ye;
	fscanf(mapa, "%f\t%f", &xa, &ya);
	fscanf(mapa, "%f\t%f", &xe, &ye);
	printf("%f\t%f\n", xa, ya);
	printf("%f\t%f\n", xe, ye);
	fprintf(nmapa, "%f\t%f\n", xa, ya);
	int c = 0;

	while(c < 3 * (pow(4, k-1))){

	float px = (xe - xa)/3; 
	float py = (ye - ya)/3;
	xb = xa + px;
	yb = ya + py;
	xd = 2 * px + xa;
	yd = 2 * py + ya;
	xc = (0.5*px) + (-0.866*py) + xb;
	yc = (0.866*px) + (0.5 * py) + yb;
	fprintf(nmapa, "%f\t%f\n", xb, yb);
	fprintf(nmapa, "%f\t%f\n", xc, yc);
	fprintf(nmapa, "%f\t%f\n", xd, yd);
	fprintf(nmapa, "%f\t%f\n", xe, ye);

	xa = xe;
	ya = ye;

	fscanf(mapa,"%f\t%f", &xe, &ye);
	c++;
	}
		c = 0;
		k++;
		fclose(mapa);
		fclose(nmapa);
	}
}
