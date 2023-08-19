#include "Grid.h"
#include "AdvectionDiffusionSolver.h"
#include "NavierStokesSolver.h"
int main() {
    // Define problem parameters
    int numCellsX = 128;
    int numCellsY = 128;
    double lengthX = 1.0;
    double lengthY = 1.0;
    double nu = 0.01;
    double dt = 0.01;

    // Create grid and solver instances
    Grid grid(numCellsX, numCellsY, lengthX, lengthY);
    NavierStokesSolver nsSolver(grid, nu, dt, 4);
    AdvectionDiffusionSolver adSolver(grid, nu, dt);
    LinearSolver linearSolver(grid, 4);  // 4 grid levels

    // Initialize and advance the advection-diffusion solver
    nsSolver.initialize();
    adSolver.initialize();
    adSolver.applyBoundaryConditions();

    // Time loop
    int numTimeSteps=100;
    for (int step = 0; step < numTimeSteps; ++step) {
        adSolver.computeFluxes();
        adSolver.updateSolution();
        adSolver.advanceTimeStep();
        nsSolver.applyBoundaryConditions();
        nsSolver.advanceTimeStep();

        // Solve linear system using multi-grid solver
        linearSolver.applyBoundaryConditions();
        linearSolver.solve();

        // Update solution of advection-diffusion equation using correction
        adSolver.updateSolutionFromCorrection(linearSolver.getCorrection());

    }
    // Assuming you have calculated hValues and errors
    std::vector<double> hValues;  // Replace with actual values
    std::vector<double> errors;    // Replace with actual values

    // Assuming you have vectors of grids and solutions
    std::vector<Grid> grids;       // Populate this with your grid instances
    std::vector<std::vector<double>> solutions;  // Populate this with your solution data


    return 0;
}
