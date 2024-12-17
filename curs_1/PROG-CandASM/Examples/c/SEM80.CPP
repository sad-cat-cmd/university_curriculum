#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#define DEL 10
extern "C" { void INTER(void); }
extern "C" { void OBR80(unsigned int); }
int N=1, X=0, Y=0, B=0, M=1, L=1, xnew, ynew, bnew, act1=0, act2=0, zzz=0;
int fig=0, a=0;
union REGS regs;
int msinit(int,int,int,int);
void submenu1(void);
void submenu2(void);
void erase1(void);
void erase2(void);
void fsin(int);
void kassin(double,int,int);
void flog(int);
void kaslog(double,int,int);
void fpar(int);
void kaspar(double,int,int);
void fexp(int);
void kasexp(double,int,int);
void figura(int,int,double);
void about(void);
main()
 {
  int s_cs, s_ip, X_max, Y_max;
  char ch;
  int driver=VGA, gmode=VGAHI;
    registerfarbgidriver(EGAVGA_driver_far);
    initgraph(&driver,&gmode,"");
    if (graphresult())
      {
       printf("\nГpафический дpайвеp недоступен.");
       getch();    return 1;
      }
    //******************************************************
    X_max=getmaxx();   Y_max=getmaxy();
    X=X_max/2;         Y=Y_max/2;
    if (!msinit(0,X_max,0,Y_max))
      {
        outtextxy(X,Y,"Нет мыши или дpайвеpа");
        getch();     return 1;
      }
    //Сохpанение вектоpа пpеpывания от клавиатуpы
    asm {
         push ax;  push bx;  push es;
         mov ah,35h; mov al,09h; int 21h; mov s_cs,es; mov s_ip,bx;
         pop es;  pop bx;  pop ax;
        }
    //Установка нового вектоpа пpеpывания от клавиатуpы
    asm {cli;
         push ax;  push dx;  push ds;
         mov dx,offset INTER;  mov ax,seg INTER;  mov ds,ax;
         mov ah,25h;  mov al,09h;  int 21h;
         pop ds;  pop dx;  pop ax;
         sti;
        }
    //Основная часть пpогpаммы
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    setbkcolor(CYAN); setcolor(RED);
    //*********************************************************
       settextjustify(CENTER_TEXT,CENTER_TEXT);
       settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
       outtextxy(320,100,"KURSOVAJA RABOTA");
       outtextxy(320,200,"po programmirovaniju");
       outtextxy(320,300,"Vipolnil Krimkin Ilja");
       getch();
       cleardevice();
       setbkcolor(BLUE);   setcolor(WHITE);
       rectangle(1,50,638,478);
       rectangle(4,53,635,475);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
       setfillstyle(SOLID_FILL,MAGENTA);
       rectangle(10,5,150,45);      floodfill(11,6,WHITE);
       setfillstyle(SOLID_FILL,GREEN);
       rectangle(165,5,305,45);     floodfill(166,6,WHITE);
       rectangle(320,5,460,45);     floodfill(321,6,WHITE);
       rectangle(475,5,615,45);     floodfill(476,6,WHITE);
       setcolor(YELLOW);
       outtextxy(80,22,"Function");
       outtextxy(235,22,"Object");
       outtextxy(390,22,"About");
       outtextxy(545,22,"Exit");
       //**************************************************************
       asm { mov ax,1;   int 33h; }
       while(1)
        {
         if (kbhit())
          {
            ch=getch();
            if (ch==27 || (ch==13 && N==4))
              {
               if (act1==1) erase1();
               else  if (act2==1) erase2();
                     else         break;
              }
            else if (ch==13 && N==1 && act1==0) { act1=1; M=1; submenu1(); }
                 else if (ch==13 && N==2) { act2=1; L=1; submenu2(); }
          }
         regs.x.ax=3;     //опpос состояния мыши
         int86(51,&regs,&regs);
         xnew=regs.x.cx;  ynew=regs.x.dx;
         bnew=regs.x.bx;
         if (xnew==X && ynew==Y && bnew==B) continue;
         X=xnew;  Y=ynew;  B=bnew;

         if (B==1 && act1==1 && M==1) fsin(0);
         else if (B==1 && act1==1 && M==4) flog(0);
              else if (B==1 && act1==1 && M==2) fpar(0);
                   else if (B==1 && act1==1 && M==3) fexp(0);

         if (X>=30 && X<=130 && Y>=60 && Y<=80 && act1==1) {M=1; OBR80(200);}
         else if (X>=30 && X<=130 && Y>=90 && Y<=110 && act1==1) {M=2; OBR80(200);}
              else if (X>=30 && X<=130 && Y>=120 && Y<=140 && act1==1) {M=3; OBR80(200);}
                   else if (X>=30 && X<=130 && Y>=150 && Y<=170 && act1==1) {M=4; OBR80(200);}

         if (B==1 && act2==1 && L==1) fig=1;
         else if (B==1 && act2==1 && L==2) fig=2;
              else if (B==1 && act2==1 && L==3) fig=3;
         if (B==1 && act2==1 && M==1) fsin(1);
         else if (B==1 && act2==1 && M==4) flog(1);
              else if (B==1 && act2==1 && M==2) fpar(1);
                   else if (B==1 && act2==1 && M==3) fexp(1);

         if (X>=185 && X<=285 && Y>=60 && Y<=80 && act2==1) {L=1; OBR80(300);}
         else if (X>=185 && X<=285 && Y>=90 && Y<=110 && act2==1) {L=2; OBR80(300);}
              else if (X>=185 && X<=285 && Y>=120 && Y<=140 && act2==1) {L=3; OBR80(300);}

         if (B==1 && N==4) break;
         else if (B==1 && N==3) { about(); a=(a+1)%2; }
              else if (B==1 && N==1 && act1==0) { act1=1; M=1; submenu1(); }
                   else if (B==1 && N==2 && act2==0) { act2=1; L=1; submenu2(); }

         if (X>=10 && X<=150 && Y>=5 && Y<=45) { N=1; OBR80(100); }
         else if (X>=165 && X<=305 && Y>=5 && Y<=45) { N=2; OBR80(100); }
              else if (X>=320 && X<=460 && Y>=5 && Y<=45) { N=3; OBR80(100);}
                   else if (X>=475 && X<=615 && Y>=5 && Y<=45) { N=4; OBR80(100);}
        }
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //Восстановление стаpого вектоpа пpеpывания от клавиатуpы
    asm {cli;
         push ax;  push dx;  push ds;
         mov dx,s_ip; mov ax,s_cs; mov ds,ax;
         mov ah,25h; mov al,09h; int 21h;
         pop ds;  pop dx;  pop ax;
         sti;
        }
    //*********************************************
    closegraph();
    return 0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int msinit(int xlo,int xhi,int ylo,int yhi)
 {
   int retcode;
     regs.x.ax=0;
     int86(51,&regs,&regs);
     retcode=regs.x.ax; //!0 - мышь уст., 0 - не уст.
     if (!retcode) return 0;
     regs.x.ax=7;  regs.x.cx=xlo;  regs.x.dx=xhi;
     int86(51,&regs,&regs);
     regs.x.ax=8;  regs.x.cx=ylo;  regs.x.dx=yhi;
     int86(51,&regs,&regs);
     return retcode;  
 }
//************************************************************
void submenu1(void)
 {
   asm { mov ax,2;   int 33h; }
   setcolor(WHITE);
   setfillstyle(SOLID_FILL,MAGENTA);
   rectangle(30,60,130,80);      floodfill(31,61,WHITE);
   setfillstyle(SOLID_FILL,GREEN);
   rectangle(30,90,130,110);     floodfill(31,91,WHITE);
   rectangle(30,120,130,140);    floodfill(31,121,WHITE);
   rectangle(30,150,130,170);    floodfill(31,151,WHITE);
   setcolor(YELLOW);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(80,70,"y=sin(x)");
   outtextxy(80,100,"y=x^2");
   outtextxy(80,130,"y=e^x");
   outtextxy(80,160,"y=ln(x)");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   asm { mov ax,1;   int 33h; }
 }
//************************************************************
void erase1(void)
 {
   setfillstyle(SOLID_FILL,BLUE);
   asm { mov ax,2;   int 33h; }
   bar(30,60,130,170);
   asm { mov ax,1;   int 33h; }
   act1=0;
   setfillstyle(SOLID_FILL,MAGENTA);
 }
 //************************************************************
void submenu2(void)
 {
   asm { mov ax,2;   int 33h; }
   setcolor(WHITE);
   setfillstyle(SOLID_FILL,MAGENTA);
   rectangle(185,60,285,80);      floodfill(186,61,WHITE);
   setfillstyle(SOLID_FILL,GREEN);
   rectangle(185,90,285,110);     floodfill(186,91,WHITE);
   rectangle(185,120,285,140);    floodfill(186,121,WHITE);
   setcolor(YELLOW);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(235,70,"Rectangle");
   outtextxy(235,100,"Triangle");
   outtextxy(235,130,"Boat");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   asm { mov ax,1;   int 33h; }
 }
//************************************************************
void erase2(void)
 {
   setfillstyle(SOLID_FILL,BLUE);
   asm { mov ax,2;   int 33h; }
   bar(185,60,285,170);
   asm { mov ax,1;   int 33h; }
   act2=0;
   setfillstyle(SOLID_FILL,MAGENTA);
 }
//************************************************************
void fsin(k)
 {
  double fx, fy;
  int sx, sy;
    erase1(); erase2();
    act1=0;
    asm { mov ax,2;   int 33h; }
    if (k==0 || k==1)
     {
      setfillstyle(SOLID_FILL,BLUE);
      bar(5,54,634,474);
      line(65,264,584,264);  line(584,264,574,259);  line(584,264,574,269);
      line(65,104,65,424);   line(65,104,60,114);    line(65,104,70,114);
      for(fx=0;fx<12.56;fx+=0.01)
       {
        fy=sin(fx);
        sx=(int)(fx*40+65);
        sy=(int)(264-fy*80);
        putpixel(sx,sy,WHITE);
       }
     }
     if (k==1)
      {
      setwritemode(XOR_PUT);
      setcolor(LIGHTGREEN);
      setlinestyle(SOLID_LINE,zzz,THICK_WIDTH);
      do {
           for(fx=0;fx<12.56;fx+=0.05)
            {
              if (kbhit()) break;
              fy=sin(fx);
              sx=(int)(fx*40+65);     sy=(int)(264-fy*80);
              kassin(fx,sx,sy);
             }
           for(fx=12.56;fx>0;fx-=0.05)
            {
              if (kbhit()) break;
              fy=sin(fx);
              sx=(int)(fx*40+65);     sy=(int)(264-fy*80);
              kassin(fx,sx,sy);
             }
         } while(!kbhit());
         setwritemode(COPY_PUT);
         setlinestyle(SOLID_LINE,zzz,NORM_WIDTH);
         setcolor(YELLOW);
      }
    setfillstyle(SOLID_FILL,MAGENTA);
    asm { mov ax,1;   int 33h; }
 }
//************************************************************
void flog(k)
 {
  double fx, fy;
  int sx, sy;
    erase1(); erase2();
    act1=0;
    asm { mov ax,2;   int 33h; }
    if (k==0 || k==1)
     {
      setfillstyle(SOLID_FILL,BLUE);
      bar(5,54,634,474);
      line(65,264,574,264);
      line(65,104,65,424);
      for(fx=0.1;fx<12;fx+=0.01)
       {
        fy=log(fx);
        sx=(int)(fx*40+65);
        sy=(int)(264-fy*40);
        putpixel(sx,sy,WHITE);
       }
     }
     if (k==1)
      {
       setwritemode(XOR_PUT);
       setcolor(LIGHTGREEN);
       setlinestyle(SOLID_LINE,zzz,THICK_WIDTH);
      do {
           for(fx=0.1;fx<12;fx+=0.05)
            {
              fy=log(fx);
              sx=(int)(fx*40+65);      sy=(int)(264-fy*40);
              kaslog(fx,sx,sy);
              if (kbhit()) break;
             }
           for(fx=12;fx>0.1;fx-=0.05)
            {
              fy=log(fx);
              sx=(int)(fx*40+65);       sy=(int)(264-fy*40);
              kaslog(fx,sx,sy);
              if (kbhit()) break;
             }
         } while(!kbhit());
         setwritemode(COPY_PUT);
         setlinestyle(SOLID_LINE,zzz,NORM_WIDTH);
         setcolor(YELLOW);
      }
    setfillstyle(SOLID_FILL,MAGENTA);
    asm { mov ax,1;   int 33h; }
 }
//************************************************************
void fpar(k)
 {
  double fx, fy;
  int sx, sy;
    erase1(); erase2();
    act1=0;
    asm { mov ax,2;   int 33h; }
    if (k==0 || k==1)
     {
      setfillstyle(SOLID_FILL,BLUE);
      bar(5,54,634,474);
      line(65,400,574,400);
      line(320,104,320,424);
      for(fx=-10;fx<10;fx+=0.01)
       {
        fy=fx*fx;
        sx=(int)(fx*20+320);
        sy=(int)(400-fy*2.5);
        putpixel(sx,sy,WHITE);
       }
     }
    if (k==1)
     {
      setwritemode(XOR_PUT);
      setcolor(LIGHTGREEN);
      setlinestyle(SOLID_LINE,zzz,THICK_WIDTH);
      do {
           for(fx=10;fx>-10;fx-=0.05)
            {
              fy=fx*fx;
              sx=(int)(fx*20+320);      sy=(int)(400-fy*2.5);
              kaspar(fx,sx,sy);
              if (kbhit()) break;
             }
           for(fx=-10;fx<10;fx+=0.05)
            {
              fy=fx*fx;
              sx=(int)(fx*20+320);      sy=(int)(400-fy*2.5);
              kaspar(fx,sx,sy);
              if (kbhit()) break;
             }
         } while(!kbhit());
        setwritemode(COPY_PUT);
        setlinestyle(SOLID_LINE,zzz,NORM_WIDTH);
        setcolor(YELLOW);
     }
    setfillstyle(SOLID_FILL,MAGENTA);
    asm { mov ax,1;   int 33h; }
 }
//************************************************************
void fexp(k)
 {
  double fx, fy;
  int sx, sy;
    erase1(); erase2();
    act1=0;
    asm { mov ax,2;   int 33h; }
    if (k==0 || k==1)
     {
      setfillstyle(SOLID_FILL,BLUE);
      bar(5,54,634,474);
      line(65,400,574,400);
      line(320,104,320,424);
      for(fx=-5;fx<5;fx+=0.01)
       {
        fy=exp(fx);
        sx=(int)(fx*40+320);
        sy=(int)(400-fy*1.7);
        putpixel(sx,sy,WHITE);
       }
     }
    if (k==1)
     {
      setwritemode(XOR_PUT);
      setcolor(LIGHTGREEN);
      setlinestyle(SOLID_LINE,zzz,THICK_WIDTH);
      do {
           for(fx=-5;fx<5;fx+=0.05)
            {
              fy=exp(fx);
              sx=(int)(fx*40+320);      sy=(int)(400-fy*1.7);
              kasexp(fx,sx,sy);
              if (kbhit()) break;
             }
           for(fx=5;fx>-5;fx-=0.05)
            {
              fy=exp(fx);
              sx=(int)(fx*40+320);      sy=(int)(400-fy*1.7);
              kasexp(fx,sx,sy);
              if (kbhit()) break;
             }
         } while(!kbhit());
        setwritemode(COPY_PUT);
        setlinestyle(SOLID_LINE,zzz,NORM_WIDTH);
        setcolor(YELLOW);
     }
    setfillstyle(SOLID_FILL,MAGENTA);
    asm { mov ax,1;   int 33h; }
 }
//************************************************************
void kassin(double fx,int sx,int sy)
 {
  double alpha;
   alpha=atan(2*cos(fx));
   figura(sx,sy,alpha);
   delay(DEL);
   figura(sx,sy,alpha);
 }
//************************************************************
void kaspar(double fx,int sx,int sy)
 {
  double alpha;
   alpha=atan(2*fx/8);
   figura(sx,sy,alpha);
   delay(DEL);
   figura(sx,sy,alpha);
 }
//************************************************************
void kaslog(double fx,int sx,int sy)
 {
  double alpha;
   alpha=atan(1/fx);
   figura(sx,sy,alpha);
   delay(DEL);
   figura(sx,sy,alpha);
 }
//************************************************************
void kasexp(double fx,int sx,int sy)
 {
  double alpha;
   alpha=atan(exp(fx)/23.5);
   figura(sx,sy,alpha);
   delay(DEL);
   figura(sx,sy,alpha);
 }
//*****************************************************************
void figura(int sx, int sy, double alpha)
 {
  int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
  int x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
  double dx, dy, dx1, dy1;
    dx=20*cos(alpha);   dy=20*sin(alpha);
    dx1=40*sin(alpha);  dy1=40*cos(alpha);
  x1=sx-dx;           y1=sy+dy;
  x2=sx+dx;           y2=sy-dy;
  x3=sx-dx1-dx;       y3=sy-dy1+dy;
  x4=sx-dx1+dx;       y4=sy-dy1-dy;
  x5=sx-dx1;          y5=sy-dy1;
  x6=sx-dx1/2-dx*2;   y6=sy-dy1/2+dy*2;
  x7=sx-dx1/2+dx*2;   y7=sy-dy1/2-dy*2;
  x8=sx-dx1/2;        y8=sy-dy1/2;
  x9=sx-dx1*1.5;      y9=sy-dy1*1.5;
  x10=sx-dx1-dx;      y10=sy-dy1+dy;
  switch(fig)
   {
    case 1: line(x1,y1,x2,y2);   line(x3,y3,x4,y4);
            line(x1,y1,x3,y3);   line(x2,y2,x4,y4);    break;

    case 2: line(x1,y1,x2,y2);   line(x1,y1,x5,y5);
            line(x2,y2,x5,y5);                         break;

    case 3: line(x1,y1,x2,y2);   line(x6,y6,x7,y7);
            line(x1,y1,x6,y6);   line(x2,y2,x7,y7);
            line(x8,y8,x9,y9);
            line(x8,y8,x10,y10); line(x9,y9,x10,y10);  break;
   }
 }
//************************************************************
void about(void)
 {
  setfillstyle(SOLID_FILL,BLUE);
  if (a==0) outtextxy(320,440,"This program was created by Krimkin I. G.");
  else      bar(50,425,550,455);
  setfillstyle(SOLID_FILL,GREEN);
 }
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
