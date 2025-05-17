import datetime
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os
import statistics as stat

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

num_samples = 1000
sample_size = 10

# TEST RUN:
# Randomly draw a sample of size N = 10 from the Price column:
print("Randomly drawn values: ")
price_sample = np.random.choice(column_data, sample_size, replace = False)
print(price_sample)

# Compute the sample mean (x̄);
sample_mean = stat.mean(price_sample)
print("Sample Mean (x̄): ", sample_mean)

# Calculate the population mean (μ);
pop_mean = stat.mean(column_data)
print("Population mean (μ): ", pop_mean)

print("As the sample size increases; the sample mean (x̄) converges to the population mean (μ).\n")

# Calculate the population standard deviation (σ);
pop_stdev = stat.pstdev(column_data)
print("Population Standard Deviation: ", pop_stdev)

# The population mean and population standard deviation remain constant because they are calculated from the entire dataset.
# Drawing different samples or changing the sample size does not affect these values—they are fixed characteristics of the population.

z_vals = []
for i in range(num_samples):
    current_sample = np.random.choice(column_data, sample_size, replace = False)
    samp_mean = stat.mean(current_sample)
    compute_z = (samp_mean - pop_mean) / (pop_stdev / np.sqrt(sample_size))
    z_vals.append(compute_z)


# Create the plot

plt.figure(figsize=(10, 6))

# Plot the histogram of property prices (scaled)
sns.histplot(z_vals, bins=30, kde = True, color='skyblue')

plt.xlabel("Z-Value")
plt.ylabel("Frequency")
plt.title("Sampling Distribution of Z for N = 10")
plt.grid(True)
plt.show()
