# DSA_Project1
# 📘 ECE 309 Program 1 — List Update Problem

## 🧠 Overview
This project implements two linked-list self-organizing heuristics — **Move-to-Front (MTF)** and **Transpose** — to minimize the number of steps required to access requested elements.  
It is based on the *List Update Problem* assignment from **ECE 309, Spring 2024**.

The program reads two input files:
- One file containing the **initial linked list data** (e.g., `data.txt`)
- One file containing the **sequence of access requests** (e.g., `request.txt`)

The algorithm selected by the user determines how the linked list reorganizes itself after each access.

---

## ⚙️ Learning Objectives
- Practice **linked-list programming and manipulation**
- Map a **real-world optimization problem** to data structures
- Apply **object-oriented design** principles
- Compare the **efficiency of list update heuristics**

---

## 🧩 Algorithms Implemented

### 🔹 Move-to-Front (MTF)
When an item is accessed, it is **moved to the front** of the list immediately.  
This assumes that recently accessed elements are more likely to be accessed again soon.

Example:
```
Before: 1 → 3 → 4 → 2 → 6 → 5
Access: 6
After:  6 → 1 → 3 → 4 → 2 → 5
```

### 🔹 Transpose
When an item is accessed, it is **swapped with the previous node** (moved one step closer to the front).  
This is a more conservative heuristic.

Example:
```
Before: 1 → 3 → 4 → 2 → 6 → 5
Access: 6
After:  1 → 3 → 4 → 6 → 2 → 5
```

---

## 🧱 Program Structure

### **Classes**
| Class | Description |
|-------|--------------|
| `Item` | Stores the integer value for each node |
| `Node` | Contains an `Item`, a pointer to the next node, and an access counter |
| `LinkedList` | Manages nodes, supports adding/removing elements, and implements `search_MTF` and `search_trans` |
| `main()` | Reads input files, selects heuristic, runs access simulation, and outputs total step count |

---

## 📂 Input Files

### **data.txt**
Contains one integer per line — the initial linked list elements.

Example:
```
1
3
4
2
6
5
```

### **request.txt**
Contains the requested items (values to search in the list), one per line or space-separated.

Example:
```
6 4 6 2 5
```

---

## 🧭 Usage

### **Compile**
```bash
g++ main.cpp -o list_update
```

### **Run**
```bash
./list_update <approach> <request_file> <data_file>
```

### **Arguments**
| Argument | Description | Example |
|-----------|--------------|----------|
| `<approach>` | Repositioning heuristic (`0` for MTF, `1` for Transpose) | `0` |
| `<request_file>` | File with access requests | `request.txt` |
| `<data_file>` | File with initial linked list | `data.txt` |

Example command:
```bash
./list_update 0 request.txt data.txt
```

---

## 🧾 Output
The program outputs **a single integer**:  
the **total number of steps** taken to process all requests.

Example output:
```
23
```

---

## 🧪 Validation and Testing

Two validation test files are provided (`validation1.txt`, `validation2.txt`):  
| File | Requests | Expected MTF Steps | Expected Transpose Steps |
|------|-----------|--------------------|--------------------------|
| validation1.txt | `0 1 2 3 4 5 6 7 8 9` | 55 | 55 |
| validation2.txt | `0 1 3 0 2 0 2 4` | 23 | 22 |

---

## 🧰 Example Run

**Given:**  
`data.txt`
```
0
1
2
3
4
```
`request.txt`
```
3
1
4
```
**Command:**
```bash
./list_update 0 request.txt data.txt
```
**Output:**
```
8
```

---

## 🧑‍💻 Author
**Michael Gentry**  
Computer Engineering Student — North Carolina State University

---

## 🧹 Notes
- The program adheres to the ECE 309 submission format:
  - Folder name: `prog1`
  - Files included:  
    `main.cpp`, `Makefile`, `request_1.txt`, `request_2.txt`, `request_3.txt`, and `report.pdf`
- To rebuild the executable with the Makefile, simply run:
  ```bash
  make
  ```
- To clean compiled files:
  ```bash
  make clean
