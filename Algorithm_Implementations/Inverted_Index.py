from collections import defaultdict

class InvertedIndex:
    def __init__(self):
        self.index = defaultdict(list)

    def add_document(self, doc_id, text):
        # Split text into words and convert to lowercase
        words = text.lower().split()
        
        # Update the index with words and their positions
        for position, word in enumerate(words):
            self.index[word].append((doc_id, position))

    def search(self, query):
        # Convert query to lowercase
        query = query.lower()
        
        # Return the positions of the query word in all documents
        return self.index.get(query, [])

# Example usage:
if __name__ == "__main__":
    # Create an inverted index instance
    idx = InvertedIndex()
    
    # Add some documents
    idx.add_document(1, "Hello world")
    idx.add_document(2, "This is a sample document")
    idx.add_document(3, "Python is awesome")
    
    # Search for a word in the index
    query = "python"
    results = idx.search(query)
    
    # Print results
    if results:
        print(f"Occurrences of '{query}' in documents:")
        for doc_id, position in results:
            print(f"Document {doc_id}, position {position}")
    else:
        print(f"'{query}' not found in any document")
