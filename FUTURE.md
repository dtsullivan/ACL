# Future Work
Some possible directions for future work. 

## Multiple trajectories
The optimization interface is 
"user friendly"
if the user 
can make the "best" decisions
with the most "relevant" information.
(Other definitions are welcome.)
Towards making a user friendly interface, one great test case involves decision amongst trajectories to choose from.
* Displays multiple trajectories and their advantages/disadvangaes
* Select trajectory 
* Click and drag trajectory

For example, we can visualize state changes over time, or some experiments in
* steepest bank angle display 
* fastest point 
* does it reach target, etc.

## Dynamics
We should provide a suite of agent dynamics.
- [x]  double integrator
- [ ] linear system
- [ ] 6-dof vehicle dynamics (i.e. rocket)
- [ ] orbital dynamics
- [ ] robotic arm (lie groups)

Other test cases for the "reinforcement learning" crowd.
- [ ] cart pole
- [ ] contact dynamics (legged)
- [ ] etc...


## Python and MATLAB integration
Python is used heavily in robotics, in particular in image recognition or planning. A wrapper for our C/C++ libraries
is essential for adoption.
* PY: A library for interfacing with the `socp` and `cprs` packages. Possibly through `cvxpy`'s standarized interface.
* PY: A library for interfacing with the `algorithms` package
* MATLAB: interfaces with algorithms package
