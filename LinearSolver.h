#pragma once

#include <vector>
#include "Grid.h"

class LinearSolver {
private:
    Grid grid;
    int maxLevels;  // Maximum number of grid levels
    // Define other parameters for the multi-grid solver

public:
    LinearSolver(const Grid& grid, int maxLevels);
    void applyBoundaryConditions();
    void relax();
    void computeResidual();
    void restrictResidual();
    void prolongCorrection();
    void solve();
    const std::vector<double>& getCorrection() const;
};
