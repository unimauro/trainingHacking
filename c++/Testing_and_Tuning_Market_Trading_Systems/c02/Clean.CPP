void clean_tails (
 int n , // Number of cases
 double *raw , // They are here
 double *work , // Work area n long
 double tail_frac // Fraction of each tail to be cleaned (0-0.5)
 )
{
 int i, istart, istop, best_start, best_stop ;
 double cover, range, best, limit, scale, minval, maxval ;
 cover = 1.0 - 2.0 * tail_frac ; // Internal fraction preserved
 for (i=0 ; i<n ; i++)
 work[i] = raw[i] ;
 qsortd ( 0 , n-1 , work ) ; // Sort data ascending
