# 🎮 Tic-Tac-Toe in C++

A simple **2-player Tic-Tac-Toe game** made in **C++**.  
This project focuses on game logic, structured functions, input validation, and clean programming practices.

---

## ⭐ Features

- **2-player local gameplay**
- **Clean and readable board UI**
- **Input validation** (rejects invalid or taken cells)
- **Checks for wins** (rows, columns, diagonals)
- **Tie detection**
- **Player & marker switching**
- **Simple and modular code structure**

---

## 🛠️ Concepts Used

### 🔹 2D Arrays  
Used to represent the 3×3 Tic-Tac-Toe board.

### 🔹 Functions  
Each major game part is separated into functions:
- `drawBoard()`
- `drawBoardAfterInput()`
- `checkwin()`
- `isTie()`
- `swapPlayerAndMarkerBoth()`

### 🔹 Input Validation  
The game checks for:
- Out-of-range input  
- Already occupied cells  

### 🔹 Game Loop Logic  
A clean `while(true)` loop runs the game until:
- A player wins  
- Or the game ends in a tie  

### 🔹 Character Handling  
Uses `toupper()` (from `<cctype>`) to normalize user input.

---

### 🖥️ Compile
---
```bash
g++ TicTacToe.cpp -o ttt
```
---
## 🚀  Run

```bash
./ttt
```
---
### 📂 File Structure 
```bash
.
├── TicTacToe.cpp
├── README.md
└── LICENSE
```

---

### 🤝 Contributing

Pull requests are welcome!
Feel free to fork this repo and improve the game.

---
### 📜 License

This project is licensed under the MIT License.
See the LICENSE file for more details.