# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <dos.h>

int well[23][11];
int tempbr[5], s1=0, s2=0, score, hd_scr;
int gamelevel = 0, gameover = 0;
int octave[10] = {125, 140, 155, 170, 185, 200, 215, 230, 245, 260} ;

typedef struct
{
  int color;
  int shape;
  int ar[4];
}tetris;
tetris tbr;

void gameend()
{
  int gi;
  char go[]={"Game Over"};
  textbackground(0);
  clrscr();

  for(gi=0; go[gi]!='\0'; ++gi) {
    textcolor(gi+1);
    gotoxy((gi*2)+30, 10); cprintf("%c",go[gi]);
				}
  textcolor(15+128);
  gotoxy(33,13);cprintf("Score : %d",score);
  randomize();
  while ( !kbhit() ) {
    sound ( octave[ random(10) ] * 2 );
    delay ( 200 ) ;
		     }
  nosound() ;
  textcolor(15);
  textbackground(0);
}

void helppage()
{
  textcolor(3);textbackground(0);
  clrscr();
  cprintf("\n\n"
	  "\n\n\r        -----[  Help  ]----------------------------------------------"
	  "\n\n\r          -> Press 'A' and 'D' to toggle left & right                "
	    "\n\r          -> Press 'W' to rotate & 'space' to hard drop              "
	    "\n\r          -> Rotation occurs clockwise, if there is proper space     "
	    "\n\r          -> Press 'Esc' to quit game                                "
	  "\n\n\n\n");
  textcolor(2);
  cprintf("\n\n\r        -----[  Scoring  ]-------------------------------------------"
	  "\n\n\r          ->    1 row - 40 X level                                   "
	    "\n\r          ->    2 rows - 100 X level                                 "
	    "\n\r          ->    3 rows - 200 X level                                 "
	    "\n\r          ->    4 rows - 500 X level                                 "
	    "\n\r          -> For filling up row(s) with hard drop -                  "
	    "\n\r                Score = score for row(s) + no. of blocks dropped     ");
  textcolor(15+128);
  cprintf("\n\n\n\n\n\r"
	  "                                Press any key ");
  getch();

  textcolor(3);
  while(( gamelevel<1 )||( gamelevel>10)) {
    clrscr();
    gotoxy(25, 10);cprintf("Enter level(1-10) -   ");
    gotoxy(45, 10);scanf("%d", &gamelevel);
					  }
    gamelevel-=1;
}

void mainpage()
{
  int mi, mj;
  int display[6][21]={ 1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,0,1,1,
		       0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,
		       0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,
		       0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,
		       0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,
		       0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,0};

  for(mi=0; mi<6; ++mi) {
    for(mj=0; mj<21; ++mj) {
      if(display[mi][mj]==1) {
	textbackground( mi+1 );
	gotoxy((mj*2)+20, 10+mi);
	cprintf("  ");
			     }
			   }
			}
  textbackground(0);textcolor(15+128);
  gotoxy(35,25);cprintf("press any key");
  randomize();
  while ( !kbhit() ) {
    sound ( octave[ random(10) ] * 2 );
    delay ( 200 ) ;
		     }
  nosound() ;
}

void initialise()
{
  int i, j;

  for( i=0; i<25; ++i )
    for( j=0; j<11; ++j ) {
      well[i][j] = 0;

      if( i<4 )
	tbr.ar[i] = 0;
			  }

  tbr.color = 0;
  tbr.shape = 0;
}

void startpage()
{
  int i, j;

  clrscr();
  textcolor(15);
  textbackground(0);

  gotoxy(20, 2);cprintf("北北北北北北北北北北北北");
  for( i=1; i<=20; ++i ) {
    gotoxy(20, 2+i);cprintf("北");
    gotoxy(42, 2+i);cprintf("北");
			 }
  gotoxy(20, 23);cprintf("北北北北北北北北北北北北");
  gotoxy(52, 13);cprintf(" Next ->");
  gotoxy(52, 17);cprintf("Level ->");
  gotoxy(52, 19);cprintf("Score ->");

  textbackground(15);textcolor(4);
  gotoxy(62, 17);cprintf("%8d ",gamelevel+1);
  gotoxy(62, 19);cprintf("%8d ",score);
}

void gameplay()
{
  int gi=1;
  randomize();

  if( s1==0 )
    s1 = random(7)+ 1 ;
  else
    s1 = s2;

  randomize();
  while(1) {
    s2 = random(7)+ 1 ;
    if(s1 != s2)
      break;
	   }

  while(1) {

    switch( gi? s2 : s1 ) {

      case 1 : tbr.ar[0]= 501; tbr.ar[1]= 502;
	       tbr.ar[2]= 503; tbr.ar[3]= 403;
	       break;

      case 2 : tbr.ar[0]= 403; tbr.ar[1]= 503;
	       tbr.ar[2]= 502; tbr.ar[3]= 602;
	       break;

      case 3 : tbr.ar[0]= 500; tbr.ar[1]= 501;
	       tbr.ar[2]= 502; tbr.ar[3]= 503;
	       break;

      case 4 : tbr.ar[0]= 402; tbr.ar[1]= 502;
	       tbr.ar[2]= 503; tbr.ar[3]= 603;
	       break;

      case 5 : tbr.ar[0]= 501; tbr.ar[1]= 502;
	       tbr.ar[2]= 503; tbr.ar[3]= 603;
	       break;

      case 6 : tbr.ar[0]= 402; tbr.ar[1]= 502;
	       tbr.ar[2]= 602; tbr.ar[3]= 503;
	       break;

      case 7 : tbr.ar[0]= 502; tbr.ar[1]= 402;
	       tbr.ar[2]= 403; tbr.ar[3]= 503;

			  }
    if(gi) {
      textbackground(0);
      for(gi=10; gi<=14; ++gi) {
	gotoxy(63, gi);
	cprintf("        ");
			       }
      textbackground(s2);
      for(gi=0; gi<4; ++gi) {
	gotoxy(((tbr.ar[gi]/100) *2)+55, (tbr.ar[gi]%100)+10);
	cprintf("  ");
			    }
      gi=0;
	   }
    else
      break;
	   }
  tbr.shape = s1 * 10;
  tbr.color = s1;
}

void draw_erase_block( char doe )
{
  int i, dx, dy;

  textbackground( (doe =='D' ? tbr.color : 0) );

  for(i=0; i<4; ++i) {

    dx = ((tbr.ar[i]/100) * 2 )+ 22;
    dy = (tbr.ar[i]%100);

    if( dy < 3 ) continue;

    gotoxy(dx, dy);
    cprintf("  ");
		     }
}

int check( int c )
{
  int i;

  if( c==-1 ) {
    for(i=0; i<4; ++i) {
      tempbr[i] = tbr.ar[i] -100;
      if( tempbr[i] <0 )
	return 0;
      if( well[tempbr[i]%100][tempbr[i]/100] > 100 )
	return 0;
		       }
    tempbr[4] = tbr.shape;
    return 1;
	      }

  if( c==1 ) {
    for(i=0; i<4; ++i) {
      tempbr[i] = tbr.ar[i] +100;
      if( tempbr[i] > 999 )
	return 0;
      if( well[tempbr[i]%100][tempbr[i]/100] > 100 )
	return 0;
		       }
    tempbr[4] = tbr.shape;
    return 1;
	     }

  if( c==0 ) {
    switch( tbr.shape ) {

      case 10: tempbr[0]= tbr.ar[0] +1;  tempbr[1]= tbr.ar[1] +1;
	       tempbr[2]= tbr.ar[2] +100;tempbr[3]= tbr.ar[3] +300;
	       tempbr[4]=11;
	       break;

      case 11: tempbr[0]= tbr.ar[0] +99; tempbr[1]= tbr.ar[1] -2;
	       tempbr[2]= tbr.ar[2] -101;tempbr[3]= tbr.ar[3] -200;
	       tempbr[4]=12;
	       break;

      case 12: tempbr[0]= tbr.ar[0] -199; tempbr[1]= tbr.ar[1] +1;
	       tempbr[2]= tbr.ar[2] +100;tempbr[3]= tbr.ar[3] +100;
	       tempbr[4]=13;
	       break;

      case 13: tempbr[0]= tbr.ar[0] +99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] -99; tempbr[3]= tbr.ar[3] -200;
	       tempbr[4]=10;
	       break;

      case 20: tempbr[0]= tbr.ar[0] -2;  tempbr[1]= tbr.ar[1] -101;
	       tempbr[2]= tbr.ar[2];     tempbr[3]= tbr.ar[3] -99;
	       tempbr[4]= 21;
	       break;

      case 21: tempbr[0]= tbr.ar[0] +2;  tempbr[1]= tbr.ar[1] +101;
	       tempbr[2]= tbr.ar[2];     tempbr[3]= tbr.ar[3] +99;
	       tempbr[4]= 20;
	       break;

      case 30: tempbr[0]= tbr.ar[0] -98; tempbr[1]= tbr.ar[1] +1;
	       tempbr[2]= tbr.ar[2] +100;tempbr[3]= tbr.ar[3] +199;
	       tempbr[4]= 31;
	       break;

      case 31: tempbr[0]= tbr.ar[0] +98; tempbr[1]= tbr.ar[1] -1;
	       tempbr[2]= tbr.ar[2] -100;tempbr[3]= tbr.ar[3] -199;
	       tempbr[4]= 30;
	       break;

      case 40: tempbr[0]= tbr.ar[0] +99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] -101; tempbr[3]= tbr.ar[3] -200;
	       tempbr[4]= 41;
	       break;

      case 41: tempbr[0]= tbr.ar[0] -99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] +101; tempbr[3]= tbr.ar[3] +200;
	       tempbr[4]= 40;
	       break;

      case 50: tempbr[0]= tbr.ar[0] -98; tempbr[1]= tbr.ar[1] -100;
	       tempbr[2]= tbr.ar[2] -1;  tempbr[3]= tbr.ar[3] -1;
	       tempbr[4]= 51;
	       break;

      case 51: tempbr[0]= tbr.ar[0] -2;  tempbr[1]= tbr.ar[1] +99;
	       tempbr[2]= tbr.ar[2];     tempbr[3]= tbr.ar[3] -99;
	       tempbr[4]= 52;
	       break;

      case 52: tempbr[0]= tbr.ar[0] +2;  tempbr[1]= tbr.ar[1] +2;
	       tempbr[2]= tbr.ar[2] +101;tempbr[3]= tbr.ar[3] +99;
	       tempbr[4]= 53;
	       break;

      case 53: tempbr[0]= tbr.ar[0] +98; tempbr[1]= tbr.ar[1] -1;
	       tempbr[2]= tbr.ar[2] -100;tempbr[3]= tbr.ar[3] +1;
	       tempbr[4]= 50;
	       break;

      case 60: tempbr[0]= tbr.ar[0] +99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] -200;tempbr[3]= tbr.ar[3];
	       tempbr[4]= 61;
	       break;

      case 61: tempbr[0]= tbr.ar[0] -99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] +200;tempbr[3]= tbr.ar[3] -2;
	       tempbr[4]= 62;
	       break;

      case 62: tempbr[0]= tbr.ar[0] +99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] -99;tempbr[3]= tbr.ar[3] +101;
	       tempbr[4]= 63;
	       break;

      case 63: tempbr[0]= tbr.ar[0] -99; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2] +99;tempbr[3]= tbr.ar[3] -99;
	       tempbr[4]= 60;
	       break;

      case 70: tempbr[0]= tbr.ar[0]; tempbr[1]= tbr.ar[1];
	       tempbr[2]= tbr.ar[2]; tempbr[3]= tbr.ar[3];
	       tempbr[4]= 70;

			}

    for(i=0; i<4; ++i) {
      if(( tempbr[i] <0 ) || ( tempbr[i] >999))
	return 0;
      if( well[tempbr[i]%100][tempbr[i]/100] > 100 )
	return 0;
		       }
    return 1;
	     }

  if( c==2 ) {
    for(i=0; i<4; ++i) {
      tempbr[i] = tbr.ar[i] +1;
      if( tempbr[i]%100 >22 )
	return 0;
      if( well[tempbr[i]%100][tempbr[i]/100] > 100 )
	return 0;
		       }
    tempbr[4] = tbr.shape;
    return 1;
	     }
  return 0;
}

void modify_tetris()
{
  int i;

  for(i=0; i<4; ++i)
    tbr.ar[i] = tempbr[i];
  tbr.shape = tempbr[4];
}

void clear_row()
{
  int row = 22, ci, cj, sc=0;

  while( row > 2 ) {
    if( well[row][10] > 9 ) {
      for( cj=0; cj<10; ++cj ) {
	gotoxy(22+(2*cj), row);
	textbackground(0);
	cprintf("  ");
	sound( octave[cj] * 5 ) ;
	delay ( 50 ) ;
	nosound() ;
			       }
      ++sc;

      for( ci=row; ; ) {
	for( cj=0; cj<10; ++cj ) {
	  gotoxy(22+(2*cj), ci);
	  textbackground( (well[ci-1][cj]%100) );
	  cprintf("  ");
	  well[ci][cj] = well[ci-1][cj];
				 }
	well[ci][10] = well[ci-1][10];
	if(( well[ci-1][10] > 0 ) && ( ci>3 ))
	  --ci;
	else
	  break;
		       }
			    }
    else
      --row;
		   }

  switch(sc) {
    case 1: score+= 40 * (gamelevel+1);
	    break;
    case 2: score+= 100 * (gamelevel+1);
	    break;
    case 3: score+= 200 * (gamelevel+1);
	    break;
    case 4: score+= 500 * (gamelevel+1);
	     }

  if( hd_scr!=0 ) {
    score+= hd_scr;
    hd_scr= 0;
		  }
  textbackground(15);textcolor(4);
  gotoxy(62, 19);cprintf("%8d ",score);
}

int dropdown()
{
  int true= 1, di=0, i=0;
  int dcount= 0;
  char dc;
  hd_scr= 0;

  while( true ) {

    if( well[3][5] < 100 )
      draw_erase_block('D');
    else
      return 1;

    if(dcount == 0)
      dcount= 5* (10 - gamelevel);

    while( dcount > 0 ) {

      delay( 10 );
      if( kbhit() )  {
	dc = getch();
	switch(dc) {

	  case 'a':
	  case 'A': if( check(-1)==1 ) {
		      draw_erase_block('E');
		      modify_tetris();
		      draw_erase_block('D');
				       }
		    break;

	  case 'd':
	  case 'D': if( check(1)==1 ) {
		      draw_erase_block('E');
		      modify_tetris();
		      draw_erase_block('D');
				      }
		    break;

	  case 'w':
	  case 'W': if( check(0)==1 ) {
		      draw_erase_block('E');
		      modify_tetris();
		      draw_erase_block('D');
				      }
		    break;

	  case ' ': for (i = 5; i >= 0; --i ) {
		      sound ( octave[5] * 2 ) ;
		      delay ( 15 ) ;
					      }
		    nosound() ;
		    dcount= -1;
		    break;

	  case (char)27: return 1;

		   }
		     }
	dcount -= 1;
			 }

    if( check(2)==1 ) {
      if( dcount==-2 )
	hd_scr+=1;
      draw_erase_block('E');
      modify_tetris();
		      }
    else
      true = 0;
		}

    for(dcount=0; dcount < 4; ++dcount) {
      well[tbr.ar[dcount]%100][tbr.ar[dcount]/100] = 100 + tbr.color;
      well[tbr.ar[dcount]%100][10] +=1;
      if( well[tbr.ar[dcount]%100][10] == 10 )
	di = 1;
					}

    if(di)
      clear_row();

    return 0;
}

void main()
{
  textbackground(0);
  clrscr();
  _setcursortype(_NOCURSOR);
  initialise();
  mainpage();
  helppage();
  startpage();

  while(1) {
    gameplay();
    if( dropdown() )
      break;
	   }
  gameend();
}