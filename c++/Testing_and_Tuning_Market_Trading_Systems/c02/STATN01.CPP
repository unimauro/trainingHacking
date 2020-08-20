#define NGAPS 11 /* Number of gaps in analysis */
 ngaps = NGAPS ;
 k = 1 ;
 for (i=0 ; i<ngaps-1 ; i++) {
 gap_size[i] = k ;
 k *= 2 ;
 }

void gap_analyze (
 int n ,
 double *x ,
 double thresh ,
 int ngaps ,
 int *gap_size ,
 int *gap_count
 )
{
 int i, j, above_below, new_above_below, count ;
 for (i=0 ; i<ngaps ; i++)
 gap_count[i] = 0 ;
 count = 1 ;
 above_below = (x[0] >= thresh) ? 1 : 0 ;
 for (i=1 ; i<=n ; i++) {
 if (i == n) // Passing end of array counts as a change
 new_above_below = 1 - above_below ;
 else
 new_above_below = (x[i] >= thresh) ? 1 : 0 ;
 if (new_above_below == above_below)
 ++count ;
 else {
 for (j=0 ; j<ngaps-1 ; j++) {
 if (count <= gap_size[j])
 break ;
 }

 ++gap_count[j] ;
 count = 1 ;
 above_below = new_above_below ;
 }
 }
}
