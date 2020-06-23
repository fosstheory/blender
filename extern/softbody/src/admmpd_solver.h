// Copyright Matt Overby 2020.
// Distributed under the MIT License.

#ifndef ADMMPD_SOLVER_H_
#define ADMMPD_SOLVER_H_

#include "admmpd_types.h"

namespace admmpd {

class Solver {
public:
    // Initialies solver data. If a per-vertex
    // variable is resized it is initialized to zero.
    // Returns true on success
    bool init(
        const Eigen::MatrixXd &V, // vertices
        const Eigen::MatrixXi &T, // tets
        const Options *options,
        SolverData *data);

    // Solve a single time step.
    // Returns number of iterations.
    int solve(
        const Options *options,
        SolverData *data);

protected:

    void update_constraints(
        const Options *options,
        SolverData *data);

    void init_solve(
        const Options *options,
        SolverData *data);

	void solve_local_step(
        const Options *options,
        SolverData *data);

    // Global step with CG:
    // 1/2||Ax-b||^2 + k/2||Kx-l||^2
	void solve_conjugate_gradients(
        const Options *options,
        SolverData *data);

    bool compute_matrices(
        const Options *options,
        SolverData *data);

    void compute_masses(
        const Options *options,
        SolverData *data);

	void append_energies(
		const Options *options,
		SolverData *data,
		std::vector<Eigen::Triplet<double> > &D_triplets);

}; // class ADMMPD_solver

} // namespace admmpd

#endif // ADMMPD_SOLVER_H_