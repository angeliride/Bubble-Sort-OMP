#!/bin/bash -l
#SBATCH -p hpc-short
#SBATCH -N 1 
#SBATCH --exclusive 
#SBATCH -J bubble_sort
#SBATCH -o bsort_omp2.txt 

g++ -fopenmp omp2.cpp -o program_omp

for i in {1..48} 
do  
    echo "Number of threads OMP_NUM_THREADS=$i"
    OMP_NUM_THREADS=$i ./program_omp >> bsort_omp2.txt
done


