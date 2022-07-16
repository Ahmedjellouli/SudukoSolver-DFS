
# solve suduko puzzle using Dept First Search DFS algorithm

in this code we will take any typical Sudoku puzzle and try to find the sulution using Dept First Search or DFS algorithm .

<p align="center">
  <img  src="https://user-images.githubusercontent.com/90426606/179363582-40e96589-2184-4d84-807e-56f5a9c30190.png">
</p>

# PRINCIPLE
## tree of possibilities
first of all you should find the tree of possibilities as shown bellow
<p align="center">
  <img width="536" height="417" src="https://user-images.githubusercontent.com/90426606/179365564-89a8e56f-95ca-4b36-9c7b-8835e1b684b8.png">
</p>

## Apply DFS algorithme
the basic idea is to start from the root (typical Sudoku puzzle) and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node (means thats it's not a solution path). Then backtrack and check for other unmarked nodes and traverse them, until finding the solution path.
<p align="center">
  <img width="536" height="417" src="https://user-images.githubusercontent.com/90426606/179366317-b06edbe6-e6e5-4ded-9f27-a46646e0eb2a.png">
</p>

# CODE




# Author

* **Ahmed Jellouli** - *ELECTRICAL ENGINEERING STUDENT INTERESTED IN DATA ANALYSIS*

# License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
