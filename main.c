
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include<string.h>
#include<unistd.h>
#include <math.h>
#define PI 3.1415927
int flag=0;
  //int choice=0;
double sp_x=0.0,sp_y=0.0,sp_z=0.0;
double c1_x=0,c1_y=0,c1_z=0;
double c2_x=0,c2_y=0,c2_z=0;
double c3_x=0,c3_y=0,c3_z=0;


static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
float _angle=0.0,angle=0.0;
void text()
{
    glColor3f(1,0,0);
     glMatrixMode(GL_PROJECTION);
     glPushMatrix();
     glLoadIdentity();
     gluOrtho2D(0,600,0,600);
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glLoadIdentity();


     glColor3f(0,1,1);
     glRasterPos2i(230,550);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"SHUF CUPS");

     glColor3f(1,1,0);
     glRasterPos2i(130,400);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"1. PLAY");

     glColor3f(1,0,1);
     glRasterPos2i(170,180);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"POSITION OF THE BALL");

     glColor3f(1,1,0);
     glRasterPos2i(130,370);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"2.EXIT");
     glColor3f(1,0,0);
     glRasterPos2i(280,440);
     glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"2");
     glColor3f(1,0,0);
     glRasterPos2i(180,440);
     glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"1");
     glColor3f(1,0,0);
     glRasterPos2i(380,440);
     glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"3");



     glColor3f(0,0,1);
     glRasterPos2i(450,120);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"SAMALA HARIKA");

       glColor3f(0,0,1);
     glRasterPos2i(450,90);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"1PE14CS122");

       glColor3f(0,0,1);
     glRasterPos2i(450,60);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"SHOBHIT KUMAR");

       glColor3f(0,0,1);
     glRasterPos2i(450,30);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"1PE14CS132");

     glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glPopMatrix();
     glMatrixMode(GL_MODELVIEW);



     //glutTimerFunc(5,text,0);
}
void Switch(int key,int x,int y)
{

if(key == 49)
    {
        text();
    }


if(key == 50)
    {
        abort();
    }


            glutPostRedisplay();
}
void drawtext(char ch[],int xpos,int ypos)
{
    int numofchar=strlen(ch);
    int i;
    glLoadIdentity();
    glRasterPos2f(xpos,ypos);
    for(i=0;i<=numofchar-1;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ch[i]);
    }
}
void screen0()
{

     glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0.2,0.2,0.2,1);
     glColor3f(1,1,1);
   // text();
    glutSwapBuffers();
    glFlush();


//return 0;
}
void screentestwon()
{
glColor3f(1,0,0);
     glMatrixMode(GL_PROJECTION);
     glPushMatrix();
     glLoadIdentity();
     gluOrtho2D(0,600,0,600);
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glLoadIdentity();


     glColor3f(0.0,0.0,0.0);
     glRasterPos2i(180,400);
     glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"YOU WON");

    }
    void screentestlost()
{
glColor3f(1,0,0);
     glMatrixMode(GL_PROJECTION);
     glPushMatrix();
     glLoadIdentity();
     gluOrtho2D(0,600,0,600);
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glLoadIdentity();


     glColor3f(0.0,0.0,0.0);
     glRasterPos2i(180,400);
     glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char*)"YOU LOST");

    }
float _cameraangle=2.0;
void update()
{

_angle+=1.0f;

if(_angle>360.f)

{

_angle-=-1.0;

}

glutPostRedisplay();

//glutTimerFunc(5,update,0);

}



//GLfloat angle = 0.0;
//GLfloat fangle=20.0;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

//sphere resize

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

int x=0,y=0;

void draw_cylinder1(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)

{

    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

        glTranslated(c1_x,c1_y,c1_z);
    /** Draw the tube */
    glColor3f(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}
void draw_cylinder2(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)

{

    glTranslated(c2_x,c2_y,c2_z);
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;


    /** Draw the tube */
    glColor3f(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
    }
void draw_cylinder3(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)

{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
      glTranslated(c3_x,c3_y,c3_z);


    /** Draw the tube */
    glColor3f(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();

}
void drawcentresphere(void)
{
glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(sp_x,sp_y,sp_z);
    glTranslated(0.0,-1.5,-10);
    glRotatef(8.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 1.0, 1.0, 0.0);
    glRotatef(30.0, 1.0, 1.0, 1.0);
    glTranslatef(0.2, 0.8, 0.7);//CENTRE


    glutSolidSphere(0.3,50,50);// radius,slices,stacks
    glPopMatrix();
    glutSwapBuffers();

}

void drawrightsphere()
{glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(sp_x,sp_y,sp_z);
    glTranslated(0.0,-1.5,-10);
    glRotatef(10.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 1.0, 1.0, 0.0);
    glRotatef(10.0, 1.0, 1.0, 1.0);
    glTranslatef(2.8, 0.0, 0.7);//RIGHT
    glutSolidSphere(0.3,50,50);// radius,slices,stacks
    glPopMatrix();
    glutSwapBuffers();
}
void drawleftsphere()
{
 glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(sp_x,sp_y,sp_z);
    glTranslated(0.0,-1.5,-10);
    //glTranslatef(-1.0 ,-1.0 ,-1.0);
glRotatef(10.0, 1.0, 0.0, 0.0);
glRotatef(20.0, 1.0, 1.0, 0.0);
glRotatef(30.0, 1.0, 1.0, 1.0);

glTranslatef(-2.2, 2.65, 0.5);//LEFT

    glutSolidSphere(0.3,50,50);// radius,slices,stacks


    glPopMatrix();
   glutSwapBuffers();


}



int RandomNumberGenerator(const int nMin,const int nMax,const int nNumOfNumsToGenerate)
{
int number;
number = rand()%(nMax-nMin) + nMin;
return number;
}
void drawscene()
{
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 screen0();


glLoadIdentity();
     glPushMatrix();
     glTranslatef(0.0,0.5,-3.0);
    glRotatef(70, 1.0, 0.0, 0.0);

    glRotatef(_cameraangle,0.0f,0.0f,-3.0f);


    glRotatef(_angle,1.0f,0.0f,5.0f);


    draw_cylinder1(0.25, 0.75, 255, 160, 100);//center
    glEnd();
    glPopMatrix();



    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.75,0.5,-3.0);
    glRotatef(70, 1.0, 0.0, 0.0);
//    glRotatef(angle,0,1,0);
     glRotatef(_cameraangle,0.0f,0.0f,3.0f);
    glRotatef(_angle,1.0f,0.0f,5.0f);
    draw_cylinder2(0.25,0.75, 255, 160, 100);//left

    glPopMatrix;


    glLoadIdentity();
   glPushMatrix();
   glTranslatef(-0.75,0.5,-3.0);
   glRotatef(70, 1.0, 0.0, 0.0);
//   glRotatef(angle,0,1,0);
    glRotatef(_cameraangle,0.0f,0.0f,-3.0f);
    glRotatef(_angle,1.0f,0.0f,5.0f);
    draw_cylinder3(0.25, 0.75, 255, 160, 100);//right


//drawleftsphere();
   glEnd();
    glPopMatrix();
    glFlush();

}
void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 400, 0.0, 400);
  glViewport(400,400, 800, 800);
}
void specialkey(int key,int x,int y,int z)
{
switch(key)
{       case  GLUT_KEY_END:
        {sp_x+=5.0;sp_y+=5.0;sp_z+=5.0;break;}

        case GLUT_KEY_F1:
          {  c1_x=0.0; c1_y+= 0.05; c1_z=0.0; break;}
        case GLUT_KEY_F2:
           { c2_x=0.0; c2_y+= 0.05; c2_z=0.0; break;}

        case GLUT_KEY_F3:
           { c3_x=0.0; c3_y+= 0.05; c3_z=0.0;break; }

        case GLUT_KEY_F4:
           { c1_x=0.0; c1_y-= 0.05; c1_z=0.0;break; }

        case GLUT_KEY_F5:
           { c2_x=0.0; c2_y-= 0.05; c2_z=0.0;break; }

        case GLUT_KEY_F6:
           { c3_x=0.0; c3_y-= 0.05; c3_z=0.0;break;}

        }
        glutPostRedisplay();
}


   int choice=0;
void userinteraction()
{

    printf(" guess the number of cylinder where is ball located  \n number1: left cylinder \n number 2: centre cylinder \n number 3: right cylinder\n");
    printf("choose number\n");
    scanf("%d",&choice);


return 0;


}



void loop (int val)
{
if (angle<=50)
{
angle+=1.0;
glutTimerFunc(15,loop,0);
}
else
{
for(angle=50;angle>=150;angle-=9.0)

glutTimerFunc(25,loop,0);


//glutPostRedisplay();
}
glutPostRedisplay();
}
/*void down(int  val)
{
//if(fangle>=20)
{
fangle-=3.0;
glutTimerFunc(5,down,0);
}
}*/

void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, (GLdouble)width/(GLdouble)height,
                   0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   drawscene();
text();



   flag=RandomNumberGenerator(1,3,1);

   if(flag==2)
drawcentresphere();


if(flag==1)
drawleftsphere();

if(flag==3)
drawrightsphere();          //sleep(2);

   sleep(5);

   for(_angle=0;_angle<=360;_angle+=1.5)
   {
   usleep(10000);
   drawscene();

   }
   userinteraction();
   //sleep(2);
      flag=RandomNumberGenerator(1,3,1);

if(flag==2)
{
drawcentresphere();
//printf("flag is %d",flag);
//printf("choice is %d ",choice);
printf("ball is placed at centre cylinder\n");
if(choice==flag)
{
printf("user won heyy your'e  correct\n");
screentestwon();

system("play nice.wav&>/dev/null&");
}
else
{
printf("you lost \n try again !!!\n");
screentestlost();
system("play wrong.wav&>/dev/null&");
}

printf("\n");

}if(flag==1)
{
drawleftsphere();
//printf("flag is %d ",flag);
//printf("choice is %d ",choice);
if(choice==flag)
{
printf("user won heyy your'e is correct\n");
screentestwon();
system("play nice.wav&>/dev/null&");

}
else
{
printf("you lost \n try again !!!");
screentestlost();
system("play wrong.wav&>/dev/null&");
}
printf("ball is placed at left cylinder \n");
printf("\n");

}
if(flag==3)
{
//printf("flag is %d ",flag);
//printf("choice is %d ",choice);
if(choice==flag)
{
printf("user won heyy your'e correct\n");
screentestwon();
system("play nice.wav&>/dev/null&");
}
else
{
printf("you lost \n try again!!!\n");
screentestlost();
system("play wrong.wav&>/dev/null&");
}
drawrightsphere();
printf("ball is placed at right cylinder \n");

}


glFlush();

}



void spincylinder()
{ theta[axis]+=1.0;
theta[axis]-=360;
if(theta[axis]>360.0)
display();
glutPostRedisplay();
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(2500,1000);
    glutCreateWindow("Create Cylinder");
    glClearColor(0.0,0.0,0.0,0.0);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutSpecialFunc(specialkey);
    glutKeyboardFunc(Switch);
     srand(time(NULL));
   // RandomNumberGenerator(1,3,1);
    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

  // glutTimerFunc(15,loop,0);
 //glutTimerFunc(5,down,0);
    //glutIdleFunc(spincylinder);
//  glutTimerFunc(10,update,);
   //glutTimerFunc(15,drawsphere,0);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();

    //return 999;
}
