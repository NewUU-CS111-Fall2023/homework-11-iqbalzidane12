/*
 * Author:
 * Date:
 * Name:Muxtorov Abdulaziz
 */

#include <iostream>
#include <vector>

bool isSatisfiable(const std::vector<std::vector<int>>& cnf_formula, std::vector<int>& assignment, int index) {
    int numClauses = cnf_formula.size();
    int numVariables = assignment.size();
    auto checkClauses = [&]() {
        for (const auto& clause : cnf_formula) {
            bool clauseSatisfied = false;
            for (int literal : clause) {
                if ((literal > 0 && assignment[abs(literal)] == 1) || (literal < 0 && assignment[abs(literal)] == 0)) {
                    clauseSatisfied = true;
                    break;
                }
            }
            if (!clauseSatisfied) {
                return false;
            }
        }
        return true;
    };
    if (index == numVariables) {
        return checkClauses();
    }
    assignment[index + 1] = 1;
    if (isSatisfiable(cnf_formula, assignment, index + 1)) {
        return true;
    }
    assignment[index + 1] = 0;
    if (isSatisfiable(cnf_formula, assignment, index + 1)) {
        return true;
    }

    return false;
}

bool solveSAT(const std::vector<std::vector<int>>& cnf_formula) {
    int numVariables = 0;
    for (const auto& clause : cnf_formula) {
        for (int literal : clause) {
            numVariables = std::max(numVariables, abs(literal));
        }
    }
    std::vector<int> assignment(numVariables + 1, 0);
    return isSatisfiable(cnf_formula, assignment, 0);
}

int task_11 () {
    std::vector<std::vector<int>> cnf_formula = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};
    bool result = solveSAT(cnf_formula);
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
