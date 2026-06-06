/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:49:39 by cperales          #+#    #+#             */
/*   Updated: 2026/06/06 12:04:21 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				has_been_lowest;
	bool				above_median;
	bool				bench;
	bool				parse;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct s_benchmark
{
	unsigned short		nsa;
	unsigned short		nsb;
	unsigned short		nss;
	unsigned short		npa;
	unsigned short		npb;
	unsigned short		nra;
	unsigned short		nrb;
	unsigned short		nrr;
	unsigned short		nrra;
	unsigned short		nrrb;
	unsigned short		nrrr;
	unsigned short		total;
	float				dt;
}						t_benchmark;

t_node		*find_last(t_node *stack);
bool		stack_sorted(t_node *stack);

void		pa(t_node ***a, t_node ***b, bool print, t_benchmark **count);
void		pb(t_node ***b, t_node ***a, bool print, t_benchmark **count);

void		sa(t_node ***a, bool print, t_benchmark **count);
void		sb(t_node ***b, bool print, t_benchmark **count);
void		ss(t_node ***a, t_node ***b, bool print, t_benchmark **count);

void		ra(t_node ***a, bool print, t_benchmark **count);
void		rb(t_node ***b, bool print, t_benchmark **count);
void		rr(t_node ***a, t_node ***b, bool print, t_benchmark **count);

void		rra(t_node ***a, bool print, t_benchmark **count);
void		rrb(t_node ***b, bool print, t_benchmark **count);
void		rrr(t_node ***a, t_node ***b, bool print, t_benchmark **count);

int			ft_is_sorted(t_node **a);
int			ft_execute_operation(char *op,
				t_node **a, t_node **b, t_benchmark *count);
void		ft_clear_stdin_line(void);
void		ft_read_opps(t_node **a, t_node **b, t_benchmark *count);

int			ft_parse_errors(int argc, char **argv);
int			ft_check_duplicates(char **argv);
void		ft_parse_options(int argc, char **argv, t_node **a, t_node **b);
void		ft_parse_modes(char **argv, t_node **a, t_node **b, int n);
int			ft_parse_num(char *argv);

int			ft_check_all(char **argv);
int			ft_check_mode(char *argv);
int			ft_check_flags(char **argv);
int			ft_check_check_flags(char **argv);
int			ft_check_args(int n, char **argv);

int			ft_execute_operation(char *op, t_node **a, t_node **b,
				t_benchmark *count);
void		ft_clear_stdin_line(void);
void		ft_read_opps(t_node **a, t_node **b, t_benchmark *count);

void		ft_str_float(float dt);
void		ft_strat_option(int n);
void		ft_bench_ops(t_benchmark *count);
void		ft_bench(int n, t_benchmark *count);

void		ft_move_node_to_top(t_node **a, bool above_median,
				t_benchmark **count);

void		ft_put_indexes(t_node ***stack);
t_node		*ft_find_from_chunk(t_node **stack, int chunk_range);
int			ft_cost_to_top(t_node *a);
int			ft_chunk_sort_loop(t_node ***a, t_node ***b, t_benchmark **count);
void		ft_chunk_sort(t_node **a, t_node **b, int n, t_benchmark *count);

int			ft_cost_of_push_on_first(t_node *a, int chunk_ranges,
				int *hold_first);
int			ft_cost_of_push_on_second(t_node *a, int chunk_ranges,
				int *hold_second);
void		ft_move_second_to_top(t_node ***a, t_node ***b,
				int hold_second, t_benchmark **count);
void		ft_move_first_to_top(t_node ***a, t_node ***b, int hold_first,
				t_benchmark **count);

size_t		ft_check_number_options(char **argv, size_t n, size_t k);
float		ft_check_individual_args(char **argv);
float		ft_check_arg_args(char **argv);
float		ft_disorder_tendency(char **argv);
float		ft_dissorder(t_node *a);

void		ft_free_all(t_node **a, t_node **b);
void		ft_free_stack(t_node **stack);
void		ft_free_array(char **m);

void		ft_parsing_selection(char **argv, t_node **a, t_node **b);
void		ft_adaptative_sort(char **argv, t_node **a, t_node **b);
int			ft_bench_option(char *s1, char *s2);

void		ft_list_stack(t_node **a, char **m, size_t *i, bool bench);
t_node		**ft_stack_operations(t_node **a, char **m, size_t i, int n);
void		ft_stack_stack(t_node ****a, char **m, int n);
int			ft_init_stack(t_node ***a, int argc, char **argv);
t_benchmark	*ft_init_bench(t_node *a);

bool		ft_above_median(t_node *a);
void		ft_arrange(t_node ***a, t_node ***b, t_benchmark **count);
void		ft_ksort(t_node **a, t_node **b, int n, t_benchmark *count);

t_node		*ft_stacknew(int content, bool bench);
t_node		*ft_stackadd_back(t_node **stack, t_node *last);
t_node		*ft_lstlast(t_node *node);
int			ft_stacksize(t_node *node);
size_t		ft_argv_len(char **argv);

t_node		*find_last(t_node *stack);
bool		stack_sorted(t_node *stack);
t_node		*find_min(t_node *stack);
t_node		*find_max(t_node *stack);
int			get_chunk_ranges(t_node *stack);

void		ft_lowest_on_a(t_node	***a, t_node	***b, t_benchmark **count);
void		ft_lowest_on_b(t_node ***a, t_node ***b, t_benchmark **count);
void		ft_simple_sort(t_node **a, t_node **b, int n, t_benchmark *count);

t_node		**ft_create_list(int nb, bool bench);

#endif
