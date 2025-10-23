
## 🎯 Overview

The **Nim Game** is a classic mathematical strategy game implemented in **C++**.  
Players take turns removing objects (like stones or sticks) from one or more piles.  
The player who takes the **last object loses** (or wins, depending on the variation).

This program provides an interactive console version of the Nim Game where you can play **human vs. human** or **human vs. computer** using logical strategy.

---

## 🧩 Game Rules

1. The game starts with a fixed number of **piles** (e.g., 3 piles).  
2. Each pile contains a certain number of **stones** (e.g., 3, 4, and 5).  
3. Players take turns choosing one pile and removing **at least one** stone.  
4. The player forced to take the **last stone loses** (normal play variant).  
5. If enabled, the computer uses the **Nim-sum (binary XOR)** strategy to play optimally.

---

## ⚙️ Features

- 🧑‍🤝‍🧑 Two-player mode  
- 💻 Single-player mode vs. AI (using Nim-sum strategy)  
- 🔢 Configurable number of piles and stones  
- 🧮 Computer automatically calculates optimal moves  
- 🎮 Simple and interactive console interface  
- ⚡ Instant input validation and winner detection  

---

## 🧠 Example Gameplay

Welcome to the Nim Game!
Enter number of piles: 3
Enter stones in each pile: 3 4 5

Current piles: [3, 4, 5]
Player 1, choose a pile (1-3): 3
Enter number of stones to remove: 2

Current piles: [3, 4, 3]
Player 2 (Computer) takes 2 stones from pile 2!

Current piles: [3, 2, 3]
Player 1, choose a pile (1-3): 1
Enter number of stones to remove: 3

Player 2 (Computer) wins!

yaml
Copy code

---

## 🧮 How the Computer Strategy Works

The **computer** uses the **Nim-sum strategy**, based on binary XOR operations:

- Compute the Nim-sum = XOR of all pile sizes.  
- If Nim-sum = 0 → the position is losing.  
- Otherwise, remove enough stones from one pile to make the new Nim-sum = 0.  

This guarantees a win if the computer starts in a **winning position**.

---

## 💻 How to Compile and Run

### 🔧 Compile
```bash
g++ nim_game.cpp -o nim
