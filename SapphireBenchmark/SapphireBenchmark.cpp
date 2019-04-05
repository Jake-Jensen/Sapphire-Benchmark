// SapphireBenchmark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Written by Jake Jensen, 2019
//
// Benchmarking utility for single core processing.

#include "pch.h"
#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <vector>
#include <Windows.h>

using namespace std;
using namespace std::chrono;

int AverageTime;																		  // Initialize the AverageTime variable
int Warmup;
void Benchmark();
vector<int> RunTimes;																	  // Initialize the RunTimes array
int n = 0;																				  // Initialize the run count variable with 0


int main()
{
	printf("Sapphire's Single Core Benchmark Suite\n");									  // Print my name and information about the program
	printf("Version 1.0.0\n");		// Add versioning information.
	printf("Starting the warmup in 2 seconds.\n\n"); 
	Warmup = 1;
	int Counter = 0;																	 
	while (Counter != 50) {															      
		Counter++;																		 
		Benchmark();
	}
	Warmup = 0;

	printf("Benching in 2 seconds.\n\n");												  // Print the delay time
	Sleep(2000);																		  // Sleep for 2 seconds
																						  
	Counter = 0;																	      // Initialize the counter with a value of 0
	while (Counter != 1000) {															  // While the counter is not 1000, run the next 2 commands
		Counter++;																		  // Increase the counter value by 1
		Benchmark();																	  // Call the benchmark
	}																					  
	for (int x : RunTimes) {															  // For every item in the RunTimes array, do the next command
		AverageTime = AverageTime + x;													  // Take the variable AverageTime, and add the element from array RunTimes
	}																					  // 
	AverageTime = AverageTime / Counter;												  // Find the average of the AverageTime value, from how many times the benchmark ran
	printf("\n\n");																		  // Just a line seperator
																						  
	cout << "Average time of all benches: " << AverageTime << " microseconds" << endl;	  // Print the average time of all benches
	system("pause"); // Probably insecure. Should replace with something like cin.ignore()
}

void Benchmark()
{
	if (Warmup != 1) { // This just prevents the loop counter and vector from being touched.
		n++;																				   // Increase the variable n by 1
		vector<int> values(1000000);														   // Initialize the vector (Values) with 1,000,000 ints
		auto f = []() -> int { return rand() % 1000000; };									   // Randomize the ints between 0 and 1,000,000
		generate(values.begin(), values.end(), f);											   // Fill the vector
		auto start = high_resolution_clock::now();											   // Get the start time point
		sort(values.begin(), values.end());													   // Call the sort function, to start sorting the vector from low to high
		auto stop = high_resolution_clock::now();											   // Get the end time point
		auto duration = duration_cast<microseconds>(stop - start);							   // Determine the duration of the sort function
																							   // 
		RunTimes.push_back(duration.count());												   // Add the duration time to the RunTimes array
																							   // 
		cout << "Bench time of run " << n << ": "											   // Print information about the current run.
			<< duration.count() << " microseconds" << endl;
	}
	else {
		vector<int> values(1000000);														   // Initialize the vector (Values) with 1,000,000 ints
		auto f = []() -> int { return rand() % 1000000; };									   // Randomize the ints between 0 and 1,000,000
		generate(values.begin(), values.end(), f);											   // Fill the vector
		auto start = high_resolution_clock::now();											   // Get the start time point
		sort(values.begin(), values.end());													   // Call the sort function, to start sorting the vector from low to high
		auto stop = high_resolution_clock::now();											   // Get the end time point
		auto duration = duration_cast<microseconds>(stop - start);
	}


}