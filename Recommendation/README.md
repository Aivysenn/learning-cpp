# How the Recommendation Engine Works

This is a data-driven preference analysis tool that maps user taste profiles and simulates basic collaborative filtering to output items for target profiles.

### 1. Matrix Structuring & Similarity Scoring

- **Nested Relational Mapping:** Leverages a multi-layered `std::map<string, map<string, int>>` to build an absolute sparse multidimensional array of user vectors and movie scores.
- **Intersection Optimization Processing:** The program cross-references the targets' high-value metrics ($\ge 4$ stars) against other entities in the index database, calculating a dynamic intersection weight score.

**Example:**

- **Input:** `Alice`
- **Process:** Detects that both `Alice` and `Bob` gave high scores to `Inception` and `The_Matrix` —> selects `Bob` as the best match pattern profile.
- **Output:** Identifies that `Bob` highly rated `Titanic`, which `Alice` has not registered, and pushes it as a top suggestion item.

—

### 2. Output Generation & Fallback Loops

- **Dynamic Filtration:** Filters the match-partner's data arrays, instantly purging any node items that the target user has already parsed into their own historical profile record map.
- **Static Baseline Fallback:** If intersection scoring returns zero structural profile correlations, defensive controls trigger a hardcoded fallback block to output general community trend metrics.

—

# What I Learned from This Project

- **Multi-Dimensional Maps:** Gained deep experience configuring and navigating nested dictionary maps to handle relational dataset systems.
- **Heuristic Pattern Logic:** Handled vector intersection logic to determine algorithmic values based on overlapping user states.
