/*
 AIR HOCKEY
 Done by:-
	  1.Sidharth
	  2.Rahul
	  3.Praveen

*/

#include<fstream.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<ctype.h>
#define pi 3.14
int level=6,arrow=1,num,point1=0,point2=0,dir=2,life1=3,life2=3;
int xb,yb,s=3,dy=0;
void coverpage();  //defined
void displayabout(); //defined
void instruction(); //defined
void mainmenu();  //defined
void submenu();   //defined
void gameplatform();//defined
void drawborder(); //defined
void creatball(int,int);  //defined
void eraseball(int,int);  //defined
void player1pad(int,int); //defined
void player2pad(int,int); //defined
void erasepad1(int); //defined
void erasepad2(int); //defined
void quitscreen();
void update1();//defined
void playerspage();//defined
void checkplayer();//defined
void checkstart();



class player
{
   int s[20],top;
 int topscore;
  int p_id;
  char p_name[20];
  int  p_age;
  char p_gender;
  public:
  player()
	{
	  top=-1;
	}
   void addscore(int);//defined
   void getdata();    //defined noproblem
   void display();    //defined noproblem
   void displayl(int,int);//defined
   void update();     //defined noproblem
   int ret() { return p_id;} //defined  noproblem
   int rettopscore();//defined
}p,current;

   void updateboard(player);  //defined
   void disp_data();//defined

 int player::rettopscore()
 {
   if(top==-1)
	  return 0;
   else
	  return s[0];
   }
 void player::getdata()
 {
    int k;
    gotoxy(30,3);
    cout<<"²²²±±±°°° Player sign up °°°±±±²²²";
    gotoxy(20,7);
    cout<<"Enter the player name: ";
    gets(p_name);
    gotoxy(20,9);
    cout<<"Enter age: ";
    cin>>p_age;
    gotoxy(20,11);
    cout<<"Enter gender (M/F): ";
    cin>>p_gender;
    ifstream f("pdetail.dat",ios::binary);
	  f.seekg(0,ios::end);
	  int l=f.tellg();
	  if(l==0)
	  {
	    k=1000;
	  }
	  else
	  {
	    int flag=1;
	    player play;
	    while(1)
	  {
	    flag=1;
	    f.seekg(0);
	    f.clear();
	    k=random(9000)+1000;
	    while(f)
	    {
		 f.read((char*)&play,sizeof(player));
		if(k==play.ret())
		flag=0;
	    }
	  if(flag==1)
	   {
	    p_id=k;
	    break;
	   }
	 }
	 }
    p_id=k;
    f.close();
   gotoxy(10,13);
   cout<<"Congratulations your id number has been generated....";
   cout<<"\n          Your id number is :"<<p_id;
   cout<<"\n               press any key to go to main menu......;)";
   ofstream f2("pdetail.dat",ios::app|ios::binary);
			f2.write((char*)&p,sizeof(player));
			f2.close();
			getch();
			mainmenu();

   }
void player::display()
{
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"..\\bgi");
   settextstyle(3,0,5); setcolor(13);
   outtextxy(150,50,"PLAYER DETAILS");
   settextstyle(1,0,2);
   setcolor(2);
   outtextxy(75,150,"Player ID : ");
   char A[20];
   sprintf(A,"%d",p_id);
   outtextxy(200,150,A);
   outtextxy(75,200,"Player name : ");
   outtextxy(270,200,p_name);
   outtextxy(75,250,"Player gender : ");
   if(p_gender=='m'||p_gender=='M')
	sprintf(A,"Male");
   else
	sprintf(A,"Female");
   outtextxy(290,250,A);
   outtextxy(75,300,"Player age : ");
   sprintf(A,"%d",p_age);
   outtextxy(250,300,A);
   settextstyle(3,0,3);
   setcolor(12);
   outtextxy(440,120,"SCORE CARD");
   settextstyle(3,0,2);
   setcolor(2);
   for(int i=0;i<=top;i++)
   {
	sprintf(A,"Score %d : %d",(i+1),s[i]);
	outtextxy(450,(150+(i*20)),A);
  }
  settextstyle(1,0,3);
  setcolor(14);
  outtextxy(100,350,"Press any key to goto mainmenu....;)");
  getch();
  mainmenu();
}
void player::displayl(int a,int b)
{
   char A[100];
   sprintf(A,"%d",p_id);
   outtextxy(a-10,b,A);
    sprintf(A,"%s",p_name);
   outtextxy(a+75,b,A);
    sprintf(A,"%c",p_gender);
   outtextxy(a+250,b,A);
   sprintf(A,"%d",p_age);
   outtextxy(a+385,b,A);
   sprintf(A,"%d",s[0]);
   outtextxy(a+530,b,A);
   }

void update1()
{
   clrscr();
   int check,flag=0;
   gotoxy(25,5);
   cout<<"²²²±±±°°° Player updation °°°±±±²²²";
   gotoxy(10,8);
   cout<<"Enter your player id: ";
   cin>>check;
   ifstream f("pdetail.dat",ios::binary);
	while(f)
	{
	  f.read((char*)&p,sizeof(player));
	  if(f&&p.ret()==check)
	 {
	  flag=1;
	  break;
	 }
	 }
   f.close();
   if(!flag)
   {
	gotoxy(30,10);
	cout<<"Sorry, no such player record is stored....";
	cout<<"\n                   press any key to goto main menu....";
	getch();
	clrscr();
	mainmenu();
   }
  else
    p.update();//player in current login
}
 void player::update()
   { int ch;
    gotoxy(10,10);
    cout<<"The folowing are the player details:-\n";
    cout<<"            1.Player name  : "<<p_name<<"\n";
    cout<<"            2.Player id    : "<<p_id<<"\n";
    cout<<"            3.Player age   : "<<p_age<<"\n";
    cout<<"            4.Player gender: "<<p_gender<<"\n";
    gotoxy(5,17);
    cout<<"What do you want to change :";
    cin>>ch;
    char name[20];int n;
    switch(ch)
    {
	 case 1:
	 cout<<"\nEnter the new name :";
	 gets(name);
	 strcpy(p_name,name);
	 break;
	 case 2:
	 cout<<"\nSorry you cannot change your id.";
	 break;
	 case 3:
	 cout<<"\nEnter new age :";
	 cin>>n;
	 p_age=n;
	 break;
	 case 4:
	 char g;
	 cout<<"\nEnter the gender :";
	 cin>>g;
	 p_gender=g;
	 break;
	 default:
	 cout<<"Sorry invalid choice...";
	 }
	 _setcursortype(_NOCURSOR);
    if(ch>=1&&ch<=4&&ch!=2)
    {
	  player d;
	  ofstream f2("edit.dat",ios::binary);
	  ifstream f1("pdetail.dat",ios::binary);
	  while(f1&&f2)
	  {
	  f1.read((char*)&d,sizeof(player));
	  if(f1&&d.ret()!=p_id)
	   f2.write((char*)&d,sizeof(player));
	  else if(f1)
	    f2.write((char*)&p,sizeof(player));
	}
	f2.close();
	f1.close();
	int re=remove("pdetail.dat"); if(!re){
	rename("edit.dat","pdetail.dat");}

	cout<<"The player details are successfully updated.";
	}
   cout<<"\nPress any key to goto main menu.";
   getch();
   mainmenu();
   }
void player::addscore(int a)
{
   int i,j,pos=0,flag=0,temp;
   s[++top]=a;
   for(i=1;i<=top;i++)
   {  temp=s[i];
	 j=i-1;
	while(j>=0 && s[j]<temp)
	{
	  s[j+1]=s[j];
	  j--;
	}
	s[j+1]=temp;
   }
  /* if(flag)
    {
    for(i=top;i>=pos;i--)
	s[i+1]=s[i];
	 s[pos]=a;
	 top++;
    }
  else
   s[++top]=a;*/
  ifstream f("pdetail.dat",ios::binary);
  ofstream f1("pnew.dat",ios::binary);
  player c;
   while(f1&&f)
   {
    f.read((char*)&c,sizeof(player));
    if(f&&c.ret()!=p.ret())
	 f1.write((char*)&c,sizeof(player));
    else if(f)
	 f1.write((char*)&p,sizeof(player));
   }
  f.close();
 f1.close();
 int k=remove("pdetail.dat");
 if(!k)
   rename("pnew.dat","pdetail.dat");

}

void updateboard(player k)
{
   fstream f("leader.dat",ios::in|ios::out|ios::binary|ios::app);
   player t;
   int flag=0;
   ofstream f1("nlead.dat",ios::binary);
   while(f)
   {
	f.read((char*)&t,sizeof(player));
	if(f)
	   {
		   if(f&&t.rettopscore()<=k.rettopscore()&&!flag&&k.ret()!=t.ret())
			{
			  flag=1;
			  f1.write((char*)&p,sizeof(player));
			  f1.write((char*)&t,sizeof(player));
			}
	    else if(k.ret()!=t.ret())
			f1.write((char*)&t,sizeof(player));
	   }
   }
   if(flag==0)
   {
	  f1.write((char*)&p,sizeof(player));
    }

	f.close();
	 f1.close();
  int test=remove("leader.dat");
  if(test==0)
    rename("nlead.dat","leader.dat");
}
void disp_data()
{
   int gdrive=DETECT,gmode;
   initgraph(&gdrive,&gmode,"..\\bgi");
   cleardevice();
   settextstyle(4,0,6);
   setcolor(4);
   outtextxy(100,70,"LEADER BOARD");
   ifstream f("leader.dat",ios::binary);
   player r;
   int i=0;
   setcolor(14);
   settextstyle(3,0,2);
   outtextxy(70,150,"ID");
   outtextxy(140,150,"NAME");
   outtextxy(280,150,"GENDER");
   outtextxy(440,150,"AGE");
   outtextxy(560,150,"SCORE");
   while(f)
   {
	setcolor(i+3);
	f.read((char*)&r,sizeof(player));
	if(f)
	  r.displayl(60,(180+(i*30)));
    i++;
  }
 f.close();
 getch();
 closegraph();
 mainmenu();
}
    enum lvl{
		unbeatable=1,
		veryhard,
		hard,
		normal,
		easy,
		veryeasy
		};
void checkplayer()
{clrscr();
   int check,flag=0;
   gotoxy(25,5);
   player l;
   cout<<"²²²±±±°°° Player details °°°±±±²²²";
   gotoxy(10,8);
   cout<<"Enter your player id: ";
   cin>>check;
   ifstream f("pdetail.dat",ios::binary);
	while(f)
	{
	  f.read((char*)&l,sizeof(player));
	  if(f&&l.ret()==check)
	 {
	  flag=1;
	  break;
	 }
	 }
   f.close();
   if(!flag)
   {
	gotoxy(30,10);
	cout<<"Sorry, no such player record is stored....";
	cout<<"\n                   press any key to goto main menu....";
	getch();
	clrscr();
	mainmenu();
   }
  else
    l.display();//player in current login
 }
void playerpage()
{
  int driver=DETECT,mode;
  char ch;
  initgraph(&driver,&mode,"..\\bgi");
  cleardevice();
  int arrow1=1;
  while(1)
{
   settextstyle(1,0,5);setcolor(13);
   outtextxy(20,40,"Players Page");
   settextstyle(3,0,3);
   setcolor(14);
   if(arrow1==1) outtextxy(100,180,"-->");
   if(arrow1==2) outtextxy(150,230,"-->");
   if(arrow1==3) outtextxy(200,280,"-->");
   if(arrow1==4) outtextxy(250,330,"-->");
   if(arrow1==5) outtextxy(300,380,"-->");
 setcolor(6);
   outtextxy(150,180,"Player signup");
   setcolor(12);
   outtextxy(200,230,"Player details update");
   setcolor(10);
   outtextxy(250,280,"Players details");
  setcolor(4);
  outtextxy(300,330,"leader board");
  setcolor(8);
  outtextxy(350,380,"Main menu");

	 {
		ch=getch();
		if(ch==13)
		{
		   if(arrow1==1) ch='p';
		   if(arrow1==2) ch='u';
		   if(arrow1==3) ch='d';
		   if(arrow1==4) ch='l';
		   if(arrow1==5) ch='m';
		}

		if(ch=='p')
		 {   cleardevice();
			closegraph();
			p.getdata();

		 }
		  if(ch=='u')
		 {
			cleardevice();
			closegraph();
			update1();
		 }
		 if(ch=='d')
		 {
		    cleardevice();
		    closegraph();
		    checkplayer();
		 }

		if(ch=='l')
		 {
		    cleardevice();
		    closegraph();
		    disp_data();
		    getch();
		 }
	    if(ch=='m')
	    {
		 cleardevice();
		 closegraph();
		 mainmenu();
	    }
		if(ch==80)
		 {
		   arrow1++;
		  if(arrow1>=6)
		  arrow1=1;
		 }
	    if(ch==72)
		 {
		   arrow1--;
		   if(arrow1<=0)
		   arrow1=5;
		 }


	    cleardevice();
	  } //end of if

    } //end of while
}//end of function

void checkstart()
{
  int dot=1;
   char c;
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"..\\bgi");
	settextstyle(1,0,3);
	setcolor(11);
	outtextxy(50,50,"Do you have an account?");
	setcolor(15);
	rectangle(100,100,120,120);

	if(dot==1)
	 {
	  setfillstyle(SOLID_FILL,12);
	  floodfill(110,110,15);
	 }
	 setcolor(15);
	 rectangle(300,100,320,120);
	if(dot==2)
	 {
	  setfillstyle(SOLID_FILL,12);
	  floodfill(310,110,15);
	 }
	 setcolor(10);
	 settextstyle(3,0,3);
	 outtextxy(130,120,"YES");
	 setcolor(4);
	 outtextxy(330,120,"NO");

   while(1)
   {
	if(kbhit())
	 {
	cleardevice();
	c=getch();
	if(c==75)
	{
	dot++;
	if(dot==3)
	dot=1;
	}
	if(c==77)
	{
	  dot--;
	  if(dot==0)
	  dot=2;
	}
	settextstyle(1,0,3);
	setcolor(11);
	outtextxy(50,50,"Do you have an account?");
	setcolor(15);
	rectangle(100,100,120,120);

	if(dot==1)
	 {
	  setfillstyle(SOLID_FILL,12);
	  floodfill(110,110,15);
	 }
	 setcolor(15);
	 rectangle(300,100,320,120);
	if(dot==2)
	 {
	  setfillstyle(SOLID_FILL,12);
	  floodfill(310,110,15);
	 }
	 setcolor(10);
	 settextstyle(3,0,3);
	 outtextxy(130,120,"YES");
	 setcolor(4);
	 outtextxy(330,120,"NO");

    if(c==13)
    {
	 if(dot==1)
	  {
		  int id=0,n;
		  outtextxy(100,350,"Please enter your id number: ");
		  for(int a=1;a<=4;a++)
		{
		   c=getch();
		   n=toascii(c)-48;
		   id=id+(pow(10,(4-a))*n);
		   char d[2];
		   sprintf(d,"%d",n);
		   outtextxy(500+(a*20),350,d);
		}
		 ifstream f("pdetail.dat",ios::binary);
		 int flag=0;
		 while(f)
		  {
		    f.read((char*)&p,sizeof(player));
		    if(p.ret()==id)
		    {
			 flag=1;
			 break;
		    }
		  }
		 if(flag==1)
		 submenu();
		  if(flag==0)
		  {  setcolor(14);
		    outtextxy(100,380,"Sorry no such record exist. You must sign in...");
		    outtextxy(100,400,"Please wait you will be directed to sign up page.");
		    delay(5000);
		    cleardevice();
		    closegraph();
		    p.getdata();
		 }
		 }


		if(dot==2)
		  {
			outtextxy(100,370,"Please wait you will be directed to sign up page.");
			delay(5000);
			cleardevice();
			closegraph();
		    p.getdata();
		   }

	}
  }//for kbhit
 }//for while
}//end of functon
void main()
{
 _setcursortype(_NOCURSOR);
 coverpage();
  _setcursortype(_NOCURSOR);
 mainmenu();
 gameplatform();
 closegraph();
}

void coverpage()
{
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"..\\bgi");
   outtextxy(50,130,"  Press any key to continue...");
   settextstyle(3,0,9); setcolor(12);
   outtextxy(65,140,"AIR HOCKEY");
   settextstyle(4,0,3); setcolor(10);
   outtextxy(250,240,"The Game " ); gotoxy(28,25);
   settextstyle(1,0,3); setcolor(9);
   outtextxy(120,330,"By Praveen,Rahul,and Sidharth");

   getch();
   closegraph();
}

void mainmenu()
{
   int driver=DETECT,mode;
   initgraph(&driver,&mode,"..\\bgi");
   char ch;
   while(1)
{
    settextstyle(4,0,6);setcolor(3);
    outtextxy(20,40,"The Game: AIR HOCKEY");
    settextstyle(1,0,2);setcolor(9);
    outtextxy(5,140,"To change options press arrow keys and to select press enter");
    settextstyle(3,0,3);
    setcolor(14);
	 if(arrow==1) outtextxy(100,180,"-->");
	 if(arrow==2) outtextxy(150,220,"-->");
	 if(arrow==3) outtextxy(200,260,"-->");
	 if(arrow==4) outtextxy(240,300,"-->");
	 if(arrow==5) outtextxy(290,340,"-->");
	 if(arrow==6) outtextxy(340,380,"-->");
   setcolor(6);
   outtextxy(150,180,"Single Player");
   setcolor(12);
   outtextxy(200,220,"Multi player");
   setcolor(4);
   outtextxy(250,260,"Quit");
   setcolor(9);
   outtextxy(290,300,"Instruction");
   setcolor(13);
   outtextxy(340,340,"About");
   setcolor(7);
   outtextxy(390,380,"Player Page");

		{
		ch=getch();
		if(ch==13)
		{
		  if(arrow==1) ch='s';
		  if(arrow==2) ch='m';
		  if(arrow==3) ch='q';
		  if(arrow==4) ch='i';
		  if(arrow==5) ch='a';
		  if(arrow==6) ch='h';
		}

	  if(ch=='q')
		 {  cleardevice();
		    closegraph();
		    quitscreen();
		    delay(1000); exit(0);
		 }
	 if(ch=='s')
		 {
		  num=1;
		  cleardevice();
		  closegraph();
		  checkstart();
		  break;
		 }
	  if(ch=='m') {num=2; cleardevice();closegraph(); break; }
	  if(ch=='a')
	  {
		cleardevice();
		displayabout();
		getch();
		cleardevice();
	  }
	  if(ch=='i')
	  {
	   cleardevice();
	   instruction();
	   cleardevice();
	   }
	 if(ch=='h')
	 {
	   cleardevice();
	   closegraph();
	   playerpage();
	   }

	 if(ch==80)
	  {
	   arrow++;
	  if(arrow>6)
	  arrow=1;
	  }
	  if(ch==72)
	  { arrow--;
	  if(arrow<=0)
	  arrow=6;
	  }


	cleardevice();
	}

  };
}

void submenu()
{



   int gdrive=DETECT,gmode;
   initgraph(&gdrive,&gmode,"..\\bgi");
    _setcursortype(_NOCURSOR);
   char dif[12],ch;
   strcpy(dif,"Easy");
   int arrow=1;
   while(1){ setbkcolor(0);
    settextstyle(3,0,4);
    setcolor(5);
  outtextxy(100,100,"Let's Start Playing! #GameIn C++");
    settextstyle(1,0,2);
    setcolor(14);
    if(arrow==1) outtextxy(220,140,"-->");
    if(arrow==2) outtextxy(200,184,"-->");
    setcolor(9);
   outtextxy(270,140,"Start game"); setcolor(3);
    outtextxy(250,184,"Difficulty:");
   setcolor(14); gotoxy(45,13);cout<<dif;

   if(kbhit())
   {
	 ch=getch();
	 if(ch==13)
	 {
	  if(arrow==1) ch='s';
	  if(arrow==2) ch='d';}
	 if(ch=='d') { level--; if(level==0) level=6;  }
	 if(ch=='s')
	 {
	 cleardevice();
	 closegraph();
	 gameplatform();
	 break;}
	 if(level==veryeasy) {strcpy(dif,"Very Easy"); s=1;dy=3;}
	 if(level==easy) {strcpy(dif,"Easy");s=1;dy=3;}
	 if(level==normal) {strcpy(dif,"Normal");s=2;dy=2;}
	 if(level==hard) {strcpy(dif,"Hard");s=2;dy=2;}
	 if(level==veryhard) {strcpy(dif,"Very Hard");s=3;dy=1;}
	 if(level==unbeatable) {strcpy(dif,"Unbeatable");s=3;dy=1;}
	 if(ch==80){
	 arrow++;
	 if(arrow>2) arrow=1;}
	 if(ch==72)
	{ arrow--;
	 if(arrow<1) arrow=2;}
	 cleardevice();
   }
   };
}
void displayabout()
{

  setcolor(5);
  settextstyle(1,0,4);
  outtextxy(200,100,"ABOUT THE GAME");
  setcolor(12);
  settextstyle(1,0,1);
  outtextxy(20,150,"Welcome to the world of air hockey. Unlike other usual hockey games");
  outtextxy(20,175,"the speciality of this game is that the disc which is usually used");
  outtextxy(20,200,"the speciality of this game is that the disc which is usually used");
  outtextxy(20,225,"play the game is not here. This wonderful game would be helpful");
  outtextxy(20,250,"for one to pass time and forget loneliness. ");
  outtextxy(20,275,"Got excited!!!!!! No more reading.... Enjoy the game;)");
  settextstyle(3,0,2);
  setcolor(4);
  outtextxy(100,370,"Press any key to go to menu....:)");
  }
 void instruction()
 {
  setcolor(2);
  settextstyle(4,0,6);
  outtextxy(170,10,"Instruction");
  settextstyle(1,0,2);
  setcolor(9);
  outtextxy(10,100,"Hi player(s), the rules of the game are simple and easy.");
  outtextxy(10,125,"All that you need to do is act as role of goal keeper.");
  outtextxy(10,150,"That is to stop the puck from going to the other side.");
  outtextxy(10,175,"If it goes into your goal, your opponent will gain a point.");
  setcolor(11);
  outtextxy(10,200,"The moves are as follow:-");
  setcolor(15);
  line(110,227,535,227);
  line(325,227,325,312);
  line(110,255,535,255);
  line(110,227,110,312);
  line(535,227,535,312);
  line(110,312,535,312);
  setcolor(10);
  outtextxy(120,230,"Player-1(RHS)");
  setcolor(14);
  outtextxy(360,230,"Player-2(LHS)");
  setcolor(10);
  outtextxy(115,255,"Up = up arrow");
  outtextxy(115,280,"Down = down arrow");
  setcolor(14);
  outtextxy(360,255,"Up = W (or) w");
  outtextxy(360,280,"Down = S (or) s");
  setcolor(9);
  outtextxy(0,310,"If the mode is single player, then you're Player 1.");
  setcolor(14);
  outtextxy(0,330,"(NOTE:In any one of the above modes, if a player fails to hit");
  outtextxy(0,350,"the ball his/her life will be decremented by one unit. If");
  outtextxy(0,370,"the player loses all the lives he is declared as out.");
  setcolor(13);
  outtextxy(10,400,"  Enjoy gaming.... press any key to go to menu....");
  getch();}

void drawborder()
{  setbkcolor(5);
int t,co1,co2;
 setcolor(2);
 line(319,6,319,471);
 for(int j=0;j<4;j++)
 {
  circle(319,239,50+j);
  circle(319,239,100+j);
  arc(8,7,270,360,45+j);
  arc(8,7,270,360,65+j);
  arc(631,7,180,270,45+j);
  arc(631,7,180,270,65+j);
  arc(631,475,90,180,45+j);
  arc(631,475,90,180,65+j);
  arc(8,470,360,90,45+j);
  arc(8,470,360,90,65+j);
 }
 if(num==1)
 {
    co1=480;
   int l1;
   for(l1=1;l1<=life1;l1++)
		{
		   co1+=25;
		   setfillstyle(SOLID_FILL,8);
		   setcolor(15);
		   circle(co1,10,10);
		   floodfill(co1,10,15);
		}
   for(int e1=l1;e1<=3;e1++)
   {
	 co1+=25;
	 setfillstyle(SOLID_FILL,5);
	 setcolor(15);
	 circle(co1,10,10);
	 floodfill(co1,10,15);
 }
 }
if(num==2)
{
   co2=80;  int l2;
		for(l2=1;l2<=life2;l2++)
		{
		   co2+=25;
		   setfillstyle(SOLID_FILL,8);
		   setcolor(15);
		   circle(co2,10,10);
		   floodfill(co2,10,15);
		  }
		for(int e2=l2;e2<=3;e2++)
		  {
		co2+=25;
		setfillstyle(SOLID_FILL,5);
		setcolor(15);
		circle(co2,10,10);
		floodfill(co2,10,15);
		  }
		 co1=480; int l1;
		 for(l1=1;l1<=life1;l1++)
		{
		   co1+=25;
		   setfillstyle(SOLID_FILL,8);
		   setcolor(15);
		   circle(co1,10,10);
		   floodfill(co1,10,15);
		 }
		  for(int e1=l1;e1<=3;e1++)
		  {
			co1+=25;
			setfillstyle(SOLID_FILL,5);
			setcolor(15);
			circle(co1,10,10);
			floodfill(co1,10,15);
		  }
  }
  for(int i=0;i<=4;i++)
	  {
	   if(num==1)
		{
		 line(3+i,2,3+i,475);
		 line(3,2+i,370,2+i);
		 line(570,2+i,636,2+i);
		 }
	   else if(num==2)
	   {
		line(3+i,2,3+i,180);
		line(3+i,280,3+i,475);
		line(3,2+i,70,2+i);
		line(270,2+i,370,2+i);
		line(570,2+i,636,2+i);

	    }

	   line(636-i,2,636-i,180);
	   line(636-i,280,636-i,475);
	   line(3,475-i,636,475-i);
	  }

		 setcolor(15);
		 setfillstyle(SOLID_FILL,5);
		 rectangle(370,0,470,20);
		 floodfill(400,10,15);
		 char A[20];
		 setcolor(14);
		 sprintf(A,"Score: %d",point1);
		 settextstyle(1,0,1);
		 outtextxy(380,0,A);

	  if(num==2)
		{setcolor(15);
		 setfillstyle(SOLID_FILL,5)
		 ;
		 rectangle(170,0,270,20);
		 floodfill(200,10,15);
		 char B[20];
		 setcolor(14);
		 sprintf(B,"Score: %d",point2);
		 settextstyle(1,0,1);
		 outtextxy(180,0,B);
		 }
  for(t=0;t<=7;t++)
    line(631+t,180,631+t,280);

   }

void creatball(int i,int j)
{
   setcolor(4);
   setfillstyle(SOLID_FILL,12);
    circle(i,j,10);
  floodfill(i,j,4);
}
void eraseball(int i,int j)
{  int x,y;
  if(dir==1)  {x=-1;y=1;}
  if(dir==-1) {x=1;y=1;}
  if(dir==2)  {x=1;y=-1;}
  if(dir==-2) {x=-1;y=-1;}
  for(int h=0;h<=s;h++)
  {
  i=xb+(x*h);
  j=yb+(y*h);
  setcolor(5);
  setfillstyle(SOLID_FILL,5);
  circle(i,j,13);
  floodfill(i,j,5);
  }
}

void player2pad(int i,int c)
{  c=1;
   setcolor(c);
   int brick2[10]={10,i,25,i,25,i+75,10,i+75,10,i};
   setfillstyle(11,c); fillpoly(4,brick2);
}
void erasepad2(int i)
 {
   setcolor(0);
   int brick2[10]={10,i,25,i,25,i+75,10,i+75,10,i};
   setfillstyle(11,0); fillpoly(4,brick2);
   }
   void erasepad1(int i)
   {
   setcolor(0);
   int brick1[10]={629,i,629,i+75,614,i+75,614,i,629,i};
   setfillstyle(11,0); fillpoly(4,brick1);

   }

void quitscreen()
 {
  int driver=DETECT,mode;char ch[10];
   initgraph(&driver,&mode,"C:\\TurboC3\\bgi");
   setcolor(5);
   gotoxy(20,9);
   cout<<" Have a nice day!!!!! ";
   settextstyle(1,0,3);
   outtextxy(100,175,"THANK YOU FOR PLAYING AIR HOCKEY.......");
   settextstyle(3,0,3);
   outtextxy(100,250,"PLEASE RATE US FROM 1-10");
   outtextxy(99,305,"-->");
   gets(ch);
   outtextxy(175,305,ch);
   setcolor(12);
   outtextxy(275,350," THANK YOU ");

 }


void player1pad(int i,int c)
{  c=1;
   setcolor(c);
   int brick1[10]={629,i,629,i+75,614,i+75,614,i,629,i};
   setfillstyle(11,c); fillpoly(4,brick1);
}

void gameplatform()
{
   int gdrive=DETECT,gmode;
   initgraph(&gdrive,&gmode,"..\\bgi");
   cleardevice();
   int j,k,g,h=0,touch=0,bou=15,touch2=0,bou2=0;
   int brick2,brick1;
   double slope=-1;
   drawborder();   setcolor(9);
   xb=g=319; yb=k=300;
   brick1=brick2=196;
   player1pad(brick1,5); if(num!=1)player2pad(brick2,5);
    creatball(xb,yb);
    int i=brick1;j=brick2;
    int x,y;
    drawborder();
   while(1)
   {
	if(kbhit())
  {   if(num!=1)
	  if(j!=brick2)
	  {
	 erasepad2(brick2);
	 erasepad2(brick2+1);
	 player2pad(j,5);
	 brick2=j;
	 }
	 if(i!=brick1)
	 {
	 erasepad1(brick1);
	 erasepad1(brick1+1);
	 player1pad(i,5);
	 brick1=i;
	 }

	  char ch=getch();
	x=0;y=0;
	  if(ch==72) x=-5;
	  else if(ch==115) y=5;
	  else if(ch==80) x=5;
	  else if(ch==119) y=-5;
	  else if(ch==27) break;
    i=i+x;
    j=j+y;
	 if(i<9) i=9;
	 if(i>394) i=394;
	 if(j<9) j=9;
	 if(j>394) j=394;
  }
  if(num==1)
   bou2=0;
if(g>=628-15-10||g<=8+15+10)
 {
	 if(g>=628-10) {life1--;}
	 if(life1==0)
	 {
	  outtextxy(220,200,"OUT");
	  delay(1000);
	  break;
	  }

	if(xb>=628-10&&(yb>i+75||yb<i))
	{

	    setcolor(3);
	    settextstyle(8,0,0);
	    if(num==1&&life1<=0||(yb>=180&&yb<=280))
		{
		    outtextxy(220,200,"OUT");
		    delay(1000);
		    break; //to break the gaint infinite while loop
		}

	    if(num==2)
		{   point2++;
		    if(point2==7||life1<=0)
			 {
			 outtextxy(220,200,"player 2 wins");
			 delay(1000);
			 break;
			 }
		}
	}

    if(num==2)
	  {
	  if(g<=8+10&&(yb>j+75||yb<j))

		    {
			 setcolor(3);
			 if((yb>j+80||yb<j-5)&&g<=8+11&&num==2)
			 {
				life2--;
			 }
			 settextstyle(8,0,0);
			 point1++;
			 if(point1==7||life2<=0||(yb>=180&&yb<=280))
			 {
				outtextxy(220,200,"player 1 wins");
				delay(1000);
				break;
			 }
		    }

	  if(g<=8+10)
	  life2--;
	  if(life2<=0)
	   {
	   outtextxy(220,200,"player 1 wins");
	   delay(1000);
	   break;
	   }

	 player2pad(brick2,5);
	  }

	 if(g>=628-15-10)
	 {
	    if(yb<=i+75&&yb>=i)
		  {
		  touch=1;
		  point1++;
		  }
	 }
	 if(g<=8+15+10&&num==2)
	{
	   if(yb<=j+75&&yb>=j)
	   {touch2=1;
	   point2++; }
	}

}
bou=0;bou2=0;
	 if(touch2)
	 {
	    bou2=15;
	    touch2=0;
	 }
	 if(touch)
	{
	    bou=15;
	    touch=0;
	}


  if(g>=628-bou-10||g<=8+bou2+10||k>=469-10||k<=7+10)
  {
	eraseball(g,k);
	slope=-slope;
	eraseball(xb,yb);
	 if(k>=469-10)
	 {
	 if(g>=xb)
	  dir=1;
	 else
	 dir=-1;
	k--;
	 }
	 if(k<=7+10)
	 {
	if(g<=xb)
	   dir=2;
	else
	  dir=-2;
	  k++;
	 }
	 if(g<=8+bou2+10)
	 {
	if(k>=yb)
	   dir=-2;
	else
	   dir=1;
	g++;
	 }
	 if(g>=628-bou-10)
	 {

	if(k>=yb)
	  dir=2;
	else
	  dir=-1;
	 g--;
	 }
   sound(300);
   delay(4);
   nosound();
   }
  if(h==1)
  yb=k;xb=g;
	if(dir==1)
	   {
		for(k=yb-s;k<=470-10&&k>=7+10;k-=5)
		  {
		  for(g=xb+s;g>=8+10&&g<=628-10;g+=5)
			if(k==(int)(slope*(g-xb)+yb))
			 {
			    eraseball(g,k);
			    eraseball(xb,yb);
			    creatball(g,k);
			    delay(dy);
			    break;
			 }
		   break;
		 }
	  }
  if(dir==-1)
	{
	   for(k=yb-s;k<=470-10&&k>=7+10;k-=5)
		 {
		  for(g=xb-s;g>=8+10&&g<=628-10;g-=5)
			if(k==(int)(slope*(g-xb)+yb))
			 {
			 eraseball(xb,yb);
			 creatball(g,k);
			 delay(dy);
			 break;
			 }
		 break;
		 }
	}
	if(dir==2)
	 {
	    for(k=yb+s;k<=470-10&&k>=7+10;k+=5)
		 {
		  for(g=xb-s;g>=8+10&&g<=628-10;g-=5)
			 if(k==abs((int)(slope*(g-xb)+yb)))
			 {
			    eraseball(xb,yb);
			    creatball(g,k);
			    delay(dy);
			    break;
			}
	   break;
		}
	 }
	 if(dir==-2)
	 {
	    for(k=yb+s;k<=470-10&&k>=7+10;k+=5)
		 {
		 for(g=xb+s;g>=8+10&&g<=628-10;g+=5)
			if(k==(int)(slope*(g-xb)+yb))
			  {
			  eraseball(xb,yb);
			  creatball(g,k);
			  delay(dy);
			  break;
			 }
		    break;
		 }
	 }

    player1pad(brick1,5);
    if(num==2)
    player2pad(brick2,5);
    h=1;
   drawborder();
  };
cleardevice();
closegraph();
p.addscore(point1);
updateboard(p);
point1=point2=0;
life1=life2=3;
mainmenu();
}


