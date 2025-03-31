/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:32:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 18:17:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int balance = 0;
pthread_mutex_t mutex;

int	main(int argc, char **argv, char **envp)
{
	long	*args;
	int	var;
	
	var = 0;
	if (!(argc == 5 || argc == 6))
		return (printf("Bad set of args"), 1);
	if (error_syntax(argv, 0) != 0)
		return (printf("Bad set of args"), 1);
	/* args = ft_calloc(sizeof(long), argc - 2);
	while (var < argc - 1)
	{
		args[var] = ft_atol(argv[var + 1]);
		if (args[var] > INT_MAX)
			return (printf("Bad set of args"), 1);
		var++;
	} */
	teste();
	(void)args;
	(void)argv;
	(void)argc;
	(void)envp;
	return (0);
}

int	error_syntax(char **argv, int var)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		var = 0;
		if (argv[i][var] == '\0')
			return (1);
		while (argv[i][var] != '\0')
		{
			if ((argv[i][var] >= '0' && argv[i][var] <= '9') ||
					(argv[i][var] == '-' || argv[i][var] == '+'))
			{
				if ((argv[i][var] == '-' || argv[i][var] == '+') &&
					((argv[i][var + 1] < '0' || argv[i][var] > '9') ||
						(var != '\0')))
					return (1);
			}
			else
				return (1);
			var++;
		}
		i++;
	}
	return (0);
}

// the initial balance is 0

// write the new balance (after as simulated 1/4 second delay)
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}

// returns the balance (after a simulated 1/4 seond delay)
int read_balance()
{
  usleep(250000);
  return balance;
}

// carry out a deposit
void* deposit(void *amount)
{
  // retrieve the bank balance
  pthread_mutex_lock(&mutex);
  int account_balance = read_balance();

  // make the update locally
  account_balance += *((int *) amount);

  // write the new bank balance
  write_balance(account_balance);

  pthread_mutex_unlock(&mutex);
  return NULL;
}

int teste(void)
{
  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);

  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;

  // the deposit amounts... the correct total afterwards should be 500
  int deposit1 = 300;
  int deposit2 = 200;
  pthread_mutex_init(&mutex, NULL);
  

  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);

  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

	  pthread_mutex_destroy(&mutex);
  // output the balance after the deposits
  int after = read_balance();
  printf("After: %d\n", after);

  return 0;
}

