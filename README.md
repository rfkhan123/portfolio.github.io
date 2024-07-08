# Social Media

<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Roshan Khan</dd>
<dt>University</dt>
<dd>KLE Technonlogical University, Hubballi-31</dd>
</dl>

# Introduction
Social media platforms have revolutionized digital communication by enabling users to connect, share content, and interact globally. The evolution of these platforms is driven by advanced algorithms and data analytics, which enhance user experience through personalized content delivery, efficient management of user interactions, and predictive modeling for engagement strategies.
As of May 2024, there are 5.04 billion social media users worldwide, which is 62% of the world's population. As of 2024, the average daily social media usage of internet users worldwide amounted to 143 minutes per day. To increase the users dependency on social media platforms we make use of many different data structures and algorithms to increase time spent per day on social media apps.

<p align="center">
  <img src="https://mauconline.net/wp-content/uploads/Understanding-Social-Media-Marketing-NEW.jpg" alt="Introduction to Social Media" width="600" height="400">
</p>


# Objectives
1. Personalize user experiences through tailored content recommendations based on user preferences and behaviors.
2. Optimize content delivery to ensure quick and relevant access to information and updates.
3. Improve the identification and targeting of user interests and trends for more effective content promotion.
4. Prioritize and display content in feeds based on user interactions and relevance, maximizing engagement.
5. Enable seamless user interaction and community building through efficient group management and user connection strategies.

# Business Cases

## 1. Content Personalization
 Content personalization in social media apps tailors content to user preferences and behaviors using collaborative filtering and content-based filtering, enhancing engagement, satisfaction, and retention through relevant, customized experiences. 

### Collaborative Filtering
[Collaborative filtering](https://github.com/rfkhan123/portfolio.github.io/main/Algorithm_Implementations/Collabarative_Filtering.cpp) is a method used to personalize content by leveraging the preferences and behaviors of similar users. It operates on the principle that users who have agreed on items in the past will agree in the future.

### Content-Based Filtering
[Content-based filtering](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Content_Filtering.cpp)  personalizes content by analyzing the attributes of the items themselves and recommending items similar to those the user has liked in the past. This method relies on the characteristics of the content rather than the preferences of other users.

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Collaborative Filtering  | O(nm)               | O(n + m)             |
| Content-Based Filtering  | O(nm)               | O(n + m)             |

## 2. Content Delivery
 Efficient content delivery in social media apps is crucial for user experience. Algorithms like A*, Dijkstra's, and Kruskal's optimize content delivery paths, database queries, and network design, ensuring quick, relevant, and cost-effective content access. 

### A* Algorithm
The [A* algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/A_star.cpp) is used for finding the shortest path in a weighted graph, which can be useful in optimizing content delivery networks (CDNs) and data retrieval.

<p align="center">
  <img src="https://raw.githubusercontent.com/Codecademy/docs/main/media/a-star-tree-8.png" alt="A* Algorithm" width="600" height="400">
</p>
### Dijkstra's Algorithm
[Dijkstra's algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Dijkstra.cpp)  is another shortest-path algorithm that finds the minimum distance between nodes in a graph. It can be particularly useful for optimizing data storage and retrieval in databases. 

### Kruskal's Algorithm
[Kruskal's algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Kruskal.cpp)  is used to find the minimum spanning tree (MST) of a graph. This is useful for network design and ensuring efficient connectivity in distributed systems. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| A* Algorithm             | O((V + E) log V)    | O(V + E)             |
| Dijkstra's Algorithm     | O(V^2) or O(E log V)| O(V)                 |
| Kruskal's Algorithm      | O(E log V)          | O(V + E)             |

## 3. Keyword Detection
 Keyword detection in social media apps involves identifying specific words or phrases within user-generated content, such as posts, comments, and messages. This is essential for content moderation, targeted advertising, and enhancing user engagement by categorizing and recommending content based on detected keywords. 

### Aho-Corasick Algorithm
 The  [Aho-Corasick algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Aho_Corasick.cpp)  is an efficient method for searching multiple keywords simultaneously within a text. It builds a finite state machine (FSM) that processes the input text in linear time, making it highly suitable for real-time keyword detection in social media applications. 

 <p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20200810153254/ahocorasick21.png" alt="Aho Corasick Algorithm" width="600" height="400">
</p>

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Aho-Corasick Algorithm   | O(n + m + z)        | O(m)                 |

## 4. Priority Ranking of Feed
 Priority ranking in social media refers to the system used to determine the order in which content is displayed to users. This is crucial for enhancing user engagement and ensuring relevant content is shown at the top of feeds. Various algorithms and methods are employed to prioritize content based on multiple factors such as user interactions, content quality, and relevance. 

### Head-Based Priority Ranking
[Head-based priority ranking](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Head_Based_priority.cpp)  is a technique where the "head" of the content distribution (i.e., the most popular or high-priority items) is given precedence. This approach leverages the popularity and engagement metrics of content to rank it higher, ensuring that the most significant and relevant posts are seen first by users. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Head-Based Priority      | O(n log n)          | O(n)                 |

## 5. Search features
 Search features in social media apps allow users to find specific content, users, hashtags, and topics quickly and efficiently. These features are essential for enhancing user engagement, enabling users to discover new content, connect with others, and stay updated on topics of interest. 

### Tries
[A trie](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Tries.cpp)  is a highly efficient data structure used for fast retrieval of strings, making it ideal for implementing search features in social media apps. Tries can significantly improve the speed and accuracy of search operations, especially for autocomplete and prefix-based search functionalities. 

### Inverted Indexes
[Inverted indexes](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Inverted_Index.py)  are a powerful data structure used in social media apps to enable efficient full-text search capabilities. They facilitate quick retrieval of documents (e.g., posts, comments, messages) that contain specific keywords or phrases. This is essential for features like search bars, hashtag tracking, content discovery, and more. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Tries                    | O(m)                | O(m)                 |
| Inverted Indexes         | O(n)                | O(n)                 |

## 6. User Connections
 User connections in social media apps form the backbone of social interactions, allowing users to connect, follow, friend, or network with one another. These connections are critical for content sharing, communication, and community building within the app. Understanding and managing user connections is key to enhancing user engagement and ensuring a robust social experience. 

### BFS
[Breadth-First Search](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/BFS.cpp)  is a fundamental graph traversal algorithm used extensively to explore user connections in social media apps. In the context of social media, users can be represented as nodes in a graph, and connections as edges. BFS is particularly useful for tasks that involve exploring the shortest path between users, discovering all connections at a certain degree of separation, and analyzing the structure of user networks. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| BFS                      | O(V + E)            | O(V)                 |

## 7. Identifying Influencers
 Identifying influencers in social media apps is crucial for understanding which users have significant impact and reach within the network. Influencers drive engagement, spread content, and shape trends. To identify these key individuals, algorithms such as PageRank and centrality measures are employed. 

### PageRank Algorithms
[PageRank](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/PageRank.cpp)   is an algorithm initially developed by Google to rank web pages in search engine results. It can also be applied to social media networks to identify influential users. The idea is that the importance of a user is determined by the number and quality of connections they have. 

### Centrality Algorithms
 Centrality measures help determine the most important nodes (users) in a network. Different centrality metrics provide various insights into user influence. 

 | Algorithm                | Time Complexity     | Space Complexity     |
 |--------------------------|---------------------|----------------------|
 | PageRank Algorithm       | O(V + E)            | O(V)                 |
 | Centrality Algorithms    | O(V^2)              | O(V)                 |

## 8. Engagement Analysis
 Engagement analysis in social media apps involves measuring and understanding how users interact with content, other users, and the platform itself. It plays a crucial role in assessing the effectiveness of content strategies, user retention efforts, and overall platform health. Various engagement metrics are used to quantify user interactions, providing insights that guide decisions on content promotion, user experience enhancements, and community management. 

### K-Means Clustering
[K-Means Clustering](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/K_Means.py) aids engagement network analysis by grouping users with similar interaction patterns, identifying communities, revealing engagement trends, and enabling targeted content strategies to enhance user experience and increase overall platform engagement.

<p align="center">
  <img src="https://static.javatpoint.com/tutorial/machine-learning/images/k-means-clustering-algorithm-in-machine-learning.png" alt="K-Means Clustering" width="600" height="400">
</p>

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| K-Means Clustering       | O(n * k * I * d)    | O(n * k + d)         |

## 9. Community Detection
 Community detection in social media apps involves identifying groups of users who interact more frequently with each other than with the rest of the network. These communities represent clusters of users with common interests, activities, or relationships. Detecting such communities is crucial for targeted marketing, personalized content delivery, and enhancing user experience by fostering meaningful interactions. 

### Common Neighbour
The [Common Neighbor](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Common_Neighbours.cpp) algorithm enhances social network analysis by identifying mutual connections between users, predicting potential friendships, fostering community building, and detecting influential users and social clusters within social media platforms.

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Common Neighbor          | O(n + m)            | O(n + m)             |

## 10. Efficient Group Management
 Efficient group management in social media apps involves handling user groups and communities effectively, ensuring seamless interaction, content sharing, and communication within groups. This includes managing group memberships, merging groups, and tracking connections between different user groups. One fundamental algorithm that aids in this process is the Union-Find algorithm, also known as the Disjoint Set Union algorithm. 

### Union Find
The [Union-Find algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Union_Find.cpp) is a data structure that efficiently handles the union and find operations on disjoint sets. In the context of social media apps, it can be used to manage user groups by quickly determining which group a user belongs to and merging groups when necessary. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Union-Find Algorithm     | O(log n) (amortized)| O(n)                 |

## 11. Push Notification 
 Push notifications are essential tools for social media apps to engage users, increase retention, and drive interaction. Effective push notification strategies involve delivering timely, relevant, and personalized messages to users, encouraging them to return to the app and engage with content or features. The use of predictive modeling enhances these strategies by anticipating user behavior and preferences, leading to more effective and targeted notifications. 

### Random Forest
[Random forest](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Random_Forest.py)  
enhance predictive analysis by forecasting user engagement, recommending content, analyzing sentiments, detecting trends and fraud, and assessing content quality, thereby improving user experiences and platform security.

<p align="center">
  <img src="https://miro.medium.com/v2/resize:fit:592/1*i0o8mjFfCn-uD79-F1Cqkw.png" alt="Random Forest Algorithm" width="600" height="400">
</p>

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Random Forest            | O(n * sqrt(d))      | O(n)                 |

## 12. Behavioral Analysis and Gamification
 Behavioral analysis and gamification are powerful techniques used in social media to enhance user engagement, retention, and overall experience. Behavioral analysis involves understanding user actions and preferences, while gamification leverages game-like elements to motivate and reward user participation. 

### Apriori Algorithm
[The Apriori algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Apriori.py)    is used for mining frequent itemsets and deriving association rules from large datasets. In the context of social media, it helps in understanding user behavior by identifying common patterns in user interactions. This information can be leveraged for both behavioral analysis and gamification. 

### FP-Growth Algorithm
[The FP-Growth algorithm](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/FP_Growth.py) is an efficient method for frequent itemset mining that avoids candidate generation, making it faster than Apriori for large datasets. It uses a compressed representation of the dataset called an FP-tree. 

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Apriori Algorithm        | O(2^n) * O(n)       | O(2^n)               |
| FP-Growth Algorithm      | O(n * (m + d))      | O(m + d)             |

## 13. Infinite Scrolling
Infinite scrolling is a popular feature in social media apps that automatically loads more content as users scroll down the page, eliminating the need for pagination and providing a seamless browsing experience. 

### Markov Chains
[Markov Chains](https://github.com/rfkhan123/portfolio.github.io/blob/main/Algorithm_Implementations/Markov_Chain.py) are stochastic models that describe a sequence of possible events in which the probability of each event depends only on the state attained in the previous event. In the context of content prefetching for social media apps, Markov Chains can be used to predict the next piece of content a user is likely to view based on their current browsing behavior.

| Algorithm                | Time Complexity     | Space Complexity     |
|--------------------------|---------------------|----------------------|
| Markov Chains            | O(n^2)              | O(n)                 |
