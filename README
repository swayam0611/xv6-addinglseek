# xv6 System Call Implementation: `lseek()`

An implementation of the standard `lseek()` system call added to the **xv6** operating system kernel. This project enables file offset manipulation (re-positioning read/write file pointers) across different seek modes for `FD_INODE` file structures.

---

## Features & Enhancements

* **`lseek(fd, offset, whence)`**: Full system call implementation supporting file offset updates.
* **Supported Seek Modes**:
  * `SEEK_SET (0)`: Sets the offset relative to the beginning of the file.
  * `SEEK_CUR (1)`: Adjusts the offset relative to the current file offset position.
  * `SEEK_END (2)`: Sets the offset relative to the total file size.
* **Kernel Safety & Concurrency**:
  * Protects inode access using kernel `ilock()` and `iunlock()` mechanics.
  * Validates memory and file bounds ($0 \le \text{offset} \le \text{file\_size}$).
  * Rejects non-seekable structures such as `FD_PIPE`.
* **Testing Routine**: Integrated `trylseek` user program to verify offset positions across multiple seek operations.

---

## Modified & Added Files

| File | Description |
| :--- | :--- |
| **`fcntl.h`** | Defined `SEEK_SET`, `SEEK_CUR`, and `SEEK_END` macros. |
| **`sysfile.c`** | Implemented `sys_lseek()` with bound checks and lock management. |
| **`syscall.h`** | Added `SYS_lseek` system call number definition. |
| **`syscall.c`** | Registered `sys_lseek` function prototype and trap vector mapping. |
| **`user.h`** | Declared `lseek(int, int, int)` prototype for user programs. |
| **`usys.S`** | Added assembly syscall entry trap wrapper for `lseek`. |
| **`Makefile`** | Included `_trylseek` in `UPROGS` target binaries. |
| **`trylseek.c`** | User space program demonstrating system call functionality. |

---

## How to Run and Test

### Prerequisites
* `qemu-system-i386` or standard `qemu`
* `gcc` / `make` build chain

### Steps

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/swayam0611/xv6-addinglseek.git
   cd xv6-addinglseek
   ```

2. **Build and Boot xv6:**
   ```bash
   make qemu-nox
   ```

3. **Execute the `trylseek` User Program:**
   Inside the xv6 shell, run `trylseek` against the built-in `README` file:
   ```bash
   $ trylseek README
   ```


---
