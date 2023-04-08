#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

using namespace std;

float x = 0.0f; // Posición horizontal del proyectil en metros
float y = 0.0f; // Posición vertical del proyectil en metros

void drawFigures() {
    
    // Esfera
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
    glutSolidSphere(1.0f, 20, 20);

    // Triangulo Izquierdo
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();

    // Triangulo Central
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();

    // Triangulo Derecho
    glBegin(GL_TRIANGLES);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    // Triangulo Inferior
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glEnd();
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Ejes Coordenados
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-50.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -50.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd();

    glTranslatef(x, y, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidSphere(1.0f, 20, 20); // Esfera en la posición actual del proyectil

    glTranslatef(0.0f, 0.0f, 0.0f);
    drawFigures();

    glutSwapBuffers();
}

float angle = 65.0f; // Ángulo de lanzamiento en grados
float speed = 20.0f; // Velocidad inicial en metros por segundo
float gravity = 9.8f; // Aceleración de la gravedad en metros por segundo al cuadrado
float time = 0.0f; // Tiempo transcurrido desde el lanzamiento en segundos
float PI = 3.1416; //Constante PI

void update(int value) {
    
    // Actualiza la posición del proyectil en función del tiempo transcurrido
    x = speed * cos(angle * PI / 180) * time;
    y = speed * sin(angle * PI / 180) * time - 0.5f * gravity * time * time;

    float t_max = speed * sin(angle * PI / 180) / gravity;
    float h_max = y + (speed * sin(angle * PI / 180)) * (speed * sin(angle * PI / 180)) / (2 * gravity);

    if (h_max <= 0.0f) {
        return;
    }

    printf("Altura maxima por intervalo de tiempo: %.2f metros\n", h_max);

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 16 milisegundos (aproximadamente 60 FPS)
    time += 0.016f; // Tiempo transcurrido en 0.016 segundos (aproximadamente 60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Lanzamiento de Proyectil - C++ | OpenGL - Computación Gráfica");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0f, 50.0f, -50.0f, 50.0f, -1.0f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
