# Need to create a 'transactions' dataframe, with seven (7) distinct columns;
# Need to create a 'Product Details' dataframe, with  four (4) distinct columns (products should be unique);
# Need to create a 'Store Information' dataframe, with four (4) distinct columns;
# Need to create a 'Employee Records' dataframe, with five (5) distinct columns (for ONLY 6-8 employees);

# In order to setup VS Code for use of the pandas library, we need to use the following command, after selecting the command prompt terminal within VS Code terminal:
# python -m venv myenv -------> [1] - Run in cmd, within the VS Code terminal.
# 'myenv' is essentially the name of the enviroment that will be created that will allow us to activate and install pip packages.
# POINT TO NOTE: The environment folder, 'myenv; CAN be renamed or given any name.
# Then, run the following command, within the same terminal:
# myenv\Scripts\activate --------> [2] 
# Lastly, run the following command:
# pip install pandas --------> [3]
# You should now be able to use the pandas library within VS Code.

import pandas as pd
# print(pd.__version__)
# print("hello world!")

# 'Transactions' dataframe
transaction = {"Transaction ID": [1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015],
               "Date": ["2-4-23", "3-4-23", "4-4-23", "5-4-23", "6-4-23", "7-4-23", "8-4-23", "9-4-23", "10-4-23", "11-4-23", "12-4-23", "13-4-23", "14-4-23", "15-4-23", "16-4-23"],
               "Product ID": ["P001", "P002", "P003", "P001", "P004", "P002", "P005", "P003", "P006", "P001", "P002", "P005", "P004", "P006", "P003"],
               "Store ID": ["S001", "S003", "S002", "S001", "S003", "S002", "S001", "S002", "S003", "S001", "S003", "S002", "S001", "S003", "S002"],
               "Sales Amount": [120.50, 250.00, 75.99, 180.75, 99.90, 215.40, 305.00, 88.60, 140.25, 199.99, 260.10, 110.00, 134.75, 95.00, 150.50],
               "Customer Type": ["New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New", "Returning", "New"],
               "Channel": ["Online", "In-Store", "Online", "In-Store", "Online", "Online", "In-Store", "Online", "Online", "In-Store", "In-Store", "Online", "In-Store", "Online", "Online"]}

df1 = pd.DataFrame(transaction)

# 'Product Details' dataframe
prod_details = {"Product ID": ["P001", "P002", "P003", "P004", "P005", "P006", "P007", "P008", "P009", "P010"],
                "Product Name": ["Smartphone X", "Running Shoes", "Blender Pro", "LED TV 42", "Gaming Laptop", "Denim Jacket", "Wireless Earbuds", "Office Chair", "Electric Kettle", "Yoga Mat"],
                "Category": ["Electronics", "Apparel", "Home Goods", "Electronics", "Electronics", "Apparel", "Electronics", "Home Goods", "Home Goods", "Apparel"],
                "Price": [699.99, 120.00, 89.50, 399.00, 1250.00, 75.00, 59.99, 145.25, 39.99, 30.00]}

df2 = pd.DataFrame(prod_details)

# 'Store Info' dataframe
store_info = {"Store ID": ["S001", "S002", "S003", "S004", "S005"],
              "Region": ["North", "South", "East", "West", "Central"],
              "Store Type": ["Flagship", "Outlet", "Boutique", "Outlet", "Flagship"],
              "Manager": ["Alice Johnson", "Brian Smith", "Cynthia Lee", "David Kim", "Eva Martinez"]}

df3 = pd.DataFrame(store_info)

# 'Employee Records' dataframe
emp_records = {"Employee ID": ["E001", "E002", "E003", "E004", "E005", "E006", "E007", "E008"],
               "Name": ["Jason Lee", "Maria Gomez", "Liam Patel", "Sophia Chen", "Noah Davis", "Ava Wilson", "Ethan Brown", "Olivia Taylor"],
               "Role": ["Sales Rep", "Store Manager", "Sales Rep", "Sales Rep", "Store Manager", "Sales Rep", "Sales Rep", "Sales Rep"],
               "Store ID": ["S001", "S002", "S001", "S003", "S004", "S002", "S005", "S003"],
               "Performance (MonthlyTarget / ActualSales)": ["10000 / 9500", "15000 / 16000", "12000 / 11000", "9000 / 8700", "14000 / 14500", "10000 / 9200", "11000 / 11200", "9500 / 9400"]}

df4 = pd.DataFrame(emp_records)

# Merge 'transactions' dataframe with the 'Product Details' dataframe on Product ID
merge1 = pd.merge(df1, df2, on='Product ID')

# Merge with 'Store Info' dataframe on Store ID
merge2 = pd.merge(merge1, df3, on='Store ID', how='left')

# Aggregating store sales
agg_store_sales = merge2.groupby('Store ID')['Sales Amount'].sum().reset_index()
agg_store_sales.rename(columns={'Sales Amount': 'Total Sales'}, inplace=True)

# Merge aggregated sales data with employee records
final_data = pd.merge(agg_store_sales, df4, on='Store ID', how='left')

# Convert Date column to datetime and set as index
df1['Date'] = pd.to_datetime(df1['Date'], format='%d-%m-%y')  # Corrected format
df1.set_index('Date', inplace=True)

# Resample for daily totals by Channel
daily_by_channel = df1.groupby('Channel')['Sales Amount'].resample('D').sum().unstack(level=0)

# Resample for weekly totals by Channel
weekly_by_channel = df1.groupby('Channel')['Sales Amount'].resample('W').sum().unstack(level=0)

# Calculate 7-day rolling average for Sales Amount
rolling_avg = df1['Sales Amount'].rolling(window=7, min_periods=1).mean()

# Print results
print("Daily Totals by Channel:")
print(daily_by_channel)
print("\nWeekly Totals by Channel:")
print(weekly_by_channel)
print("\n7-day Rolling Average of Sales Amount:")
print(rolling_avg)

# New Analysis
# 1. Group by Product Category
category_analysis = merge2.groupby('Category').agg({
    'Sales Amount': ['sum', 'mean']
}).round(2)
category_analysis.columns = ['Total Sales', 'Average Sales']
category_analysis = category_analysis.sort_values('Total Sales', ascending=False)

# 2. Group by Region and Channel
region_channel_analysis = merge2.groupby(['Region', 'Channel']).agg({
    'Sales Amount': ['mean', 'sum']
}).round(2)
region_channel_analysis.columns = ['Average Sales', 'Total Revenue']

# 3. High-value transactions analysis (threshold: $200)
high_value_threshold = 200
high_value_sales = merge2[merge2['Sales Amount'] > high_value_threshold]
high_value_by_category = high_value_sales.groupby('Category')['Sales Amount'].agg(['count', 'mean']).round(2)
customer_type_comparison = high_value_sales.groupby('Customer Type')['Sales Amount'].mean().round(2)

print("\n1. Category Analysis:")
print(category_analysis)
print("\n2. Region and Channel Analysis:")
print(region_channel_analysis)
print("\n3. High-Value Sales Analysis ($200+):")
print("\nHigh-value transactions by Category:")
print(high_value_by_category)
print("\nAverage High-value Purchase by Customer Type:")
print(customer_type_comparison)