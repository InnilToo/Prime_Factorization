#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Prime Factorization

int isnumber (char *string) {
  for (int i = 0; i < strlen(string); i++) {
    if (isdigit(string[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int n = pow(10,6);
  int A[n];
  memset(A, 0, sizeof A);
  int prime_number_array[(int)sqrt(n)];
  memset(prime_number_array, 0, sizeof prime_number_array);
  int SoE_counter = 0;

  //Sieve of Eratosthenes
  for (int i = 2; i <= sqrt(n); i++) {
    if (!A[i]) {
      for (int j = pow(i, 2); j < n; j += i) {
        A[j] = 1;
      }
    }
  }
  for(int i = 2; i < n; i++) {
		if (!A[i]) {
			prime_number_array[SoE_counter] = i;
			SoE_counter++;
		}
	}

  //scan for input
  char string[512];
  long long data;
  while (1) {
    scanf("%s", string);
    if (isnumber(string) == 0) {
      fprintf(stderr, "Error: Chybny vstup!\n");
      return 100;
    }
    data = atoll(string);
    if (data <= 0) {
      if (data < 0) {
          fprintf(stderr, "Error: Chybny vstup!\n");
          return 100;
      }
      break;
    }
    if (data == 1) {
			printf("Prvociselny rozklad cisla 1 je:\n1\n");
			continue;
		}
    printf("Prvociselny rozklad cisla %lld je:\n", data);
    //creating new array with prime factorization of data number
    int temp_prime_number_array[(int)sqrt(n)];
    memset(temp_prime_number_array, 0, sizeof temp_prime_number_array);
    int i = 0;
    int j = 0;
    while (data > 1) {
      if((data % prime_number_array[i]) == 0) {
        data = data/prime_number_array[i];
        temp_prime_number_array[j] = prime_number_array[i];
        j++;
        i = 0;
      } else {
        i++;
      }
    }
    //printing the output
    i = 1;
    int prev = temp_prime_number_array[0];
    int power = 1;
    while (temp_prime_number_array[i] != 0) {
      if (temp_prime_number_array[i] == prev) {
          power++;
      } else {
        if (power == 1) {
          printf("%d x ", prev);
        } else {
          printf("%d^%d x ", prev, power);
        }
        power = 1;
      }
      prev = temp_prime_number_array[i];
      i++;
    }
      if (power == 1) {
        printf("%d\n", prev);
      } else {
        printf("%d^%d\n", prev, power);
      }
  }

  return 0;
}
