from sklearn.cluster import KMeans
import numpy as np

engagement_data = np.array([[10], [15], [20], [25], [30], [35], [40]])

num_clusters = 2

kmeans = KMeans(n_clusters=num_clusters)

kmeans.fit(engagement_data)

cluster_labels = kmeans.labels_
centroids = kmeans.cluster_centers_

print("Cluster Labels:", cluster_labels)
print("Centroids:", centroids)
