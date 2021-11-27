<!-- ## Welcome to _Gogogo!_ Project Homepage -->

This is the basic introduction of our project, including our data collection, filtering, recommendation, path planning, visualization, and final validation trip.

### Introduction
In this project, we will finish a one-day trip planning with public data and data-driven algorithms.

Basically, our system encloses four main steps:
1. [Public Data Collection](#1-data-collection)
2. [Destination Recommendation](2-destination-recommendation)
3. [Path Planning](3-path-planning)
4. [Interactive Path Visualization](4-path-visualization-on-map)

### 1. Data Collection
#### Nearby Area Search
We *roughly* figure out nearby areas (e.g., based on transportations) around the target traveling area.
These areas provide close places with large area.

For example, to explore candidate areas around _Kwun Tong Line_, we have these candidates:
<!-- ![Area candidates](./img/1_1_location_candidates.png) -->
<img src="./img/1_1_location_candidates.png" alt="Area candidates" width="60%" height="auto" >

#### Basic Data Examples
Then based on nearby areas, we collected all related *"tags"* in [_Instagram_](https://www.instagram.com/), where people would like to share beautiful photos
with location and tags. And we can therefore collect location inforamtion (e.g., longitude and latitude) and place popularity information (e.g., # likes of a post).

Here shows some samples of our collected information from Instagram via data scraping.

``` 
tag_name,num_post,max_likes,top_post_url
ngoutaokok,6150,308,https://www.instagram.com/p/CHDGYcYhDBi
oimanestate,1110,425,https://www.instagram.com/p/CO8pnj9gNZ3
```

[Instagram search result with tag _#ngautaukok_](https://www.instagram.com/explore/tags/ngautaukok/) <br>
[Instagram search result with tag _#oimanestate_](https://www.instagram.com/explore/tags/oimanestate/) <br>
 

### 2. Destination Recommendation
After we collected destination candidates for photographing.
We proposed an enconomical filtering algorithm based on popularity and sustanabilty.



### 3. Path Planning
We consider four different factors for path planning, _Happy_ level, _Calories_, _Cost_, and _Time_.
- Happy level is provided by the destination depending on its scenery beauty level.
- Calories can be computed based on distance and path via some algorithm.
- Cost and transportation Time can be retrieved from some software, e.g., Google Map, CityMapper.

### 4. Path Visualization on Map
Finally, we visualize our recommended places and paths in [_Google MyMaps_](https://mymaps.google.com/).
We give an initial suggested map and path planning produced by our system.
And then the user can feel free to change locations and path in his own map.
