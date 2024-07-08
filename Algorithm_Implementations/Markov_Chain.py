import numpy as np

# Example transition matrix (representing transition probabilities)
# This matrix should be derived from historical user interaction data
transition_matrix = np.array([
    [0.2, 0.3, 0.5],   # Transition probabilities from state 1
    [0.4, 0.1, 0.5],   # Transition probabilities from state 2
    [0.3, 0.6, 0.1]    # Transition probabilities from state 3
])

# Example states (content items or categories)
states = ['Image', 'Video', 'Article']

# Function to predict next state using the Markov Chain
def predict_next_state(current_state):
    current_index = states.index(current_state)
    next_index = np.random.choice(len(states), p=transition_matrix[current_index])
    return states[next_index]

# Example usage
current_state = 'Image'
next_state = predict_next_state(current_state)
print(f"Predicted next content type after {current_state}: {next_state}")
