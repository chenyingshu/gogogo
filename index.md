<!-- ## Welcome to _Gogogo!_ Project Homepage -->

This is the basic introduction of our project, including system illustration, system demonstration and a final project presentation with a validation trip.

We aim to design a trip planning system considering cost effectiveness, comfort and happiness for photograph lovers. 

The output recommended locations and paths were verified with a actual trip experiment. And we discover that our system's plan can recommend places suitable for photographing with few people and artistic scenery, and provide happy traveling experience with less boring transportation. 

## System Illustration
In this project, we prototype a one-day trip plan with public data and data-driven algorithms.  

Basically, our trip planning system encloses four main steps:
1. [Public Data Collection](#1-data-collection)
2. [Destination Recommendation](2-destination-recommendation)
3. [Path Planning](3-path-planning)
4. [Interactive Path Visualization](4-path-visualization-on-map)

For coding details, please refer to our Github repository. 

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

<!--![Pseudo Code for Location Recommendation](./img/recommend_alg.png)-->
<img src="./img/recommend_alg.png" alt="Area candidates" width="60%" height="auto" >


### 3. Path Planning
We consider three different factors for path planning, _Calories_, _Cost_, and _Time_, indicating customized _Happy_ level.

- Happy level is provided by recommended destinations depending on its scenery beauty level and sufficiently few population, and other traveling experience such as energy consumption (calories), cost, and traffic time.
- Calories can be computed based on distance and path via some algorithm.
- Cost and transportation Time can be retrieved from some software, e.g., Google Map, CityMapper.

### 4. Path Visualization on Map
Finally, we visualize our recommended places and paths in [_Google MyMaps_](https://mymaps.google.com/).
We give an initial suggested map and path planning produced by our system.
And then the user can feel free to change locations and path in his own map.


## System Demonstration

Here is a short video clip of system demonstration (no audio):

<iframe width="560" height="315" src="https://www.youtube.com/embed/i3DSoiUEotE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


Please check more details in the [demo link](https://chenyingshu.github.io/gogogo/demo/).

## Empirical Trip
We take "Kwun Tong Line" as an experimental target area and input N = 6 destinations for trip planning. 

Our system output "Choi Hong Estate" > "Jimmy Bridge" > "Kai Tak Cruise Terminal" > "Kowloon City" > "Oi Man Estate" > "Whampoa Garden" recommended locations and travel paths.

Here are some photos taken by our travellers during the trip.

<div>
 TBD
</div>

## Project Presentation

<iframe width="560" height="315" src="https://www.youtube.com/embed/3rxb72IZaSg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## Project Materials
 [<img src="https://uploads-ssl.webflow.com/51e0d73d83d06baa7a00000f/5cab99df4998decfbf9e218e_paper-01.png" alt="report" sizes="(max-width: 479px) 12vw, (max-width: 767px) 7vw, (max-width: 991px) 41.84375px, 56.6875px" srcset="https://uploads-ssl.webflow.com/51e0d73d83d06baa7a00000f/5cab99df4998decfbf9e218e_paper-01-p-500.png 500w, https://uploads-ssl.webflow.com/51e0d73d83d06baa7a00000f/5cab99df4998decfbf9e218e_paper-01.png 672w"  width="60em">](https://github.com/chenyingshu/gogogo/blob/main/Group9_Project_Report.pdf) **Report** 
 
 [<img src="https://uploads-ssl.webflow.com/51e0d73d83d06baa7a00000f/5cae3b53b42ebb3dd4175a82_68747470733a2f2f7777772e69636f6e66696e6465722e636f6d2f646174612f69636f6e732f6f637469636f6e732f313032342f6d61726b2d6769746875622d3235362e706e67.png" alt="code" width="55em">](https://github.com/chenyingshu/gogogo)  **<\Code>**
