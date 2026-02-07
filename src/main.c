#include <stdio.h>
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

void particle_border_collision(Particle* particle) {
    if (particle->x - particle->radius < 0 || particle->x + particle->radius > WIDTH)
        particle->velocity_x *= -1;

    if (particle->y - particle->radius < 0 || particle->y + particle->radius > HEIGHT)
        particle->velocity_y *= -1;
}

void inter_particle_collision(Particle* particle) {
    Particle* other_particle;
    Vector2 particle_center = (Vector2){particle->x, particle->y};
    Vector2 other_particle_center;

    for (int i = 0; i < PARTICLE_COUNT; i++) {
        other_particle = &particles[i];
        if (particle == other_particle) continue;

        other_particle_center = (Vector2){other_particle->x, other_particle->y};

        bool collide = CheckCollisionCircles(particle_center, particle->radius,
                                             other_particle_center, other_particle->radius);

        if (collide)
            printf("Collision detected!\n");
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

    particle_border_collision(particle);
    inter_particle_collision(particle);
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