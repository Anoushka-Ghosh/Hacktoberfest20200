import requests # Import libraries / pip3 install requests
from bs4 import BeautifulSoup # pip3 install bs4
import pandas as pd # pip3 install pandas

url="http://feeds.bbci.co.uk/news/rss.xml?edition=us"

resp=requests.get(url) # GET request to feed URL

soup = BeautifulSoup(resp.content, features="xml") # Fetch XML data from feed

items = soup.findAll('item') # Locate posts

item = items[1] # Declare variable

posts = [] # Create empty table

for item in items: # Filter data
    post = {}
    post['title'] = item.title.text
    post['description'] = item.description.text
    post['link'] = item.link.text
    post['pubDate'] = item.pubDate.text
    posts.append(post)

#print(posts)

#print(posts[0])

df = pd.DataFrame(posts,columns=['title','description','link','pubDate']) # Create table

print(df) # For convenience

df.to_csv('BBCNews.csv',index=False, encoding = 'utf-8') # Convert table to CSV
