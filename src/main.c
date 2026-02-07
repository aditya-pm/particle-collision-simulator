#include <time.h>

#include "raylib.h"

#define WIDTH 1200
#define HEIGHT 800
#define PARTICLE_COUNT 25

typedef struct {
    float x, y;
    float radius;
    float velocity_x, velocity_y;
} Particle;

Particle particles[PARTICLE_COUNT];

void init_particles() {
    SetRandomSeed(time(NULL));
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        particles[i].radius = GetRandomValue(5, 15);
        particles[i].x = GetRandomValue(particles[i].radius, WIDTH - particles[i].radius);
        particles[i].y = GetRandomValue(particles[i].radius, HEIGHT - particles[i].radius);
        particles[i].velocity_x = GetRandomValue(-5, 5);
        particles[i].velocity_y = GetRandomValue(-5, 5);
    }
}

void draw_particle(Particle particle) {
    DrawCircle(particle.x, particle.y, particle.radius, WHITE);
}

void draw_particles() {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        draw_particle(particles[i]);
    }
}

void update_particle(Particle* particle) {
    particle->x += particle->velocity_x;
    particle->y += particle->velocity_y;

    // collision with walls
    if (particle->x - particle->radius < 0 || particle->x + particle->radius > WIDTH)
        particle->velocity_x *= -1;

    if (particle->y - particle->radius < 0 || particle->y + particle->radius > HEIGHT)
        particle->velocity_y *= -1;
}

void update_particles() {
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        update_particle(particles + i);
    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Particles");
    SetTargetFPS(60);

    init_particles();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        draw_particles();
        update_particles();

        EndDrawing();
    }

    CloseWindow();
}