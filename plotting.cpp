#include "plotting.h"
#define FORCE_IMPORT_ARRAY
#include "matplotlib-cpp/matplotlibcpp.h"  // Include matplotlib-cpp library

namespace Plotting {
    void plotErrorsVsGridSpacing(const std::vector<double>& hValues, const std::vector<double>& errors) {
        namespace plt = matplotlibcpp;

        plt::plot(hValues, errors);
        plt::xlabel("Grid Spacing");
        plt::ylabel("Errors");
        plt::show();
    }

    void plotSolutionsOnGridLevels(const std::vector<Grid>& grids, const std::vector<std::vector<double>>& solutions) {
        namespace plt = matplotlibcpp;

        for (size_t i = 0; i < solutions.size(); ++i) {
            std::vector<std::vector<double>> coordinates = grids[i].getCoordinates();
            std::vector<double> cellCentersX, cellCentersY;

            // Extract X and Y coordinates from coordinates matrix
            for (const auto& coordRow : coordinates) {
                cellCentersX.push_back(coordRow[0]);
                cellCentersY.push_back(coordRow[1]);
            }

            // Plot solutions against X coordinates
            plt::plot(cellCentersX, solutions[i]);
        }

        plt::xlabel("X Coordinates");
        plt::ylabel("Solution");
        plt::show();
    }
}
