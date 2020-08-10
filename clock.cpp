#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#define pi 3.14159
main()
{   float x,y,k,hour,minute,second,cs,cm,x1,x2,y1,y2;
    int gd=0,gm,i=0,b;
    double js,jm,jh,jw;
    char c;
    time_t t;
    time(&t);
    struct tm *p=localtime(&t);
     hour=p->tm_hour;
     minute=p->tm_min;
     second=p->tm_sec;
     cs=second;


/*
   printf("Set time:Enter hour minute and seconds ");
    scanf("%f%f%f",&hour,&minute,&second);
    cs=second;
    cm=0;
    if(hour>12||minute>60||second>60||hour<1||minute<0||second<0)
    {printf("INVALID!");exit(0);}
  */
    initgraph(&gd,&gm,"");
//floodfill(0,0,14);
//setcolor(0);

for(k=150;k<154;k++)
circle(200,200,k);
for(i=1;i<=12;i++)
    {
       jw=30*(i-3)*pi/180;
       x=200+130*cos(jw);
       y=200+130*sin(jw);
       sprintf(&c,"%d",i);
       outtextxy(x,y,&c);
    }
minute+=cs/60;
jm=(-90+6*minute)*pi/180;
x1=200+90*cos(jm);
y1=200+90*sin(jm);
line(200,200,x1,y1);
hour+=minute/60;
jh=(-90+30*hour)*pi/180;
x2=200+80*cos(jh);
y2=200+80*sin(jh);
line(200,200,x2,y2);


js=(-90+6*cs)*pi/180;
b=getbkcolor();
while(TRUE)
    {
        setcolor(RED);
       x=200+100*cos(js);
       y=200+100*sin(js);
       line(200,200,x,y);
            if(js-jm<=6*pi/180)
                {setcolor(15);
                line(200,200,x1,y1);
                }
            if(js-jh<=6*pi/180)
                {setcolor(15);
                line(200,200,x2,y2);
                }










       delay(990);
       cs++;
       if(cs==60)
       {
           setcolor(b);
           line(200,200,x1,y1);
           setcolor(15);
         jm=jm+(6*pi/180);
          x1=200+90*cos(jm);
          y1=200+90*sin(jm);
          line(200,200,x1,y1);
                if(jm-jh<=6*pi/180)
                {setcolor(15);
                line(200,200,x2,y2);
                }
          cs=0;
          ++cm;
                if(cm==4)
                {
                    setcolor((b));
                    line(200,200,x2,y2);
                    setcolor(15);
                    jh+=2*pi/180;
                    x2=200+80*cos(jh);
                    y2=200+80*sin(jh);
                    setcolor(15);
                    line(200,200,x2,y2);
                    cm=0;
                }
        }
        setcolor(b);
       line(200,200,x,y);
       js=js+(6*pi/180);
    }




    getch();
}


