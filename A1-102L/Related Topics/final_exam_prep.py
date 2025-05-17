import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os
import statistics as stat

matrix = np.array([[1,2,4,7,8],[1,5,9,64,9]])
print("First Matrix: \n", matrix)
matrix2 = np.array([[1,0,8,0,1],[9,8,5,84,12]])
print("Second Matrix: \n", matrix2)
add = matrix + matrix2 
print("Addition: \n", add)
print(add[1,1]) # Indexing for rows and columns both start from 0;



null_matrix = np.zeros((3,3), dtype = 'int32')
print(null_matrix)

# In order to create a matrix with random 'decimal' values;
rand = np.random.rand(3,4)
print(rand)

# In order to create a matrix with random 'int' values;
# The size of the matrix is also defined;
intrand = np.random.randint(14, size = (3,4))
print(intrand)

id = np.identity(4, dtype = 'int32')
print(id)

# Task: Initialize a custom defined array;
ones = np.ones((5,5), dtype = 'int32')
print(ones)
sub = np.array([[1,5,7],[3,0,3],[90,45,1]])
print(sub)
ones[1:4,1:4] = sub
print("\n Substituted Matrix: \n", ones)

#m1 = np.arange(1,21)
#print(m1)
#m1 = m1.reshape((5,4))
#print(m1)


# Performing matrix multiplication;
# Defining two matrices;
m1 = np.random.randint(10, size = (5,4))
m2 = np.random.randint(10, size = (4,3))
print("Matrix # 1: \n", m1)
print("Matrix # 2: \n", m2)
prod = m1@m2
print("Multiplication Product: \n", prod)

second_col = prod[:, 1] # All the elements in the second row;
print("Second Column: ", second_col)
sum_2 = np.sum(second_col)
mean_2 = np.mean(second_col)

print("Sum Of Elements In 2nd Column: ", sum_2)
print("Mean Of Elements In 2nd Column: ", mean_2)


# Generate a random synthetic student exam data;
n1 = np.arange(1,21)
nums = np.random.randint(10,100, size = 20)
series = pd.Series(nums, index = n1)
print(series)
avg = np.mean(nums)
print("Average Score: ", avg)

# 'Transactions' dataframe
transaction = {"Transaction ID": [1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015],
               "Date": ["2-4-23", "3-4-23", "4-4-23", "5-4-23", "6-4-23", "7-4-23", "8-4-23", "9-4-23", "10-4-23", "11-4-23", "12-4-23", "13-4-23", "14-4-23", "15-4-23", "16-4-23"],
               "Product ID": ["P001", "P002", "P003", "P001", "P004", "P002", "P005", "P003", "P006", "P001", "P002", "P005", "P004", "P006", "P003"],
               "Store ID": ["S001", "S003", "S002", "S001", "S003", "S002", "S001", "S002", "S003", "S001", "S003", "S002", "S001", "S003", "S002"],
               "Sales Amount": [120.50, 250.00, 75.99, 180.75, 99.90, 215.40, 305.00, 88.60, 140.25, 199.99, 260.10, 110.00, 134.75, 95.00, 150.50],
               "Customer Type": ["New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New"],
               "Channel": ["Online", "In-Store", "Online", "In-Store", "Online", "Online", "In-Store", "Online", "Online", "In-Store", "In-Store", "Online", "In-Store", "Online", "Online"]}

df1 = pd.DataFrame(transaction)
print(df1)
