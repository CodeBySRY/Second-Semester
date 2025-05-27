# 📊 ES111 Project – Demonstrating the Central Limit Theorem (CLT)

## Overview

This project is a practical demonstration of the **Central Limit Theorem (CLT)** using a real-world dataset containing Indian house prices. The objective is to simulate sampling from a population and show how the sampling distribution of the sample mean approaches a normal distribution, even when the population distribution is unknown or not normal.

## 🧠 Central Limit Theorem (CLT) Recap

The **Central Limit Theorem** states that if you take sufficiently large random samples from a population with a finite level of variance, the sample means will be approximately normally distributed, regardless of the shape of the population distribution.

---

## 📁 Dataset Used

- **File**: `IndianHousePrices.csv`
- **Source**: Real-world data representing residential property prices across India.
- **Column of Interest**: `Price` – This numerical column is treated as the population from which samples are drawn.

---

## 🧪 Project Setup and Code Summary

### 📦 Libraries Used
- `numpy` – For sampling and numerical operations
- `pandas` – For data manipulation
- `statistics` – For computing mean and population standard deviation
- `matplotlib` and `seaborn` – For visualization

### ⚙️ Core Steps

1. **Data Loading**  
   Load the CSV dataset and extract the `Price` column.

2. **Initial Sampling and Mean Calculation**  
   - Draw a single random sample of size 10.
   - Compute and compare the sample mean ( x̄ ) with the population mean ( μ ).

3. **Population Metrics**  
   - Compute population mean \( \mu \) and population standard deviation \( \sigma \).

4. **Simulation**  
   - Draw 1000 random samples of size 10.
   - For each sample, compute the z-value:
     \[
     Z = (x̄ − μ) / (σ / √n) ]
   - Store all z-values for visualization.

5. **Visualization**  
   - Plot a histogram with KDE of the z-values.
   - Demonstrates the convergence of the sampling distribution to a standard normal distribution.

---

## 📈 Output Explanation

The histogram plot illustrates that even with a sample size of only 10 and 1000 iterations:
- The distribution of the sample means becomes approximately normal.
- The center of the histogram aligns closely with 0 (i.e., no bias in sampling).

This validates the Central Limit Theorem.

---

## 🗃️ File Structure

```text
📁 ES111 Project
├── IndianHousePrices.csv
├── es111.py  ← Main Python script
└── ReadMe.md           ← Project documentation
