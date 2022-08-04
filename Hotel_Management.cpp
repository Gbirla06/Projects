//In turbo C++ version
#include<iostream.h>
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
fstream f1,f2,f3,f4,f5;
class HOTEL
 {
  char array[100];
  struct booking_data
  {
    long charge;
    int room_type,room_no;
    char name[25],address[75],phone[20],date[25];
  }book;
  public:
  void booking();
  void map();
  void view_data();
  void check_out();
  void view_all();
  void restaurent();
 }H;
int dekho;
void main()
{
 int gd=DETECT,gm,i;
 initgraph(&gd,&gm,"../bgi");
 setbkcolor(LIGHTBLUE);
 setcolor(YELLOW);
 settextstyle(7,0,5) ;
 delay(600);
 outtextxy(215,50,"WELCOME");        delay(600);
 outtextxy(285,150,"TO");            delay(600);
 outtextxy(240,250,"HOTEL");         delay(600);
 outtextxy(160,350,"ROYAL PALACE");  delay(600);
 for(i=2;i<=14;i++)
 { setcolor(i);
   outtextxy(215,50,"WELCOME");        delay(30);
   outtextxy(285,150,"TO");            delay(30);
   outtextxy(240,250,"HOTEL");         delay(30);
   outtextxy(160,350,"ROYAL PALACE");  delay(30);
 }
 getch(); cleardevice();
 setcolor(YELLOW);
 for(i=0;i<=500;i++){ circle(320,250,i);delay(3);}
 setcolor(MAGENTA);
 for(i=500;i>0;i--) { circle(320,250,i);delay(3);}
 delay(100);
 H.map();
 LABEL :
 cleardevice();
 setbkcolor(BLACK);
 setcolor(WHITE);
 settextstyle(7,0,3);
 outtextxy(190,40,"SELECT YOUR OPTION");
 outtextxy(260,130,"BOOKING");
 outtextxy(260,170,"VIEW MAP");
 outtextxy(260,210,"VIEW DATA");
 outtextxy(260,250,"CHECK OUT");
 outtextxy(260,290,"VIEW ALL");
 outtextxy(260,330,"RESTAURENT");
 outtextxy(260,370,"EXIT");
 int x=250,y=123;
 outtextxy(x,y,".");
 char w;
 int count=0,option_code=0;
do
 {  count++;
    w=getch();
    if(w=='\0'+'H')
     { setcolor(BLACK);
       outtextxy(x,y,".");
       y=y-40;
       if(y<123)
       {   y=363;
	   setcolor(WHITE);
	   outtextxy(x,y,".");
	   option_code=7;
       }
       if(y==123)
       {  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=1;
       }
       if(y==323)
       { setcolor(WHITE);
	 outtextxy(x,y,".");
	 option_code=6;
       }
       if(y==283)
       {  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=5;
       }
       if(y==243)
       {  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=4;
       }
       if(y==203)
       {  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=3;
       }
       if(y==163)
       {  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=2;
       }
     }
    else if(w=='\0'+'P')
     { setcolor(BLACK);
       outtextxy(x,y,".");
       y=y+40;
       if(y==163)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=2;
	}
	if(y==203)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=3;
	}
	if(y==243)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=4;
	}
	if(y==283)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=5;
	}
	if(y==323)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=6;
	}
	if(y==363)
	{ setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=7;
	}
	if(y>363)
	{ y=123;
	  setcolor(WHITE);
	  outtextxy(x,y,".");
	  option_code=1;
	}
      }
 }while(w!=13);
 if(count==1)
   {  option_code=1;
   }
switch(option_code)
{
  case 1:H.booking();
  break;
  case 2:H.map();
  break;
  case 3:H.view_data();
  break;
  case 4:H.check_out();
  break;
  case 5:H.view_all();
  break;
  case 6:H.restaurent();
  break;
  case 7:exit(1);
  break;
}
goto LABEL;
}//main
void HOTEL::booking()
{   clrscr();
    cleardevice();
    f1.open("NOP.txt",ios::out|ios::in);
    char ch;int p;
    f1.get(ch);
    f1.seekp(1,ios::end);
    ch='b';
    f1.put(ch);
    f1.seekp(0,ios::end);
    p=f1.tellp();
    f1.close();
    f2.open("HOTEL.csv",ios::app);
    f3.open("RECORD.csv",ios::app);
    f3<<"NAME,ROOM NUMBER,ADDRESS,PHONE,ROOM CODE,CHECK IN DATE"<<"\n";
    setcolor(RED);
    cout<<"Enter The Data ........................"<<endl<<endl;
    cout<<"Enter Name  ::";
    gets(book.name);cout<<endl;
    cout<<"Enter Address ::";
    gets(book.address);cout<<endl;
    cout<<"Enter Phone no.";
    gets(book.phone);cout<<endl;
    time_t t;
    struct tm *ti;
    time(&t);
    ti=localtime(&t);
    cout<<"YOUR CHECK IN DATE & TIME : "<<asctime(ti)<<endl;
    strcpy(book.date,asctime(ti));
    cout<<"Select Room Type"<<endl<<"1.For :ROYAL ROOM SUIT  (Charge 1500/day)"<<endl<<
				   "2.For :A.C.ROOM         (Charge 1000/day)"<<endl<<
				   "3.For :NON A.C. ROOM    (Charge 800/day)"<<endl<<
				   "4.For :DOUBLE-BED ROOM  (Charge 700/day)"<<endl<<
				   "5.For :SINGLE-ROOM      (Charge 400/day)"<<endl;
    cin>>book.room_type;cout<<endl;
    book.room_no=p;
    cout<<"Your room_no is"<<book.room_no<<endl;
    f3<<book.name<<","<<book.room_no<<","<<book.address<<","<<book.phone<<","<<book.room_type<<","<<book.date<<endl;
    f2.write((char*)&book,sizeof(book));
    f2.close();
    f3.close();
    getch();
}
void HOTEL::view_data()
{
 clrscr();
 cleardevice();
 cout<<"Enter Room_no To View Data"<<endl;
 cin>>dekho;
 char h='n';
 f2.open("HOTEL.csv",ios::in);
 while(!f2.eof()&&f2.read((char*)&book,sizeof(book)))
 { if(book.room_no==dekho)
     { cout<<"NAME:: ";
       puts(book.name);cout<<endl;
       cout<<"ADDRESS:: ";
       puts(book.address);cout<<endl;
       cout<<"MOBILE NO. ::";
       puts(book.phone);cout<<endl;
       cout<<"CHECK IN DATE ::";
       puts(book.date);
       h='y';
     }
 }
 if(h=='n')
 {  cout<<"THIS ROOM IS EMPTY"<<endl;
 } f2.close();
getch();
}
void HOTEL::map()
{
 setbkcolor(BLACK);cleardevice();setcolor(WHITE);
 settextstyle(7,0,3);
 outtextxy(200,10,"TOP VIEW OF HOTEL");
 line(50,50,50,440)   ;delay(5);// left verticle
 line(590,50,590,440) ;delay(5);//right verticle
 line(50,50,590,50)   ;delay(5);//upper horizantal
 line(50,440,200,440) ;delay(5);//left lower horizantal
 line(590,440,440,440);delay(5);//right lower horizontal
 line(200,440,120,330);delay(5);//inner slant left lower
 line(440,440,520,330);delay(5);//inner slant right lower
 line(120,330,120,200);delay(5);//inner middle left half verticle
 line(520,330,520,200);delay(5);//inner middle right half verticle
 line(120,200,190,90) ;delay(5);//inner slant left upper
 line(520,200,450,90) ;delay(5);//inner slant right upper
 line(190,90,450,90)  ;delay(5);//inner middle horizantal
 line(120,330,50,330) ;delay(5);//left  lower small horizantal
 line(120,200,50,200) ;delay(5);//left upper small horizantal
 line(190,90,190,50)  ;delay(5);//small left upper verticle
 line(450,90,450,50)  ;delay(5);//small right upper verticle
 line(520,200,590,200);delay(5);//small right upper horizantal
 line(520,330,590,330);delay(5);//small right lower horizantal
 line(170,200,215,130);delay(5);//inner most slant left upper
 line(470,200,425,130);delay(5);//inner most slant right upper
 line(215,130,425,130);delay(5);//inner most upper 1 horizontal
 line(170,200,240,200);delay(5);//inner most upper 2 hori (1)
 line(300,200,470,200);delay(5);//inner most upper 2 hori (2)
 line(170,330,220,400);delay(5);//inner most lower slant left
 line(470,330,420,400);delay(5);//inner most lower slant right
 line(170,330,470,330);delay(5);//inner most lower horizantol 1
 line(220,400,280,400);delay(5);//inner most lower horizontal 2 (1)
 line(360,400,420,400);delay(5);//inner most lower horizontal 2 (2)
 rectangle(170,230,470,300);//rectangle
 int poly1[8]={170,230,470,230,470,300,170,300};
 setfillstyle(1,3);    fillpoly(4,poly1);
 int poly2[8]={440,440,520,330,590,330,590,440};
 setfillstyle(10,18);  fillpoly(4,poly2);
 int poly3[8]={50,440,200,440,120,330,50,330};
 setfillstyle(10,18);  fillpoly(4,poly3);
 int poly4[8]={280,400,360,400,370,420,270,420};
 setfillstyle(2,WHITE);        fillpoly(4,poly4);
 int poly5[8]={170,330,470,330,420,400,220,400};
 setfillstyle(1,6);            fillpoly(4,poly5);
 int poly6[8]={215,130,425,130,470,200,170,200};
			       fillpoly(4,poly6);
 int poly7[8]={190,90,190,50,450,50,450,90};
 setfillstyle(7,MAGENTA);      fillpoly(4,poly7);
 int poly8[10]={50,200,120,200,190,90,190,50,50,50};
 setfillstyle(9,24);           fillpoly(5,poly8);
 int poly9[10]={520,200,590,200,590,50,450,50,450,90};
 setfillstyle(9,24);           fillpoly(5,poly9);
 int poly10[8]={120,330,120,200,50,200,50,330};
 setfillstyle(11,YELLOW);      fillpoly(4,poly10);
 int poly11[8]={520,200,590,200,590,330,520,330};
 setfillstyle(11,YELLOW);      fillpoly(4,poly11);
 int poly12[8]={150,240,140,240,140,290,150,290};
 setfillstyle(8,WHITE);        fillpoly(4,poly12);
 int poly13[8]={490,240,500,240,500,290,490,290};
 setfillstyle(8,WHITE);        fillpoly(4,poly13);
 int poly14[8]={250,130,260,130,260,90,250,90};
 setfillstyle(2,WHITE);        fillpoly(4,poly14);
 setcolor(RED); settextstyle(8,0,1);
 outtextxy(240,250,"Swimming Pool");
 setcolor(WHITE);  settextstyle(8,0,5);
 outtextxy(75,230,"P");
 outtextxy(545,230,"P");
 settextstyle(11,0,5);
 outtextxy(280,160,"RESTAURENT");
 outtextxy(85,380,"LAWN");
 outtextxy(525,380,"LAWN");
 outtextxy(300,425,"ENTRY");
 outtextxy(305,360,"HOTEL");
 outtextxy(285,65,"GAME ZONE");
 outtextxy(170,450,"press any key to go back to main menu");
 getch();
}
void HOTEL::check_out()
{
  clrscr();cleardevice();
  char t='n',a[10],b[10];
  int i,j;long double l;
  f1.open("HOTEL.csv",ios::in);
  f2.open("TEMP.csv",ios::out);
  cout<<"=============================================================================="<<endl;
  cout<<"PLEASE ENTER ROOM_NO. TO REMOVE BOOKED PLACE"<<endl;
  int g;
  cin>>g;
  while(!f1.eof()&&f1.read((char*)&book,sizeof(book)))
  {
    if(book.room_no!=g)
    {  f2.write((char*)&book,sizeof(book));
    }
    else
    {
     j=book.room_type;
     cout<<"YOUR NAME IS ";
     puts(book.name);
     cout<<"YOUR CHECK IN DATE  (DD/MM/YYYY): ";
     puts(book.date);
     t='y';
    }
  }
 f1.close();
 f2.close();
 remove("HOTEL.csv");
 rename("TEMP.csv","HOTEL.csv");
 if(t=='n')
 {
   cout<<"PLEASE ENTER CORRECT ROOM NO.THIS ROOM.NO IS NOT BOOKED"<<endl;
 }
 if(t=='y')
 { time_t t;
   struct tm *ti;
   time(&t);
   ti=localtime(&t);
   cout<<"YOUR CHECK OUT DATE & TIME : "<<asctime(ti)<<endl;
   cout<<"ENTER THE DAYS YOU STAYED  :" ;
   cin>>i;
   cout<<endl;
   cout<<"YOUR ROOM TYPE WAS ";
   switch(j)
   { case 1:cout<<"1.For :ROYAL ROOM SUIT  (Charge 1500/day)"<<endl;
     break;
     case 2:cout<<"A.C.Room (Charge 1000/day)"<<endl;
     break;
     case 3:cout<<"Non A.C. Room (Charge 800/day)"<<endl;
     break;
     case 4:cout<<"4.For :DOUBLE-BED ROOM  (Charge 700/day)"<<endl;
     break;
     case 5:cout<<"5.For :SINGLE-ROOM      (Charge 400/day)"<<endl;
     break;
   }
  if(j==1)
  { l=(i*1500);}
  else if(j==2)
  { l=(i*1000);}
  else if(j==3)
  { l=(i*800);}
  else if(j==4)
  { l=(i*700);}
  else if(j==5)
  { l=(i*400);}
  cout<<"YOUR CHARGE IS :Rs "<<l<<"/-"<<endl;
  cout<<"PLEASE PAY CHARGE"<<endl;
  cout<<"PLEASE SUBMIT ROOM NO."<<g<<" KEY "<<endl;
  cout<<"YOU HAVE SUCCESSFULLY CHECKED OUT........"<<endl<<endl<<endl; getch();
  cout<<"...##----THANK YOU----##...##----ARU AAUJO----##...##----HAPPY JOURNEY----##..."<<endl;
 } getch();
}
void HOTEL::view_all()
{
  clrscr(); cleardevice();
  f1.open("HOTEL.csv",ios::in);
  cout<<".....................LIST OF ALL CUSTOMERS...................."<<endl<<endl<<endl;
  cout<<"\t\t"<<"NAME";
  gotoxy(40,4);cout<<"ROOM NO."<<endl;
  int s=0;
  cout<<"            ......................................."<<endl;
  while(!f1.eof()&&f1.read((char*)&book,sizeof(book)))
  { cout<<"\t\t"<<book.name;
    gotoxy(43,6+s);cout<<book.room_no<<endl;
    s++;
  }
  f1.close();
  getch();
}
void HOTEL::restaurent()
{
  clrscr(); cleardevice();
  settextstyle(1,0,4);
  setbkcolor(YELLOW);  setcolor(RED);
  outtextxy(85,145,"WELCOME TO OUR RESTAURENT");   settextstyle(8,0,3);
  outtextxy(180,245,"PLEASE TAKE YOUR SEAT");    getch();   clrscr();
  int price[100]={150,130,100,120,110,50,50,30,150,80,90,95,45,45,30,80,95,105,110,160,96};
  char food[100][30]={"AMADI KI BHAJI","BARWAHA Ki JALEBI","DAL-BATI","KAJU CURRY","SHAHI PANEER","TANDURI ROTTI","BUTTER PARATHA","GHEE ROTTI","PANEER ANGARA","PLAIN DOSA","MASALA DOSA","MYSORE SPECIAL","PAV BHAJI","CHHOLA BHATURA","BOMBAY VADA PAV","FRENCH FREIES","GULAB JAMUN","RASGULLA","MOONG HALWA","GAJAR HALWA","FRUIT SALAD"} ;
  settextstyle(1,0,3);
  cleardevice();
  int j=-1;
  menu_card:
  outtextxy(250,20,"MENU CARD"); setbkcolor(BLACK);
  for(int i=0;i<=20;i++)
   {
    gotoxy(25,5+(i));cout<<i;
    gotoxy(30,5+(i));cout<<food[i];
    gotoxy(50,5+(i));cout<<"Rs."<<price[i]<<"/-";
   } getch();
   int q[20],r;
   food_code:
   gotoxy(1,1);cleardevice();
   gotoxy(6,2);cout<<"PRESS '0' TO GO BACK TO MENU CARD  OTHERWISE PRESS '1' TO CONTINUE ::";
   cin>>r;
   if(r==0)
   { goto menu_card;}
     j++;
     gotoxy(20,7);cout<<"ENTER THE FOOD CODE YOU WANT TO HAVE ::" ;
     cin>>q[j];
     if(q[j]>20)
     {  gotoxy(20,8);cout<<"ENTER CORRECT CHOICE"<<endl;
	getch();
	goto food_code;
     }
     gotoxy(20,9);cout<<"DO YOU WANT SOMETHING MORE Y/N ::";
     char k;
     cin>>k;
     cleardevice(); setcolor(RED);
     if(k=='Y'||k=='y')
     { goto food_code; }
     int sum=0;  settextstyle(7,0,4);
     f4.open("HOTEL.csv",ios::in);
     gotoxy(5,2);cout<<"ARE YOU STAYING IN HOTEL 'ROYAL PALACE'  Y/N ::";
     char p='n',ch='n', bill_name[20];
     cin>>p;
     if(p=='Y'||p=='y')
     {
      gotoxy(5,4);cout<<"PLEASE SHOW YOUR IDENTITY CARD GIVEN AT THE TIME OF BOOKING "<<endl;
      int l;
      gotoxy(5,6);cout<<"ENTER ROOM NUMBER :";
      cin>>l;     ch='g';
      while(!f4.eof())
      {
	f4.read((char*)&book,sizeof(book));
	if(book.room_no==l)
	 {
	  strcpy(bill_name,book.name);
	  gotoxy(5,8);cout<<"NAME :"<<book.name<<endl;
	  ch='y';
	  break;
	 }
      }
     if(ch=='g')
     {
      gotoxy(5,8);cout<<"YOU ARE NOT BOOKED YOUR CHANCE HAD GONE";
     }
    getch();
    }
    cleardevice();
    char name[20];
    if(ch!='y')
    {
      gotoxy(28,1);cout<<"ENTER YOUR NAME ::";
      gets(bill_name);
      gotoxy(30,5);cout<<"NAME ::"<<bill_name;
    }
    strcpy(name,bill_name);
    strcat(bill_name,".csv");
    f5.open(bill_name,ios::app);
    f5<<" RESTAURENT ROYAL PALACE "<<endl;
    if(ch=='y')
    {
    gotoxy(30,5);cout<<"NAME ::"<<book.name;
    f5<<book.name<<endl;
    }
    if(ch!='y')
    {  f5<<"NAME ::"<<name<<endl;
    }
    outtextxy(235,25,"YOUR BILL");
    for(int s=0;s<=j;s++)
    { gotoxy(30,7+s);cout<<food[q[s]];
      f5<<food[q[s]]<<" ";
      gotoxy(49,7+s);cout<<"Rs."<<price[q[s]]<<"/-";
      f5<<" Rs. "<<price[q[s]]<<"/-"<<endl;
      sum=sum+ price[q[s]];
    }
    if(ch=='y')
    {
       gotoxy(30,9+s);cout<<"TOTAL::            Rs."<<sum<<"/-";
       f5<<"TOTAL IN Rs."<<sum<<"/-"<<endl;
       gotoxy(30,10+s);cout<<"DISCOUNT 10%       Rs."<<sum/10<<"/-";
       f5<<"DISCOUNT 10% IN Rs."<<sum/10<<"/-"<<endl;
       sum=sum-(sum/10);
       gotoxy(30,11+s);cout<<"PLEASE PAY         Rs."<<sum<<"/- Only";
       f5<<"PLEASE PAY Rs."<<sum<<"/- Only"<<endl;
    }
    else
    {
      gotoxy(30,9+s);cout<<"TOTAL::            Rs."<<sum<<"/-";
      f5<<"TOTAL IN Rs."<<sum<<"/- "<<endl;
      gotoxy(30,10+s);cout<<"PLEASE PAY         Rs."<<sum<<"/- Only";
      f5<<"PLEASE PAY Rs."<<sum<<"/- Only"<<endl;
    }
  f4.close();
  f5.close();
  getch();
}
