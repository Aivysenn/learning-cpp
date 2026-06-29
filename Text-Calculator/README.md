# How the Text Calculator Works

This is a simple text-based mathematical interpreter that parses equations written in plain English words. It operates in two main phases:

### 1. Lexical Mapping Phase

- **Word-to-Number Translation:** The program takes textual inputs (`"zero"` through `"ten"`) and converts them into standard integers using a `std::map`.
- **Operator Mapping:** Keywords like `"plus"` and `"minus"` are identified and translated into logical mathematical characters (`'+'` and `'-'`).
- **Dynamic Tokenization:** Using `std::stringstream`, the program breaks down a raw input string sequential buffer into separate, clean words.

**Example:**

- **Input:** `five plus three minus two`
- **Process:** `five` —> `5`, `plus` —> `+`, `three` —> `3`, `minus` —> `-`, `two` —> `2`
- **Output:** `Math result: 6`

—

### 2. Execution & Reverse Lookup Phase

- **Arithmetic Processing:** The system iterates through the extracted words, caching the last seen operation and applying it immediately to the next parsed integer.
- **Bi-directional Output:** Once the integer result is calculated, the program uses a reversed lookup map (`std::map<int, string>`) to translate the answer back into readable English text.
- **Error Handling:** If an unrecognized word or symbol enters the stream, the loop breaks instantly with a safe exception error message.

—

# What I Learned from This Project

Developing this application allowed me to strengthen my foundational programming skills and dive deeper into C++ core concepts:

- **Data Structures (`std::map`):** I learned how to effectively use associative arrays for key-value mapping. I also implemented a dynamic reverse lookup by iterating through the original map to automatically build the decryption dictionary.
- **Data Initialization & Refactoring:** I practiced code optimization by replacing multiple individual assignment lines with a clean, structured initializer list, making the code much more readable and professional.
- **String Parsing & Buffer Manipulation:** I gained hands-on experience in string tokenization, handling characters sequentially, extracting multi-digit numbers using `isdigit()`, and converting them safely to integers with `stoi()`.
- **Logical Control Flow:** Debugging the interactive prompt improved my understanding of complex boolean logic, standard input handling (`getline`), and defensive validation for user edge cases.
