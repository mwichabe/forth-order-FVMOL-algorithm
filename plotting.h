#pragma once
#include <vector>
#include "Grid.h"  // Include necessary headers for Grid

namespace Plotting {
    void plotErrorsVsGridSpacing(const std::vector<double>& hValues, const std::vector<double>& errors);
    void plotSolutionsOnGridLevels(const std::vector<Grid>& grids, const std::vector<std::vector<double>>& solutions);
}
