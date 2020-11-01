#include <ctime>
#include <deque>
#include <GL/glut.h>
#include <unistd.h>

#define UNUSED(param) (void)(param)
#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

char title[] = "SNAKE - GAME RAN SAN MOI";

float map_half_length = 30.0f;

int direction = DOWN;
int move_speed = 100;
bool moved = false;
std::deque< std::deque<float> > part_coords; // hang doi 2 chieu

bool food_available = false;
int food_coords[2];

int growth_stage = 0;
int growth = 2;

void spawnFood(){
    if(!food_available){
        while(true){
            bool collides = false;

            // toa do ngau nhien tam thoi
            int temp_food_coords[2] = { food_coords[0] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length,
                                        food_coords[1] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length };

            // co va cham voi ran khong?
            for(unsigned int a = 0; a < part_coords.size(); a++){
                if(temp_food_coords[0] == part_coords[a][0] &&
                   temp_food_coords[1] == part_coords[a][1]){
                    collides = true;
                }
            }

            // neu no khong va cham voi con ran, thi hay bien no thanh thanh toa do thuc an
            if(collides == false){
                food_coords[0] = temp_food_coords[0];
                food_coords[1] = temp_food_coords[1];

                food_available = true;

                break;
            }
        }
    }

    glLoadIdentity(); // glLoadIdentity thay the ma trasn hien tai bang ma tran danh tinh. no tuong duong ve mat ngu nghia voi viec goi glLoadMatrix
    glTranslatef(food_coords[0], food_coords[1], -40.0f); //glTranslate tao ra mot ban dich x y z. ma tran hien tai (xem glMatrixMode) duoc nhan voi ma tran dich nay, 
	//voi san pham thay the ma tran hien tai, nhu the glMultMatrix duoc goi voi ma tran sau doi so cua no
    
	glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON); // glBegin va glEnd phan dinh cac dinh xac dinh mot nguyen thuy hoac mot nhom nhu nguyen thuy. 
	//glBegin chap nhan 1 doi so duy nhat trong do muoi cach cac dinh duoc dien giai. lay n la so nguyen bat dau tu 1 va N la tong dinh duoc chi dinh
	
        glVertex2d( 1.0f,  1.0f);
        glVertex2d( 1.0f, -1.0f);
        glVertex2d(-1.0f, -1.0f);
        glVertex2d(-1.0f,  1.0f);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // thu tu dinh la chieu kim dong ho
    // thu tu phu la truoc, sau, trai, phai, tren, duoi (neu co)

    // lap lai kich thuoc con ran va ve tung phan tai toa do tuong ung cua no
    for(unsigned int a = 0; a < part_coords.size(); a++){
        glLoadIdentity();
        glTranslatef(part_coords[a][0], part_coords[a][1], -40.0f);
        glColor3f(0.0f, 1.0f, 0.0f);

        glBegin(GL_POLYGON);
            glVertex2d( 1.0f,  1.0f); // cac lenh ham glVertex duoc su dung de chi dinh cac dinh diem , duong thang va da giac
            glVertex2d( 1.0f, -1.0f); 
            glVertex2d(-1.0f, -1.0f);
            glVertex2d(-1.0f,  1.0f);
        glEnd();
    }

    spawnFood();

    glutSwapBuffers(); // thuc hien trao doi bo dem tren lop duoc su dung cho cua so hien tai
    // glutSwapBuffers thuc day cac noi dung cua bo dem sau cua lop trong su dung cua cua so hien hanh de tro thanh noi dung cua bo dem truoc

}

void moveSnake(int new_direction){
    direction = new_direction;

    int last_part = part_coords.size() - 1;
    std::deque<float> new_head = part_coords[last_part];

    if(direction == UP){
        // co phai ran da dung trung minh
        for(unsigned int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0]        == part_coords[a][0] &&
               part_coords[0][1] + 2.0f == part_coords[a][1]){
                exit(0);
            }
        }

        // co phai ran da va vao tuong
        if(part_coords[0][1] == map_half_length){
            exit(0);
        }

        // chung ta da nhan duoc thuc an
        if(part_coords[0][0]        == food_coords[0] &&
           part_coords[0][1] + 2.0f == food_coords[1]){
            growth_stage++;
            food_available = false;
        }

        new_head[1] = part_coords[0][1] + 2.0f;
    } else if(direction == DOWN){
        
        for(unsigned int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0]        == part_coords[a][0] &&
               part_coords[0][1] - 2.0f == part_coords[a][1]){
                exit(0);
            }
        }

    
        if(part_coords[0][1] == -map_half_length){
            exit(0);
        }

        
        if(part_coords[0][0]        == food_coords[0] &&
           part_coords[0][1] - 2.0f == food_coords[1]){
            growth_stage++;
            food_available = false;
        }

        new_head[1] = part_coords[0][1] - 2.0f;
    } else {
        new_head[1] = part_coords[0][1];
    }

    if(direction == LEFT){
        
        for(unsigned int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0] - 2.0f == part_coords[a][0] &&
               part_coords[0][1]        == part_coords[a][1]){
                exit(0);
            }
        }

    
        if(part_coords[0][0] == -map_half_length){
            exit(0);
        }

        if(part_coords[0][0] - 2.0f == food_coords[0] &&
           part_coords[0][1]        == food_coords[1]){
            growth_stage++;
            food_available = false;
        }

        new_head[0] = part_coords[0][0] - 2.0f;
    } else if(direction == RIGHT){
       
        for(unsigned int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0] + 2.0f == part_coords[a][0] &&
               part_coords[0][1]        == part_coords[a][1]){
                exit(0);
            }
        }

        
        if(part_coords[0][0] == map_half_length){
            exit(0);
        }

        
        if(part_coords[0][0] + 2.0f == food_coords[0] &&
           part_coords[0][1]        == food_coords[1]){
            growth_stage++;
            food_available = false;
        }

        new_head[0] = part_coords[0][0] + 2.0f;
    } else {
        new_head[0] = part_coords[0][0];
    }

    part_coords.push_front(new_head);

    if(!growth_stage){
        part_coords.pop_back();
    } else if(growth_stage == growth){
        growth_stage = 0;
    } else {
        growth_stage++;
    }

    glutPostRedisplay();
}

void keyboard(int key, int x, int y){
    UNUSED(x); // macro tham so UNUSED di dong 
    UNUSED(y);

    switch(key){
        case GLUT_KEY_UP:{
            if(direction == LEFT || direction == RIGHT){
                moved = true;

                moveSnake(UP);
            }

            break;
        }

        case GLUT_KEY_DOWN:{
            if(direction == LEFT || direction == RIGHT){
                moved = true;

                moveSnake(DOWN);
            }

            break;
        }

        case GLUT_KEY_LEFT:{
            if(direction == UP || direction == DOWN){
                moved = true;

                moveSnake(LEFT);
            }

            break;
        }

        case GLUT_KEY_RIGHT:{
            if(direction == UP || direction == DOWN){
                moved = true;

                moveSnake(RIGHT);
            }

            break;
        }
    }

    glutPostRedisplay();
}

void initGL(){
    glMatrixMode(GL_PROJECTION); // dat che do ma tran hien tai
    gluPerspective(75.0f, 1, 0.0f, 35.0f);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void moveSnakeAuto(int value){
    if(!moved){
        UNUSED(value);

        if(direction == UP){
            moveSnake(UP);
        } else if(direction == DOWN){
            moveSnake(DOWN);
        } else if(direction == LEFT){
            moveSnake(LEFT);
        } else if(direction == RIGHT){
            moveSnake(RIGHT);
        }
    } else {
        moved = false;
    }

    glutTimerFunc(move_speed, moveSnakeAuto, 0);
}

void reshape(GLsizei width, GLsizei height){
    UNUSED(width);
    UNUSED(height);

    // co dinhh kich thuoc cua so
    glutReshapeWindow(600, 600);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutCreateWindow(title);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);
    glutTimerFunc(move_speed, moveSnakeAuto, 0);

    int initSize = 3;

    // chi dinh toa do tung phan con ran
    for(int a = 1; a <= initSize; a++){
        std::deque<float> row;

        row.push_back(0.0f);
        row.push_back((map_half_length + 2.0f + (initSize * 2)) - (a * 2));

        part_coords.push_front(row);
    }
    srand(time(NULL));
    initGL();
    glutMainLoop();
    return 0;
}


