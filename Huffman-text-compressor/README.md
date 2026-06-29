# How the Huffman Compressor Works

This is a data optimization tool that analyzes character occurrences in a text sequence and simulates a variable-length prefix code compression tree.

### 1. Frequency Analysis & Token Scoring

- **Character Statistics:** Iterates across the raw input string buffer, counting character occurrences using a cumulative `std::map<char, int>`.
- **Dynamic Bit Allocation:** Sorts token sequences using `std::vector` transformations to bind high-frequency characters to shorter binary codes (e.g., `0`) and rare elements to appended bit masks (e.g., `110`).

**Example:**

- **Input:** `hello`
- **Process:** Counts `'l'` as the highest frequency character —> maps `'l'` to code `0` —> maps other characters to longer sequences like `10` or `110`.
- **Output:** Transforms raw text into a low-overhead custom binary data stream.

—

### 2. Stream Serialization & Reverse Decoding

- **Bit Stream Encoding:** Sequentially translates characters into compressed structural strings of simulated binary bit representations.
- **Relational Reconstructed Lookup:** Uses a reversed dictionary lookup configuration (`std::map<string, char>`) to decode the incoming bit streams back into clean, uncompressed text strings.
- **Optimization Metric Calculations:** Automatically computes real-time comparisons against standard 8-bit ASCII configurations to output optimization percentages.

—

# What I Learned from This Project

- **Algorithmic Efficiency:** Gained practical understanding of basic greedy data-compression theory by converting static data structures into variable-length structures.
- **Multi-Structure Synchronization:** Handled multi-pass data pipelines, shifting key-value mappings dynamically between maps and sorting vectors to preserve data integrity.
