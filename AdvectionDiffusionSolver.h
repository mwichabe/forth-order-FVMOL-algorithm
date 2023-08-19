#pragma once
#include "Grid.h"
#include "LinearSolver.h"

class AdvectionDiffusionSolver {
private:
    Grid grid;
    double nu;  // Diffusion coefficient
    double dt;  // Time step

public:
    AdvectionDiffusionSolver(const Grid& grid, double nu, double dt);
    void initialize();
    void applyBoundaryConditions();
    void computeFluxes();
    void updateSolution();
    void advanceTimeStep();
    void updateSolutionFromCorrection(const std::vector<double> vector);
};
