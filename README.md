# CPP-Water-Jug
C++ state-space solver for the Water Jug problem using Dijkstra's algorithm, priority queues, and cost tracking to compute an optimal sequence of jug operations.

This implementation supports six weighted actions -- fill A, fill B, empty A, empty B, pour A->B, and pour B->A -- and evaluates them according to configurable operation costs.

It also reconstructs and returns the sequence of operations along with the final minimum cost once the target state is reached.
