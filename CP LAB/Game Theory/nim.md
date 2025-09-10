# Nim Game

## Definition
- A game with piles of stones.  
- Two players take turns.  
- On each turn, a player can remove any positive number of stones from **one pile only**.  
- The player who takes the last stone **wins**.  

---

## 🔹 Nim Sum
- The key idea is the **XOR (⊕)** of all pile sizes.  
- This XOR value is called the **Nim Sum**.  

\[
\text{Nim Sum} = A_1 \oplus A_2 \oplus A_3 \oplus \cdots \oplus A_n
\]

---

## 🔹 Winning Condition
- If **Nim Sum = 0** → Losing position.  
- If **Nim Sum ≠ 0** → Winning position.  

---

## 🔹 Example
Piles = `[3, 4, 5]`  

Compute Nim Sum:  

\[
3 \oplus 4 \oplus 5 = (011)_2 \oplus (100)_2 \oplus (101)_2 = (010)_2 = 2
\]

- **Nim Sum = 2 ≠ 0 → Winning position.**

### Best move
Make a pile reduction so that Nim Sum becomes 0.  

- Current piles: `[3, 4, 5]`  
- Suppose we reduce **5 → 3**  
- New piles: `[3, 4, 3]`  

\[
3 \oplus 4 \oplus 3 = 0 \quad \checkmark
\]

✅ The winning move is to reduce 5 to 3.  

---

## 🔹 Summary
- Nim is solved with **XOR (Nim Sum)**.  
- **If Nim Sum = 0 → Losing position.**  
- **If Nim Sum ≠ 0 → Winning position** (you can always find a move to make it 0).  
