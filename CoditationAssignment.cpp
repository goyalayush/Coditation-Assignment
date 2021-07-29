#include <bits/stdc++.h>
using namespace std;
//1 for live. 0 for dead.
//Values of number of rows and columns initialized can be changed as per requirement.
//Currently i have taken them as 100 X 100 grid.

class liveOrDead {
	private:
		int x_coordinate;
		int y_coordinate;
		int orthogonal_grid[100][100];
		int auxiliary_grid[100][100];
		int numberOfRows = 25;
		int numberOfCols = 25;
		int dx[8] = {-1, -1, 0, 1, 1, 0, 1, -1}; //changing current x-coordinate
		int dy[8] = {-1, 0, -1, 1, 0, 1, -1, 1}; //changing current y-coordinate
		vector<pair<pair<int,int>, int>> changes;
		
	public:
		//Constructor to initialize values properly.
		liveOrDead() {
			x_coordinate = 0;
			y_coordinate = 0;
			// Initializing Orthogonal Grid with 625 random values
			srand((unsigned) time(0));
			for(int row = 0; row < numberOfRows; row++) {
				for(int col = 0; col < numberOfCols; col++) {
					orthogonal_grid[row][col] = (rand()%2);
					auxiliary_grid[row][col] = (rand()%2); 
				}
			}
		}
		
		//Updating the matrix with new Values entered by user.
		void update_OrthogonalMatrix(int x_coordinate, int y_coordinate, int newValue) {
			orthogonal_grid[x_coordinate][y_coordinate] = newValue;
		}
		
		//Checking if Coordinates are not going out of bound.
		bool isValid(int rVal, int cVal, int row, int col) {
			return (rVal >= 0 && rVal < row && cVal >= 0 && cVal < col);
		}
		
		//Updating the grid after a tick or time event passed.
		void updationAfterInput() {
			for(int row = 0; row < numberOfRows; row++) {
				for(int col = 0; col < numberOfCols; col++) {
					if(orthogonal_grid[row][col] == 1) {
						int count_live = 0;
						for(int i = 0; i < 8; i++) {
							int rVal = row-dx[i];
							int cVal = col-dy[i];
							if(isValid(rVal, cVal, 5, 5) && orthogonal_grid[rVal][cVal] == 1) {
								count_live++;
							}
						}
						if(count_live < 2 || count_live > 3) {
							auxiliary_grid[row][col] = 0;
							changes.push_back({{row, col}, 0});
						}
					} else {
						int count_live = 0;
						for(int i = 0; i < 8; i++) {
							int rVal = row-dx[i];
							int cVal = col-dy[i];
							if(isValid(rVal, cVal, 5, 5) && orthogonal_grid[rVal][cVal] == 1) {
								count_live++;
							}
						}
						if(count_live == 3) {
							auxiliary_grid[row][col] = 1;
							changes.push_back({{row, col}, 1});
						}
					}
				}
			}
		}
		
		//Printing the grid.
		void print_OrthogonalMatrix() {
			for(int row = 0; row < numberOfRows; row++) {
				for(int col = 0; col < numberOfCols; col++) {
					cout<< orthogonal_grid[row][col]<<" "; 
				}
				cout<<"\n";
			}
		}
		
		//Printing changes happened at that instance of tick.
		void printChanges() {
			for(int i = 0; i < changes.size(); i++) {
				cout<<"x-coordinate: "<<changes[i].first.first<<": y-coordinate: "<<changes[i].first.second<<": changed to:"<<changes[i].second<<"\n";
			}
		}
		
		//Printing state of particular cell desired by the user.
		void stateOfParticularCell(int x_coordinate, int y_coordinate) {
			cout<<orthogonal_grid[x_coordinate][y_coordinate];
		}
		
};

int main() {
	liveOrDead Matrix;
	
	int input = -1;
	int newX = -1, newY = -1, newValue = 0;
	string doUpdation = "no";
	int findX = -1, findY = -1;
			
	cout<<"Coditation Assignment: \n";
	cout<<"Choose from following options[1-4] to perform operations on Orthogonal Grid: \n";
	cout<<"\nPress 1: To Update the cells with new Values of your choice. (Atmax 100).\n";
	cout<<"\nPress 2: To Print the current values of the Orthogonal Matrix and to know the Last changes done after adding cells.\n";
	cout<<"\nPress 3: To Print the current value of the specific cell. X and Y coordinates required. Range->1 to 25. \n";
	cout<<"\nPress 4: To Exit.\n";
	
	//Menu option to access all different scenarios.
	do {
		cout<<"Enter your choice: \n";
		cin>>input;
		switch(input) {
			case 1:
				cout<<"Enter new values for cell (max 100): \n";
				for(int count = 0; count < 100; count++) {
					cout<<"Enter x coordinate: ";
					cin>>newX;
					cout<<"\nEnter y coordinate: ";
					cin>>newY;
					cout<<"\nEnter new value: ";
					cin>>newValue;
					Matrix.update_OrthogonalMatrix(newX, newY, newValue);
					cout<<"\nUpdation done. "<<100-count-1<<" chances remaining. Want to continue updation? yes/no: \n";
					cin>>doUpdation;
					if(doUpdation == "yes" || doUpdation == "Yes") {
						Matrix.update_OrthogonalMatrix(newX, newY, newValue);
						continue;
					} else {
						cout<<"\nCalculating the state of cells in Orthogonal Grid.\n";
						//Updating new values
						Matrix.updationAfterInput();
						cout<<"Press 2 to print the updated values of cells.\n";
						break;
					}
				}
				break;
			
			case 2:
				 cout<<"Current Values of cells in the Grid are: \n";
				 Matrix.print_OrthogonalMatrix();
				 Matrix.printChanges();
				 break;
				
			case 3:
				cout<<"Enter coordinates of Particular cell to know its value: \n";
				cout<<"Enter x coordinate: ";
				cin>>findX;
				cout<<"\nEnter y coordinate: ";
				cin>>findY;
				Matrix.stateOfParticularCell(findX, findY);
				cout<<"\n";
				break;
				
			case 4:
				cout<<"Exiting...\n";
				break;
		}
	}while(input < 4 && input >= 1);
	
	return 0;
}
