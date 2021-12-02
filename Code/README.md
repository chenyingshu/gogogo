# Source Code 
This directory contains related source code and data for the project.

# Instruction
## Data
The folder _Data_ contains the sample collected raw data for destination recommendation using a data scraping script.
- [_tag_raw_data.csv_](./Data/tag_raw_data.csv) is a csv file containing collected information (#likes,#posts, etc.) from Instagram with tags of all candidate destinations.
- [_post_loc_data.csv_](./Data/post_loc_data.csv) contains corresponding location information in most hot posts with destination tags.
- [_location_data.csv_](./Data/location_data.csv) contains corresponding location's longitude and latitude in each Instagram location page extracted from hot posts (_post_loc_data.csv_).

## Codes
### Data Collection
[_A Simple Example of Instagram Data Scraping.ipynb_](./A%20Simple%20Example%20of%20Instagram%20Data%20Scraping.ipynb) is a Python notebook script which shows an example how we collect the statistics of a candidate location from public photo website (e.g., Instagram).

### Destination Recommendation

### Path Planning
The folder Code contains the code of our path planning algorithm, user can simplely run TDSP/Debug/TDSP.exe to find the path result.
In this program the user need to in put the number of cities, the start cities, the weights of cost, time and calorie to suggest their happyniess preference. 
The user also need to give the cost Matrix between nodes.A cost matrix is a cities_num * cities_num size matirx.
For example, if cities number is 3, the the matrix for cost looks like this:<br/>
0 2.2 3.8<br/>
2.1 0 2<br/>
6.1 2.3 0<br/>
