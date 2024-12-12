#include <GL/glut.h>
#include <iostream>

// Positions initiales des deux voitures
float car1X = -1.0f; // Voiture 1
float car2X = 1.0f;  // Voiture 2
float speedCar1 = 0.02f; // Vitesse de la voiture 1
float speedCar2 = 0.01f; // Vitesse de la voiture 2

// Fonction pour dessiner une voiture
void drawCar(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b); // Couleur de la voiture
    glBegin(GL_POLYGON); // Corps de la voiture
    glVertex2f(x - 0.1f, y - 0.05f); // Bas-gauche
    glVertex2f(x + 0.1f, y - 0.05f); // Bas-droite
    glVertex2f(x + 0.1f, y + 0.05f); // Haut-droite
    glVertex2f(x - 0.1f, y + 0.05f); // Haut-gauche
    glEnd();

    // Roues de la voiture
    glColor3f(0.0f, 0.0f, 0.0f); // Noires
    glBegin(GL_POLYGON); // Roue gauche
    glVertex2f(x - 0.08f, y - 0.06f);
    glVertex2f(x - 0.05f, y - 0.06f);
    glVertex2f(x - 0.05f, y - 0.08f);
    glVertex2f(x - 0.08f, y - 0.08f);
    glEnd();

    glBegin(GL_POLYGON); // Roue droite
    glVertex2f(x + 0.05f, y - 0.06f);
    glVertex2f(x + 0.08f, y - 0.06f);
    glVertex2f(x + 0.08f, y - 0.08f);
    glVertex2f(x + 0.05f, y - 0.08f);
    glEnd();
}

// Fonction d'affichage
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dessiner les deux voitures
    drawCar(car1X, -0.5f, 1.0f, 0.0f, 0.0f); // Voiture rouge
    drawCar(car2X, 0.5f, 0.0f, 0.0f, 1.0f);  // Voiture bleue

    glutSwapBuffers();
}
//Deux objets en collision etc..(ajout des routes, des panneaux de circulations, arret s'il y'a feu rouge, deplacer si feu vert) PFE
// Fonction pour mettre à jour les positions des voitures
void update(int value) {
    //carAgent
    car1X += speedCar1; // Déplacer la voiture 1
    car2X -= speedCar2; // Déplacer la voiture 2

    // Revenir à la position initiale si les voitures sortent de l'écran

    if (car1X > 1.2f) car1X = -1.0f;
    if (car2X < -1.2f) car2X = 1.0f;

    glutPostRedisplay(); // Redessiner
    glutTimerFunc(16, update, 0); // Appeler cette fonction toutes les 16ms (~60 FPS)
}

// Initialisation OpenGL
void init() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f); // Fond gris clair
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Définir le système de coordonnées
}

// Fonction principale
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Two Cars Simulation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0); // Lancer la mise à jour
    glutMainLoop();
    return 0;
}
