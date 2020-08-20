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


///

istart = 0 ; // Start search at the beginning
 istop = (int) (cover * (n+1)) - 1 ; // This gives desired coverage
 if (istop >= n) // Happens if careless user has tail=0
 istop = n - 1 ;


///

 best = 1.e60 ; // Will be minimum span
 best_start = best_stop = 0 ; // Not needed; shuts up LINT
 while (istop < n) { // Test every possible position
 range = work[istop] - work[istart] ; // This is what we minimize
 if (range < best) {
 best = range ;
 best_start = istart ;
 best_stop = istop ;
 }
 ++istart ;
 ++istop ;
 }

///

[200~ minval = work[best_start] ; // Value at start of interior interval
 maxval = work[best_stop] ; // And end
 if (maxval <= minval) { // Rare pathological situation
 maxval *= 1.0 + 1.e-10 ;
 minval *= 1.0 - 1.e-10 ;
 }

//

 limit = (maxval - minval) * (1.0 - cover) ;
 scale = -1.0 / (maxval - minval) ;
 for (i=0 ; i<n ; i++) {
 if (raw[i] < minval) // Left tail
 raw[i] = minval - limit * (1.0 - exp ( scale * (minval - raw[i]) ) ) ;
 else if (raw[i] > maxval) // Right tail
 raw[i] = maxval + limit * (1.0 - exp ( scale * (raw[i] - maxval) ) ) ;
 }
}

//



