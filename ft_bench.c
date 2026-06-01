
#include "ft_push_swap.h"


ft_str_float(float dt)
{
	dt *= 10000;
	ft_putnbr_fd(dt / 100, 2);
	write(2, ',', 1);
	ft_putnbr_fd(dt % 100, 2);
	write(2, "%%\n", 2);

}
void	ft_strat_option(int n)
{
	if (n == 1)
		write (2, "Simple / O(n^2)\n", 16);
	else if (n == 2)
		write(2, "Medium / O(n^3/2)\n" 18);
	else if (n == 3)
		write(2, "Complex / O(nlog(n))\n", 21);
	else if (n == 4)
		write(2, "Adaptive / O(n^2)\n", 18);
	else if (n == 5)
		write(2, "Adaptive / O(n^3/2)\n", 20);
	else if (n == 6)
		write(2, "Adaptive / O(nlog(n))\n", 22);
}

void	ft_bench_ops(t_benchmark count)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(count->sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(count->sb, 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(count->pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(count->pb, 2);
	write(2, "\n[bench] ra: ", 13);
	ft_putnbr_fd(count->ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(count->rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(count->rr, 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(count->rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(count->rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(count->rrr, 2);
}

void	ft_bench(float dt, int n, t_benchmark count)
{
	write(2, "[bench] dissorder: ", 19);
	ft_str_float(dt);
	write(2, "[bench] strategy: ");
	ft_strat_option(n);
	write(2, "[bench] total ops: ", 20);
	ft_putnbr_fd(count->total, 2);
	ft_bench_ops(count);
}
