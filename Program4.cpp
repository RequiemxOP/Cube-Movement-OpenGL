#include <GL/glut.h>

int screenWidth = 800;
int screenHeight = 600;

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat distanceZ = -5.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, distanceZ);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    // Draw the color cube
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Left face
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Top face
    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f
    );
// Bottom face
glColor3f(0.0f, 1.0f, 1.0f);  // Cyan
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);

glEnd();

glFlush();
glutSwapBuffers();
}

void reshape(int width, int height)
{
    screenWidth = width;
    screenHeight = height;

    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q' || key == 27)  // 'q', 'Q', or ESC key to exit the program
        exit(0);
}

void specialKeys(int key, int x, int y)
{
    const GLfloat stepSize = 0.9f;

    switch (key) {
    case GLUT_KEY_UP:
        angleX -= stepSize;
        break;
    case GLUT_KEY_DOWN:
        angleX += stepSize;
        break;
    case GLUT_KEY_LEFT:
        angleY -= stepSize;
        break;
    case GLUT_KEY_RIGHT:
        angleY += stepSize;
        break;
    case GLUT_KEY_PAGE_UP:
        distanceZ += stepSize;
        break;
    case GLUT_KEY_PAGE_DOWN:
        distanceZ -= stepSize;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Camera Movement");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}