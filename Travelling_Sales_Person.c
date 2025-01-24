/*
Travelling sales person
SCT221-0207/2023 -- Marylyne Nashipae
SCT221-0181/2023 -- Brian Kyalo Kimanzi
SCT221-0522/2022 -- Kaguchia Kago 
 */
#include <stdio.h>
#include <limits.h>

#define MAX 20 // Maximum number of cities 
#define INF INT_MAX  // INF = "infinity"

int No_City; // Number of cities
int costMatrix[MAX][MAX]; 
int dynamicProg[1 << MAX][MAX]; // dynamicprogramming to store minimum costs

// Function to solve TSP using Dynamic Programming 
int TravellingSalesMan(int mask, int pos) {
    // If all cities are visited, return cost to return to the starting city
    if (mask == (1 << No_City) - 1) {
        return costMatrix[pos][0];
    }

    // If this subproblem is already solved, return the stored result
    if (dynamicProg[mask][pos] != -1) {
        return dynamicProg[mask][pos];
    }

    int res = INF;  //Initialize the minimum cost as "infinity"

    // Try visiting all unvisited cities
    for (int city = 0; city < No_City; city++) {
        if ((mask & (1 << city)) == 0) { // If city is not visited
            int newCostMatrix = costMatrix[pos][city] + TravellingSalesMan(mask | (1 << city), city);
            if (newCostMatrix < res) {
                res = newCostMatrix;
            }
        }
    }

    // Store and return the minimum cost
    return dynamicProg[mask][pos] = res;
}

int main() {

    No_City = 4; 
    int sampleCostMatrix[MAX][MAX] = {
        {0, 11, 17, 22},
        {11, 0, 46, 25},
        {17, 46, 0, 30},
        {22, 25, 30, 0}
    };

    // Copy example cost matrix into the global cost matrix
    for (int i = 0; i < No_City; i++) {
        for (int j = 0; j < No_City; j++) {
            costMatrix[i][j] = sampleCostMatrix[i][j];
        }
    }

    // Initialize g table with -1
    for (int i = 0; i < (1 << MAX); i++) {
        for (int j = 0; j < MAX; j++) {
            dynamicProg[i][j] = -1;
        }
    }

    // Solve TSP starting from city 0 with only city 0 visited mask = 1
    int output = TravellingSalesMan(1, 0);

    printf("The minimum cost of all cities visited = %d\n", output);

    return 0;
}



