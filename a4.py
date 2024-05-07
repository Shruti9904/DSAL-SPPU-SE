class SetADT:
    def __init__(self):
        self.elements=set()

    def add(self,element):
        self.elements.add(element)

    def remove(self,element):
        self.elements.discard(element)

    def is_contain(self,element):
        return element in self.elements
    
    def size(self):
        return len(self.elements)
    
    def intersection(self,other_set):
        intersection_set=set()
        for element in self.elements:
            if other_set.is_contain(element):
                intersection_set.add(element)
        return intersection_set
    
    def union(self,other_set):
        union_set=set()
        for element in self.elements:
            union_set.add(element)
        for element in other_set.elements:
            union_set.add(element)
        return union_set

    
    def difference(self,other_set):
        difference_set=set()
        for element in self.elements: 
            if not other_set.is_contain(element):
                difference_set.add(element)
        return difference_set
    
    def iterator(self):
        return iter(self.elements)
    
    def subset(self,other_set):
        for element in self.elements:
            if not other_set.is_contain(element):
                return False
        return True
    
set1=SetADT()
set2=SetADT()

set1.add(1)
set1.add(2)
set1.add(3)
set1.add(4)

set2.add(3)
set2.add(4)

print("Set1 : ",set1.elements)
print("Set2 : ",set2.elements)
print("Intersection:",set1.intersection(set2))  
print("Union:",set1.union(set2))  
print("Difference:",set1.difference(set2))  
print("Is set2 a subset of set1",set2.subset(set1))  

# def create_set2():
#     set2.elements.clear()
#     n=int(input("Enter no of elements to be added in set2:"))
#     for i in range(n):
#         element = input("Enter element to add in set2: ")
#         set2.add(element)
#     print("Elements added to set2.")

# def print_menu():
#     print("Menu:")
#     print("1. Add element to set")
#     print("2. Remove element from set")
#     print("3. Check if element is in set")
#     print("4. Get size of set")
#     print("5. Iterate over set")
#     print("6. Intersection of two sets")
#     print("7. Union of two sets")
#     print("8. Difference between two sets")
#     print("9. Check if set is a subset of another set")
#     print("0. Exit")

# if __name__ == "__main__":
#     set1 = SetADT()
#     set2 = SetADT()

#     while True:
#         print_menu()
#         choice = input("Enter your choice: ")

#         if choice == "1":
#             n=int(input("Enter no of elements to be added:"))
#             for i in range(n):
#                 element = input("Enter element to add: ")
#                 set1.add(element)
#             print("Elements added to set.")

#         elif choice == "2":
#             element = input("Enter element to remove: ")
#             set1.remove(element)
#             print("Element removed from set.")
#         elif choice == "3":
#             element = input("Enter element to check: ")
#             if set1.contains(element):
#                 print("Element is in the set.")
#             else:
#                 print("Element is not in the set.")
#         elif choice == "4":
#             print("Size of set:", set1.size())
#         elif choice == "5":
#             print("Elements in set:")
#             for element in set1.iterator():
#                 print(element)
#         elif choice == "6":
#             create_set2()
#             intersection = set1.intersection(set2)
#             print("Intersection of set1 and set2:", intersection)
#         elif choice == "7":
#             create_set2()
#             union = set1.union(set2)
#             print("Union of set1 and set2:", union)
#         elif choice == "8":
#             create_set2()
#             difference = set1.difference(set2)
#             print("Difference between set1 and set2:", difference)
#         elif choice == "9":
#             create_set2()
#             if set1.subset(set2):
#                 print("Set1 is a subset of set2.")
#             else:
#                 print("Set1 is not a subset of set2.")
#         elif choice == "0":
#             print("Exiting program.")
#             break
#         else:
#             print("Invalid choice. Please try again.")

