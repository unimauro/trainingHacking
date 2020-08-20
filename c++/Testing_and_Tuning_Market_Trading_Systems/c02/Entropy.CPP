double entropy (
 int n , // Number of data values
 double *x , // They are here
 int nbins , // Number of bins, at least 2
 int *count // Work area nbins long
 )
Chapter 2 Pre-optimization Issues
23
{
 int i, k ;
 double minval, maxval, factor, p, sum ;
 minval = maxval = x[0] ;
 for (i=1 ; i<n ; i++) {
 if (x[i] < minval)
 minval = x[i] ;
 if (x[i] > maxval)
 maxval = x[i] ;
 }
 factor = (nbins - 1.e-10) / (maxval - minval + 1.e-60) ;
 for (i=0 ; i<nbins ; i++)
 count[i] = 0 ;
 for (i=0 ; i<n ; i++) { // Count the number of cases in each bin
 k = (int) (factor * (x[i] - minval)) ;
 ++count[k] ;
 }
 sum = 0.0 ;
 for (i=0 ; i<nbins ; i++) { // Sum Equation 2-1
 if (count[i]) {
 p = (double) count[i] / n ;
 sum += p * log ( p ) ;
 }
 }
 return -sum / log ( (double) nbins ) ;
}
