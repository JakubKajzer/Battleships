#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void wyswietl_jedno(int **tab, int rozmiar)
{
	/*
	 * kod błędów
	 * 0- puste pole
	 * 1- statek
	 * 8 trafienie
	 * 2-pudlo
	 */
	int i,j;
		for(j=0;j<rozmiar+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}
				printf("\n");
	for(i =0; i < rozmiar;i++)
		{
			for(j=0;j<rozmiar;j++)
			{

					if(j==0)
					{
						if(i<9)printf("\033[1m%d \033[0m ",i+1);
						else
						printf("\033[1m%d\033[0m ",i+1);
					}
					if(tab[i][j]==0)
						printf("'  ");
					else printf("S  ");

			}
		printf("\n");
		}
}

void wyswietl_dwa(int **tab, int **bat, int rozmiar)
{
	/*
	 * kod błędów
	 * 0- puste pole
	 * 1- statek
	 * 8 trafienie
	 * 2-pudlo
	 */
	int i,j;
		for(j=0;j<rozmiar+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}
		printf("\t");
		for(j=0;j<rozmiar+1;j++)
		{
				if(j==0)printf("   ");
				else
				{
					if(j<=9)
					printf("\033[1m%d \033[0m ",j);
					else
					printf("\033[1m%d\033[0m ",j);
				}
		}

				printf("\n");


	for(i =0; i < rozmiar;i++)
		{
			for(j=0;j<rozmiar;j++)
			{

					if(j==0)
					{
						if(i<9)
						{
							printf("\033[1m%d \033[0m ",i+1);
						}
						else
						{
							printf("\033[1m%d\033[0m ",i+1);
						}
					}
					switch(tab[i][j])
					{
						case 0: printf("'  "); break;
						case 1: printf("S  "); break;
						case 2: printf("P  "); break;
						case 8: printf("X  "); break;
					}

			}
					printf("\t");
				for(j=0;j<rozmiar;j++)
				{
					if(j==0)
					{
						if(i<9)
						{
							printf("\033[1m%d \033[0m ",i+1);
						}
						else
						{
							printf("\033[1m%d\033[0m ",i+1);
						}
					}
					switch(bat[i][j])
					{
						case 0: printf("'  "); break;
						case 1: printf("S  "); break;
						case 2: printf("P  "); break;
						case 8: printf("X  "); break;
					}

				}

		printf("\n");
		}
}


int ustaw_statek(int **tab,int rozmiar)
{

	int err=0;
	int x,y,k,dlugosc;
	int i,j, czyblad=0;
	int wczytane=4;
	char dummy;

	do
	{
		wyswietl_jedno(tab,rozmiar);
		czyblad=0;
		if(err==1) printf("Zly rozmiar, wsporzedne kola lub kierunek.\n");
			printf("Podaj wsporzedne pola poczatku statku, jego kierunek(1 w prawo, 0 w dol) i dlugosc(1-5)\nW postaci:(x y k d):");
		if(wczytane<4)scanf("%c",&dummy);
		wczytane=scanf("%d %d %d %d",&y,&x,&k, &dlugosc);
		if(x>0 && y>0 && (k==0 || k==1) && (dlugosc>0 && dlugosc<6) && wczytane==4)
		{

			if((k==0 && x<rozmiar-dlugosc+2)||(k==1 && y<rozmiar-dlugosc+2))
			{

				if(k==0)
					{
						for(i=x-1;i<x+dlugosc-1;i++)
							if(tab[i][y-1]==1) czyblad=1;
						for(i=x-1;i<x+dlugosc-1;i++)
						{

							if(czyblad==0)
								tab[i][y-1]=1;
							else err=1;
						}
						if(czyblad==0)err=0;
					}
				else
				{
					for(j=y-1;j<y+dlugosc-1;j++)
					{
						if(tab[x-1][j]==1) czyblad=1;
					}
					for(j=y-1;j<y+dlugosc-1;j++)
					{
						if(czyblad==0)
						tab[x-1][j]=1;
						else err=1;
					}
					if(czyblad==0)err=0;
				}
			}else err=1;
		}else err=1;
		system("clear");
	}while(err);
			return dlugosc;
}


void losuj_statek(int **tab, int dlugosc,int rozmiar)
{

	int err=0;
	do
	{
	int i,j, czyblad=0;
		int x,y,k;
		x=1+rand()%rozmiar;
		y=1+rand()%rozmiar;
		k=rand()%2;

			if((k==0 && x<rozmiar-dlugosc+2)||(k==1 && y<rozmiar-dlugosc+2))
			{

		if(k==0)
			{
				for(i=x-1;i<x+dlugosc-1;i++)
					if(tab[i][y-1]==1) czyblad=1;
				for(i=x-1;i<x+dlugosc-1;i++)
				{

					if(czyblad==0)
					tab[i][y-1]=1;
					else err=1;
				}
				if(czyblad==0)err=0;
			}
				else
				{
					for(j=y-1;j<y+dlugosc-1;j++)
					{
						if(tab[x-1][j]==1) czyblad=1;
					}
					for(j=y-1;j<y+dlugosc-1;j++)
					{
						if(czyblad==0)
						tab[x-1][j]=1;
						else err=1;
					}
					if(czyblad==0)err=0;
				}
			}else err=1;
		}while(err);
}

void strzel(int **wrog,int **strzaly,int rozmiar)
{
		int x,y,wczytane;
		char dummy;
		printf("\nPodaj wspolrzedne pola ostrzalu:");
		wczytane=scanf("%d %d",&x,&y);
		while(x<=0 || x>rozmiar || y<=0 || y>rozmiar || wczytane<2 )
		{
			if(wczytane<2)scanf("%c",&dummy);
			printf("Podales bledne wspolrzedne pola!");
			printf("\nPodaj wspolrzedne pola ostrzalu:");
			wczytane=scanf("%d %d",&x,&y);
		}
		x--;
		y--;
		if(wrog[y][x]==1)
		{
			strzaly[y][x]=8;
		}else strzaly[y][x]=2;
}

int policz_statki_gracza(int **tab,int rozmiar)
{
	int suma =0;
	int i,j;

	for(i=0;i<rozmiar;i++)
		for(j=0;j<rozmiar;j++)
		if(tab[i][j]==1)suma++;

	return suma;
}

int policz_statki_przeciwnika(int **statki,int **trafienia, int rozmiar)
{
	/*
	 * kod błędów
	 * 0- puste pole
	 * 1- statek
	 * 8 trafienie
	 * 2-pudlo
	 */
	int i,j,suma=0,strzelone=0;
	for(i=0;i<rozmiar;i++)
		for(j=0;j<rozmiar;j++)
		if(statki[i][j]==1)suma++;
	for(i=0;i<rozmiar;i++)
		for(j=0;j<rozmiar;j++)
		if(trafienia[i][j]==8)strzelone++;

	return suma-strzelone;

}

void AI_strzel(int **tab,int rozmiar)
{
	/*
	 * kod błędów
	 * 0- puste pole
	 * 1- statek
	 * 8 trafienie
	 * 2-pudlo
	 */
		int x,y;
		static int ost_x,ost_y;
		static int czytrafione=0;
		static int offset=1;
		static int pionowepodejrzenia=0;

		switch(czytrafione)
		{
			case 0:
			{

				x=rand()%rozmiar;
				y=rand()%rozmiar;

				while(tab[y][x]==2 || tab[y][x]==8)
				{
					x=rand()%rozmiar;
					y=rand()%rozmiar;
				}

				if(tab[y][x]==1)
				{
					tab[y][x]=8;
					czytrafione=4;
					ost_x=x;
					ost_y=y;
				}else tab[y][x]=2;
					break;
			}
			case 4:
			{
				if(ost_x+offset<=rozmiar-1)
				{
					if(tab[ost_y][ost_x+offset]==1)
					{
						tab[ost_y][ost_x+offset]=8;
						offset++;
					}
					else
					{
						tab[ost_y][ost_x+offset]=2;
						if(offset==1)
							pionowepodejrzenia=1;
						czytrafione=3;
						offset=1;
					}
				}
				else
				{
					if(offset==1)
							pionowepodejrzenia=1;
						czytrafione=3;
						offset=1;
				}
				break;
			}
			case 3:
			{
				if(ost_x-offset>=0)
				{
					if(tab[ost_y][ost_x-offset]==1)
					{
						tab[ost_y][ost_x-offset]=8;
						offset++;
					}
					else
					{
						tab[ost_y][ost_x-offset]=2;
						if(offset==1 && pionowepodejrzenia==1)
							czytrafione=2;
							else
							czytrafione=0;
						offset=1;
					}
				}
				else
				{
					if(offset==1 && pionowepodejrzenia==1)
							czytrafione=2;
							else
							czytrafione=0;
						offset=1;
				}
				break;
			}
			case 2:
			{
				if(ost_y+offset<=rozmiar-1)
				{
					if(tab[ost_y+offset][ost_x]==1)
					{
						tab[ost_y+offset][ost_x]=8;
						offset++;
					}
					else
					{
						tab[ost_y+offset][ost_x]=2;
							czytrafione=1;
							offset=1;
					}
				}
				else
				{
					czytrafione=1;
					offset=1;
				}
					break;
			}
			case 1:
			{
				if(ost_y-offset>=0)
				{
					if(tab[ost_y-offset][ost_x]==1)
					{
						tab[ost_y-offset][ost_x]=8;
						offset++;
					}
					else
					{
						tab[ost_y-offset][ost_x]=2;
						czytrafione=0;
						offset=1;
						pionowepodejrzenia=0;
					}
				}
				else
				{
						czytrafione=0;
						offset=1;
						pionowepodejrzenia=0;
				}
				break;
			}
		}

}


int main(int argc, char* argv[])
{
	srand(time(NULL));
	int i,j,liczbastatkow;
	int **gracz; //tablica ze statkami moimi
	int **przeciwnik; //tablica ze statkami przeciwnika
	int **ostrzal; //tablica do strzelania w przeciwnika
	int statki[5]={0};
	int rozmiar=atoi(argv[1])*5+5;
	int wczytane;
	char dummy;

	gracz=(int**)malloc(rozmiar*sizeof(int*));
	przeciwnik=(int**)malloc(rozmiar*sizeof(int*));
	ostrzal=(int**)malloc(rozmiar*sizeof(int*));
	for (i=0;i<rozmiar;i++)
	{
		gracz[i]=(int*)malloc(rozmiar*sizeof(int));
		przeciwnik[i]=(int*)malloc(rozmiar*sizeof(int));
		ostrzal[i]=(int*)malloc(rozmiar*sizeof(int));
	}
	system("clear");

			printf("Ile statkow chcesz ustawic(1-20):");
			wczytane=scanf("%d",&liczbastatkow);
			if(wczytane<1)scanf("%c",&dummy);
			while(liczbastatkow<1 || liczbastatkow>20)
			{
				system("clear");
				printf("Nieprawidlowe dane!\n");
				printf("Ile statkow chcesz ustawic(1-20):");
				wczytane=scanf("%d",&liczbastatkow);
				if(wczytane<1)scanf("%c",&dummy);
			}

			system("clear");
			for(i=0;i<liczbastatkow;i++)
			switch(ustaw_statek(gracz,rozmiar))
		{
			case 1:
			statki[0]++;
			break;

			case 2:
			statki[1]++;
			break;

			case 3:
			statki[2]++;
			break;

			case 4:
			statki[3]++;
			break;

			case 5:
			statki[4]++;
			break;
		}


		for(i=0; i<5;i++)
		{
			for(j=0;j<statki[i];j++)
			losuj_statek(przeciwnik,i+1,rozmiar);
		}

		system("clear");
		while(policz_statki_gracza(gracz,rozmiar)>0 && policz_statki_przeciwnika(przeciwnik,ostrzal,rozmiar)>0)
		{
			wyswietl_dwa(gracz,ostrzal,rozmiar);
			printf("Pola statkow gracza: %d\n",policz_statki_gracza(gracz,rozmiar));
			printf("Pola statkow przeciwnika: %d",policz_statki_przeciwnika(przeciwnik,ostrzal,rozmiar));
			strzel(przeciwnik,ostrzal,rozmiar);
			AI_strzel(gracz,rozmiar);
			system("clear");

		}
		if(policz_statki_gracza(gracz,rozmiar)!=0)
		printf("Wygrales!\nWpisz cokolwiek aby kontynuowac");
		else
		printf("Przegrales!\nWpisz cokolwiek aby kontynuowac");
		char znak;
			scanf("%s",&znak);

	for (i=0;i<rozmiar;i++)
	{
		free(gracz[i]);
		free(przeciwnik[i]);
		free(ostrzal[i]);
	}
	free(gracz);
	free(przeciwnik);
	free(ostrzal);

	return 0;
}

