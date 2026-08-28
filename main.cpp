#include <GL/glut.h>
#include <cmath>

const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 800;

float planePosX = -140.0f;
float planePosY = 110.0f;
float planeSpeed = 3.5f;

void init() {
    glClearColor(0.08f, 0.12f, 0.22f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, (GLdouble)WINDOW_WIDTH, 0.0f, (GLdouble)WINDOW_HEIGHT);
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1416f * (float)i / (float)num_segments;
        glVertex2f(cx + r * cosf(theta), cy + r * sinf(theta));
    }
    glEnd();
}

// Unified Vector Font Drawer matching original line coordinates
void drawChar(char c, float x, float y, float scale) {
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    if (c == 'T') {
        glVertex2f(x, y + 12 * scale); glVertex2f(x + 10 * scale, y + 12 * scale);
        glVertex2f(x + 5 * scale, y + 12 * scale); glVertex2f(x + 5 * scale, y);
    } else if (c == 'E') {
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y);
        glVertex2f(x, y); glVertex2f(x + 8 * scale, y);
        glVertex2f(x, y + 6 * scale); glVertex2f(x + 6 * scale, y + 6 * scale);
    } else if (c == 'R') {
        glVertex2f(x, y); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x + 7 * scale, y + 12 * scale);
        glVertex2f(x + 7 * scale, y + 12 * scale); glVertex2f(x + 7 * scale, y + 6 * scale);
        glVertex2f(x + 7 * scale, y + 6 * scale); glVertex2f(x, y + 6 * scale);
        glVertex2f(x + 3 * scale, y + 6 * scale); glVertex2f(x + 8 * scale, y);
    } else if (c == 'M') {
        glVertex2f(x, y); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x + 4 * scale, y + 6 * scale);
        glVertex2f(x + 4 * scale, y + 6 * scale); glVertex2f(x + 8 * scale, y + 12 * scale);
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x + 8 * scale, y);
    } else if (c == 'I') {
        glVertex2f(x + 3 * scale, y); glVertex2f(x + 3 * scale, y + 12 * scale);
    } else if (c == 'N') {
        glVertex2f(x, y); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 8 * scale, y); glVertex2f(x + 8 * scale, y + 12 * scale);
    } else if (c == 'A') {
        glVertex2f(x, y); glVertex2f(x + 4 * scale, y + 12 * scale);
        glVertex2f(x + 4 * scale, y + 12 * scale); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 2 * scale, y + 4 * scale); glVertex2f(x + 6 * scale, y + 4 * scale);
    } else if (c == 'L') {
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y);
        glVertex2f(x, y); glVertex2f(x + 7 * scale, y);
    } else if (c == 'C') {
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y);
        glVertex2f(x, y); glVertex2f(x + 8 * scale, y);
    } else if (c == 'F') {
        glVertex2f(x, y); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x + 8 * scale, y + 12 * scale);
        glVertex2f(x, y + 6 * scale); glVertex2f(x + 6 * scale, y + 6 * scale);
    } else if (c == 'O') {
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x, y + 12 * scale);
    } else if (c == 'S') {
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y + 6 * scale);
        glVertex2f(x, y + 6 * scale); glVertex2f(x + 8 * scale, y + 6 * scale);
        glVertex2f(x + 8 * scale, y + 6 * scale); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 8 * scale, y); glVertex2f(x, y);
    } else if (c == 'U') {
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y);
        glVertex2f(x, y); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 8 * scale, y); glVertex2f(x + 8 * scale, y + 12 * scale);
    } else if (c == 'G') {
        glVertex2f(x + 8 * scale, y + 12 * scale); glVertex2f(x, y + 12 * scale);
        glVertex2f(x, y + 12 * scale); glVertex2f(x, y);
        glVertex2f(x, y); glVertex2f(x + 8 * scale, y);
        glVertex2f(x + 8 * scale, y); glVertex2f(x + 8 * scale, y + 6 * scale);
        glVertex2f(x + 4 * scale, y + 6 * scale); glVertex2f(x + 8 * scale, y + 6 * scale);
    } else if (c == '1') {
        glVertex2f(x + 2 * scale, y + 9 * scale); glVertex2f(x + 5 * scale, y + 12 * scale);
        glVertex2f(x + 5 * scale, y + 12 * scale); glVertex2f(x + 5 * scale, y);
        glVertex2f(x, y); glVertex2f(x + 10 * scale, y);
    }
    glEnd();
}

void drawString(const char* str, float x, float y, float scale) {
    float spacing = 12.0f * scale;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            x += spacing * 0.7f;
            continue;
        }
        drawChar(str[i], x, y, scale);
        x += spacing;
    }
}

void drawSkyAndEnvironment() {
    glBegin(GL_QUADS);
        glColor3f(0.12f, 0.45f, 0.85f);
        glVertex2f(0, WINDOW_HEIGHT); glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
        glColor3f(0.58f, 0.82f, 0.98f);
        glVertex2f(WINDOW_WIDTH, 260); glVertex2f(0, 260);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.24f, 0.26f, 0.30f);
        glVertex2f(0, 0); glVertex2f(WINDOW_WIDTH, 0); glVertex2f(WINDOW_WIDTH, 260); glVertex2f(0, 260);
    glEnd();

    glColor3f(0.22f, 0.65f, 0.28f);
    glBegin(GL_QUADS);
        glVertex2f(0, 210); glVertex2f(WINDOW_WIDTH, 210); glVertex2f(WINDOW_WIDTH, 235); glVertex2f(0, 235);
        glVertex2f(0, 65); glVertex2f(WINDOW_WIDTH, 65); glVertex2f(WINDOW_WIDTH, 90); glVertex2f(0, 90);
    glEnd();
}

void drawTree(float x, float y) {
    glColor3f(0.38f, 0.24f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(x - 5.0f, y); glVertex2f(x + 5.0f, y);
        glVertex2f(x + 5.0f, y + 105.0f); glVertex2f(x - 5.0f, y + 105.0f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(x, y + 80.0f); glVertex2f(x - 18.0f, y + 105.0f);
        glVertex2f(x, y + 85.0f); glVertex2f(x + 18.0f, y + 105.0f);
    glEnd();

    glColor3f(0.12f, 0.48f, 0.20f);
    drawCircle(x, y + 125.0f, 32.0f, 20);
    drawCircle(x - 22.0f, y + 110.0f, 24.0f, 18);
    drawCircle(x + 22.0f, y + 110.0f, 24.0f, 18);
    drawCircle(x - 12.0f, y + 145.0f, 22.0f, 18);
    drawCircle(x + 12.0f, y + 145.0f, 22.0f, 18);
}

void drawBackdropTrees() {
    for (float x = 80.0f; x < (float)WINDOW_WIDTH - 20.0f; x += 110.0f) {
        drawTree(x, 260.0f);
    }
}

void drawClouds() {
    glColor3f(0.98f, 0.99f, 1.0f);
    drawCircle(190, 650, 58, 30); drawCircle(245, 678, 72, 30); drawCircle(310, 650, 55, 30);
    drawCircle(820, 680, 75, 30); drawCircle(895, 708, 88, 30); drawCircle(975, 680, 66, 30);
    drawCircle(1250, 630, 62, 30); drawCircle(1320, 658, 76, 30);
}

void drawVehicle(float x, float y, bool isAmbulance) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    if (isAmbulance) {
        glColor3f(0.96f, 0.96f, 0.98f);
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(48, 0); glVertex2f(48, 24); glVertex2f(0, 24); glEnd();
        glColor3f(0.20f, 0.30f, 0.45f);
        glBegin(GL_QUADS); glVertex2f(34, 11); glVertex2f(45, 11); glVertex2f(43, 22); glVertex2f(36, 22); glEnd();
        glColor3f(0.95f, 0.12f, 0.12f);
        glBegin(GL_QUADS);
            glVertex2f(16, 8); glVertex2f(22, 8); glVertex2f(22, 16); glVertex2f(16, 16);
            glVertex2f(13, 11); glVertex2f(25, 11); glVertex2f(25, 13); glVertex2f(13, 13);
        glEnd();
        glColor3f(0.95f, 0.20f, 0.20f);
        glBegin(GL_QUADS); glVertex2f(21, 24); glVertex2f(27, 24); glVertex2f(26, 28); glVertex2f(22, 28); glEnd();
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(11, 0, 4.5f, 10); drawCircle(37, 0, 4.5f, 10);
    } else {
        glColor3f(0.95f, 0.20f, 0.15f);
        glBegin(GL_QUADS); glVertex2f(0, 0); glVertex2f(45, 0); glVertex2f(45, 22); glVertex2f(0, 22); glEnd();
        glColor3f(0.20f, 0.30f, 0.45f);
        glBegin(GL_QUADS); glVertex2f(32, 10); glVertex2f(42, 10); glVertex2f(40, 20); glVertex2f(34, 20); glEnd();
        glColor3f(0.95f, 0.95f, 0.95f);
        glBegin(GL_QUADS); glVertex2f(0, 8); glVertex2f(45, 8); glVertex2f(45, 12); glVertex2f(0, 12); glEnd();
        glColor3f(0.15f, 0.65f, 0.95f);
        glBegin(GL_QUADS); glVertex2f(20, 22); glVertex2f(26, 22); glVertex2f(25, 26); glVertex2f(21, 26); glEnd();
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(10, 0, 4.0f, 10); drawCircle(35, 0, 4.0f, 10);
    }
    glPopMatrix();
}

void drawLabeledAirportComplex() {
    // 1. Cargo & Freight Logistics Facility
    glColor3f(0.94f, 0.92f, 0.85f);
    glBegin(GL_QUADS); glVertex2f(80, 180); glVertex2f(430, 180); glVertex2f(430, 310); glVertex2f(80, 310); glEnd();

    glColor3f(0.25f, 0.30f, 0.38f);
    for (int x = 110; x < 390; x += 80) {
        glBegin(GL_QUADS);
            glVertex2f((float)x, 180.0f); glVertex2f((float)x + 55.0f, 180.0f);
            glVertex2f((float)x + 55.0f, 270.0f); glVertex2f((float)x, 270.0f);
        glEnd();
    }
    glColor3f(0.15f, 0.15f, 0.15f);
    drawString("CARGO", 215, 280, 0.9f);

    // 2. Fire & Rescue Station
    glColor3f(0.88f, 0.22f, 0.20f);
    glBegin(GL_QUADS); glVertex2f(460, 180); glVertex2f(650, 180); glVertex2f(650, 305); glVertex2f(460, 305); glEnd();

    glColor3f(0.20f, 0.20f, 0.22f);
    glBegin(GL_QUADS);
        glVertex2f(475, 180); glVertex2f(535, 180); glVertex2f(535, 270); glVertex2f(475, 270);
        glVertex2f(555, 180); glVertex2f(615, 180); glVertex2f(615, 270); glVertex2f(555, 270);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawString("FIRE RESCUE", 492, 285, 0.58f);

    // 3. Central Air Traffic Control Tower
    glColor3f(0.08f, 0.08f, 0.08f);
    glBegin(GL_QUADS); glVertex2f(710, 200); glVertex2f(770, 200); glVertex2f(755, 560); glVertex2f(725, 560); glEnd();

    glColor3f(0.94f, 0.92f, 0.85f);
    glBegin(GL_QUADS); glVertex2f(660, 560); glVertex2f(820, 560); glVertex2f(835, 630); glVertex2f(645, 630); glEnd();

    glColor3f(0.12f, 0.22f, 0.38f);
    glBegin(GL_QUADS); glVertex2f(668, 568); glVertex2f(812, 568); glVertex2f(825, 620); glVertex2f(655, 620); glEnd();

    glColor3f(0.20f, 0.20f, 0.20f);
    glBegin(GL_TRIANGLES); glVertex2f(625, 630); glVertex2f(855, 630); glVertex2f(740, 680); glEnd();

    glColor3f(0.94f, 0.92f, 0.85f);
    drawString("ATC", 715, 585, 0.75f);

    // 4. Terminal 1
    glColor3f(0.08f, 0.08f, 0.08f);
    glBegin(GL_QUADS); glVertex2f(890, 180); glVertex2f(1350, 180); glVertex2f(1350, 350); glVertex2f(890, 350); glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.80f, 0.98f); glVertex2f(910, 200); glVertex2f(1330, 200);
        glColor3f(0.30f, 0.60f, 0.85f); glVertex2f(1330, 320); glVertex2f(910, 320);
    glEnd();

    glColor3f(0.45f, 0.25f, 0.12f);
    glBegin(GL_QUADS); glVertex2f(870, 350); glVertex2f(1370, 350); glVertex2f(1350, 380); glVertex2f(890, 380); glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawString("TERMINAL 1", 1060, 355, 0.85f);
}

void drawRunway() {
    glColor3f(0.25f, 0.27f, 0.30f);
    glBegin(GL_QUADS); glVertex2f(0, 90); glVertex2f(WINDOW_WIDTH, 90); glVertex2f(WINDOW_WIDTH, 210); glVertex2f(0, 210); glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    for (int x = 10; x < WINDOW_WIDTH; x += 65) {
        glVertex2f((float)x, 150.0f);
        glVertex2f((float)x + 35.0f, 150.0f);
    }
    glEnd();
}

void drawAirplane(float x, float y, float bodyR, float bodyG, float bodyB) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glColor3f(bodyR * 0.65f, bodyG * 0.65f, bodyB * 0.65f);
    glBegin(GL_POLYGON); glVertex2f(-12, 22); glVertex2f(22, 22); glVertex2f(10, 10); glVertex2f(-18, 10); glEnd();

    glColor3f(bodyR, bodyG, bodyB);
    glBegin(GL_POLYGON);
        glVertex2f(-22, 26); glVertex2f(0, 35); glVertex2f(135, 35); glVertex2f(160, 30);
        glVertex2f(178, 20); glVertex2f(160, 10); glVertex2f(135, 5); glVertex2f(0, 5);
    glEnd();

    glColor3f(0.12f, 0.50f, 0.95f);
    glBegin(GL_POLYGON); glVertex2f(-18, 23); glVertex2f(162, 23); glVertex2f(172, 19); glVertex2f(162, 15); glVertex2f(-18, 15); glEnd();

    glColor3f(0.12f, 0.20f, 0.35f);
    glBegin(GL_POLYGON); glVertex2f(148, 25); glVertex2f(168, 25); glVertex2f(160, 32); glVertex2f(142, 32); glEnd();

    glColor3f(0.20f, 0.25f, 0.35f);
    for (float wx = 20; wx < 130; wx += 11) {
        glBegin(GL_QUADS); glVertex2f(wx, 26); glVertex2f(wx + 6, 26); glVertex2f(wx + 6, 30); glVertex2f(wx, 30); glEnd();
    }

    glColor3f(bodyR * 0.85f, bodyG * 0.85f, bodyB * 0.85f);
    glBegin(GL_POLYGON); glVertex2f(55, 18); glVertex2f(105, 18); glVertex2f(82, 62); glVertex2f(60, 62); glEnd();

    glColor3f(0.95f, 0.20f, 0.20f);
    glBegin(GL_TRIANGLES); glVertex2f(82, 62); glVertex2f(85, 73); glVertex2f(70, 62); glEnd();

    glColor3f(0.12f, 0.50f, 0.95f);
    glBegin(GL_POLYGON); glVertex2f(-6, 35); glVertex2f(28, 35); glVertex2f(6, 75); glVertex2f(-14, 75); glEnd();

    glColor3f(0.40f, 0.44f, 0.50f);
    glBegin(GL_POLYGON); glVertex2f(62, 2); glVertex2f(92, 2); glVertex2f(92, 15); glVertex2f(62, 15); glEnd();

    if (y <= 190.0f) {
        glColor3f(0.25f, 0.25f, 0.25f);
        glLineWidth(3.5f);
        glBegin(GL_LINES);
            glVertex2f(40, 10); glVertex2f(40, -3);
            glVertex2f(115, 10); glVertex2f(115, -3);
        glEnd();
        glColor3f(0.12f, 0.12f, 0.12f);
        drawCircle(40, -4, 5.5f, 12);
        drawCircle(115, -4, 5.5f, 12);
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSkyAndEnvironment();
    drawBackdropTrees();
    drawClouds();
    drawLabeledAirportComplex();

    drawVehicle(510.0f, 140.0f, false);
    drawVehicle(920.0f, 140.0f, true);

    drawRunway();

    drawAirplane(1120.0f, 155.0f, 0.98f, 0.98f, 1.0f);
    drawAirplane(planePosX, planePosY, 0.96f, 0.98f, 1.0f);

    glutSwapBuffers();
}

void update(int value) {
    planePosX += planeSpeed;

    if (planePosX > 380.0f && planePosX < 980.0f) {
        if (planePosY < 480.0f) {
            planePosY += 1.8f;
        }
    }

    if (planePosX > (float)WINDOW_WIDTH + 180.0f) {
        planePosX = -160.0f;
        planePosY = 110.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Labeled Multi-Terminal Airport Simulator - OpenGL");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
