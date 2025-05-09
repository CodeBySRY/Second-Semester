# 🏘️ Pakistan's Real Estate Market Analysis

This is a semester project for **AI102L** that analyzes Pakistan's real estate market using data scraped from **Zameen.com**. It provides insights into property prices based on factors like city and number of bedrooms, while also cleaning and visualizing the data in meaningful ways.

> **Student:** Shayan Rizwan  
> **Roll Number:** 2024585  
> **Course:** AI102L

---



## 📊 Features

- 📦 Loads and inspects raw CSV real estate data.
- 🧹 Cleans and preprocesses the data:
  - Converts prices (PKR in Lakh/Crore) into numeric format.
  - Cleans missing or invalid values.
  - Filters out outliers (top 1% of prices).
- 🌆 Filters and analyzes listings from **major cities**:
  - Karachi, Islamabad, Faisalabad, Rawalpindi, Gujranwala, Multan, Peshawar, Sargodha, Hyderabad.
- 📈 Generates clean, insightful plots:
  - Distribution of property prices.
  - Average price by city.
  - Average price by number of bedrooms.

---

## 🔧 `convert_price` Function – Technical Explanation

In the raw dataset, price values are stored as **strings** like:

- `"PKR 2.5 Crore"`  
- `"PKR 75 Lakh"`  
- `"PKR 1,200,000"`

These formats are **not suitable for numeric analysis**, so we define a function to **convert them to standardized numeric PKR values**.

```python
def _convert_price(self, price_str):
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
```
To standardize the price column from string formats like "PKR 2.5 Crore" or "PKR 80 Lakh" into numerical values, the convert_price function uses built-in Python string methods (replace(), strip(), and lower()) to clean the text and extract the numeric portion. **These methods do not require any external libraries** and are chained for concise and readable preprocessing. This ensures consistent numeric conversion before further analysis and plotting.


---

## 🛠️ Technologies Used

- Python 🐍
- pandas 📊
- seaborn & matplotlib 📉
- Jupyter / VS Code (recommended IDEs)

---

## 📌 How to Run

1. Clone the repo or download the `.py` file and the CSV.
2. Make sure `raw_data_zameen.csv` is in the same directory as the script.
3. Run the Python script:
```bash
python code.py
