#pragma once
#include "Grid.h"
#include "LinearSolver.h"

class NavierStokesSolver {
private:
    Grid grid;
    double nu;  // Viscosity coefficient
    double dt;  // Time step
    LinearSolver linearSolver;

public:
    NavierStokesSolver(const Grid& grid, double nu, double dt, int maxLevels);
    void initialize();
    void applyBoundaryConditions();
    void computeConvectiveTerm();
    void computeDiffusiveTerm();
    void computeProjection();
    void advanceTimeStep();
};
