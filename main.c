#include <ncurses.h>
#include <stdlib.h>
int rozmiar=1;



void newgame()
{
	endwin();
	switch(rozmiar)
	{
		case 1:
		{
			system("./engine 1");
			break;
		}
		case 2:
		{
			system("./engine 2");
			break;
		}
		case 3:
		{
			system("./engine 3");
			break;
		}
		case 4:
		{
			system("./engine 4");
			break;
		}
	}
}



void options()
{
	int kolumny,wiersze;
	const short int min_wybor = 1;
   	const short int max_wybor = 5;
	int ktory = 1;
    	int znak;
   	 const char txt1[] = "10x10";
   	 const char txt2[] = "15x15";
   	 const char txt3[] = "20x20";
  	 const char txt4[] = "25x25";
 	 const char txt5[] = "POWROT";


        init_pair( 1, COLOR_WHITE, COLOR_BLACK );
	init_pair( 2,COLOR_GREEN,COLOR_BLACK);
        attron( COLOR_PAIR( 1 ) );

    do
    {
getmaxyx(stdscr,kolumny,wiersze);
mvprintw(kolumny/2-1, wiersze/2-5, "Rozmiar planszy:");
mvprintw(kolumny-1, 0, "W,S - poruszanie sie; ENTER - wybor");
        //wyswietlanie
        switch( ktory )
        {
        case 1:

            mvprintw( kolumny/2+4 ,wiersze/2, txt5 );

			if(rozmiar==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+1, wiersze/2, txt2 );
			if(rozmiar==2) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+2, wiersze/2, txt3 );
			if(rozmiar==3) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+3, wiersze/2, txt4 );
			if(rozmiar==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(rozmiar==1) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2, wiersze/2, txt1 );
			if(rozmiar==1) attroff( COLOR_PAIR( 2 ) );
            break;

        case 2:
			if(rozmiar==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2  , wiersze/2, txt1 );
			if(rozmiar==1) attroff( COLOR_PAIR( 2 ) );

            mvprintw( kolumny/2+4, wiersze/2, txt5 );

			if(rozmiar==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+2, wiersze/2, txt3 );
			if(rozmiar==3) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+3, wiersze/2, txt4 );
			if(rozmiar==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(rozmiar==2) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+1, wiersze/2, txt2 );
			if(rozmiar==2) attroff( COLOR_PAIR( 2 ) );
            break;

        case 3:
			if(rozmiar==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2  , wiersze/2, txt1 );
			if(rozmiar==1) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+1, wiersze/2, txt2 );
			if(rozmiar==2) attroff( COLOR_PAIR( 2 ) );

            mvprintw( kolumny/2+4, wiersze/2, txt5 );

			if(rozmiar==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+3, wiersze/2, txt4 );
			if(rozmiar==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			if(rozmiar==3) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+2, wiersze/2, txt3 );
			if(rozmiar==3) attroff( COLOR_PAIR( 2 ) );
            break;
	case 4:
			if(rozmiar==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2  , wiersze/2, txt1 );
			if(rozmiar==1) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+1, wiersze/2, txt2 );
			if(rozmiar==2) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+2, wiersze/2, txt3 );
			if(rozmiar==3) attroff( COLOR_PAIR( 2 ) );

			mvprintw( kolumny/2+4, wiersze/2, txt5 );

            attron( A_REVERSE );
			if(rozmiar==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+3, wiersze/2, txt4 );
			if(rozmiar==4) attroff( COLOR_PAIR( 2 ) );
            break;
	case 5:
			if(rozmiar==1) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2  , wiersze/2, txt1 );
			if(rozmiar==1) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==2) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+1, wiersze/2, txt2 );
			if(rozmiar==2) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==3) attron( COLOR_PAIR( 2 ) );
            mvprintw( kolumny/2+2, wiersze/2, txt3 );
			if(rozmiar==3) attroff( COLOR_PAIR( 2 ) );

			if(rozmiar==4) attron( COLOR_PAIR( 2 ) );
			mvprintw( kolumny/2+3, wiersze/2, txt4 );
			if(rozmiar==4) attroff( COLOR_PAIR( 2 ) );

            attron( A_REVERSE );
			mvprintw( kolumny/2+4, wiersze/2, txt5 );
            break;
        }
        attroff( A_REVERSE );
        //pobieranie znaku
        znak = getch();
        clear();
        if( znak == 'w' && ktory != min_wybor )
        {
            ktory--;
        }
        else if( znak == 's' && ktory != max_wybor )
        {
            ktory++;
        }
        //reakcja
        if( znak == 10 )
        {
            switch( ktory )
            {
            case 1:
		rozmiar=1;
                break;
            case 2:
		rozmiar=2;
                break;
	    case 3:
		rozmiar=3;
                break;
	    case 4:
		rozmiar=4;
                break;
            }
        }

    } while( ktory != 5 || znak != 10 );

}

void logo()
{
	int kolumny,wiersze;
	getmaxyx(stdscr,kolumny,wiersze);
	init_pair( 1, COLOR_YELLOW, COLOR_BLACK );
	attron( A_BOLD | COLOR_PAIR(1));
		mvprintw( 1, wiersze/2-34, ".______        ___      .___________..___________. __       _______ " );
		mvprintw( 2, wiersze/2-34, "|   _  \\      /   \\     |           ||           ||  |     |   ____|" );
		mvprintw( 3, wiersze/2-34, "|  |_)  |    /  ^  \\    `---|  |----``---|  |----`|  |     |  |__   " );
		mvprintw( 4, wiersze/2-34, "|   _  <    /  /_\\  \\       |  |         |  |     |  |     |   __|  " );
		mvprintw( 5, wiersze/2-34, "|  |_)  |  /  _____  \\      |  |         |  |     |  `----.|  |____ " );
		mvprintw( 6, wiersze/2-34, "|______/  /__/     \\__\\     |__|         |__|     |_______||_______|" );
		mvprintw( 7, wiersze/2-25, "     _______. __    __   __  .______        _______." );
		mvprintw( 8, wiersze/2-25, "    /       ||  |  |  | |  | |   _  \\      /       |" );
		mvprintw( 9, wiersze/2-25, "   |   (----`|  |__|  | |  | |  |_)  |    |   (----`" );
		mvprintw( 10, wiersze/2-25,"    \\   \\    |   __   | |  | |   ___/      \\   \\    " );
		mvprintw( 11, wiersze/2-25,".----)   |   |  |  |  | |  | |  |      .----)   |   " );
		mvprintw( 12, wiersze/2-25,"|_______/    |__|  |__| |__| | _|      |_______/    " );
		attroff( A_BOLD | COLOR_PAIR(1));
}

void menu()
{
int kolumny,wiersze;
    const char txt1[] = "NOWA GRA";
    const char txt2[] = "OPCJE";
    const char txt3[] = "WYJSCIE";
    int ktory = 1;
    int znak;
    const short int min_wybor = 1;
    const short int max_wybor = 3;


        init_pair( 1, COLOR_WHITE, COLOR_BLACK );
        attron( COLOR_PAIR( 1 ) );

    do
    {
getmaxyx(stdscr,kolumny,wiersze);
logo();
mvprintw(13, wiersze/2-8, "by Jakub Kajzer");
mvprintw(kolumny-1, 0, "W,S - poruszanie sie; ENTER - wybor");

        switch( ktory )
        {
        case 1:
            mvprintw( kolumny/2+4, wiersze/2-2, txt2 );
            mvprintw( kolumny/2+5, wiersze/2-3, txt3 );
            attron( A_REVERSE );
            mvprintw( kolumny/2+3, wiersze/2-3, txt1 );
            break;

        case 2:
            mvprintw( kolumny/2+3, wiersze/2-3, txt1 );
            mvprintw( kolumny/2+5, wiersze/2-3, txt3 );
            attron( A_REVERSE );
            mvprintw( kolumny/2+4, wiersze/2-2, txt2 );
            break;

        case 3:
            mvprintw( kolumny/2+3, wiersze/2-3, txt1 );
            mvprintw( kolumny/2+4, wiersze/2-2, txt2 );
            attron( A_REVERSE );
            mvprintw( kolumny/2+5, wiersze/2-3, txt3 );
            break;
        }
        attroff( A_REVERSE );
        znak = getch();
        clear();
        if( znak == 'w' && ktory != min_wybor )
        {
            ktory--;
        }
        else if( znak == 's' && ktory != max_wybor )
        {
            ktory++;
        }
        if( znak == 10 )
        {
            switch( ktory )
            {
            case 1:
                newgame();
                break;
            case 2:
                options();
                break;
            }
        }

    } while( ktory != 3 || znak != 10 );

    move( 9, 0 );
    printw( "Koniec programu, przycisnij przycisk..." );
    getch();
}

int main()
{
    initscr();
    noecho();
    start_color();
    menu();
    endwin();
    system("clear");
    return 0;

}
