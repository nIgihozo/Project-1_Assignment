#include <stdio.h>

/*Function Prototypes*/
int total_distance(int arr[], int n);
float average_distance(int arr[], int n);
int longest_route(int arr[], int n);
int count_above_limit(int arr[], int n, int limit);
int recursive_sum(int arr[], int n);

/*Main function that analyzes delivery route distances*/

int main(void)
{
    int routes[6] = {12, 25, 18, 40, 15, 30};
    int n = 6;
    int limit = 20;

    printf("===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance covered: %d km\n", total_distance(routes, n));
    printf("Average distance per route: %.2f km\n", average_distance(routes, n));
    printf("Longest route: %d km\n", longest_route(routes, n));
    printf("Number of routes above limit: %d\n", count_above_limit(routes, n, limit));
     printf("Routes above 20km: %d\n", count_above_limit(routes, n, 20));
    printf("Recursive sum: %d\n", recursive_sum(routes, n));
   
    return(0);
}

int total_distance(int arr[], int n)
{
    int sum = 0, i;
    for(i = 0; i < n; i++)
            sum += arr[i];
    return(sum);
}

/*Reuse total distance to calculate the Average*/
 float average_distance(int arr[], int n)
 {
    return((float)total_distance(arr, n) / n);
 }

 /*Longest distance*/
 int longest_route(int arr[], int n)
 {
    int max = arr[0], i;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i]; 
    }
    return(max);
 }

 /*Count the number of routes above a certain limit*/
 int count_above_limit(int arr[], int n, int limit)
 {
    int count = 0, i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] > limit)
            count++;
    }
    return(count);
 }

 /*Recursive Function*/
int recursive_sum(int arr[], int n)
{
    /*Base Case*/
        if (n <= 0)
        return 0;

        /*Recursive Sum Case*/
        return arr[n - 1] + recursive_sum(arr, n - 1);
}