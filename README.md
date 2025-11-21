# get_next_line

> *Because `read()` alone isn’t enough.*

---

## 📖 Overview
`get_next_line` is a custom implementation of a line‑by‑line reader in C.  
It provides a function that returns one line at a time from a file descriptor, including the terminating newline if present.  
The project explores buffer management, static variables, and robust memory handling.

This version is extended and documented for personal use beyond the 42 curriculum.

---

## ⚙️ Specifications

- **Program name:** `get_next_line`  
- **Turn-in files (42 spec):** `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`  
- **Bonus files:** `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`  
- **External functions allowed:**  
  - `read`, `malloc`, `free`  
- **Global variables:** Not allowed  
- **Static variables:** Allowed inside functions only  
- **Output:** Function returns one line per call, or `NULL` on EOF/error  

---

## 📌 Mandatory Part

### Prototype
```c
char *get_next_line(int fd);

---

```
## 📜 Requirements

- Must return the next line from a file descriptor.  
- The returned line must include the terminating `\n` if present.  
- If the file does not end with a newline, the last line must be returned without `\n`.  
- The function must work with any valid `BUFFER_SIZE` (defined at compile time).  
- Memory must be managed correctly:
  - Free all allocated memory when no longer needed.
  - No memory leaks allowed.  
- On error or EOF, the function must return `NULL`.  
- Global variables are forbidden.  
- Static variables are allowed only inside functions.  
- External functions permitted:
  - `read`
  - `malloc`
  - `free`

## 🛠️ Implementation Notes

- **Static buffer per fd** → stores leftover data between calls.  
- **Reading loop** → repeatedly calls `read()` until a newline or EOF is found.  
- **String joins** → dynamically concatenate chunks until a full line is ready.  
- **Line extraction** → copy up to and including newline into the return string.  
- **Leftover management** → keep remainder for next call.  
- **Error handling** → invalid fd or read error returns `NULL`.  

---

## 🎯 Bonus Part

- Support for multiple file descriptors simultaneously.  
- Each fd maintains its own static buffer (e.g., `databasin[OPEN_MAX]`).  
- Switching between fds does not corrupt leftover data.  
- Must handle alternating calls across different fds without losing track of each buffer.  

---

## 🛠️ Build

- Compile the mandatory version manually:
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     get_next_line.c get_next_line_utils.c main.c -o gnl

- Compile the bonus version manually:
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus


## 🧹 Clean

- Remove compiled executables:
  ```bash
  -rm -f gnl gnl_bonus
  -Remove any leftover object files:  
  rm -f gnl *.o

## 📜 License

- This repository is intended for **personal learning and development**.  
- You are free to:
  - Use the code for educational purposes.  
  - Adapt and extend the implementation in your own projects.  
- Restrictions:
  - No warranty is provided.  
  - The author is not responsible for any misuse or damages.  
- Attribution:
  - Please credit **Edmond Abang Ina** if you share or reuse significant portions of this work.  
