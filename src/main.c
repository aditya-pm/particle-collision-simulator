#include "raylib.h"

#define WIDTH 1200
#define HEIGHT 800
#define PARTICLE_COUNT 15

typedef struct {
    float x, y;
    float radius;
    float velocity_x, velocity_y;
} Particle;

void draw_particle(Particle particle) {
    DrawCircle(particle.x, particle.y, particle.radius, WHITE);
}

void update_particle(Particle* particle) {
    particle->x += particle->velocity_x;
    particle->y += particle->velocity_y;
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Particles");
    SetTargetFPS(60);

    Particle particle = {300, 300, 50, 2, 2};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        draw_particle(particle);
        update_particle(&particle);

        EndDrawing();
    }

    CloseWindow();
}