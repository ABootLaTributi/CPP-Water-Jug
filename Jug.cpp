#include "Jug.h"

using namespace std;

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA)
    : Ca(Ca), Cb(Cb), N(N), cfA(cfA), cfB(cfB), ceA(ceA), ceB(ceB), cpAB(cpAB), cpBA(cpBA) {}

bool Jug::isValidInput() {
    return (Ca > 0 && Ca <= Cb && Cb <= 1000 && N <= Cb && cfA > 0 && cfB > 0 && ceA > 0 && ceB > 0 && cpAB > 0 && cpBA > 0);
}

bool Jug::dijkstra(std::string &solution) {
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    std::unordered_map<int, std::unordered_map<int, int>> costs;  // To store the minimum cost for each state
    pq.push({0, 0, 0, {}});  // Initial state with jugs empty and cost 0
    costs[0][0] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int a = current.a;
        int b = current.b;
        int cost = current.cost;

        // Check if we reached the goal
        if (b == N && a == 0) {
            solution.clear();
            for (const std::string& action : current.actions) {
                solution += action + "\n";
            }
            solution += "success " + std::to_string(cost);
            return true;
        }

        // Define all possible actions
        std::vector<std::tuple<int, int, int, std::string>> actions = {
            {Ca, b, cost + cfA, "fill A"},
            {a, Cb, cost + cfB, "fill B"},
            {0, b, cost + ceA, "empty A"},
            {a, 0, cost + ceB, "empty B"},
            {a - std::min(a, Cb - b), b + std::min(a, Cb - b), cost + cpAB, "pour A B"},
            {a + std::min(Ca - a, b), b - std::min(Ca - a, b), cost + cpBA, "pour B A"}
        };

        for (const auto& action : actions) {
            int new_a, new_b, new_cost;
            std::string action_str;
            std::tie(new_a, new_b, new_cost, action_str) = action;

            // If this new state has a lower cost, consider it
            if (costs.find(new_a) == costs.end() || costs[new_a].find(new_b) == costs[new_a].end() || new_cost < costs[new_a][new_b]) {
                costs[new_a][new_b] = new_cost;
                State newState = {new_a, new_b, new_cost, current.actions};
                newState.actions.push_back(action_str);
                pq.push(newState);
            }
        }
    }

    return false;  // If we exhaust the priority queue without finding a solution
}

int Jug::solve(std::string &solution) {
    if (!isValidInput()) {
        solution.clear();
        return -1;
    }

    if (!dijkstra(solution)) {
        solution.clear();
        return 0;
    }

    return 1;
}