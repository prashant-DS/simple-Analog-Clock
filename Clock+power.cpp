#include<stdio.h>
#include<time.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
#define pi 3.14159
int main()
{
int hour,minute,second,pg=0;
double ah,am,as;
char s[12];
time_t t;

DWORD mw=GetSystemMetrics(SM_CXSCREEN);
initwindow(200,200,"",mw-220,20,true,false);
while(1)
{
 setactivepage(pg);
 setvisualpage(1-pg);
 cleardevice();
 time(&t);
 struct tm *p=localtime(&t);
 hour=p->tm_hour;minute=p->tm_min;second=p->tm_sec;
 setcolor(CYAN);
 circle(100,100,50);
 setcolor(DARKGRAY);
 settextstyle(COMPLEX_FONT,0,1);
 outtextxy(135,95,"3");
 outtextxy(95,130,"6");
 outtextxy(53,95,"9");
 outtextxy(91,54,"12");
as=(-90+6*second)*pi/180;
setcolor(RED);
line(100,100,100+40*cos(as),100+40*sin(as));

minute+=second/60;
am=(-90+6*minute)*pi/180;
setcolor(BROWN);
line(100,100,100+30*cos(am),100+30*sin(am));

hour+=minute/60;
ah=(-90+6*hour)*pi/180;
setcolor(BLUE);
line(100,100,100+20*cos(ah),100+20*sin(ah));

setcolor(MAGENTA);
 strftime(s,12,"%d-%b-%Y",p);
 rectangle(35,165,165,190);
 setcolor(GREEN);
 settextstyle(BOLD_FONT,0,1);
 outtextxy(40,170,s);

 setcolor(BROWN);
 int a[]={135,134,150,165,140,165,120,145};
 drawpoly(4,a);
 int b[]={65,134,50,165,60,165,80,145};
 drawpoly(4,b);
setcolor(DARKGRAY);
circle(47,47,25);
circle(153,47,25);
POINT m;
GetCursorPos(&m);
int c1x=mw-220+47,c1y=47+20,c2x=mw-220+153;
int d1=(c1x-m.x)*(c1x-m.x)+(c1y-m.y)*(c1y-m.y)-625,d2=(c2x-m.x)*(c2x-m.x)+(c1y-m.y)*(c1y-m.y)-625;

setcolor(RED);settextstyle(SMALL_FONT,0,4);outtextxy(33,40,"SHUT");outtextxy(33,50,"DOWN");outtextxy(133,45,"RESTART");
if(d1<0)
     {setcolor(12);settextstyle(EUROPEAN_FONT,0,5);outtextxy(30,25,"S");
     if(GetAsyncKeyState(VK_LBUTTON))
          system("C:\\Windows\\System32\\shutdown /s /t 0");
     }
else if(d2<0)
     {setcolor(12);settextstyle(EUROPEAN_FONT,0,5);outtextxy(136,25,"R");
     if(GetAsyncKeyState(VK_LBUTTON))
          system("C:\\Windows\\System32\\shutdown /r /t 0");
     }

delay(20);
 pg=1-pg;
}
return 0;
}
