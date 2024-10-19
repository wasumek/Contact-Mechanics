# Computational Contact Mechanics Projects

This repository contains projects from a computational contact mechanics class. The projects explore essential topics in contact mechanics, such as beam deflections on elastic foundations, constrained optimization techniques, and modeling surface contact. These studies use numerical methods to solve mechanical contact problems, which are crucial in engineering and physics applications, particularly in areas like material science and structural analysis.

## Table of Contents
- [Overview](#overview)
- [Projects](#projects)
- [Installation](#installation)
- [Usage](#usage)

## Overview

Contact mechanics investigates how solid bodies interact when they come into contact, focusing on deformations, stresses, and the transfer of forces at contact surfaces. This field is fundamental for understanding phenomena like wear, friction, and structural integrity in engineering applications. The projects in this repository apply numerical techniques to tackle constrained optimization problems and analyze mechanical behavior using computational approaches.

## Projects

1. **Beam on Elastic Foundation**: This project models the deflection behavior of a beam resting on an elastic foundation, a classic contact mechanics problem often encountered in structural engineering.
   
2. **Constrained Optimization using Augmented Lagrange Multiplier Method**: This project applies the augmented Lagrangian method to solve constrained optimization problems that arise in contact mechanics, including non-penetration conditions.

3. **Constrained Optimization using Barrier Method**: A computational approach to constrained optimization using barrier functions, designed to model contact under strict mechanical constraints.

4. **Contact with a Motionless Surface**: Numerical simulations modeling the interaction between a moving object and a rigid, motionless surface, emphasizing friction and normal contact forces.

## Installation

To run the code in this repository:
Clone the repository:
   ```bash
   git clone https://github.com/wasumek/Contact-Mechanics.git
```

## Usage

Once compiled, run the C programs in your terminal to simulate various contact mechanics scenarios. Each source file contains code and comments that help illustrate the simulation process for the specific mechanics problem being solved.
Modify input parameters within the code to customize the simulations for different scenarios.
   ```bash
    gcc -o outputfile sourcefile.c
```


