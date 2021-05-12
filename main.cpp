#include <windows.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;

GLfloat a = 0.0f;
GLfloat b = 0.0f;
GLfloat c = 0.0f;

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Idle()
{
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255,255,0);
    glVertex2f(0.0f, 0.7f);//12
    glVertex2f(0.0f, 0.6f);

    glVertex2f(0.38f, 0.7f);//1
    glVertex2f(0.34f, 0.6f);

    glVertex2f(-0.38f, 0.7f);//11
    glVertex2f(-0.34f, 0.5f);

    glVertex2f(-0.38f, -0.7f);
    glVertex2f(-0.34f, -0.5f);//7

    glVertex2f(0.7f, 0.48f);
    glVertex2f(0.6f, 0.32f); //2

    glVertex2f(0.7f, -0.48f);
    glVertex2f(0.6f, -0.35f);

    glVertex2f(-0.7f, -0.48f);
    glVertex2f(-0.6f, -0.32f);

    glVertex2f(-0.7f, 0.48f);
    glVertex2f(-0.6f, 0.32f);

    glVertex2f(-0.7f, 0.48f);
    glVertex2f(-0.6f, 0.32f);

    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.6f, 0.0f);

    glVertex2f(0.0f, -0.7f);
    glVertex2f(0.0f, -0.6f);

    glVertex2f(0.38f, -0.7f);
    glVertex2f(0.34f, -0.6f);

    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glEnd();

glLoadIdentity();
    glBegin(GL_LINES);
    glColor3f(1.1f, 1.1f, 1.1f);
    glVertex2f(0.7f, 0.7f);
    glVertex2f( -0.7f, 0.7f);

    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.7f, -0.7f );

    glVertex2f(-0.7f, -0.7f);
    glVertex2f(0.7f, -0.7f );


    glVertex2f(0.7f, -0.7f);
    glVertex2f(0.7f, 0.7f );

    glEnd();


    glPushMatrix();
    glRotatef(a,0.0,0.0,0.1);
    glLineWidth(2.4f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // second
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.0f, 0.5f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(b,0.0,0.0,0.1);
    glLineWidth(3.4f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);  //minute
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.0f, 0.5f);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(c,0.0,0.0,0.1);
    glLineWidth(5.4f);
    glBegin(GL_LINES);
    glColor3ub(0, 255, 255);  // Hour
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.0f, 0.4f);

    glEnd();
    glPopMatrix();



    a-=0.0075f;
    if(a<=-360)
        {
            if(b<=-360)
            {
                c-=5.0f;
                a=0.0f;
                b=0.0f;
            }
            else
                {
                    b-=6.0f;
                    a=0.0f;
            }

         }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Clock");
    glutDisplayFunc(display);//
    initGL();
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;}
