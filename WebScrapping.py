import requests
from bs4 import BeautifulSoup
import csv

def scrape_product_info(url):
    # Send a GET request to the URL
    response = requests.get(url)
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.content, 'html.parser')
    # Find all product containers
    products = soup.find_all('div', class_='product')

    product_info = []
    for product in products:
        name = product.find('h2', class_='product-name').text.strip()
        price = product.find('span', class_='product-price').text.strip()
        rating = product.find('div', class_='product-rating').text.strip()
        product_info.append({'Name': name, 'Price': price, 'Rating': rating})

    return product_info

def save_to_csv(product_info, filename):
    with open(filename, mode='w', newline='', encoding='utf-8') as file:
        fieldnames = ['Name', 'Price', 'Rating']
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        for product in product_info:
            writer.writerow(product)

if __name__ == "__main__":
    # URL of the e-commerce website to scrape
    url = 'https://google.com'

    # Scrape product information
    product_info = scrape_product_info(url)

    # Save product information to a CSV file
    save_to_csv(product_info, 'products.csv')

    print("Product information scraped and saved to products.csv file.")