#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int size;
	printf("\n\033[22;31mO programa irá gerar arquivos no formato map{n}.dat onde n é o nivel do fractal.\n\n");
	printf("Cada arquivo contém coordenadas no formato x  y que correspondem a pontos que formam o fractal.\033[0m\n\n");
	
	printf("Quantos niveis quer criar: ");
	scanf("%d", &size);
	/*__fpurge(stdin);
	
	float P1x, P1y, P2x, P2y;
	printf("Insira x de P1: ");
	scanf("%f", &P1x);
	__fpurge(stdin);
	printf("\nInsira y de P1: ");
	scanf("%f", &P1y);
	__fpurge(stdin);	
	printf("\nInsira x de P2: ");
        scanf("%f", &P2x);
	__fpurge(stdin);
        printf("\nInsira y de P2: ");
        scanf("%f", &P2y);
	__fpurge(stdin);
	
	float P3x = 0.5*((P2x - P1x)/2)+(-0.866*(P2y - P1y)) - P1x;
	float P3y = 0.866*((P2x - P1x)/2)+(0.5*(P2y - P1y)) + P1y;	
	
	printf("P1x = %f", P1x);
	printf("P1y = %f", P1y);
	printf("P3x = %f", P3x);
	printf("P3y = %f", P3y);	

	FILE *triangulo = fopen("map0.dat", "w");
	fprintf(triangulo, "%f\t%f\n", P1x, P1y);
	fprintf(triangulo, "%f\t%f\n", P2x, P2y); 
	fprintf(triangulo, "%f\t%f\n", P3x, P3y);
	fprintf(triangulo, "%f\t%f\n", P1x, P1y);
	
	fclose(triangulo);
*/

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
	system ("gnuplot fractal.gpl");
	return 0;
}
