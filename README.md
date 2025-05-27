![FMI-tutorial-logo](https://github.com/user-attachments/assets/03cafb7f-6b46-4ea7-a155-0b606684d9f5)

# FMI Implementation tutorial

This is the repository for the tutorial "Exporting and importing an FMU using C code" presented at the [Modelica and FMI Conference 2025](https://modelica.org/events/modelica2025/).

## Target Audience

Developers who want to import or export models as FMUs or couple their tool to other tools using FMI.

## Before we start

- install [uv](https://docs.astral.sh/uv/getting-started/installation/)
- install [Visual Studio](https://visualstudio.microsoft.com/downloads/) or your favorite IDE that's supported by [CMake](https://cmake.org/)
- clone this repository recursively `git clone --recursive https://github.com/modelica/fmi-import-export-tutorial-2025.git`

## Anatomy of an FMU

### Model Description

- meta information
- interface types
- variables, causality, variability
- model structure

### Directory Structure

- documentation
- resources
- binaries
- source code

### Sources

- FMU structure
- schema
- headers
- resources: FMI Spec, FMI Implementers Guide

## Implement an FMU

- generate scaffolding with FMPy
- compile & run with FMPy
- set up a CMake project
- run FMU with fmusim
    - log FMI calls
    - provide input
    - save output
- debug
    - attach a debugger to FMPy
    - debug with fmusim

## Import an FMU

### The hard way

- read model description
- load shared library
- load symbols
- call functions

Challenges:

- read & validate model description
- check return codes
- log messages
- log API calls

### Use Reference FMUs Framework

- clone repo
- create a CMake project
- get inspiration from Reference FMUs examples and fmusim

## Tips & Tricks

