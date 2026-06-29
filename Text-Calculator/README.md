# How the Cipher Works

This is a custom cryptographic algorithm based on a substitution cipher with dynamic noise injection. It operates in two main phases:

### 1. Encryption Phase

- **Character Mapping:** The program takes each letter of the input text and replaces it with a unique pre-defined number using a `std::map` (e.g., `'a'` becomes `309`, `'b'` becomes `103`).
- **Noise Injection:** To make the encrypted text harder to crack, the algorithm automatically generates and inserts a random special symbol (chosen from `;!@#$%^&*`) immediately after each number.
- **Punctuation & Spaces:** All spaces and standard punctuation marks are left untouched to preserve the original sentence structure.

**Example:**

- **Input:** `hi`
- **Process:** `'h'` —> `32` + random symbol (e.g., `#`), `'i'` —> `401` + random symbol (e.g., `^`)
- **Output:** `32#401^`

—

### 2. Decryption Phase

- **Tokenization:** The program reads the encrypted string and reconstructs the multi-digit numbers by checking if a character `isdigit`.
- **Noise Filtering:** It identifies the random special symbols and safely ignores them, treating them as simple data separators.
- **Reverse Lookup:** Using a reversed map (`std::map<int, char>`), the program converts the numbers back into their original characters and outputs the decrypted message.

—

# What I Learned from This Project

Developing this application allowed me to strengthen my foundational programming skills and dive deeper into C++ core concepts:

- **Data Structures (`std::map`):** I learned how to effectively use associative arrays for key-value mapping. I also implemented a dynamic reverse lookup by iterating through the original map to automatically build the decryption dictionary.
- **Data Initialization & Refactoring:** I practiced code optimization by replacing multiple individual assignment lines with a clean, structured initializer list, making the code much more readable and professional.
- **String Parsing & Buffer Manipulation:** I gained hands-on experience in string tokenization, handling characters sequentially, extracting multi-digit numbers using `isdigit()`, and converting them safely to integers with `stoi()`.
- **Logical Control Flow:** Debugging the interactive prompt improved my understanding of complex boolean logic, standard input handling (`getline`), and defensive validation for user edge cases.
