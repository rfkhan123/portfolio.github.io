from sklearn.cluster import KMeans
import numpy as np

# Example engagement data (replace with your actual data)
engagement_data = np.array([[10], [15], [20], [25], [30], [35], [40]])

# Number of clusters (K)
num_clusters = 2

# Create a K-means clustering model
kmeans = KMeans(n_clusters=num_clusters)

# Fit the model to the data
kmeans.fit(engagement_data)

# Get cluster labels and centroids
cluster_labels = kmeans.labels_
centroids = kmeans.cluster_centers_

# Print results
print("Cluster Labels:", cluster_labels)
print("Centroids:", centroids)
