import datetime
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os

# Debug: Confirm files are together
# print("Files in folder:", os.listdir())

# Load the CSV (same directory)
d1 = pd.read_csv(r"D:\2ND SEMESTER\Second-Semester\A1-102L\Related Topics\ES111 Project\IndianHousePrices.csv")
print(d1.head())

# Preview data: check for the number of rows and columns in the data frame;
print('Dataset has: \n', d1.shape[0], ' records\n', d1.shape[1], ' columns')

# print(d1.dtypes)
