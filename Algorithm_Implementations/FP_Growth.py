from collections import defaultdict, namedtuple
from itertools import combinations

class FPNode:
    def __init__(self, item, count, parent):
        self.item = item
        self.count = count
        self.parent = parent
        self.children = {}
        self.next = None

class FPGrowth:
    def __init__(self, min_support):
        self.min_support = min_support
        self.item_counts = defaultdict(int)
        self.transactions = []
        self.freq_patterns = []

    def build_fp_tree(self):
        self.item_counts = defaultdict(int)
        header_table = defaultdict(int)
        for transaction in self.transactions:
            for item in transaction:
                self.item_counts[item] += 1
        frequent_items = {item for item, count in self.item_counts.items() if count >= self.min_support}

        if not frequent_items:
            return None, None

        for item in frequent_items:
            header_table[item] = None

        root = FPNode(None, None, None)
        for transaction in self.transactions:
            sorted_items = sorted([item for item in transaction if item in frequent_items], key=lambda x: (-self.item_counts[x], x))
            current_node = root
            for item in sorted_items:
                current_node = self.insert_node(current_node, item, header_table)
        
        return root, header_table

    def insert_node(self, parent_node, item, header_table):
        if item in parent_node.children:
            child_node = parent_node.children[item]
            child_node.count += 1
        else:
            child_node = FPNode(item, 1, parent_node)
            parent_node.children[item] = child_node

            if header_table[item] is None:
                header_table[item] = child_node
            else:
                current_node = header_table[item]
                while current_node.next:
                    current_node = current_node.next
                current_node.next = child_node

        return child_node

    def mine_patterns(self, root, header_table, prefix):
        for item, node in sorted(header_table.items(), key=lambda x: -self.item_counts[x[0]]):
            new_prefix = prefix.copy()
            new_prefix.append(item)
            self.freq_patterns.append((new_prefix, self.item_counts[item]))
            
            conditional_pattern_base = []
            conditional_node = node
            while conditional_node:
                path = self.get_path(conditional_node)
                if path:
                    conditional_pattern_base.append((path, conditional_node.count))
                conditional_node = conditional_node.next

            conditional_tree, conditional_header = self.build_conditional_tree(conditional_pattern_base)
            if conditional_tree:
                self.mine_patterns(conditional_tree, conditional_header, new_prefix)

    def get_path(self, node):
        path = []
        while node.parent.item:
            path.append(node.parent.item)
            node = node.parent
        path.reverse()
        return path

    def build_conditional_tree(self, conditional_pattern_base):
        transactions = []
        for pattern, count in conditional_pattern_base:
            transactions.extend([pattern] * count)
        self.transactions = transactions
        return self.build_fp_tree()

    def find_frequent_patterns(self, transactions):
        self.transactions = transactions
        root, header_table = self.build_fp_tree()
        if not root:
            return []

        self.mine_patterns(root, header_table, [])
        return self.freq_patterns

if __name__ == "__main__":
    transactions = [
        ["bread", "milk", "vegetables"],
        ["bread", "diapers", "beer", "eggs"],
        ["milk", "diapers", "beer", "cola"],
        ["bread", "milk", "diapers", "beer"],
        ["bread", "milk", "diapers", "cola"]
    ]

    min_support = 2
    fp_growth = FPGrowth(min_support)
    frequent_patterns = fp_growth.find_frequent_patterns(transactions)

    print("Frequent Itemsets with minimum support of", min_support)
    for itemset, support in frequent_patterns:
        print(itemset, ":", support)
