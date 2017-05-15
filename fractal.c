#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv){
	int size = atoi(argv[0]);

	// nome do arquivo a ser criado, ou map{n+1}.dat
	char filename[size];
	// nome do arquivo que serve de base ao que será criado, ou map{n}.dat
	char base[size];
	// k é o level do fractal
	int k = 1;
	int i;
	for(i = 0; i < sizeof(filename); i++){
		//cria os nomes dos arquivos
		sprintf(base, "map%d.dat", k-1);
		sprintf(filename, "map%d.dat", k);
		//abre dois arquivos, o segundo(nmapa) é o fractal criado a partir do primeiro(mapa)
		FILE *mapa = fopen(base, "r"),
		     *nmapa   = fopen(filename, "w");
		//Os pontos necessários para criar o padrão sobre uma reta
		float xa, ya, xb, yb, xc, yc, xd, yd, xe, ye;

		fscanf(mapa, "%f\t%f", &xa, &ya);
		fscanf(mapa, "%f\t%f", &xe, &ye);
		fprintf(nmapa, "%f\t%f\n", xa, ya);
		int c = 0;

		while(c < (3 * (pow(4, k-1)))){

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
	system ("gnuplot fractal.gpl");
	return 0;
}
