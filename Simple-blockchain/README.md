# How the Mini-Blockchain Works

This is a functional cryptographic ledger simulator that replicates transaction state logging, proof-of-work mining puzzles, and block validation chains.

### 1. Ledger Databases & Transaction Queues

- **State Ledger Mapping:** Tracks absolute user balances via a standard `std::map<string, int>` currency ledger registry.
- **Pending Transaction Buffer:** Collects verified transactions into a dynamic string vector pool, serving as a clean unmined block memory cache buffer.
- **Immutable Vector Chain:** Stores immutable historical block validation structural nodes inside a continuous sequential `std::vector<Block>` configuration.

**Example:**

- **Input:** `send Alice Bob 10`
- **Process:** Validates if `balances["Alice"] >= 10` —> updates ledger accounts instantly —> appends text log to the pending memory transaction buffer.
- **Output:** `Transaction added to pending pool: [Alice sent 10 to Bob]`

—

### 2. Proof-of-Work Mining & Hash Linking

- **Puzzle Guessing Loop:** The `mine` module launches a computational guessing cycle (`rand()`), trying nonces until a modular mathematical conditional check resolves true.
- **Sequential Block Invalidation:** Every newly forged structural block grabs the dynamic structural nonce property of the preceding ledger node, acting as a basic immutable hash line pointer.
- **Inflation Block Rewards:** Successful mining cycles automatically update system state mappings to mint block reward units directly into a target wallet address.

—

# What I Learned from This Project

- **Distributed Ledger Paradigms:** Implemented basic cryptographic consensus architectures by abstracting balances, network pools, and immutable node lines.
- **Data State Synchronization:** Handled clear multi-pass buffers, shifting unmined vector data blocks safely into concrete struct attributes upon successful processing.
