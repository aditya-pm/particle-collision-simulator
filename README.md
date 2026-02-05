# Particle Collision Simulator

A real-time 2D particle collision simulation written in C using the raylib graphics library.

This project began as an implementation inspired by a tutorial on elastic collision simulation.  
I extended and modified it to better reflect real-world physics and to deepen my understanding of collision dynamics.


## Features

- 2D particle simulation using raylib
- Multiple particles with real-time collision detection
- **Variable mass per particle**
- Mass-proportional particle size for visual clarity
- Elastic collision response using conservation of momentum
- Deterministic physics update loop (time-step based)


## Physics Overview

Each particle has an independent mass, position, and velocity.  
Collisions are resolved by projecting velocities onto the collision normal and applying conservation of momentum.

Mass differences are visually represented by particle size, and lighter particles respond more strongly to collisions with heavier ones.


## Controls

W.I.P


## Built With

- **C**
- **raylib**


## Notes

This project is intended as a learning-focused physics simulation and a stepping stone toward more advanced physics engines and real-time systems.

Future improvements may include inelastic collisions, spatial partitioning, and interactive parameter control.


## Preview

TODO: Add screenshots/gif
