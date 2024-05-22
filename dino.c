#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 10
#define JUMP_HEIGHT 6

int gameOver;
int score;
int dinoX, dinoY;
int cactusX, cactusY;
int isJumping;

void setup() {
    gameOver = 0;
    score = 0;
    dinoX = 5;
    dinoY = HEIGHT - 1;
    cactusX = WIDTH - 5;
    cactusY = HEIGHT - 1;
    isJumping = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoY && j == dinoX)
                printf("R");
            else if (i == cactusY && j == cactusX)
                printf("+");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\nScore: %d\n", score);
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' && !isJumping)
            jump();
    }
}

void jump() {
    isJumping = 1;
    dinoY -= JUMP_HEIGHT;
}

void update() {
    if (isJumping) {
        if (dinoY >= HEIGHT - 1) {
            isJumping = 0;
            dinoY = HEIGHT - 1;
        } else {
            dinoY++;
        }
    }

    cactusX--;

    if (cactusX <= 0) {
        cactusX = WIDTH - 5;
        score++;
    }

    if ((cactusX == dinoX) && (cactusY == dinoY))
        gameOver = 1;
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(100);
    }
    printf("\nGame Over! Final Score: %d\n", score);
    return 0;
}