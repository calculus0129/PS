"""graph = {
    'Q': ['W', 'A'],
    'W': ['Q', 'A', 'S', 'D', 'E'],
    'E': ['W', 'S', 'D', 'F', 'R'],
    'R': ['E', 'D', 'F', 'G', 'T'],
    'T': ['R', 'F', 'G', 'H', 'Y'],
    'Y': ['T', 'G', 'H', 'J', 'U'],
    'U': ['Y', 'H', 'J', 'K', 'I'],
    'I': ['U', 'J', 'K', 'L', 'O'],
    'O': ['I', 'K', 'L', 'P'],
    'P': ['O', 'L'],

    'A': ['Q', 'W', 'S', 'Z'],
    'S': ['A', 'W', 'E', 'D', 'X', 'Z'],
    'D': ['S', 'E', 'R', 'F', 'C', 'X'],
    'F': ['D', 'R', 'T', 'G', 'V', 'C'],
    'G': ['F', 'T', 'Y', 'H', 'B', 'V'],
    'H': ['G', 'Y', 'U', 'J', 'N', 'B'],
    'J': ['H', 'U', 'I', 'K', 'M', 'N'],
    'K': ['J', 'I', 'O', 'L', 'M'],
    'L': ['K', 'O', 'P'],

    'Z': ['A', 'S', 'X'],
    'X': ['Z', 'S', 'D', 'C'],
    'C': ['X', 'D', 'F', 'V'],
    'V': ['C', 'F', 'G', 'B'],
    'B': ['V', 'G', 'H', 'N'],
    'N': ['B', 'H', 'J', 'M'],
    'M': ['N', 'J', 'K']
}

dist = {}

def bfs_dist(key):
    global dist
    discovered={x:False for x in graph}
    que=[key]
    dist[(key,key)]=0
    discovered[key]=True
    while que:
        f=que.pop(0)
        for next in graph[f]:
            if discovered[next]: continue
            discovered[next]=True
            dist[(key,next)]=dist[(key,f)]+1
            que.append(next)

def init():
    global graph
    for key in graph:
        bfs_dist(key)

def work(s):
    global dist
    n=len(s)
    ans=n
    for i in range(1, n):
        ans += dist[(s[i-1],s[i])]<<1
    return ans
    
init()
t = int(input())
while t:
    print(work(input()))
    t-=1
"""

from collections import deque

class KeyboardDistanceCalculator:
    def __init__(self):
        self.graph = {
            'Q': ['W', 'A'],
            'W': ['Q', 'A', 'S', 'E'],
            'E': ['W', 'S', 'D', 'R'],
            'R': ['E', 'D', 'F', 'T'],
            'T': ['R', 'F', 'G', 'Y'],
            'Y': ['T', 'G', 'H', 'U'],
            'U': ['Y', 'H', 'J', 'I'],
            'I': ['U', 'J', 'K', 'O'],
            'O': ['I', 'K', 'L', 'P'],
            'P': ['O', 'L'],

            'A': ['Q', 'W', 'S', 'Z'],
            'S': ['A', 'W', 'E', 'D', 'X', 'Z'],
            'D': ['S', 'E', 'R', 'F', 'C', 'X'],
            'F': ['D', 'R', 'T', 'G', 'V', 'C'],
            'G': ['F', 'T', 'Y', 'H', 'B', 'V'],
            'H': ['G', 'Y', 'U', 'J', 'N', 'B'],
            'J': ['H', 'U', 'I', 'K', 'M', 'N'],
            'K': ['J', 'I', 'O', 'L', 'M'],
            'L': ['K', 'O', 'P'],

            'Z': ['A', 'S', 'X'],
            'X': ['Z', 'S', 'D', 'C'],
            'C': ['X', 'D', 'F', 'V'],
            'V': ['C', 'F', 'G', 'B'],
            'B': ['V', 'G', 'H', 'N'],
            'N': ['B', 'H', 'J', 'M'],
            'M': ['N', 'J', 'K']
        }
        self.dist = {}
        self.init_distances()

    def bfs_dist(self, key):
        discovered = {x: False for x in self.graph}
        que = deque([key])
        self.dist[(key, key)] = 0
        discovered[key] = True
        
        while que:
            f = que.popleft()
            for next_key in self.graph[f]:
                if discovered[next_key]: continue
                discovered[next_key] = True
                self.dist[(key, next_key)] = self.dist[(key, f)] + 1
                que.append(next_key)

    def init_distances(self):
        for key in self.graph:
            self.bfs_dist(key)
        # print("Distances initialized:", self.dist)  # For debugging

    def calculate_cost(self, s):
        n = len(s)
        ans = n
        for i in range(1, n):
            ans += self.dist[(s[i-1], s[i])] * 2  # Using * 2 instead of << 1 for clarity
        return ans

# Main function to process input and output
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    t = int(data[0])
    queries = data[1:t+1]

    calculator = KeyboardDistanceCalculator()
    results = [calculator.calculate_cost(query) for query in queries]
    
    for result in results:
        print(result)
