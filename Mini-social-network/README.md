# How the Mini-Social Network Works

This is a structural social-graph modeling program that replicates network profile registration, bidirectional friend linking, and a mutual-connection recommendation tracker.

### 1. Social Graph Mapping & Edge Connections

- **Adjacency Vector Mapping:** Uses a `std::map<string, vector<string>>` structure to simulate an absolute directional social network graph database, where names link to continuous dynamic arrays of friends.
- **Bidirectional Verification:** The `friend` command updates both nodes simultaneously, establishing immediate cross-referenced synchronization across the database registry.

**Example:**

- **Input:** `suggest Alice`
- **Process:** Loops through `Alice`'s friends (`Bob` and `Charlie`) —> aggregates their friend vectors —> filters out `Alice` and her existing connections —> tracks recurring profiles.
- **Output:** Identifies `David` as a top-tier suggestion with `2` mutual friends in common.

—

### 2. Friends-of-Friends Analytics Flow

- **Mutual Intersection Discovery:** Iterates through nested state vectors to dynamically populate temporary score maps (`std::map<string, int>`) tracking mutual relationships.
- **Lookup Interception Filtering:** Employs `std::find` checking routines to securely purge historical nodes from active calculation loops, blocking redundant notifications.

—

# What I Learned from This Project

- **Graph Abstractions:** Modeled complex mathematical relational network data maps using zero traditional pointers or complex custom objects.
- **Nested Iteration Mechanics:** Handled nested matrix array processing logic pipelines to evaluate connections across extended data layers.
