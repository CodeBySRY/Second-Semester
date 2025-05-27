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
   - Compute population mean and population standard deviation.

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

## 📚 Observations
Q1. **What do you observe about the spread and shape of the z-value distribution as N increases?**

As sample size N increases (from 10 to 1000), the spread (standard deviation) of the sampling distribution decreases.
The shape becomes more sharply peaked and closely resembles a normal distribution.
For small N, the histogram is wider and more variable (more spread out); for large N, it is narrower and more concentrated around 0.

Q2. **How does this confirm what the Central Limit Theorem predicts?**

The CLT states that as the sample size increases, the sampling distribution of the sample mean approaches a normal distribution, regardless of the shape of the population distribution. 
My observation (narrower, more normal-shaped histogram for N=1000) confirms this.

---

## 🗂 Resources:

- “The Central Limit Theorem – With Examples In Python” Youtube, uploaded by Jon Krohn, 16th March, 2020,
https://www.youtube.com/watch?v=1p8pBje5SOE

- Python – Central Limit Theorem
GeeksforGeeks
https://www.geeksforgeeks.org/python-central-limit-theorem/

---

## 🗃️ File Structure

```text
📁 ES111 Project
├── IndianHousePrices.csv
├── es111.py  ← Main Python script
└── ReadMe.md           ← Project documentation
```
---
