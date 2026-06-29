# How the Math Parser Works

This is a dynamic algebraic string parser that tokenizes and evaluates basic mathematical expressions while strictly maintaining operator precedence rules.

### 1. Tokenization & Priority Mapping

- **Operator Classification:** Uses a `std::map<char, int>` configuration to map arithmetic characters (`*`, `/`, `+`, `-`) to distinct priority values (e.g., `*` ranks at `2`, while `+` ranks at `1`).
- **Stream Buffer Splitting:** A `std::stringstream` reads the expression sequentially, splitting numbers and operator characters into separate dynamic vector buffers.

**Example:**

- **Input:** `2 * 3 + 4`
- **Process:** Maps `*` to priority `2` and `+` to priority `1` —> executes `2 * 3` first —> caches result (`6`) —> processes `+ 4`.
- **Output:** `Execution Result: 10`

—

### 2. Two-Pass Evaluation Phase

- **High-Priority Filter:** The system loops through the operation vector. If a priority `2` operator (`*` or `/`) is detected, it instantly pops the last number from the calculation stack and evaluates it.
- **Low-Priority Resolution:** Delayed operations (`+` or `-`) are safely resolved in a secondary sequential pass across the remaining computed values.
- **Defensive Error Validations:** Automatically checks for edge cases such as invalid operators or divisions by zero.

—

# What I Learned from This Project

- **Precedence Logic:** Learned how to utilize priority arrays to resolve order-of-operation hierarchies inside raw text data.
- **Stack Buffering:** Handled basic abstract state evaluation by combining vector arrays to serve as multi-pass calculation stacks.
