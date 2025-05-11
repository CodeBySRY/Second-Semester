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
# print(d1.head())

# Preview data: check for the number of rows and columns in the data frame;
# print('Dataset has: \n', d1.shape[0], ' records\n', d1.shape[1], ' columns')

# To check for the type of variable of each column;
# print(d1.dtypes)

# Extract the 'Price' column as the target variable;
# The head() function in Pandas is used to quickly inspect the first few rows of a DataFrame or Series.
# column_data = d1['Price'].head(10)
column_data = d1['Price']
# print(column_data)

# Now that the 'Price' column has been extracted, we randomly draw a sample of size n = 10, from the price column;
# Sample size (sample_size) = 10
# Num. of samples (num_samples) = 1000

sample_size = 10

# Trying...
# Randomly draw a sample of size N = 10 from the Price column:
print("Randomly drawn values: ")
price_sample = np.random.choice(column_data, sample_size, replace = False)
print(price_sample)






price_upper_limit = d1['Price'].quantile(0.50)
filtered_data = d1[d1['Price'] <= price_upper_limit]

# Create the plot
"""
plt.figure(figsize=(10, 6))

# Plot the histogram of property prices (scaled)
sns.distplot(filtered_data['Price'], bins=30, color='skyblue')

plt.xlabel("Sample Mean")
plt.ylabel("Frequency")
plt.title("Sampling Distribution")
plt.grid(True)
plt.show()
"""