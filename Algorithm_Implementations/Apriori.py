from collections import defaultdict
from itertools import combinations

def generate_candidates(itemsets, k):
    candidates = set()
    for itemset1 in itemsets:
        for itemset2 in itemsets:
            union = itemset1.union(itemset2)
            if len(union) == k:
                candidates.add(tuple(sorted(union)))
    return candidates
def prune(itemsets, candidates, min_support, transactions):
    item_counts = defaultdict(int)
    frequent_itemsets = []

    for transaction in transactions:
        for candidate in candidates:
            if set(candidate).issubset(transaction):
                item_counts[candidate] += 1

    for itemset, count in item_counts.items():
        support = count / len(transactions)
        if support >= min_support:
            frequent_itemsets.append(itemset)

    return frequent_itemsets

def apriori(transactions, min_support):
    itemsets = [set(transaction) for transaction in transactions]
    k = 1
    frequent_itemsets = []

    while True:
        candidates = generate_candidates(itemsets, k)
        frequent_itemsets_k = prune(itemsets, candidates, min_support, transactions)

        if not frequent_itemsets_k:
            break

        frequent_itemsets.extend(frequent_itemsets_k)
        k += 1

    return frequent_itemsets
if __name__ == "__main__":
    transactions = [
        {"bread", "milk", "vegetables"},
        {"bread", "diapers", "beer", "eggs"},
        {"milk", "diapers", "beer", "cola"},
        {"bread", "milk", "diapers", "beer"},
        {"bread", "milk", "diapers", "cola"}
    ]

    min_support = 0.4
    frequent_itemsets = apriori(transactions, min_support)

    print("Frequent Itemsets with minimum support of", min_support)
    for itemset in frequent_itemsets:
        print(itemset)
