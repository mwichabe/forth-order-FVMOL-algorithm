#pragma once

#include <vector>

class Grid {
public:
    Grid(int numCellsX, int numCellsY, double lengthX, double lengthY);
    std::vector<std::vector<double>> getCoordinates() const;
    // Define functions to get cell centers, areas, volumes, and neighbors.
};


