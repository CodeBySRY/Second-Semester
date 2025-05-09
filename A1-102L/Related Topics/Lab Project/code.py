# Semester Project: Pakistans Real Estate Market Analysis
# AI102L
# Shayan Rizwan [2024585]


import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from pathlib import Path

class RealEstateAnalyzer:
    # A class to analyze real estate data from Zameen.com;

    def __init__(self, file_path):
        # Initialize the analyzer with a CSV file path.
        self.file_path = file_path
        self.data = None
        self.filtered_data = None

    def load_data(self):
        self.data = pd.read_csv(self.file_path)
        print(f"Data loaded successfully. Shape: {self.data.shape}")
        # Using self.data.shape, we can output the number of rows or columns in the dataframe, before being cleaned (raw data).

    def clean_data(self, max_bedrooms=11, price_quantile=0.99):
        """
        Clean the dataset by:
        - Converting 'bedroom' to numeric.
        - Standardizing prices (PKR in lakh/crore).
        - Removing outliers.
        """
        
        # Clean bedrooms
        self.data['bedroom'] = pd.to_numeric(self.data['bedroom'], errors='coerce')
        self.data = self.data.dropna(subset=['bedroom'])
        self.data = self.data[self.data['bedroom'] <= max_bedrooms]

        # Clean prices
        self.data['price'] = self.data['price'].apply(self._convert_price)
        self.data = self.data.dropna(subset=['price'])

        # Remove price outliers
        price_limit = self.data['price'].quantile(price_quantile)
        self.filtered_data = self.data[self.data['price'] <= price_limit]

        # Clean city names
        self.data['location_city'] = self.data['location_city'].str.strip().str.title()
        print("Data cleaned successfully.")

    def _convert_price(self, price_str):
        # Helper method to convert price strings to numeric values (PKR);

        # try and except in Python are error-handling blocks:
        # try runs code that might fail, and except gracefully handles any errors that occur, preventing crashes.


        try:
            if pd.isna(price_str):
                return np.nan
            clean_str = price_str.replace("PKR", "").replace(",", "").strip().lower()
            if 'crore' in clean_str:
                return float(clean_str.split()[0]) * 10**7
            elif 'lakh' in clean_str:
                return float(clean_str.split()[0]) * 10**5
            return np.nan
        except:
            return np.nan



    def plot_price_distribution(self):
    # Plot histogram of property prices (always uses filtered data);
      plt.figure(figsize=(10, 6))
      sns.histplot(self.filtered_data['price'], bins=30,
                  color='skyblue', edgecolor='black')
      plt.xlabel("Price (PKR)")
      plt.ylabel("Number of Properties")
      plt.title("Distribution of Property Prices")
      plt.grid(True)
      plt.show()


    def plot_avg_price_by_city(self, cities=None):

        # Plot average prices by city.
        cities = [
                'Karachi', 'Islamabad', 'Faisalabad', 'Rawalpindi',
                'Gujranwala', 'Multan', 'Peshawar', 'Sargodha', 'Hyderabad'
            ]

        city_data = self.data[self.data['location_city'].isin(cities)]
        avg_price = city_data.groupby('location_city')['price'].mean().sort_values(ascending=False)

        plt.figure(figsize=(12, 6))
        avg_price.plot(kind='bar', color='coral')
        plt.title('Average Property Prices by City')
        plt.xlabel('City')
        plt.ylabel('Average Price (PKR)')
        plt.xticks(rotation=45)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.show()

    def plot_avg_price_by_bedroom(self, max_bedrooms=11):

        avg_price = self.data.groupby('bedroom')['price'].mean().sort_index()
        avg_price = avg_price[avg_price.index <= max_bedrooms]

        plt.figure(figsize=(10, 6))
        avg_price.plot(kind='bar', color='teal', edgecolor='black')
        plt.title('Average Price by Number of Bedrooms')
        plt.xlabel('Number of Bedrooms')
        plt.ylabel('Average Property Price (PKR)')
        plt.xticks(rotation=0)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.show()


# Initialize and run analysis
r1 = RealEstateAnalyzer(r"D:\2ND SEMESTER\Second-Semester\A1-102L\Related Topics\Lab Project\raw_data_zameen.csv")
r1.load_data()
r1.clean_data(max_bedrooms=11)  
# Generate plots
r1.plot_price_distribution()
r1.plot_avg_price_by_city()
r1.plot_avg_price_by_bedroom()