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
