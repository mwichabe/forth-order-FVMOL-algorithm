#pragma once
#include "Grid.h"
#include "AdvectionDiffusionSolver.h"
#include "NavierStokesSolver.h"

namespace TestCases {
    class TestCase1_1 {
    public:
        static void run(const Grid& grid, double nu, double dt);
        static void compareWithExactSolution(const Grid& grid, double nu, double dt);
    };

    class TestCase1_2 {
    public:
        static void run(const Grid& grid, double nu, double dt);
        static void compareWithExactSolution(const Grid& grid, double nu, double dt);
    };

    class TestCase1_3 {
    public:
        static void run(const Grid& grid, double nu, double dt);
        static void compareWithExactSolution(const Grid& grid, double nu, double dt);
    };
}

