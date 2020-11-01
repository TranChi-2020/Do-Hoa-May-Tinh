#include <GL/glut.h>

      int   m_x,m_y;                // mouse x y
      bool  m_down = false;

      int   play = true;          //жизнь продолжается
      int   size_ = 50;          //диаметр клетки

const int   X=20;            // сколько клеток в ряду
const int   Y=15;            // сколько рядов


int w =  X*size_;              //ширина окна
int h =  Y*size_;              //высота окна

struct P
{
    bool life;
    int next;
} p [X][Y];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,255);
    glPointSize(size_);
    glBegin(GL_POINTS);
    for (int y = 0; y < Y; ++y)
        for (int x = 0; x < X; ++x)
            if (p[x][y].life) glVertex2f(size_/2 + x*size_, size_/2 + y*size_);


    if (m_down && m_x > 0 && m_y > 0 &&  m_x < X * size_ && m_y < Y*size_)

        p[m_x/size_][m_y/size_].life = 1;

        else
                    {
                        int x = m_x/size_;  int y = m_y/size_;
                        glVertex2f(size_/2 + size_ * x ,size_/2 + size_ * y);
                    }

    glEnd();

    glutSwapBuffers(); //glFlush();

}

int left (int xx)
{
 if (xx == 0 ) xx = X - 1; else xx--;
 return xx;
}

int right (int xx)
{
 if (xx == X - 1 ) xx = 0; else xx++;
 return xx;
}


int up (int yy)
{
 if (yy == 0 ) yy = Y-1; else yy--;
 return yy;
}

int down (int yy)
{
 if (yy == Y - 1 ) yy = 0; else yy++;
 return yy;
}

void update()
{

      for (int y = 0; y < Y; ++y) for (int x = 0; x < X; ++x)
      {
                  int counter    = 0;

                  if (p[left(x)]    [y].life)    counter++;         //left
                  if (p[right(x)]   [y].life)    counter++;         //right
                  if (p[x]          [up(y)].life) counter++;        //up
                  if (p[x]          [down(y)].life) counter++;      //down

                  if (p[left(x)]    [up(y)].life) counter++;        //left  +  up
                  if (p[right(x)]   [up(y)].life) counter++;         //right + down

                  if (p[left(x)]    [down(y)].life) counter++;      //left + up
                  if (p[right(x)]   [down(y)].life) counter++;      //right

                  if ( p[x][y].life) if (counter != 2 && counter != 3) p[x][y].next = false; else p[x][y].next = true;
                  if (!p[x][y].life) if (counter == 3) p[x][y].next = true; else p[x][y].next = false;
      }
        for (int y = 0; y < Y; ++y) for (int x = 0; x < X; ++x)
        p[x][y].life  = p[x][y].next;


}



void timer(int = 0)
{

    if(GetAsyncKeyState('1'))  play = 1; // 1 2 3 это клавиши ))
    if(GetAsyncKeyState('2'))  play = 0;
    if(GetAsyncKeyState('3'))  for (int y = 0; y < Y; ++y) for (int x = 0; x < X; ++x)
                               {p[x][y].next =0; p[x][y].life  = 0;} //clear
    if (play) update ();

    display();
    glutTimerFunc(10, timer, 0);
}

void mouse (int button, int state, int ax, int ay)
{
    m_y=ay;
    m_x=ax;
    m_down = state == GLUT_DOWN;
}

void motion (int ax, int ay)
{
    m_x=ax;
    m_y=ay;
}

void mousewrite ()
{

}

void motionpass (int ax, int ay)
{
   m_x=ax;
   m_y=ay;
}

int main(int argc, char **argv)
{
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
       {

            p[x][y].life  = rand()% 2;
            p[x][y].next  = 0;
      }

      glutInit(&argc, argv);
      //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(w, h);
      glutInitWindowPosition(-10, -10);
      glutCreateWindow("Brownian motion");
      glClearColor(0, 0, 0, 1.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho (0, w, h, 0, -1, 1);
      glutDisplayFunc(display);
      timer();
      glutMouseFunc(mouse);
      glutMotionFunc(motion);
      glutPassiveMotionFunc(motionpass);
      mousewrite();
      glutMainLoop();
}



