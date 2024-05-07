class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))

    def search(self, key):
        index = self.hash_function(key)
        comparisons = 0
        for k, v in self.table[index]:
            comparisons += 1
            if k == key:
                return comparisons
        return comparisons

def chaining_collision_technique(numbers):
    hash_table = HashTable(100)  # Adjust size according to the number of clients
    for number, client in numbers:
        hash_table.insert(client, number)
    comparisons = 0
    for _, client in numbers:
        comparisons += hash_table.search(client)
    return comparisons

def linear_probing_collision_technique(numbers):
    hash_table = [None] * 100  # Adjust size according to the number of clients
    for number, client in numbers:
        index = hash(client) % 100
        while hash_table[index] is not None:
            index = (index + 1) % 100
        hash_table[index] = number
    comparisons = 0
    for _, client in numbers:
        index = hash(client) % 100
        while hash_table[index] is not None and hash_table[index] != client:
            index = (index + 1) % 100
            comparisons += 1
    return comparisons

if __name__ == "__main__":
    # Example usage
    clients_numbers = [("John", "123-456-7890"), ("Alice", "987-654-3210"), ("Bob", "555-555-5555"),["John","486-456-789"]]
    
    # Using chaining collision technique
    comparisons_chaining = chaining_collision_technique(clients_numbers)
    print("Comparisons with chaining:", comparisons_chaining)
    
    # Using linear probing collision technique
    comparisons_linear_probing = linear_probing_collision_technique(clients_numbers)
    print("Comparisons with linear probing:", comparisons_linear_probing)

