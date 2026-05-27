# 🔢 NumSysConverter

A comprehensive **Number System Converter** that performs conversions between **Binary**, **Decimal**, **Octal**, and **Hexadecimal** number systems. Available in both **C** and **Python** implementations.

---

## ✨ Features

The program supports **12 conversion operations** covering all possible pairs among the four major number systems:

| #  | Conversion                  | Direction          |
|----|-----------------------------|--------------------|
| 1  | Binary → Decimal            | Base 2 → Base 10   |
| 2  | Octal → Decimal             | Base 8 → Base 10   |
| 3  | Hexadecimal → Decimal       | Base 16 → Base 10  |
| 4  | Decimal → Binary            | Base 10 → Base 2   |
| 5  | Decimal → Octal             | Base 10 → Base 8   |
| 6  | Decimal → Hexadecimal       | Base 10 → Base 16  |
| 7  | Binary → Octal              | Base 2 → Base 8    |
| 8  | Octal → Binary              | Base 8 → Base 2    |
| 9  | Binary → Hexadecimal        | Base 2 → Base 16   |
| 10 | Hexadecimal → Binary        | Base 16 → Base 2   |
| 11 | Octal → Hexadecimal         | Base 8 → Base 16   |
| 12 | Hexadecimal → Octal         | Base 16 → Base 8   |

---

## 📁 Project Structure

```
Conversions/
├── C programming/
│   ├── Conversions.c              # Core C implementation
│   ├── Conversions.exe            # Compiled executable
│   ├── Conversions (Arrays).c     # Array-based C implementation
│   ├── Conversions (Arrays).exe   # Compiled executable (array version)
│   └── conversions arrays video.mp4  # Demo video
├── Python/
│   └── Conversions.py             # Python implementation
└── README.md
```

### Two C Implementations

- **`Conversions.c`** — Standard implementation using individual digit input.
- **`Conversions (Arrays).c`** — Alternative array-based implementation with the same functionality.

### Python Implementation

- **`Conversions.py`** — Cleaner, Pythonic version with streamlined string-based input (enter the full number at once instead of digit-by-digit).

---

## 🚀 Getting Started

### Prerequisites

- **C**: A C compiler such as GCC or MSVC
- **Python**: Python 3.x

### Running the C Version

```bash
# Compile
gcc "C programming/Conversions.c" -o conversions -lm

# Run
./conversions
```

> On Windows with the pre-built executable:
> ```
> "C programming\Conversions.exe"
> ```

### Running the Python Version

```bash
python Python/Conversions.py
```

---

## 📖 Usage

Both versions present an interactive menu-driven interface. On launch, you'll see:

```
List of Conversions
1.Binary -> Decimal
2.Octal -> Decimal
3.Hexa Decimal -> Decimal
4.Decimal -> Binary
5.Decimal -> Octal
6.Decimal -> Hexadecimal
7.Binary -> Octal
8.Octal -> Binary
9.Binary -> Hexa Decimal
10.Hexa Decimal -> Binary
11.Octal -> Hexa Decimal
12.Hexa Decimal -> Octal
Enter number which Conversion you want -
```

### Example — Binary to Decimal

**Python version:**
```
Enter number which Conversion you want - 1
You selected Binary -> Decimal
Enter the binary number: 1101
The final answer is: 13
```

### Example — Decimal to Hexadecimal

**Python version:**
```
Enter number which Conversion you want - 6
You selected Decimal -> Hexa Decimal
Enter the Decimal number: 255
The final answer is: FF
```

The program runs in a loop, allowing you to perform multiple conversions in a single session.

---

## ⚙️ How It Works

The converter uses the following core algorithms:

| Function              | Purpose                                                          |
|-----------------------|------------------------------------------------------------------|
| `any_radix_to_dec`    | Converts any base (2, 8, 16) to decimal using positional weights |
| `dec_to_any_radix`    | Converts decimal to any base using repeated division             |
| `bin_to_oct`          | Groups binary digits in 3s to produce octal digits               |
| `oct_to_bin`          | Maps each octal digit to its 3-bit binary representation         |
| `bin_to_hexadec`      | Groups binary digits in 4s to produce hexadecimal digits         |
| `hexadec_to_bin`      | Maps each hex digit to its 4-bit binary representation           |

For **cross-base conversions** (e.g., Octal ↔ Hexadecimal), the program uses **binary as an intermediate** representation — first converting to binary, then to the target base.

---

## ✅ Input Validation

Both implementations include input validation:

- **Binary** inputs only accept `0` and `1`
- **Octal** inputs only accept digits `0`–`7`
- **Decimal** inputs only accept digits `0`–`9`
- **Hexadecimal** inputs accept `0`–`9` and `A`–`F` (case-insensitive)
- The C version prompts digit-by-digit with re-entry on invalid input
- The Python version accepts the full number as a string for a smoother experience

---

## 🤝 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests for:

- Bug fixes
- New number system support (e.g., Base64)
- GUI or web-based interface
- Unit tests

---

## 📄 License

This project is open source and available for educational purposes.

---

## 👤 Author

**Sanjay kumar Chitturi**

---

> 💡 *Built as a learning project to understand number system conversions and algorithm implementation across multiple programming languages.*
