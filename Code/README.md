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
