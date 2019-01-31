#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


float plane = 250.00;
float lift = 0.00;
float shipX = 20.00;
float shipY = 0.00;
float train = 0.00;
int i;
int p = 0;
int state = 1;
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(-250.00,250.00,-250.00,250.00,-250.00,5.00);
}
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=1000;i++)

    {
        float angle = 2.0f * 3.1416f * i/1000;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //sky
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(-250.00, 250.00);
    glVertex2f(250.00, 250.00);
    glVertex2f(250.00, 100.00);
    glVertex2f(-250.00, 100.00);
    glEnd();

    //river
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-250.00, 100.00);
    glVertex2f(250.00, 100.00);
    glVertex2f(250.00, -250.00);
    glVertex2f(-250.00, -250.00);
    glEnd();

    //earth
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.6, 0.1);
    glVertex2f(-250.00, -5.00);
    glVertex2f(-90.00, -5.00);
    glVertex2f(-75.00, -30.00);
    glVertex2f(-250.00, -30.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.6, 0.1);
    glVertex2f(25.00, -5.00);
    glVertex2f(250.00, -5.00);
    glVertex2f(250.00, -30.00);
    glVertex2f(40.00, -30.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.1);
    glVertex2f(-250.00, -30.00);
    glVertex2f(-75.00, -30.00);
    glVertex2f(-75.00, -45.00);
    glVertex2f(-250.00, -45.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.1);
    glVertex2f(40.00, -30.00);
    glVertex2f(250.00, -30.00);
    glVertex2f(250.00, -45.00);
    glVertex2f(40.00, -45.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.1);
    glVertex2f(25.00, -5.00);
    glVertex2f(40.00, -30.00);
    glVertex2f(40.00, -45.00);
    glVertex2f(25.00, -20.00);
    glEnd();

    //rail line
     glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-250.00, -21.00);
    glVertex2f(-80.00, -21.00);
    glVertex2f(-78.00, -23.00);
    glVertex2f(-250.00, -23.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-250.00, -12.00);
    glVertex2f(-86.00, -12.00);
    glVertex2f(-84.00, -14.00);
    glVertex2f(-250.00, -14.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(29.00, -12.00);
    glVertex2f(250.00, -12.00);
    glVertex2f(250.00, -14.00);
    glVertex2f(30.00, -14.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(34.00, -21.00);
    glVertex2f(250.00, -21.00);
    glVertex2f(250.00, -23.00);
    glVertex2f(35.00, -23.00);
    glEnd();


   //rail line inside
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-250.00, -21.00);
    glVertex2f(-80.00, -21.00);
    glVertex2f(-78.00, -23.00);
    glVertex2f(-250.00, -23.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-250.00, -12.00);
    glVertex2f(-86.00, -12.00);
    glVertex2f(-84.00, -14.00);
    glVertex2f(-250.00, -14.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(29.00, -12.00);
    glVertex2f(250.00, -12.00);
    glVertex2f(250.00, -14.00);
    glVertex2f(30.00, -14.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(34.00, -21.00);
    glVertex2f(250.00, -21.00);
    glVertex2f(250.00, -23.00);
    glVertex2f(35.00, -23.00);
    glEnd();

    //inside rail line
    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-96.00, -14.00);
    glVertex2f(-90.00, -14.00);
    glVertex2f(-85.00, -21.00);
    glVertex2f(-91.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-110.00, -14.00);
    glVertex2f(-104.00, -14.00);
    glVertex2f(-99.00, -21.00);
    glVertex2f(-105.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-124.00, -14.00);
    glVertex2f(-118.00, -14.00);
    glVertex2f(-113.00, -21.00);
    glVertex2f(-119.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-138.00, -14.00);
    glVertex2f(-132.00, -14.00);
    glVertex2f(-127.00, -21.00);
    glVertex2f(-133.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-152.00, -14.00);
    glVertex2f(-146.00, -14.00);
    glVertex2f(-141.00, -21.00);
    glVertex2f(-147.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-166.00, -14.00);
    glVertex2f(-160.00, -14.00);
    glVertex2f(-155.00, -21.00);
    glVertex2f(-161.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-180.00, -14.00);
    glVertex2f(-174.00, -14.00);
    glVertex2f(-169.00, -21.00);
    glVertex2f(-175.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-194.00, -14.00);
    glVertex2f(-188.00, -14.00);
    glVertex2f(-183.00, -21.00);
    glVertex2f(-189.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-208.00, -14.00);
    glVertex2f(-202.00, -14.00);
    glVertex2f(-197.00, -21.00);
    glVertex2f(-203.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-222.00, -14.00);
    glVertex2f(-216.00, -14.00);
    glVertex2f(-211.00, -21.00);
    glVertex2f(-217.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(-236.00, -14.00);
    glVertex2f(-230.00, -14.00);
    glVertex2f(-225.00, -21.00);
    glVertex2f(-231.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(32.00, -14.00);
    glVertex2f(38.00, -14.00);
    glVertex2f(43.00, -21.00);
    glVertex2f(37.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(46.00, -14.00);
    glVertex2f(52.00, -14.00);
    glVertex2f(57.00, -21.00);
    glVertex2f(51.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(60.00, -14.00);
    glVertex2f(66.00, -14.00);
    glVertex2f(71.00, -21.00);
    glVertex2f(65.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(74.00, -14.00);
    glVertex2f(80.00, -14.00);
    glVertex2f(85.00, -21.00);
    glVertex2f(79.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(88.00, -14.00);
    glVertex2f(94.00, -14.00);
    glVertex2f(99.00, -21.00);
    glVertex2f(93.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(88.00, -14.00);
    glVertex2f(94.00, -14.00);
    glVertex2f(99.00, -21.00);
    glVertex2f(93.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(102.00, -14.00);
    glVertex2f(108.00, -14.00);
    glVertex2f(113.00, -21.00);
    glVertex2f(107.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(116.00, -14.00);
    glVertex2f(122.00, -14.00);
    glVertex2f(127.00, -21.00);
    glVertex2f(121.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(130.00, -14.00);
    glVertex2f(136.00, -14.00);
    glVertex2f(141.00, -21.00);
    glVertex2f(135.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(144.00, -14.00);
    glVertex2f(150.00, -14.00);
    glVertex2f(155.00, -21.00);
    glVertex2f(149.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(158.00, -14.00);
    glVertex2f(164.00, -14.00);
    glVertex2f(169.00, -21.00);
    glVertex2f(163.00, -21.00);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(172.00, -14.00);
    glVertex2f(178.00, -14.00);
    glVertex2f(183.00, -21.00);
    glVertex2f(177.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(186.00, -14.00);
    glVertex2f(192.00, -14.00);
    glVertex2f(197.00, -21.00);
    glVertex2f(191.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(200.00, -14.00);
    glVertex2f(206.00, -14.00);
    glVertex2f(211.00, -21.00);
    glVertex2f(205.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(214.00, -14.00);
    glVertex2f(220.00, -14.00);
    glVertex2f(225.00, -21.00);
    glVertex2f(219.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(228.00, -14.00);
    glVertex2f(234.00, -14.00);
    glVertex2f(239.00, -21.00);
    glVertex2f(233.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.647059 , 0.164706, 0.164706);
    glVertex2f(242.00, -14.00);
    glVertex2f(248.00, -14.00);
    glVertex2f(253.00, -21.00);
    glVertex2f(247.00, -21.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.847059 , 0.864706, 0.864706);
    glVertex2f(-90.00, -6.00 + lift);
    glVertex2f(25.00, -6.00 + lift);
    glVertex2f(42.00, -31.00 + lift);
    glVertex2f(-75.00, -31.00 + lift);
    glEnd();//lift








    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(25.00, 90.00);
    glVertex2f(30.00, 90.00);
    glVertex2f(30.00, -6.50);
    glVertex2f(25.00, -6.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-95.00, 70.00);
    glVertex2f(-90.00, 70.00);
    glVertex2f(-75.00, 55.50);
    glVertex2f(-80.00, 55.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(25.00, 70.00);
    glVertex2f(30.00, 70.00);
    glVertex2f(45.00, 55.50);
    glVertex2f(40.00, 55.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-65.00, 90.00 + lift);
    glVertex2f(-60.00, 90.00 + lift);
    glVertex2f(-60.00, -7.50 + lift);
    glVertex2f(-65.00, -7.50 + lift);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(0.00, 90.00 + lift);
    glVertex2f(5.00, 90.00 + lift);
    glVertex2f(5.00, -7.50 + lift);
    glVertex2f(0.00, -7.50 + lift);
    glEnd();//lift




    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-65.00, 90.00 + lift);
    glVertex2f(5.00, 90.00 + lift);
    glVertex2f(15.00, 69.50 + lift);
    glVertex2f(-55.00, 69.50 + lift);
    glEnd();//lift

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(-25.00, 110.00 + lift);
    glVertex2f(-10.00, 130.00 + lift);
    glVertex2f(5.00, 110.00 + lift);
    glEnd();//lift

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.58824, 0.24);
    glVertex2f(-25.00, 110.00 + lift);
    glVertex2f(5.00, 110.00 + lift);
    glVertex2f(5.00, 80.00 + lift);
    glVertex2f(-25.00, 80.0 + lift);
    glEnd();//lift

    glBegin(GL_QUADS);
    glColor3f(0.8824, 0.824, 0.24);
    glVertex2f(-15.00, 100.00 + lift);
    glVertex2f(0.00, 100.00 + lift);
    glVertex2f(0.00, 80.00 + lift);
    glVertex2f(-15.00, 80.0 + lift);
    glEnd();//lift


    //the sun
    glColor3f(1.0 ,1.0, 0.0);
    circle(23.00,40.00,-180.00,180.00);


        //the ship
    glBegin(GL_QUADS);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(-220.00 + shipX, 110.00 + shipY);
    glVertex2f(-175.00 + shipX, 60.00 + shipY);
    glVertex2f(-175.00 + shipX, 40.00 + shipY);
    glVertex2f(-220.00 + shipX, 90.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(-175.00 + shipX, 60.00 + shipY);
    glVertex2f(-175.00 + shipX, 40.00 + shipY);
    glVertex2f(-140.00 + shipX, 60.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.00);
    glVertex2f(-220.00 + shipX, 110.00 + shipY);
    glVertex2f(-190.00 + shipX, 110.00 + shipY);
    glVertex2f(-155.00 + shipX, 75.00 + shipY);
    glVertex2f(-175.00 + shipX, 60.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 0.00, 1.00);
    glVertex2f(-155.00 + shipX, 75.00 + shipY);
    glVertex2f(-175.00 + shipX, 60.00 + shipY);
    glVertex2f(-160.00 + shipX, 60.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(-155.00 + shipX, 75.00 + shipY);
    glVertex2f(-160.00 + shipX, 60.00 + shipY);
    glVertex2f(-140.00 + shipX, 60.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(-200.00 + shipX, 100.00 + shipY);
    glVertex2f(-200.00 + shipX, 160.00 + shipY);
    glVertex2f(-190.00 + shipX, 150.00 + shipY);
    glVertex2f(-190.00 + shipX, 90.00 + shipY);
    glEnd();//ship swim

    glBegin(GL_QUADS);
    glColor3f(0.00, 1.00, 0.00);
    glVertex2f(-190.00 + shipX, 150.00 + shipY);
    glVertex2f(-185.00 + shipX, 160.00 + shipY);
    glVertex2f(-185.00 + shipX, 95.00 + shipY);
    glVertex2f(-190.00 + shipX, 90.00 + shipY);
    glEnd();//ship swim side

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.80, 0.90);
    glVertex2f(-190.00 + shipX, 150.00 + shipY);
    glVertex2f(-185.00 + shipX, 160.00 + shipY);
    glVertex2f(-195.00 + shipX, 165.00 + shipY);
    glVertex2f(-200.00 + shipX, 160.00 + shipY);
    glEnd();//ship swim side


    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-95.00, 90.00);
    glVertex2f(-90.00, 90.00);
    glVertex2f(-90.00, -6.50);
    glVertex2f(-95.00, -6.50);
    glEnd(); // need to go behind ship

    //train
    glBegin(GL_QUADS);
    glColor3f(0.7824 + train, 0.724, 0.724);
    glVertex2f(85.00 + train, -5.00);
    glVertex2f(100.00 + train, -5.00);
    glVertex2f(100.00 + train, -25.00);
    glVertex2f(85.00 + train, -25.0);
    glEnd();//run

    glBegin(GL_QUADS);
    glColor3f(0.00, 1.00, 1.00);
    glVertex2f(75.00 + train, 7.00);
    glVertex2f(90.00 + train, 35.00);
    glVertex2f(100.00 + train, 25.00);
    glVertex2f(85.00 + train, -5.0);
    glEnd();//run

    glBegin(GL_QUADS);
    glColor3f(1.00, 0.00, 0.234230);
    glVertex2f(75.00 + train, 7.00);
    glVertex2f(85.00 + train, -5.00);
    glVertex2f(85.00 + train, -25.00);
    glVertex2f(75.00 + train, -10.0);
    glEnd();//run
    //test


    glBegin(GL_QUADS);
    glColor3f(0.8824, 0.824, 0.24);
    glVertex2f(226.00 + train, 25.00);
    glVertex2f(266.00 + train, 25.00);
    glVertex2f(266.00 + train, -25.00);
    glVertex2f(226.00 + train, -25.0);
    glEnd();//run train front

    glBegin(GL_QUADS);
    glColor3f(0.7824, 1.00, 0.724);
    glVertex2f(216.00 + train, 35.00);
    glVertex2f(256.00 + train, 35.00);
    glVertex2f(266.00 + train, 25.00);
    glVertex2f(226.00 + train, 25.0);
    glEnd();//run //roof of train

    glBegin(GL_QUADS);
    glColor3f(0.224, 0.824, 0.24);
    glVertex2f(216.00 + train, 35.00);
    glVertex2f(226.00 + train, 25.00);
    glVertex2f(226.00 + train, -25.00);
    glVertex2f(216.00 + train, -10.0);
    glEnd();//run train side

    glBegin(GL_QUADS);
    glColor3f(0.8824, 0.824, 0.24);
    glVertex2f(184.00 + train, 25.00);
    glVertex2f(224.00 + train, 25.00);
    glVertex2f(224.00 + train, -25.00);
    glVertex2f(184.00 + train, -25.0);
    glEnd();//run train front

    glBegin(GL_QUADS);
    glColor3f(0.7824, 1.00, 0.724);
    glVertex2f(174.00 + train, 35.00);
    glVertex2f(214.00 + train, 35.00);
    glVertex2f(224.00 + train, 25.00);
    glVertex2f(184.00 + train, 25.0);
    glEnd();//run //roof of train

    glBegin(GL_QUADS);
    glColor3f(0.224, 0.824, 0.24);
    glVertex2f(174.00 + train, 35.00);
    glVertex2f(184.00 + train, 25.00);
    glVertex2f(184.00 + train, -25.00);
    glVertex2f(174.00 + train, -10.0);
    glEnd();//run train side


    //test

    glBegin(GL_QUADS);
    glColor3f(0.8824, 0.824, 0.24);
    glVertex2f(142.00 + train, 25.00);
    glVertex2f(182.00 + train, 25.00);
    glVertex2f(182.00 + train, -25.00);
    glVertex2f(142.00 + train, -25.0);
    glEnd();//run train front

    glBegin(GL_QUADS);
    glColor3f(0.7824, 1.00, 0.724);
    glVertex2f(132.00 + train, 35.00);
    glVertex2f(172.00 + train, 35.00);
    glVertex2f(182.00 + train, 25.00);
    glVertex2f(142.00 + train, 25.0);
    glEnd();//run //roof of train

    glBegin(GL_QUADS);
    glColor3f(0.224, 0.824, 0.24);
    glVertex2f(132.00 + train, 35.00);
    glVertex2f(142.00 + train, 25.00);
    glVertex2f(142.00 + train, -25.00);
    glVertex2f(132.00 + train, -10.0);
    glEnd();//run train side

    glBegin(GL_QUADS);
    glColor3f(0.7824, 1.00, 0.724);
    glVertex2f(90.00 + train, 35.00);
    glVertex2f(130.00 + train, 35.00);
    glVertex2f(140.00 + train, 25.00);
    glVertex2f(100.00 + train, 25.0);
    glEnd();//run //roof of train

    glBegin(GL_QUADS);
    glColor3f(0.8824, 0.824, 0.24);
    glVertex2f(100.00 + train, 25.00);
    glVertex2f(140.00 + train, 25.00);
    glVertex2f(140.00 + train, -25.00);
    glVertex2f(100.00 + train, -25.0);
    glEnd();//run train front

    glBegin(GL_TRIANGLES);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(100.00 + train, 24.00);
    glVertex2f(100.00 + train, -5.00);
    glVertex2f(84.00 + train, -5.00);
    glEnd();//window train run


    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(15.00, 70.00 + lift);
    glVertex2f(10.00, 70.00 + lift);
    glVertex2f(10.00, -30.50 + lift);
    glVertex2f(15.00, -30.50 + lift);
    glEnd();//lift // need to go front train

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-55.00, 70.00 + lift);
    glVertex2f(-50.00, 70.00 + lift);
    glVertex2f(-50.00, -30.50 + lift);
    glVertex2f(-55.00, -30.50 + lift);
    glEnd();// need to go front train

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(40.00, 75.00);
    glVertex2f(45.00, 75.00);
    glVertex2f(45.00, -29.0);
    glVertex2f(40.00, -29.0);
    glEnd();// need to go front train

    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-75.00, 75.00);
    glVertex2f(-80.00, 75.00);
    glVertex2f(-80.00, -29.0);
    glVertex2f(-75.00, -29.0);
    glEnd();// need to go behind ship // need to go front train

    //plane
     glBegin(GL_QUADS);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(plane + 135.00, 165.00);
    glVertex2f(plane + 160.00, 220.00);
    glVertex2f(plane + 170.00, 220.00);
    glVertex2f(plane + 155.00, 165.00);
    glEnd();//wings plane fly

    glBegin(GL_QUADS);
    glColor3f(0.00, 1.00, 0.00);
    glVertex2f(plane + 100.00, 180.00);
    glVertex2f(plane + 200.00, 180.00);
    glVertex2f(plane + 200.00, 150.00);
    glVertex2f(plane + 100.00, 150.00);
    glEnd();//front plane fly

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(plane + 95.00, 185.00);
    glVertex2f(plane + 185.00, 185.00);
    glVertex2f(plane + 200.00, 180.00);
    glVertex2f(plane + 100.00, 180.00);
    glEnd();//front plane fly

    glBegin(GL_TRIANGLES);
    glColor3f(0.00, 1.00, 0.00);
    glVertex2f(plane + 100.00, 150.00);
    glVertex2f(plane + 80.00, 155.00);
    glVertex2f(plane + 100.00, 180.00);
    glEnd();//cockpit plane fly

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(plane + 95.00, 185.00);
    glVertex2f(plane + 80.00, 155.00);
    glVertex2f(plane + 100.00, 180.00);
    glEnd();//cockpit plane fly

    glBegin(GL_QUADS);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(plane + 135.00, 165.00);
    glVertex2f(plane + 155.00, 165.00);
    glVertex2f(plane + 185.00, 120.00);
    glVertex2f(plane + 165.00, 120.00);
    glEnd();//wings plane fly

    glBegin(GL_QUADS);
    glColor3f(1.00, 0.00, 0.00);
    glVertex2f(plane + 200.00, 180.00);
    glVertex2f(plane + 225.00, 180.00);
    glVertex2f(plane + 215.00, 160.00);
    glVertex2f(plane + 200.00, 150.00);
    glEnd();//wings plane fly

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(plane + 210.00, 180.00);
    glVertex2f(plane + 225.00, 210.00);
    glVertex2f(plane + 230.00, 210.00);
    glVertex2f(plane + 225.00, 180.00);
    glEnd();//wings plane fly

    glBegin(GL_QUADS);
    glColor3f(0.00, 0.00, 0.00);
    glVertex2f(plane + 190.00, 190.00);
    glVertex2f(plane + 225.00, 210.00);
    glVertex2f(plane + 230.00, 210.00);
    glVertex2f(plane + 225.00, 180.00);
    glEnd();//wings plane fly






    //bridge


    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex2f(-75.00, 75.00);
    glVertex2f(-80.00, 75.00);
    glVertex2f(-80.00, -29.0);
    glVertex2f(-75.00, -29.0);
    glEnd();// need to go behind ship // need to go front train



    glFlush();
}

void ptimer(int)
{
    switch(p)
    {
        case 1: if (plane > -500)
                    plane = plane - 1;
    }

    glutPostRedisplay();
    glutTimerFunc(1000/60,ptimer,0);
}

void ltimer(int)
{
    switch(state)
    {
        case 1: if (lift < 100)
                   lift = lift + 1;
                else
                    state = 2;
                    printf("%d", state);
                    break;
        case 3: if (lift > 0)
                    lift = lift - 1;
                else
                    state = 4;
                    p = 1;
                    printf("%d", state);
                    break;
    }

    glutPostRedisplay();
    glutTimerFunc(1000/30,ltimer,0);
}

void stimer(int)
{
    switch(state)
    {
        case 2: if(shipX >- 300 && shipY >- 300){
                   shipX = shipX + 1.5;
                   shipY = shipY - 1;
                }
                else
                    state = 3;
                    printf("%d", state);
                    break;



    }

    glutPostRedisplay();
    glutTimerFunc(1000/30,stimer,0);
}

void ttimer(int)
{
    switch(state)
    {
        case 4: if(train > -600){
                   train = train - 1;
                }
                else
                    state = 5;
                    printf("%d", state);
                    break;



    }

    glutPostRedisplay();
    glutTimerFunc(1000/60,ttimer,0);
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1350, 700);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Circle Application");
    init();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(0,ptimer,0);
    glutTimerFunc(0,ltimer,0);
    glutTimerFunc(0,stimer,0);
    glutTimerFunc(0,ltimer,0);
    glutTimerFunc(0,ttimer,0);
    glutMainLoop();
    return 0;
}
