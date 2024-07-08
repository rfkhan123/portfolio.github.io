from collections import defaultdict

class InvertedIndex:
    def __init__(self):
        self.index = defaultdict(list)

    def add_document(self, doc_id, text):
        words = text.lower().split()
    
        for position, word in enumerate(words):
            self.index[word].append((doc_id, position))

    def search(self, query):
        query = query.lower()
        
        return self.index.get(query, [])
if __name__ == "__main__":
    idx = InvertedIndex()
    idx.add_document(1, "Hello world")
    idx.add_document(2, "This is a sample document")
    idx.add_document(3, "Python is awesome")
    query = "python"
    results = idx.search(query)
    if results:
        print(f"Occurrences of '{query}' in documents:")
        for doc_id, position in results:
            print(f"Document {doc_id}, position {position}")
    else:
        print(f"'{query}' not found in any document")
