### Plug DP

    Plug DP is used to solve connectivity problem, such as Hamiltonian Path/Cycle(Circuit).

    We already learned to use DP to find hamiltonian path in Session 13.  It is based on state, which is defined as a subset of nodes.  From the algorithm, we see we have two loops.  In each loop, we find all the combination (2**V) in order to check if there is a hamiltonian path.  The complexity of this DP algorithm is O((V**2)*(2**V)).  It has a lot of improvement comparing with O(V!).

    The space complexity is O(2**V) as there are 2**V states.  We can improve it by compressing the state.

    Due to its high space complexity, we can only use it to process the problem with small scales.  Can we do state compression??

#### State : transitioning state vs Established state 

    Just like FSM, DP is actually one kind of state transition.  But all the transitioning new state is based on the established states, which will never be changed once the state is established.

    The state is what I called plug, which represents the connectivity.  We can call this DP as connectivity-based DP.

    Concept: Plug

### Optimal Substructure

    Transition Line: It is used to partion two states: transitioning state vs Established state.
    The direction of transition: From bottom to top, from left to right

