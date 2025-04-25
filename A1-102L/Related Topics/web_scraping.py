import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from urllib.request import urlopen # used to open URLs;
import requests # HTTP library to send HTTP requests;
from bs4 import BeautifulSoup # library for parsing HTML and XML documents;
# From the parsed HTML and XML documents, parsed trees are created from which data can be extracted easily.

# We declare a variable and assign it the URL from where data is to be extracted;
url = "https://www.geeksforgeeks.org/"
# Using requests, we can open/fetch the webpage.
response = requests.get(url) 
# Since the output is <Response [200]>, it means that the request was successfully sent.
# print(response)
# html = urlopen(url) # This has the same function as requests, whereby, the webpage is fetched.
# Therefore, the above call is redundant.
# You can either use urlopen(), or, requests.get(), and both will perform and return the same function.
soupObj = BeautifulSoup(response.text, 'lxml')
type(soupObj)

# The script above, uptil to this point, prepares the HTML content from the webpage to be scraped and processed for data extraction.
# The soup object that we defined (soupObj), allows us to extract interesting info about the web page we are scraping.

title = soupObj.title # Allows us to extract the title of the web page we are scraping;
print(title)

# text = soupObj.get_text() # Allows us to extract the text of the webpage;
# print(soupObj.text)

# soupObj.find_all("a")
# The above line of code is used to return all the anchor, <a>, tags, which are used to define the hyperlinks in HTML.
# The .find_all() returns all the individual and seperate links on that webpage that we are scraping.
# Since the above line of code prints out all the attributes of html tags, we can use a for loop to extract and print out only the hyperlinks.
# Firstly, we assign the .find_all() line of code to a variable, and use a for loop that iterates over all the links, extracts it and prints them in a formatted order.
# The code block below essentially prints out all the hyperlinks of the webpage that we are scraping; 
hyperlinks = soupObj.find_all("a")
for weblink in hyperlinks:
    print(weblink.get("href")) 
    # The "href" is an attribute that prints out the actual URLs or link destination(s).
# headings = soupObj.find_all("h2") # Used to extract subheadings or titles in a webpage;
# print(soupObj.prettify()[:100])